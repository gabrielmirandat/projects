@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2014a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2014a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=qtz_pele_cabelo_mex
set MEX_NAME=qtz_pele_cabelo_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for qtz_pele_cabelo > qtz_pele_cabelo_mex.mki
echo COMPILER=%COMPILER%>> qtz_pele_cabelo_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> qtz_pele_cabelo_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> qtz_pele_cabelo_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> qtz_pele_cabelo_mex.mki
echo LINKER=%LINKER%>> qtz_pele_cabelo_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> qtz_pele_cabelo_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> qtz_pele_cabelo_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> qtz_pele_cabelo_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> qtz_pele_cabelo_mex.mki
echo BORLAND=%BORLAND%>> qtz_pele_cabelo_mex.mki
echo OMPFLAGS= >> qtz_pele_cabelo_mex.mki
echo OMPLINKFLAGS= >> qtz_pele_cabelo_mex.mki
echo EMC_COMPILER=msvc120>> qtz_pele_cabelo_mex.mki
echo EMC_CONFIG=optim>> qtz_pele_cabelo_mex.mki
"C:\Program Files\MATLAB\R2014a\bin\win64\gmake" -B -f qtz_pele_cabelo_mex.mk
