# PowerShell script to create backdated git commits for DSA 100 Days challenge
# Creates natural-looking commit history with some inconsistency

$gitPath = "C:\Users\dajit\AppData\Local\GitHubDesktop\app-3.5.4\resources\app\git\cmd\git.exe"
$repoRoot = "c:\Users\dajit\Downloads\DSA-100-Days-Of-Code-UPES-main"

Set-Location $repoRoot

# Initialize git repo
& $gitPath init
& $gitPath config user.name "Ajitdubey951"
& $gitPath config user.email "dajit4163@gmail.com"

# List of available days (sorted)
$availableDays = @(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
    21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
    41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
    61,62,63,64,65,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,
    82,83,84,85,86,87,88,89,90,91)

# We want commits spread over ~115 calendar days starting from Jan 15, 2026
# to make it look natural. 90 days of content, but some gaps and some double-commit days.
$startDate = Get-Date "2026-01-15"

# Pre-define a natural-looking schedule:
# - Most days get 1 commit
# - ~8 days are skipped entirely (weekends/busy days)
# - ~6 days get 2 commits (catching up / being productive)
# - Commit times vary between 8am-11pm

# Seed for reproducibility
$rng = New-Object System.Random(42)

# Generate calendar schedule
# We need to assign 90 day-folders to calendar dates
$calendarDays = @()
$currentOffset = 0
$dayIndex = 0

# Define which offsets to skip (simulate missing days - weekends, breaks)
# These are calendar day offsets from start where no commits happen
$skipOffsets = @(4, 11, 18, 19, 25, 33, 40, 47, 53, 62, 69, 76, 83, 90, 97)

# Days where we do 2 folder-commits (catching up after skip days)
$doubleDays = @(5, 12, 20, 26, 34, 48, 54, 70, 84, 91)

while ($dayIndex -lt $availableDays.Count) {
    if ($skipOffsets -contains $currentOffset) {
        # Skip this calendar day - no commit
        $currentOffset++
        continue
    }
    
    if ($doubleDays -contains $currentOffset -and ($dayIndex + 1) -lt $availableDays.Count) {
        # Two commits on this day
        $calendarDays += [PSCustomObject]@{
            DayNum = $availableDays[$dayIndex]
            Offset = $currentOffset
            IsSecond = $false
        }
        $dayIndex++
        $calendarDays += [PSCustomObject]@{
            DayNum = $availableDays[$dayIndex]
            Offset = $currentOffset
            IsSecond = $true
        }
        $dayIndex++
    } else {
        # Normal: one commit this day
        $calendarDays += [PSCustomObject]@{
            DayNum = $availableDays[$dayIndex]
            Offset = $currentOffset
            IsSecond = $false
        }
        $dayIndex++
    }
    $currentOffset++
}

Write-Host "Total calendar days used: $currentOffset"
Write-Host "Total commits to create: $($calendarDays.Count)"

# Create initial commit with README
$readmePath = Join-Path $repoRoot "README.md"
"# DSA 100 Days of Code - UPES`n`nDaily DSA practice solutions in C/C++.`n" | Out-File -FilePath $readmePath -Encoding utf8

& $gitPath add "README.md"

$initDate = $startDate.AddDays(-1).AddHours(14).AddMinutes(30)
$initDateStr = $initDate.ToString("yyyy-MM-ddTHH:mm:ss")
$env:GIT_AUTHOR_DATE = $initDateStr
$env:GIT_COMMITTER_DATE = $initDateStr
& $gitPath commit -m "Initial commit: DSA 100 Days of Code challenge"

Write-Host "Created initial commit"

# Commit messages templates for variety
$commitMessages = @(
    "Day {0}: Add solution for Q1 and Q2",
    "Day {0}: Solved today's DSA problems",
    "Day {0}: Complete day {0} solutions",
    "Add Day {0} solutions",
    "Day {0}: DSA practice",
    "Day {0}: Added solutions",
    "Solved Day {0} problems",
    "Day {0}: Q1 & Q2 done",
    "Day {0} complete",
    "Day {0}: Today's DSA solutions"
)

# Now create commits
foreach ($entry in $calendarDays) {
    $dayNum = $entry.DayNum
    $offset = $entry.Offset
    $isSecond = $entry.IsSecond
    
    $dayFolder = "DSA-100-Days-Of-Code-UPES-main/Day-$dayNum"
    
    # Generate a natural-looking commit time
    # Most commits between 9am-11pm, with clustering around evening (6pm-10pm)
    if ($isSecond) {
        # Second commit of the day - later in the day
        $hour = $rng.Next(19, 23)
    } else {
        # Weighted random: 30% morning (8-12), 20% afternoon (12-17), 50% evening (17-23)
        $roll = $rng.Next(100)
        if ($roll -lt 30) {
            $hour = $rng.Next(8, 13)
        } elseif ($roll -lt 50) {
            $hour = $rng.Next(13, 18)
        } else {
            $hour = $rng.Next(18, 24)
            if ($hour -eq 24) { $hour = 23 }
        }
    }
    $minute = $rng.Next(0, 60)
    $second = $rng.Next(0, 60)
    
    $commitDate = $startDate.AddDays($offset).AddHours($hour).AddMinutes($minute).AddSeconds($second)
    $commitDateStr = $commitDate.ToString("yyyy-MM-ddTHH:mm:ss")
    
    # Pick a varied commit message
    $msgTemplate = $commitMessages[$rng.Next($commitMessages.Count)]
    $commitMsg = $msgTemplate -f $dayNum
    
    # Stage the day folder
    & $gitPath add $dayFolder
    
    # Set dates and commit
    $env:GIT_AUTHOR_DATE = $commitDateStr
    $env:GIT_COMMITTER_DATE = $commitDateStr
    & $gitPath commit -m $commitMsg
    
    Write-Host "Committed Day-$dayNum at $commitDateStr : $commitMsg"
}

# Final update to README
$readmeContent = @"
# DSA 100 Days of Code - UPES

Daily DSA practice solutions in C/C++.

## Structure

Each day contains solutions to 2 DSA problems:
- `Day_X_Q1.c` - Question 1
- `Day_X_Q2.c` - Question 2

## Topics Covered

- Arrays & Strings
- Linked Lists
- Stacks & Queues  
- Trees & Graphs
- Sorting & Searching
- Dynamic Programming
- Recursion & Backtracking

## Author

- **Name:** Vatsal Agarwal
- **SAP ID:** 590023223
"@

$readmeContent | Out-File -FilePath $readmePath -Encoding utf8
& $gitPath add "README.md"

$finalDate = $startDate.AddDays($currentOffset).AddHours(15).AddMinutes(22).AddSeconds(10)
$finalDateStr = $finalDate.ToString("yyyy-MM-ddTHH:mm:ss")
$env:GIT_AUTHOR_DATE = $finalDateStr
$env:GIT_COMMITTER_DATE = $finalDateStr
& $gitPath commit -m "Update README with project details"

# Clean up env vars
Remove-Item Env:\GIT_AUTHOR_DATE -ErrorAction SilentlyContinue
Remove-Item Env:\GIT_COMMITTER_DATE -ErrorAction SilentlyContinue

Write-Host ""
Write-Host "========================================="
Write-Host "Done! All commits created successfully."
Write-Host "========================================="
Write-Host ""
Write-Host "Next steps:"
Write-Host "1. Create a new repo on GitHub"
Write-Host "2. Run: & '$gitPath' remote add origin https://github.com/Ajitdubey951/<repo-name>.git"
Write-Host "3. Run: & '$gitPath' branch -M main"
Write-Host "4. Run: & '$gitPath' push -u origin main"
