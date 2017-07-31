*version 9.1 4145164485
u 37
C? 2
R? 4
L? 2
V? 5
? 3
@libraries
@analysis
.AC 1 3 0
+0 101
+1 1K
+2 100K
.TRAN 0 0 0 0
+0 1ns
+1 1ms
.TF 0 V(R1:1) V(R3:1)
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
pageloc 1 0 3334 
@status
n 0 115:04:27:13:06:57;1432742817 e 
s 2832 115:04:27:13:06:57;1432742817 e 
*page 1 0 970 720 iA
@ports
port 30 GND_EARTH 340 240 h
port 36 BUBBLE 260 150 h
a 1 x 3 0 0 0 hcn 100 LABEL=Ve
port 35 BUBBLE 480 150 h
a 1 x 3 0 0 0 hcn 100 LABEL=Vs
@parts
part 7 r 210 150 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=50
part 32 VAC 210 200 h
a 0 u 13 0 -9 23 hcn 100 ACMAG=3V
a 0 sp 0 0 0 50 hln 100 PART=VAC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V3
a 1 ap 9 0 20 10 hcn 100 REFDES=V3
part 33 VAC 260 200 h
a 0 u 13 0 -9 23 hcn 100 ACMAG=3V
a 0 sp 0 0 0 50 hln 100 PART=VAC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V4
a 1 ap 9 0 20 10 hcn 100 REFDES=V4
part 8 r 260 150 d
a 0 u 13 0 15 25 hln 100 VALUE=50
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 2 C 310 150 h
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
a 0 u 13 0 15 25 hln 100 VALUE=1.5143n
part 4 L 390 150 h
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 15 0 hln 100 REFDES=L1
a 0 u 13 0 15 25 hln 100 VALUE=0.16727H
part 3 r 480 170 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=10k
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 27 nodeMarker 270 150 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 29 nodeMarker 480 150 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
@conn
w 13
a 0 up 0:33 0 0 0 hln 100 V=
s 340 150 390 150 12
a 0 up 33 0 365 149 hct 100 V=
w 24
a 0 up 0:33 0 0 0 hln 100 V=
s 210 200 210 190 23
a 0 up 33 0 212 195 hlt 100 V=
w 26
a 0 up 0:33 0 0 0 hln 100 V=
s 260 200 260 190 25
a 0 up 33 0 262 195 hlt 100 V=
w 19
a 0 up 0:33 0 0 0 hln 100 V=
s 480 210 480 240 18
s 480 240 340 240 20
a 0 up 33 0 410 239 hct 100 V=
s 340 240 260 240 31
s 260 240 210 240 34
w 15
a 0 up 0:33 0 0 0 hln 100 V=
s 450 150 480 150 14
a 0 up 33 0 465 149 hct 100 V=
s 480 150 480 170 16
w 10
a 0 up 0:33 0 0 0 hln 100 V=
s 210 150 260 150 9
a 0 up 33 0 235 149 hct 100 V=
s 260 150 270 150 11
s 270 150 310 150 28
@junction
j 310 150
+ p 2 1
+ w 10
j 210 150
+ p 7 1
+ w 10
j 260 150
+ p 8 1
+ w 10
j 390 150
+ p 4 1
+ w 13
j 340 150
+ p 2 2
+ w 13
j 450 150
+ p 4 2
+ w 15
j 480 170
+ p 3 1
+ w 15
j 480 210
+ p 3 2
+ w 19
j 210 190
+ p 7 2
+ w 24
j 260 190
+ p 8 2
+ w 26
j 270 150
+ p 27 pin1
+ w 10
j 480 150
+ p 29 pin1
+ w 15
j 340 240
+ s 30
+ w 19
j 210 200
+ p 32 +
+ w 24
j 210 240
+ p 32 -
+ w 19
j 260 200
+ p 33 +
+ w 26
j 260 240
+ p 33 -
+ w 19
j 480 150
+ s 35
+ p 29 pin1
j 480 150
+ s 35
+ w 15
j 260 150
+ s 36
+ p 8 1
j 260 150
+ s 36
+ w 10
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
