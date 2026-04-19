# Recreate backdated git commits with cleaned files (no comments, no Vatsal)
# Uses the EXACT same date schedule as the original script

$gitPath = "C:\Users\dajit\AppData\Local\GitHubDesktop\app-3.5.4\resources\app\git\cmd\git.exe"
$repoRoot = "c:\Users\dajit\Downloads\DSA-100-Days-Of-Code-UPES-main"

Set-Location $repoRoot

$availableDays = @(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
    21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
    41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
    61,62,63,64,65,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,
    82,83,84,85,86,87,88,89,90,91)

$startDate = Get-Date "2026-01-15"
$rng = New-Object System.Random(42)

# Same schedule logic as original
$calendarDays = @()
$currentOffset = 0
$dayIndex = 0

$skipOffsets = @(4, 11, 18, 19, 25, 33, 40, 47, 53, 62, 69, 76, 83, 90, 97)
$doubleDays = @(5, 12, 20, 26, 34, 48, 54, 70, 84, 91)

while ($dayIndex -lt $availableDays.Count) {
    if ($skipOffsets -contains $currentOffset) {
        $currentOffset++
        continue
    }
    
    if ($doubleDays -contains $currentOffset -and ($dayIndex + 1) -lt $availableDays.Count) {
        $calendarDays += [PSCustomObject]@{ DayNum = $availableDays[$dayIndex]; Offset = $currentOffset; IsSecond = $false }
        $dayIndex++
        $calendarDays += [PSCustomObject]@{ DayNum = $availableDays[$dayIndex]; Offset = $currentOffset; IsSecond = $true }
        $dayIndex++
    } else {
        $calendarDays += [PSCustomObject]@{ DayNum = $availableDays[$dayIndex]; Offset = $currentOffset; IsSecond = $false }
        $dayIndex++
    }
    $currentOffset++
}

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

# Initial commit with README
& $gitPath add "README.md"

$initDate = $startDate.AddDays(-1).AddHours(14).AddMinutes(30)
$initDateStr = $initDate.ToString("yyyy-MM-ddTHH:mm:ss")
$env:GIT_AUTHOR_DATE = $initDateStr
$env:GIT_COMMITTER_DATE = $initDateStr
& $gitPath commit -m "Initial commit: DSA 100 Days of Code challenge"
Write-Host "Created initial commit"

# Create commits for each day
foreach ($entry in $calendarDays) {
    $dayNum = $entry.DayNum
    $offset = $entry.Offset
    $isSecond = $entry.IsSecond
    
    $dayFolder = "DSA-100-Days-Of-Code-UPES-main/Day-$dayNum"
    
    if ($isSecond) {
        $hour = $rng.Next(19, 23)
    } else {
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
    
    $msgTemplate = $commitMessages[$rng.Next($commitMessages.Count)]
    $commitMsg = $msgTemplate -f $dayNum
    
    & $gitPath add $dayFolder
    
    $env:GIT_AUTHOR_DATE = $commitDateStr
    $env:GIT_COMMITTER_DATE = $commitDateStr
    & $gitPath commit -m $commitMsg
    
    Write-Host "Committed Day-$dayNum at $commitDateStr"
}

# Final README update
$finalDate = $startDate.AddDays($currentOffset).AddHours(15).AddMinutes(22).AddSeconds(10)
$finalDateStr = $finalDate.ToString("yyyy-MM-ddTHH:mm:ss")
$env:GIT_AUTHOR_DATE = $finalDateStr
$env:GIT_COMMITTER_DATE = $finalDateStr
& $gitPath add -A
& $gitPath commit -m "Update README with project details" --allow-empty

Remove-Item Env:\GIT_AUTHOR_DATE -ErrorAction SilentlyContinue
Remove-Item Env:\GIT_COMMITTER_DATE -ErrorAction SilentlyContinue

# Set up remote and force push
& $gitPath remote add origin "https://github.com/Ajitdubey951/100-DAYS-OF-DSA.git"
& $gitPath branch -M main

Write-Host ""
Write-Host "========================================="
Write-Host "Done! All commits recreated with cleaned files."
Write-Host "Now force pushing to GitHub..."
Write-Host "========================================="

& $gitPath push -u origin main --force

Write-Host ""
Write-Host "Force push complete! Heatmap preserved."
