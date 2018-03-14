
# Operativsystemer IMT2282 Oblig 3 <br>
### Askil Amundøy Olsen <br>

**Verktøy brukt for kvalitetsikring** <br>
> [PSScriptAnalyzer](https://github.com/PowerShell/PSScriptAnalyzer) <br>
Har fått tilbakemelding om å ikke bruke `Write-Host`, bruker heller `Write-Output` <br>
Får heller ikke bruke aliases *(? for Where-Object og echo for Write-Output)*. Dette har blitt endret på. <br>
PSScriptAnalyzer returnerer nå ingenting.

Kan kjøres slik: <br>
- `Invoke-ScriptAnalyzer .\chromeThreadCount.ps1`
- `Invoke-ScriptAnalyzer .\procmi.ps1`
- `Invoke-ScriptAnalyze .\myprocinfo.ps1`

**Oblig del 1**<br>
Kan kjøres med <br>
`powershell.exe .\myprocinfo.ps1` <br>

**Oblig del 2**<br>
Kan kjøres med <br>
`powershell.exe .\procmi.ps1`

**Oblig del 3**<br>
Kan kjøres med <br>
`powershell.exe .\chromeThreadCount.ps1` + *prosess id*
