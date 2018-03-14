

param([Int[]] $processids)

foreach ($id in $processids) {
    #Create filename
    $file = "$(get-date -f dd-MM-yyyy)-$id.meminfo"
    $process = Get-CimInstance Win32_Process | Where-Object {$_.ProcessId -eq $id}
    if(Get-Process | ? {$_.id -eq $id}){
    Write-Output "*********Memory info for PID: $id*********">$file
    Write-Output "Workingset size: $([math]::Round($process.WorkingSetSize /1Mb, 2 ))Mb">>$file
    Write-Output "Virtualmem size: $([math]::Round($process.VirtualSize /1Gb, 2 ))Gb">>$file
    } else {
        Write-Output "$id id not a valid PID"
    }
}