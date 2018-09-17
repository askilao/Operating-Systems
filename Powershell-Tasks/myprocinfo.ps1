While (1) {

    "    

    VALGT:
    1. Hvem er jeg og hva er navnet paa dette scriptet ?
    2. Hvor lenge er det siden siste boot ?
    3. Hvor mange prosesser og traader finnes?
    4. Hvor mange context switcher fant sted siste sekund
    5. Hvor stor andel av CPU-tiden ble benyttet i kernel mode og i usermode siste sekund
    6. Hvor mange interupts fant sted siste sekund
    9. Avslutt dette scriptet

    "


$Valg = Read-Host -Prompt 'Valg: '
#henter hele filpathen til scriptet og klipper ned til bare navnet
$ScriptName = & { split-path $MyInvocation.PSCommandPath -Leaf }

$OSinfo = Get-CimInstance Win32_PerfFormattedData_PerfOS_System
$CPUinfo = Get-CimInstance Win32_PerfFormattedData_Counters_ProcessorInformation | Where-Object {$_.Name -eq "_Total"}
$Uptime =  [timespan]::fromseconds($OSinfo.SystemUpTime)
$PrintUptime = "Uptime(DD.HH.MM.SS): " + $Uptime

switch ( $Valg )
{
    1 {Write-Output "Du er $env:UserName og scriptet heter $ScriptName" }
    2 {Write-Output $PrintUptime}
    3 {Write-Output "Det er $($OSinfo.Processes) prosesser og  $($OSinfo.Threads) Traader"}
    4 {Write-Output "Det siste sekundet var det $($OSinfo.ContextSwitchesPersec) context switches"}
    5 {Write-Output "Prosessoren var $($CPUinfo.PercentUserTime)% i Usermode og $($CPUinfo.PercentPrivilegedTime)% i Kernelmode det siste sekund"}
    6 {Write-Output "Det var $($CPUinfo.InterruptsPersec) interupts det siste sekundet"}
    9 {exit}    
    default { Write-Output "Ugyldig input" }
}

}
