*version 9.1 7930510
u 81
V? 7
R? 3
? 2
@libraries
@analysis
.TRAN 1 0 0 1
+0 0ns
+1 300000ns
+4 33000
+5 V(A)
+6 7
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
pageloc 1 0 2798 
@status
n 0 115:05:17:20:32:45;1434583965 e 
s 2832 115:05:17:20:32:45;1434583965 e 
*page 1 0 970 720 iA
@ports
port 30 BUBBLE 390 170 h
a 1 x 3 0 0 0 hcn 100 LABEL=A
port 26 GND_EARTH 310 210 h
@parts
part 8 r 390 170 d
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=10.051k
part 7 r 340 170 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=50
part 9 VDC 330 170 d
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V6
a 1 ap 9 0 24 7 hcn 100 REFDES=V6
a 1 u 13 0 -11 18 hcn 100 DC=5V
part 2 VSIN 130 170 d
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 VAMPL=0.636
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 FREQ=33000
part 3 VSIN 170 170 d
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 0 a 0:13 0 0 0 hln 100 PKGREF=V2
a 1 ap 9 0 20 10 hcn 100 REFDES=V2
a 1 u 0 0 0 0 hcn 100 VAMPL=0.212
a 1 u 0 0 0 0 hcn 100 FREQ=99000
part 4 VSIN 210 170 d
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 0 a 0:13 0 0 0 hln 100 PKGREF=V3
a 1 ap 9 0 20 10 hcn 100 REFDES=V3
a 1 u 0 0 0 0 hcn 100 VAMPL=0.127
a 1 u 0 0 0 0 hcn 100 FREQ=165000
part 5 VSIN 250 170 d
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 0 a 0:13 0 0 0 hln 100 PKGREF=V4
a 1 ap 9 0 20 10 hcn 100 REFDES=V4
a 1 u 0 0 0 0 hcn 100 VAMPL=0.0909
a 1 u 0 0 0 0 hcn 100 FREQ=231000
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 28 nodeMarker 390 170 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
@conn
w 25
a 0 up 0:33 0 0 0 hln 100 V=
s 390 170 380 170 24
a 0 up 33 0 385 169 hct 100 V=
w 73
a 0 up 0:33 0 0 0 hln 100 V=
s 290 170 250 170 72
a 0 up 33 0 270 169 hct 100 V=
w 76
a 0 up 0:33 0 0 0 hln 100 V=
s 90 170 90 210 75
s 310 210 390 210 69
s 90 210 310 210 77
a 0 up 33 0 200 209 hct 100 V=
w 54
a 0 up 0:33 0 0 0 hln 100 V=
s 340 170 350 170 66
s 340 170 330 170 79
a 0 up 33 0 335 169 hct 100 V=
@junction
j 380 170
+ p 7 2
+ w 25
j 390 170
+ p 8 1
+ w 25
j 390 170
+ p 28 pin1
+ p 8 1
j 390 170
+ p 28 pin1
+ w 25
j 390 170
+ s 30
+ p 8 1
j 390 170
+ s 30
+ p 28 pin1
j 390 170
+ s 30
+ w 25
j 340 170
+ p 7 1
+ w 54
j 290 170
+ p 9 -
+ w 73
j 250 170
+ p 5 +
+ w 73
j 210 170
+ p 4 +
+ p 5 -
j 390 210
+ p 8 2
+ w 76
j 310 210
+ s 26
+ w 76
j 330 170
+ p 9 +
+ w 54
j 170 170
+ p 3 +
+ p 4 -
j 90 170
+ p 2 -
+ w 76
j 130 170
+ p 2 +
+ p 3 -
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
