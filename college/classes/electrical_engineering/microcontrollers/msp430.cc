"http://jeffrey.co.in/blog/2014/03/running-msp430f5529-launchpad-on-gnulinux/"

debugger eZ-FET lite.
C toolchain(gcc-msp430)
'sudo apt-get install gcc-msp430 msp430-libc msp430mcu'

Below steps describe how to use mspdebug from Energia
1) Download Energia for GNU/Linux from http://energia.nu/download/
2) Extract the tgz file. I got a folder named energia-0101E0011. The number in the folder name might 
   change for you depending on the energia version you are using.
3) Go into the folder energia-0101E0011/hardware/tools/msp430/bin/ using the cd command.
3) Copy libmsp430.so to /usr/lib/
4) Update the firmware of the debugger using sudo ./mspdebug tilib --allow-fw-update
5) Now you can run mspdebug using the following command sudo ./mspdebug tilib

"https://rtime.felk.cvut.cz/hw/index.php/MSP430F5529_Launchpad"

'sudo apt-get install gcc-msp430 gdb-msp430 msp430-libc msp430mcu'
'sudo apt-get install libboost-all-dev'
'sudo apt-get install libusb-dev libreadline-dev libusb-1.0-0-dev libudev-dev'
'wget http://www-s.ti.com/sc/techzip/slac460.zip'
'unzip slac460.zip'
'cd MSPDebugStack_OS_Package/'
'# read README-BUILD.txt'
'make'
...

"https://mycontraption.com/programming-the-msp430-launchpad-on-ubuntu/"

binutils-msp430
gcc-msp430
msp430-libc
mspdebug
'sudo apt-get install binutils-msp430 gcc-msp430 msp430-libc mspdebug'
'lsusb'
'sudo mspdebug rf2500'
'man mspdebug'
inside mspdebug
'md 0xf800 2048'
'erase'

"https://sergioprado.org/trabalhando-com-o-msp430-no-linux/"

'sudo apt-get install msp430-libc mspdebug msp430mcu binutils-msp430 gcc-msp430 gdb-msp430'
'msp430-gcc --version'
'sudo apt-get remove gdb'
'sudo apt-get install gdb-msp430'











