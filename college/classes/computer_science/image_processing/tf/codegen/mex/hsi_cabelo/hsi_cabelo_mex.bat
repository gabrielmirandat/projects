@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2014a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2014a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=hsi_cabelo_mex
set MEX_NAME=hsi_cabelo_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for hsi_cabelo > hsi_cabelo_mex.mki
echo COMPILER=%COMPILER%>> hsi_cabelo_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> hsi_cabelo_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> hsi_cabelo_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> hsi_cabelo_mex.mki
echo LINKER=%LINKER%>> hsi_cabelo_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> hsi_cabelo_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> hsi_cabelo_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> hsi_cabelo_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> hsi_cabelo_mex.mki
echo BORLAND=%BORLAND%>> hsi_cabelo_mex.mki
echo OMPFLAGS= >> hsi_cabelo_mex.mki
echo OMPLINKFLAGS= >> hsi_cabelo_mex.mki
echo EMC_COMPILER=msvc120>> hsi_cabelo_mex.mki
echo EMC_CONFIG=optim>> hsi_cabelo_mex.mki
"C:\Program Files\MATLAB\R2014a\bin\win64\gmake" -B -f hsi_cabelo_mex.mk
