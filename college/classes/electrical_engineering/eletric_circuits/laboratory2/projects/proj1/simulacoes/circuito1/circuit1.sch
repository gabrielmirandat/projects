*version 9.1 3232988523
u 36
V? 3
L? 2
C? 2
R? 2
? 9
@libraries
@analysis
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
pageloc 1 0 2464 
@status
n 0 116:02:26:16:41:44;1459021304 e 
s 2832 116:02:30:19:15:06;1459376106 e 
c 116:02:26:16:41:39;1459021299
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
a 0 u 13 0 15 40 hln 100 VALUE=1.050k
part 3 L 600 210 h
a 0 ap 9 0 25 5 hln 100 REFDES=L1
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 u 13 0 20 20 hln 100 VALUE=33uH
part 4 c 550 210 h
a 0 ap 9 0 10 0 hln 100 REFDES=C1
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 u 13 0 5 25 hln 100 VALUE=0.1uF
part 30 VSIN 510 230 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 FREQ=0.5k
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 34 nodeMarker 510 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin;;BRIGHTRED
a 0 a 0 0 4 22 hlb 100 LABEL=7
a 0 sp 0 0 0 0 hln 100 COLOR=BRIGHTBLUE
part 35 nodeMarker 670 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout;;BRIGHTBLUE
a 0 a 0 0 4 22 hlb 100 LABEL=8
a 0 sp 0 0 0 0 hln 100 COLOR=BRIGHTRED
@conn
w 12
a 0 up 0:33 0 0 0 hln 100 V=
s 580 210 600 210 11
a 0 up 33 0 590 209 hct 100 V=
w 18
a 0 up 0:33 0 0 0 hln 100 V=
s 510 270 510 290 17
s 510 290 590 290 19
s 670 290 670 270 21
s 590 290 670 290 23
a 0 up 33 0 630 289 hct 100 V=
w 8
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=Vin
s 510 230 510 210 7
a 0 sr 3 0 512 220 hln 100 LABEL=Vin
s 510 210 550 210 9
a 0 up 33 0 530 209 hct 100 V=
w 14
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=Vout
s 670 210 670 230 15
a 0 up 33 0 672 220 hlt 100 V=
a 0 sr 3 0 672 220 hln 100 LABEL=Vout
s 660 210 670 210 13
@junction
j 600 210
+ p 3 1
+ w 12
j 660 210
+ p 3 2
+ w 14
j 670 230
+ p 5 2
+ w 14
j 670 270
+ p 5 1
+ w 18
j 590 290
+ s 6
+ w 18
j 580 210
+ p 4 2
+ w 12
j 550 210
+ p 4 1
+ w 8
j 510 270
+ p 30 -
+ w 18
j 510 230
+ p 30 +
+ w 8
j 510 210
+ p 34 pin1
+ w 8
j 670 210
+ p 35 pin1
+ w 14
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
