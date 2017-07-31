*version 9.1 1056228834
u 23
V? 2
R? 2
C? 2
? 3
@libraries
@analysis
.AC 1 3 0
+0 101
+1 4.0K
+2 400K
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
pageloc 1 0 1960 
@status
n 0 115:04:20:14:54:14;1432144454 e 
s 2832 115:04:20:14:54:18;1432144458 e 
*page 1 0 970 720 iA
@ports
port 17 GND_EARTH 550 210 h
port 20 BUBBLE 490 160 h
a 1 x 3 0 0 0 hcn 100 LABEL=Vin
port 19 BUBBLE 600 160 h
a 1 x 3 0 0 0 hcn 100 LABEL=Vout
@parts
part 4 c 600 200 v
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
part 2 VAC 490 170 h
a 0 u 13 0 -9 23 hcn 100 ACMAG=1V
a 0 sp 0 0 0 50 hln 100 PART=VAC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 20 10 hcn 100 REFDES=V1
part 3 r 530 160 h
a 0 u 13 0 15 25 hln 100 VALUE=3.651k
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 21 nodeMarker 490 160 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 22 nodeMarker 600 160 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
@conn
w 14
a 0 up 0:33 0 0 0 hln 100 V=
s 600 200 600 210 13
s 600 210 550 210 15
s 550 210 490 210 18
a 0 up 33 0 520 209 hct 100 V=
w 6
a 0 up 0:33 0 0 0 hln 100 V=
s 490 170 490 160 5
s 490 160 530 160 7
a 0 up 33 0 510 159 hct 100 V=
w 10
a 0 up 0:33 0 0 0 hln 100 V=
s 570 160 600 160 9
a 0 up 33 0 585 159 hct 100 V=
s 600 160 600 170 11
@junction
j 600 170
+ p 4 2
+ w 10
j 600 200
+ p 4 1
+ w 14
j 550 210
+ s 17
+ w 14
j 490 210
+ p 2 -
+ w 14
j 570 160
+ p 3 2
+ w 10
j 600 160
+ s 19
+ w 10
j 490 170
+ p 2 +
+ w 6
j 530 160
+ p 3 1
+ w 6
j 490 160
+ s 20
+ w 6
j 490 160
+ p 21 pin1
+ s 20
j 490 160
+ p 21 pin1
+ w 6
j 600 160
+ p 22 pin1
+ s 19
j 600 160
+ p 22 pin1
+ w 10
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
