foreach($id in (Get-Process chrome).id  ){ Write-Output "chrome $id $((Get-Process chrome | Where-Object {$_.id -eq $id } | Select-Object -ExpandProperty Threads).count) "}
