cd ..\Detours
rmdir /S /Q include
rmdir /S /Q lib.X86
rmdir /S /Q bin.X86
cd src
SET DETOURS_TARGET_PROCESSOR=X64
nmake clean
nmake
