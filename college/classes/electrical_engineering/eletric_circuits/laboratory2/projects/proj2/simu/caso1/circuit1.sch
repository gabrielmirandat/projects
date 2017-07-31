*version 9.1 702307445
u 58
V? 4
L? 2
C? 3
R? 2
? 12
@libraries
@analysis
.AC 0 1 0
+0 101
+1 10
+2 1.00K
.DC 0 0 0 0 1 1
.TRAN 1 0 0 0
+0 0ns
+1 10ms
+3 20us
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 1900 
@status
n 0 116:03:07:13:12:37;1460045557 e 
s 2832 116:03:07:13:12:41;1460045561 e 
c 116:03:07:13:12:34;1460045554
*page 1 0 970 720 iA
@ports
port 6 GND_EARTH 590 290 h
@parts
part 5 r 670 270 v
a 0 ap 9 0 15 5 hln 100 REFDES=R1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 u 13 0 15 40 hln 100 VALUE=4750
part 44 c 570 210 h
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 ap 9 0 15 0 hln 100 REFDES=C2
a 0 u 13 0 15 25 hln 100 VALUE=100n
part 43 VSIN 510 230 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 FREQ=2000
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 55 nodeMarker 530 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=11
@conn
w 18
a 0 up 0:33 0 0 0 hln 100 V=
s 670 290 670 270 21
s 590 290 670 290 23
a 0 up 33 0 630 289 hct 100 V=
s 590 290 510 290 39
s 510 290 510 270 41
w 14
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=Vout
s 670 210 670 230 15
a 0 up 33 0 672 220 hlt 100 V=
a 0 sr 3 0 672 220 hln 100 LABEL=Vout
s 600 210 670 210 36
a 0 up 33 0 600 209 hct 100 V=
w 8
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=Vin
s 510 230 510 210 7
a 0 sr 3 0 512 220 hln 100 LABEL=Vin
s 510 210 530 210 53
a 0 up 33 0 540 209 hct 100 V=
s 530 210 570 210 56
@junction
j 510 230
+ p 43 +
+ w 8
j 670 230
+ p 5 2
+ w 14
j 670 270
+ p 5 1
+ w 18
j 590 290
+ s 6
+ w 18
j 510 270
+ p 43 -
+ w 18
j 570 210
+ p 44 1
+ w 8
j 600 210
+ p 44 2
+ w 14
j 530 210
+ p 55 pin1
+ w 8
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
