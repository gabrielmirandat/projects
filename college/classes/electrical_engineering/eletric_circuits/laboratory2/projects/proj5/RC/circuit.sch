*version 9.1 789154596
u 47
V? 4
L? 2
C? 3
R? 3
? 9
@libraries
@analysis
.AC 1 3 0
+0 1000
+1 4k
+2 400k
.DC 0 0 0 0 1 1
.TRAN 0 0 0 0
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
pageloc 1 0 2119 
@status
n 0 116:04:12:00:34:37;1463024077 e 
s 2832 116:04:12:02:10:25;1463029825 e 
c 116:04:12:00:34:34;1463024074
*page 1 0 970 720 iA
@ports
port 6 GND_EARTH 590 290 h
@parts
part 36 VAC 510 230 h
a 0 u 13 0 -9 23 hcn 100 ACMAG=2V
a 0 sp 0 0 0 50 hln 100 PART=VAC
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
part 37 r 610 210 u
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R1
a 0 u 13 0 10 25 hln 100 VALUE=3.650k
a 0 xp 9 0 25 0 hln 100 REFDES=R1
part 38 c 670 260 v
a 0 u 13 0 5 25 hln 100 VALUE=1nF
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=C1
a 0 xp 9 0 10 0 hln 100 REFDES=C1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 34 nodeMarker 510 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin;;BRIGHTRED
a 0 a 0 0 4 22 hlb 100 LABEL=7
a 0 sp 0 0 0 0 hln 100 COLOR=BRIGHTBLUE
part 35 nodeMarker 670 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout;;BRIGHTBLUE
a 0 a 0 0 4 22 hlb 100 LABEL=8
a 0 sp 0 0 0 0 hln 100 COLOR=BRIGHTRED
@conn
w 18
a 0 up 0:33 0 0 0 hln 100 V=
s 510 270 510 290 17
s 510 290 590 290 19
s 590 290 670 290 23
a 0 up 33 0 630 289 hct 100 V=
s 670 260 670 290 39
w 8
a 0 sr 0 0 0 0 hln 100 LABEL=Vin
a 0 up 0:33 0 0 0 hln 100 V=
s 510 230 510 210 7
a 0 sr 3 0 512 220 hln 100 LABEL=Vin
s 570 210 510 210 41
a 0 up 33 0 515 209 hct 100 V=
w 14
a 0 sr 0 0 0 0 hln 100 LABEL=Vout
a 0 up 0:33 0 0 0 hln 100 V=
s 670 210 670 230 15
a 0 up 33 0 672 220 hlt 100 V=
a 0 sr 3 0 672 220 hln 100 LABEL=Vout
s 610 210 670 210 43
@junction
j 590 290
+ s 6
+ w 18
j 510 210
+ p 34 pin1
+ w 8
j 670 210
+ p 35 pin1
+ w 14
j 510 230
+ p 36 +
+ w 8
j 510 270
+ p 36 -
+ w 18
j 670 230
+ p 38 2
+ w 14
j 670 260
+ p 38 1
+ w 18
j 570 210
+ p 37 2
+ w 8
j 610 210
+ p 37 1
+ w 14
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
