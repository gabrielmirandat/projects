*version 9.1 2133796976
u 137
C? 4
R? 10
L? 4
V? 7
? 3
@libraries
@analysis
.AC 0 2 0
+0 101
+1 1K
+2 100.00K
.TRAN 1 0 0 0
+0 1ns
+1 1ms
.OP 1 
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
pageloc 1 0 9390 
@status
n 0 116:04:18:19:16:31;1463609791 e 
s 2832 116:04:18:19:16:35;1463609795 e 
c 116:04:18:19:15:46;1463609746
*page 1 0 970 720 iA
@ports
port 30 GND_EARTH 210 230 h
port 65 GND_EARTH 530 230 h
port 103 GND_EARTH 350 360 h
@parts
part 3 r 350 160 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 8 r 130 140 d
a 0 u 13 0 15 25 hln 100 VALUE=50
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 7 r 80 140 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=50
part 5 VSIN 80 190 h
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=3
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 FREQ=5000
part 6 VSIN 130 190 h
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=3
a 0 a 0:13 0 0 0 hln 100 PKGREF=V2
a 1 ap 9 0 20 10 hcn 100 REFDES=V2
a 1 u 0 0 0 0 hcn 100 FREQ=10000
part 2 C 180 140 h
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
a 0 u 13 0 15 25 hln 100 VALUE=5.2182n
part 4 L 260 140 h
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 15 0 hln 100 REFDES=L1
a 0 u 13 0 15 25 hln 100 VALUE=0.048542H
part 56 r 670 160 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
part 57 r 450 140 d
a 0 u 13 0 15 25 hln 100 VALUE=50
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 ap 9 0 15 0 hln 100 REFDES=R5
part 59 r 400 140 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=50
a 0 a 0:13 0 0 0 hln 100 PKGREF=R6
a 0 ap 9 0 15 0 hln 100 REFDES=R6
part 60 VSIN 400 190 h
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=3
a 1 u 0 0 0 0 hcn 100 FREQ=5000
a 0 a 0:13 0 0 0 hln 100 PKGREF=V3
a 1 ap 9 0 20 10 hcn 100 REFDES=V3
part 61 VSIN 450 190 h
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=3
a 1 u 0 0 0 0 hcn 100 FREQ=10000
a 0 a 0:13 0 0 0 hln 100 PKGREF=V4
a 1 ap 9 0 20 10 hcn 100 REFDES=V4
part 94 r 490 290 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R7
a 0 ap 9 0 15 0 hln 100 REFDES=R7
part 95 r 270 270 d
a 0 u 13 0 15 25 hln 100 VALUE=50
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R8
a 0 ap 9 0 15 0 hln 100 REFDES=R8
part 97 r 220 270 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=50
a 0 a 0:13 0 0 0 hln 100 PKGREF=R9
a 0 ap 9 0 15 0 hln 100 REFDES=R9
part 98 VSIN 220 320 h
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=3
a 1 u 0 0 0 0 hcn 100 FREQ=5000
a 0 a 0:13 0 0 0 hln 100 PKGREF=V5
a 1 ap 9 0 20 10 hcn 100 REFDES=V5
part 99 VSIN 270 320 h
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=3
a 1 u 0 0 0 0 hcn 100 FREQ=10000
a 0 a 0:13 0 0 0 hln 100 PKGREF=V6
a 1 ap 9 0 20 10 hcn 100 REFDES=V6
part 64 L 580 140 h
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L2
a 0 ap 9 0 15 0 hln 100 REFDES=L2
a 0 u 13 0 15 25 hln 100 VALUE=0.14403H
part 63 C 500 140 h
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 ap 9 0 15 0 hln 100 REFDES=C2
a 0 u 13 0 15 25 hln 100 VALUE=1.75862n
part 101 C 320 270 h
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C3
a 0 ap 9 0 15 0 hln 100 REFDES=C3
a 0 u 13 0 15 25 hln 100 VALUE=15.1576n
part 102 L 400 270 h
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L3
a 0 ap 9 0 15 0 hln 100 REFDES=L3
a 0 u 13 0 15 25 hln 100 VALUE=0.016711H
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 29 nodeMarker 350 140 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout1
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
part 27 nodeMarker 140 140 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin1
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 67 nodeMarker 670 140 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
part 68 nodeMarker 460 140 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 105 nodeMarker 490 270 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
part 106 nodeMarker 280 270 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
@conn
w 10
a 0 sr 0 0 0 0 hln 100 LABEL=Vin1
a 0 up 0:33 0 0 0 hln 100 V=
s 140 140 180 140 28
a 0 sr 3 0 160 138 hcn 100 LABEL=Vin1
s 130 140 140 140 11
s 80 140 130 140 9
a 0 up 33 0 105 139 hct 100 V=
w 19
a 0 up 0:33 0 0 0 hln 100 V=
s 210 230 130 230 31
s 130 230 80 230 22
s 350 230 210 230 20
a 0 up 33 0 280 229 hct 100 V=
s 350 200 350 230 18
w 26
a 0 up 0:33 0 0 0 hln 100 V=
s 130 190 130 180 25
a 0 up 33 0 132 185 hlt 100 V=
w 24
a 0 up 0:33 0 0 0 hln 100 V=
s 80 190 80 180 23
a 0 up 33 0 82 185 hlt 100 V=
w 13
a 0 up 0:33 0 0 0 hln 100 V=
s 210 140 260 140 12
a 0 up 33 0 235 139 hct 100 V=
w 39
a 0 up 0:33 0 0 0 hln 100 V=
s 530 230 450 230 66
s 450 230 400 230 62
s 670 230 530 230 44
a 0 up 33 0 600 229 hct 100 V=
s 670 200 670 230 38
w 37
a 0 up 0:33 0 0 0 hln 100 V=
s 450 190 450 180 36
a 0 up 33 0 452 185 hlt 100 V=
w 35
a 0 up 0:33 0 0 0 hln 100 V=
s 400 190 400 180 34
a 0 up 33 0 402 185 hlt 100 V=
w 33
a 0 up 0:33 0 0 0 hln 100 V=
s 530 140 580 140 32
a 0 up 33 0 555 139 hct 100 V=
w 71
s 350 270 400 270 70
a 0 up 33 0 375 269 hct 100 V=
w 73
s 220 320 220 310 72
a 0 up 33 0 222 315 hlt 100 V=
w 75
s 270 320 270 310 74
a 0 up 33 0 272 315 hlt 100 V=
w 77
s 490 330 490 360 76
s 490 360 350 360 82
a 0 up 33 0 420 359 hct 100 V=
s 270 360 220 360 100
s 350 360 270 360 104
w 47
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0:3 0 290 308 hcn 100 LABEL=Vin2
s 460 140 500 140 69
a 0 up 33 0 480 139 hct 100 V=
a 0 sr 3 0 480 138 hcn 100 LABEL=Vin2
s 450 140 460 140 58
s 400 140 450 140 50
a 0 up 33 0 425 139 hct 100 V=
w 15
a 0 sr 0 0 0 0 hln 100 LABEL=Vout1
a 0 up 0:33 0 0 0 hln 100 V=
s 320 140 350 140 14
a 0 up 33 0 335 139 hct 100 V=
a 0 sr 3 0 325 138 hcn 100 LABEL=Vout1
s 350 140 350 160 16
w 53
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0:3 0 465 308 hcn 100 LABEL=Vout2
s 640 140 670 140 52
a 0 up 33 0 655 139 hct 100 V=
a 0 sr 3 0 645 138 hcn 100 LABEL=Vout2
s 670 140 670 160 54
w 85
a 0 sr 0:3 0 290 468 hcn 100 LABEL=Vin3
s 280 270 320 270 107
a 0 sr 3 0 300 268 hcn 100 LABEL=Vin3
s 220 270 270 270 88
a 0 up 33 0 300 269 hct 100 V=
s 270 270 280 270 96
w 91
a 0 sr 0:3 0 465 468 hcn 100 LABEL=Vout3
s 460 270 490 270 90
a 0 up 33 0 475 269 hct 100 V=
a 0 sr 3 0 465 268 hcn 100 LABEL=Vout3
s 490 270 490 290 92
@junction
j 350 160
+ p 3 1
+ w 15
j 350 140
+ p 29 pin1
+ w 15
j 320 140
+ p 4 2
+ w 15
j 130 140
+ p 8 1
+ w 10
j 140 140
+ p 27 pin1
+ w 10
j 80 140
+ p 7 1
+ w 10
j 180 140
+ p 2 1
+ w 10
j 130 230
+ p 6 -
+ w 19
j 210 230
+ s 30
+ w 19
j 80 230
+ p 5 -
+ w 19
j 350 200
+ p 3 2
+ w 19
j 130 180
+ p 8 2
+ w 26
j 130 190
+ p 6 +
+ w 26
j 80 180
+ p 7 2
+ w 24
j 80 190
+ p 5 +
+ w 24
j 210 140
+ p 2 2
+ w 13
j 260 140
+ p 4 1
+ w 13
j 670 160
+ p 56 1
+ w 53
j 670 140
+ p 67 pin1
+ w 53
j 640 140
+ p 64 2
+ w 53
j 450 140
+ p 57 1
+ w 47
j 460 140
+ p 68 pin1
+ w 47
j 400 140
+ p 59 1
+ w 47
j 500 140
+ p 63 1
+ w 47
j 450 230
+ p 61 -
+ w 39
j 530 230
+ s 65
+ w 39
j 400 230
+ p 60 -
+ w 39
j 670 200
+ p 56 2
+ w 39
j 450 180
+ p 57 2
+ w 37
j 450 190
+ p 61 +
+ w 37
j 400 180
+ p 59 2
+ w 35
j 400 190
+ p 60 +
+ w 35
j 530 140
+ p 63 2
+ w 33
j 580 140
+ p 64 1
+ w 33
j 350 270
+ p 101 2
+ w 71
j 400 270
+ p 102 1
+ w 71
j 220 310
+ p 97 2
+ w 73
j 220 320
+ p 98 +
+ w 73
j 270 310
+ p 95 2
+ w 75
j 270 320
+ p 99 +
+ w 75
j 490 330
+ p 94 2
+ w 77
j 350 360
+ s 103
+ w 77
j 220 360
+ p 98 -
+ w 77
j 270 360
+ p 99 -
+ w 77
j 270 270
+ p 95 1
+ w 85
j 220 270
+ p 97 1
+ w 85
j 280 270
+ p 106 pin1
+ w 85
j 320 270
+ p 101 1
+ w 85
j 490 290
+ p 94 1
+ w 91
j 490 270
+ p 105 pin1
+ w 91
j 460 270
+ p 102 2
+ w 91
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
