*version 9.1 965889306
u 35
R? 2
C? 2
L? 2
V? 2
? 4
@libraries
@analysis
.TRAN 1 0 0 0
+0 0ns
+1 0.10s
.OP 0 
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
pageloc 1 0 2278 
@status
n 0 113:08:13:18:16:03;1379106963 e 
s 0 113:08:13:18:16:29;1379106989 e 
*page 1 0 970 720 iA
@ports
port 6 GND_EARTH 530 400 h
@parts
part 2 r 750 370 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 4 L 650 300 h
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 15 0 hln 100 REFDES=L1
part 5 VSIN 530 330 h
a 1 u 0 0 0 0 hcn 100 FREQ=100
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 VAMPL=1
a 1 u 0 0 0 0 hcn 100 VOFF=0
part 3 c 590 300 h
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
a 0 u 13 0 15 25 hln 100 VALUE=1u
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 26 nodeMarker 750 300 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
part 25 nodeMarker 530 300 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 34 iMarker 620 300 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=3
@conn
w 18
a 0 up 0:33 0 0 0 hln 100 V=
s 750 370 750 390 17
s 750 390 530 390 19
a 0 up 33 0 640 389 hct 100 V=
s 530 390 530 370 21
s 530 400 530 390 23
w 14
a 0 up 0:33 0 0 0 hln 100 V=
s 710 300 750 300 13
a 0 up 33 0 730 299 hct 100 V=
s 750 300 750 330 15
w 8
a 0 up 0:33 0 0 0 hln 100 V=
s 530 330 530 300 7
s 530 300 590 300 9
a 0 up 33 0 560 299 hct 100 V=
w 12
a 0 up 0:33 0 0 0 hln 100 V=
s 620 300 650 300 29
a 0 up 33 0 635 299 hct 100 V=
@junction
j 710 300
+ p 4 2
+ w 14
j 750 330
+ p 2 2
+ w 14
j 750 370
+ p 2 1
+ w 18
j 530 400
+ s 6
+ w 18
j 530 390
+ w 18
+ w 18
j 530 330
+ p 5 +
+ w 8
j 530 370
+ p 5 -
+ w 18
j 530 300
+ p 25 pin1
+ w 8
j 750 300
+ p 26 pin1
+ w 14
j 590 300
+ p 3 1
+ w 8
j 620 300
+ p 3 2
+ w 12
j 650 300
+ p 4 1
+ w 12
j 620 300
+ p 34 pin1
+ p 3 2
j 620 300
+ p 34 pin1
+ w 12
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
