ECHO  OFF
cls
echo.
echo.
echo.
echo.
echo.
echo.                     PRIMEIRA FASE: COMPILAR O ARQUIVO
echo.
echo.
echo.
A51 %1.ASM
IF ERRORLEVEL 1 GOTO AERROR
CLS
echo.
echo.
echo.
echo.
echo.
echo.
echo.                     SEGUNDA FASE: LINKAR O ARQUIVO
echo.
echo.
BL51 %1.OBJ
IF ERRORLEVEL 1 GOTO AERRORA
OH51 %1
IF ERRORLEVEL 1 GOTO AERRORA
CLS
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo.                  TERCEIRA FASE: CONVERTER O ARQUIVO
echo.
echo.
HEX2BIN %1.HEX
GOTO FINIS
echo.
echo.
echo.
echo.
echo.
echo.
GOTO FINIS
:AERROR
echo.
echo.
echo.
echo.
ECHO.                 HOUVE ERRO NA COMPILACAO !
ECHO.
ECHO.                 PROCESSAMENTO INTERROMPIDO
ECHO.
ECHO.         OLHE O ARQUIVO ".LST" PARA VERIFICAR OS ERROS
ECHO.
ECHO.        VOLTE AO PROGRAMA FONTE ( NO EDITOR ) PARA CORRIGI-LO
ECHO.
pause
GOTO FINIS1
:AERRORA
ECHO.                 HOUVE ERRO NA LINKAGEM !
ECHO.
ECHO.                 PROCESSAMENTO INTERROMPIDO
ECHO.
Echo.
ECHO.                       Tecle algo . . .
echo.
echo.
echo.
GOTO FINIS1
pause
:FINIS
ECHO.
ECHO.
ECHO.
ECHO.       VOCE TEVE SUCESSO NA EDICÇO DO PROGRAMA , CRIANDO
ECHO.
ECHO.       OS ARQUIVOS : .OBJ - ARQUIVO COMPILADO
ECHO.
ECHO.                     .HEX - ARQUIVO PARA SIMULA€ÇO
ECHO.
ECHO.                     .BIN - ARQUIVO A SER TRANSMITIDO PARA A PLACA
ECHO.                            OU A SER GRAVADO NA EPROM
ECHO.
ECHO.
pause 
:FINIS1
