# PowerShell script to remove all comments from C/C++ files and replace Vatsal with Ajit
# This processes all .c and .cpp files in the DSA directory

$baseDir = "c:\Users\dajit\Downloads\DSA-100-Days-Of-Code-UPES-main\DSA-100-Days-Of-Code-UPES-main"

# Get all .c and .cpp files
$files = Get-ChildItem -Path $baseDir -Recurse -Include "*.c","*.cpp"

$totalFiles = $files.Count
$processedCount = 0
$modifiedCount = 0

Write-Host "Found $totalFiles files to process..."

foreach ($file in $files) {
    $processedCount++
    $content = Get-Content -Path $file.FullName -Raw
    $originalContent = $content
    
    # Read file line by line
    $lines = Get-Content -Path $file.FullName
    $newLines = @()
    $inBlockComment = $false
    $modified = $false
    
    foreach ($line in $lines) {
        $currentLine = $line
        
        # Handle block comments /* ... */
        if ($inBlockComment) {
            if ($currentLine -match '\*/') {
                # End of block comment - remove up to and including */
                $currentLine = ($currentLine -replace '^.*?\*/', '').TrimStart()
                $inBlockComment = $false
                if ([string]::IsNullOrWhiteSpace($currentLine)) {
                    $modified = $true
                    continue
                }
            } else {
                # Still inside block comment, skip this line
                $modified = $true
                continue
            }
        }
        
        # Check for block comment start
        if ($currentLine -match '/\*') {
            if ($currentLine -match '/\*.*?\*/') {
                # Single-line block comment like /* comment */
                $currentLine = $currentLine -replace '/\*.*?\*/', ''
                $currentLine = $currentLine.TrimEnd()
                if ([string]::IsNullOrWhiteSpace($currentLine)) {
                    $modified = $true
                    continue
                }
                $modified = $true
            } else {
                # Multi-line block comment starts here
                $before = ($currentLine -replace '/\*.*$', '').TrimEnd()
                $inBlockComment = $true
                if ([string]::IsNullOrWhiteSpace($before)) {
                    $modified = $true
                    continue
                }
                $currentLine = $before
                $modified = $true
            }
        }
        
        # Check if the entire line is a // comment (with optional leading whitespace)
        if ($currentLine -match '^\s*//') {
            $modified = $true
            continue  # Skip this line entirely
        }
        
        # Remove inline // comments (but be careful not to remove // in strings)
        # Simple approach: remove // that appears outside of string literals
        # For these DSA files, inline comments are typically at end of code lines
        if ($currentLine -match '//') {
            # Check if // is inside a string literal by counting quotes before it
            $idx = $currentLine.IndexOf('//')
            $beforeSlash = $currentLine.Substring(0, $idx)
            $doubleQuoteCount = ($beforeSlash.ToCharArray() | Where-Object { $_ -eq '"' }).Count
            $singleQuoteCount = ($beforeSlash.ToCharArray() | Where-Object { $_ -eq "'" }).Count
            
            # If even number of quotes, the // is not inside a string
            if ($doubleQuoteCount % 2 -eq 0) {
                $currentLine = $currentLine.Substring(0, $idx).TrimEnd()
                $modified = $true
                if ([string]::IsNullOrWhiteSpace($currentLine)) {
                    continue
                }
            }
        }
        
        $newLines += $currentLine
    }
    
    # Remove trailing empty lines
    while ($newLines.Count -gt 0 -and [string]::IsNullOrWhiteSpace($newLines[-1])) {
        $newLines = $newLines[0..($newLines.Count - 2)]
        $modified = $true
    }
    
    # Remove leading empty lines
    while ($newLines.Count -gt 0 -and [string]::IsNullOrWhiteSpace($newLines[0])) {
        $newLines = $newLines[1..($newLines.Count - 1)]
        $modified = $true
    }
    
    if ($modified) {
        $modifiedCount++
        # Write back the cleaned content
        $newLines -join "`n" | Set-Content -Path $file.FullName -NoNewline -Encoding UTF8
        Write-Host "[$processedCount/$totalFiles] Cleaned: $($file.Name)"
    } else {
        Write-Host "[$processedCount/$totalFiles] No changes: $($file.Name)"
    }
}

# Fix the README - replace Vatsal Agarwal with Ajit
$readmePath = "c:\Users\dajit\Downloads\DSA-100-Days-Of-Code-UPES-main\README.md"
$readmeContent = Get-Content -Path $readmePath -Raw
$readmeContent = $readmeContent -replace 'Vatsal Agarwal', 'Ajit Dubey'
$readmeContent = $readmeContent -replace '590023223', 'Ajitdubey951'
$readmeContent | Set-Content -Path $readmePath -NoNewline -Encoding UTF8
Write-Host ""
Write-Host "Updated README.md - replaced Vatsal with Ajit"

Write-Host ""
Write-Host "========================================="
Write-Host "Done! Processed $totalFiles files, modified $modifiedCount files."
Write-Host "========================================="
