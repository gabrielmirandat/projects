@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2014a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2014a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=hsi_pele_mex
set MEX_NAME=hsi_pele_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for hsi_pele > hsi_pele_mex.mki
echo COMPILER=%COMPILER%>> hsi_pele_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> hsi_pele_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> hsi_pele_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> hsi_pele_mex.mki
echo LINKER=%LINKER%>> hsi_pele_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> hsi_pele_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> hsi_pele_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> hsi_pele_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> hsi_pele_mex.mki
echo BORLAND=%BORLAND%>> hsi_pele_mex.mki
echo OMPFLAGS= >> hsi_pele_mex.mki
echo OMPLINKFLAGS= >> hsi_pele_mex.mki
echo EMC_COMPILER=msvc120>> hsi_pele_mex.mki
echo EMC_CONFIG=optim>> hsi_pele_mex.mki
"C:\Program Files\MATLAB\R2014a\bin\win64\gmake" -B -f hsi_pele_mex.mk
