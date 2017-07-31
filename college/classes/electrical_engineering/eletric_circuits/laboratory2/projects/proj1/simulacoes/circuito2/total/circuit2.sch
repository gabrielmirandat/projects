*version 9.1 61995046
u 58
R? 3
V? 5
L? 2
C? 2
? 4
@libraries
@analysis
.TRAN 1 0 0 0
+0 0ns
+1 2ms
+3 2us
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
pageloc 1 0 3512 
@status
c 116:02:31:12:53:01;1459439581
n 0 116:02:31:12:53:04;1459439584 e 
s 2832 116:02:31:17:49:34;1459457374 e 
*page 1 0 970 720 iA
@ports
port 8 GND_EARTH 620 340 h
@parts
part 6 L 660 180 h
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 25 0 hln 100 REFDES=L1
a 0 u 13 0 15 25 hln 100 VALUE=33uH
part 7 c 740 270 v
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
a 0 u 13 0 5 35 hln 100 VALUE=0.1uF
part 2 r 520 240 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 40 hln 100 VALUE=2.250k
part 38 VSIN 520 270 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 FREQ=3k
a 1 u 0 0 0 0 hcn 100 VAMPL=2.828
a 1 u 0 0 0 0 hcn 100 VOFF=0
part 5 r 620 240 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 45 hln 100 VALUE=1.050k
part 56 VSIN 620 270 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V2
a 1 xp 9 0 20 10 hcn 100 REFDES=V2
a 1 u 0 0 0 0 hcn 100 FREQ=10k
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 VAMPL=7.071
a 1 u 0 0 0 0 hcn 100 VOFF=0
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 39 nodeMarker 520 250 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=V1:+
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 43 nodeMarker 740 190 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=C1:2
a 0 a 0 0 4 22 hlb 100 LABEL=3
part 41 nodeMarker 620 250 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=V2:+
a 0 a 0 0 4 22 hlb 100 LABEL=2
@conn
w 10
a 0 up 0:33 0 0 0 hln 100 V=
s 520 200 520 180 9
s 520 180 620 180 11
a 0 up 33 0 570 179 hct 100 V=
s 620 180 620 200 13
s 620 180 660 180 15
w 18
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=Vout
s 740 190 740 240 47
a 0 sr 3 0 742 215 hln 100 LABEL=Vout
s 720 180 740 180 17
s 740 180 740 190 44
a 0 up 33 0 742 210 hlt 100 V=
w 34
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=Vin1
s 520 250 520 270 45
a 0 sr 3 0 522 260 hln 100 LABEL=Vin1
s 520 240 520 250 40
a 0 up 33 0 522 255 hlt 100 V=
w 57
a 0 sr 3 0 622 260 hln 100 LABEL=Vin2
a 0 up 0:33 0 0 0 hln 100 V=
s 620 250 620 270 46
a 0 sr 3 0 622 260 hln 100 LABEL=Vin2
s 620 240 620 250 42
a 0 up 33 0 622 255 hlt 100 V=
w 26
a 0 up 0:33 0 0 0 hln 100 V=
s 520 310 520 340 25
s 740 340 620 340 23
s 520 340 620 340 27
s 620 310 620 340 29
s 740 270 740 340 21
@junction
j 520 200
+ p 2 2
+ w 10
j 620 200
+ p 5 2
+ w 10
j 660 180
+ p 6 1
+ w 10
j 620 180
+ w 10
+ w 10
j 720 180
+ p 6 2
+ w 18
j 620 340
+ s 8
+ w 26
j 520 240
+ p 2 1
+ w 34
j 740 240
+ p 7 2
+ w 18
j 740 270
+ p 7 1
+ w 26
j 520 270
+ p 38 +
+ w 34
j 520 310
+ p 38 -
+ w 26
j 520 250
+ p 39 pin1
+ w 34
j 740 190
+ p 43 pin1
+ w 18
j 620 240
+ p 5 1
+ w 57
j 620 250
+ p 41 pin1
+ w 57
j 620 270
+ p 56 +
+ w 57
j 620 310
+ p 56 -
+ w 26
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
