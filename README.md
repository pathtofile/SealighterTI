# Sealighter TI
Combining Sealighter with unpatched exploits to run the Threat-Intelligence ETW Provider.

# Overview
## The Problem - PPL and Anti-Malware
The `Microsoft-Windows-Threat-Intelligence` ETW Provider is an excelent tool to [detect process injection](https://blog.redbluepurple.io/windows-security-research/kernel-tracing-injection-detection), and other type of attacks. Unlike usermode hooking or in-process ETW Providers, avoiding or tampering with the `Threat-Intelligence` is very difficult.

However, to subscribe to this Provider requries a process with very special privliges, marked as [Protected Process Light (PPL)](https://www.alex-ionescu.com/?p=97) 'Anti-Malware' or higher. To legitimatly run a program at this level you must submit a driver to Microsoft to be co-signed by them, something not everyone has the inclination or reputation to do.

I originally created a research project named [PPLRunner](https://github.com/pathtofile/PPLRunner) that would allow you create PPL process in a test environment, however this tool requires Windows to be put into a debug or 'test signing' mode. This could in theory also have the affect of altering the behaviour of the malware or program you are attempting to analyse, which may behave differently if it believes it is being debugged/not on a 'real' machine.


## The Solution - Exploit to success
Back in 2018 [Alex Ionescu](https://twitter.com/aionescu) and [James Forshaw](https://twitter.com/tiraniddo) presented a [series of talks](http://publications.alex-ionescu.com/Recon/Recon%202018%20-%20Unknown%20Known%20DLLs%20and%20other%20code%20integrity%20trust%20violations.pdf), as well as some [blogs](https://googleprojectzero.blogspot.com/2018/08/windows-exploitation-tricks-exploiting.html), covering many ways you could trick Windows into illegitimately running arbitry code at the PPL level.

In 2021 [Clément Labro](https://twitter.com/itm4n) created the project [PPLDump](https://github.com/itm4n/PPLdump), which uses one of the unpatched techniques Alex and James covered, to trick a PPL-elevated `services.exe` into loading an arbitraty DLL.


## The Glue - SealighterTI
PPLDump uses it's elevated access to dump the memory of `lsass.exe`. I've taken Clément's awesome code, and instead combined it with my ETW Logging tool (Sealighter)[https://github.com/pathtofile/Sealighter], to enable you to get events from the `Microsoft-Windows-Threat-Intelligence` logging to the Windows Event Log. This is possible from a 'production' machine, without the need for a signed driver or to put the machine into 'test signing' mode.


# To Build


# To Run


# Technical Details




# Aknowlegements
All of the work to run arbitary code as PPL is the work of [Clément Labro](https://twitter.com/itm4n) and their [PPLDump](https://github.com/itm4n/PPLdump) project. I simply worked on glueing the ETW Logging to the end of it.

The Research from [Alex Ionescu](https://twitter.com/aionescu) and [James Forshaw](https://twitter.com/tiraniddo) is instrumental the making this project possible.


# Further Reading Links
- http://publications.alex-ionescu.com/Recon/Recon%202018%20-%20Unknown%20Known%20DLLs%20and%20other%20code%20integrity%20trust%20violations.pdf
- https://blog.scrt.ch/2021/04/22/bypassing-lsa-protection-in-userland/
- https://github.com/itm4n/PPLdump
- https://googleprojectzero.blogspot.com/2018/08/windows-exploitation-tricks-exploiting.html
- https://www.alex-ionescu.com/?p=97
- https://blog.redbluepurple.io/windows-security-research/kernel-tracing-injection-detection


-----------------------

# TODO Before I push

## Write README
- Add Build instructions
- Make sure everyone is 100pc given credit
    - But also explain your additions

## Write Blog
- Make sure everyone is 100pc given credit
    - But also explain your additions
