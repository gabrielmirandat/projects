*version 9.1 1970551168
u 117
V? 5
L? 2
C? 3
R? 4
? 15
U? 2
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
pageloc 1 0 2356 
@status
n 0 116:03:28:12:36:39;1461857799 e 
s 2832 116:03:28:12:36:39;1461857799 e 
c 116:03:28:12:36:37;1461857797
*page 1 0 970 720 iA
@ports
port 68 GND_EARTH 450 300 h
port 110 GND_EARTH 540 230 h
@parts
part 59 r 480 260 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R1
a 0 xp 9 0 15 0 hln 100 REFDES=R1
part 60 r 580 180 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R2
a 0 xp 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=10k
part 58 OPAMP 550 220 h
a 0 sp 11 0 50 60 hln 100 PART=OPAMP
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=U1
a 0 ap 9 0 14 0 hln 100 REFDES=U1
a 0 u 0:13 0 20 82 hlb 100 VPOS=+10V
a 0 u 0:13 0 20 91 hlb 100 VNEG=-10V
part 61 VSIN 450 260 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=Vi
a 1 xp 9 0 20 10 hcn 100 REFDES=Vi
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 FREQ=1k
a 1 u 0 0 0 0 hcn 100 VAMPL=-0.5
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 92 nodeMarker 650 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=13
part 115 nodeMarker 460 260 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=14
@conn
w 82
a 0 up 0:33 0 0 0 hln 100 V=
s 620 180 650 180 81
s 650 180 650 210 83
s 650 240 630 240 85
s 650 210 650 240 93
a 0 up 33 0 652 225 hlt 100 V=
w 105
a 0 up 0:33 0 0 0 hln 100 V=
s 520 260 550 260 104
s 520 260 520 180 106
a 0 up 33 0 522 220 hlt 100 V=
s 520 180 580 180 108
w 112
s 540 230 540 220 111
s 540 220 550 220 113
w 98
a 0 up 0:33 0 0 0 hln 100 V=
s 450 260 460 260 97
s 460 260 480 260 116
a 0 up 33 0 470 259 hct 100 V=
@junction
j 620 180
+ p 60 2
+ w 82
j 630 240
+ p 58 OUT
+ w 82
j 650 210
+ p 92 pin1
+ w 82
j 480 260
+ p 59 1
+ w 98
j 520 260
+ p 59 2
+ w 105
j 550 260
+ p 58 -
+ w 105
j 580 180
+ p 60 1
+ w 105
j 540 230
+ s 110
+ w 112
j 550 220
+ p 58 +
+ w 112
j 460 260
+ p 115 pin1
+ w 98
j 450 260
+ p 61 +
+ w 98
j 450 300
+ s 68
+ p 61 -
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
