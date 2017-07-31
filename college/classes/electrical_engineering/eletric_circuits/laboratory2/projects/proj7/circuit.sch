*version 9.1 2805142979
u 170
V? 11
L? 2
C? 3
R? 3
? 11
@libraries
@analysis
.AC 0 1 0
+0 1000
+1 4k
+2 400k
.DC 0 0 0 0 1 1
.TRAN 1 0 0 0
+0 0ns
+1 5ms
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
pageloc 1 0 5101 
@status
n 0 116:05:01:23:22:31;1464834151 e 
s 2832 116:05:01:23:26:45;1464834405 e 
c 116:05:01:23:22:28;1464834148
*page 1 0 970 720 iA
@ports
port 6 GND_EARTH 560 290 h
@parts
part 95 r 420 180 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R1
a 0 xp 9 0 25 0 hln 100 REFDES=R1
a 0 u 13 0 10 25 hln 100 VALUE=50
part 98 r 460 180 d
a 0 x 0:13 0 0 0 hln 100 PKGREF=R2
a 0 xp 9 0 25 0 hln 100 REFDES=R2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 10 25 hln 100 VALUE=50
part 99 r 500 180 d
a 0 x 0:13 0 0 0 hln 100 PKGREF=R3
a 0 xp 9 0 25 0 hln 100 REFDES=R3
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 10 25 hln 100 VALUE=50
part 100 r 540 180 d
a 0 x 0:13 0 0 0 hln 100 PKGREF=R4
a 0 xp 9 0 25 0 hln 100 REFDES=R4
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 10 25 hln 100 VALUE=50
part 101 r 580 180 d
a 0 x 0:13 0 0 0 hln 100 PKGREF=R5
a 0 xp 9 0 25 0 hln 100 REFDES=R5
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 10 25 hln 100 VALUE=50
part 59 r 670 180 u
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 10 25 hln 100 VALUE=10.05k
a 0 x 0:13 0 0 0 hln 100 PKGREF=R6
a 0 xp 9 0 25 0 hln 100 REFDES=R6
part 66 VSIN 420 230 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 FREQ=1k
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=1.2732
part 165 VSIN 460 230 h
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 0 x 0:13 0 0 0 hln 100 PKGREF=V2
a 1 xp 9 0 20 10 hcn 100 REFDES=V2
a 1 u 0 0 0 0 hcn 100 FREQ=3k
a 1 u 0 0 0 0 hcn 100 VAMPL=0.4244
part 68 VSIN 500 230 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V3
a 1 xp 9 0 20 10 hcn 100 REFDES=V3
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 FREQ=5k
a 1 u 0 0 0 0 hcn 100 VAMPL=0.2546
part 167 VSIN 540 230 h
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 0 x 0:13 0 0 0 hln 100 PKGREF=V4
a 1 xp 9 0 20 10 hcn 100 REFDES=V4
a 1 u 0 0 0 0 hcn 100 FREQ=7k
a 1 u 0 0 0 0 hcn 100 VAMPL=0.1818
part 169 VSIN 580 230 h
a 1 u 0 0 0 0 hcn 100 FREQ=9k
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 0 x 0:13 0 0 0 hln 100 PKGREF=V5
a 1 xp 9 0 20 10 hcn 100 REFDES=V5
a 1 u 0 0 0 0 hcn 100 VAMPL=0.1414
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 150 nodeMarker 610 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=9
@conn
w 103
a 0 up 0:33 0 0 0 hln 100 V=
s 420 230 420 220 102
a 0 up 33 0 422 225 hlt 100 V=
w 116
a 0 up 0:33 0 0 0 hln 100 V=
s 460 180 480 180 115
s 480 180 480 280 117
a 0 up 33 0 482 230 hlt 100 V=
s 500 280 500 270 87
s 480 280 500 280 119
w 122
a 0 up 0:33 0 0 0 hln 100 V=
s 500 230 500 220 121
a 0 up 33 0 502 225 hlt 100 V=
w 114
a 0 up 0:33 0 0 0 hln 100 V=
s 460 230 460 220 113
a 0 up 33 0 462 225 hlt 100 V=
w 108
a 0 up 0:33 0 0 0 hln 100 V=
s 460 270 460 280 83
s 440 180 440 280 109
a 0 up 33 0 442 230 hlt 100 V=
s 420 180 440 180 107
s 440 280 460 280 163
w 130
a 0 up 0:33 0 0 0 hln 100 V=
s 540 230 540 220 129
a 0 up 33 0 542 225 hlt 100 V=
w 124
a 0 up 0:33 0 0 0 hln 100 V=
s 500 180 520 180 123
s 520 180 520 280 125
a 0 up 33 0 522 230 hlt 100 V=
s 540 270 540 280 89
s 520 280 540 280 127
w 141
a 0 sr 0 0 0 0 hln 100 LABEL=Vin
a 0 up 0:33 0 0 0 hln 100 V=
s 580 180 610 180 140
a 0 sr 3 0 600 178 hcn 100 LABEL=Vin
a 0 up 33 0 600 179 hct 100 V=
s 610 180 630 180 151
w 143
a 0 sr 0:3 0 742 220 hln 100 LABEL=Vout
a 0 up 0:33 0 0 0 hln 100 V=
s 710 290 710 180 148
a 0 up 33 0 712 200 hlt 100 V=
a 0 sr 3 0 692 180 hln 100 LABEL=Vout
s 420 270 420 290 64
s 420 290 560 290 156
a 0 up 33 0 685 289 hct 100 V=
s 560 290 710 290 159
s 670 180 710 180 168
w 132
a 0 up 0:33 0 0 0 hln 100 V=
s 540 180 560 180 131
s 560 180 560 280 133
a 0 up 33 0 562 230 hlt 100 V=
s 580 280 580 270 93
s 560 280 580 280 135
w 138
a 0 up 0:33 0 0 0 hln 100 V=
s 580 230 580 220 137
a 0 up 33 0 582 225 hlt 100 V=
@junction
j 420 220
+ p 95 2
+ w 103
j 460 220
+ p 98 2
+ w 114
j 460 180
+ p 98 1
+ w 116
j 500 270
+ p 68 -
+ w 116
j 500 220
+ p 99 2
+ w 122
j 500 230
+ p 68 +
+ w 122
j 500 180
+ p 99 1
+ w 124
j 540 220
+ p 100 2
+ w 130
j 540 180
+ p 100 1
+ w 132
j 580 220
+ p 101 2
+ w 138
j 580 180
+ p 101 1
+ w 141
j 610 180
+ p 150 pin1
+ w 141
j 560 290
+ s 6
+ w 143
j 670 180
+ p 59 1
+ w 143
j 630 180
+ p 59 2
+ w 141
j 420 180
+ p 95 1
+ w 108
j 460 230
+ p 165 +
+ w 114
j 460 270
+ p 165 -
+ w 108
j 540 230
+ p 167 +
+ w 130
j 540 270
+ p 167 -
+ w 124
j 420 230
+ p 66 +
+ w 103
j 420 270
+ p 66 -
+ w 143
j 580 270
+ p 169 -
+ w 132
j 580 230
+ p 169 +
+ w 138
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
