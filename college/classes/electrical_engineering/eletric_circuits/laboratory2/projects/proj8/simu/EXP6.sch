*version 9.1 2470637225
u 278
C? 5
R? 11
L? 8
V? 8
? 3
@libraries
@analysis
.AC 0 2 0
+0 101
+1 1K
+2 100.00K
.TRAN 1 0 0 0
+0 1ms
+1 1s
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
pageloc 1 0 8406 
@status
n 0 116:05:09:14:21:11;1465492871 e 
s 2832 116:05:09:14:34:07;1465493647 e 
c 116:05:09:13:12:59;1465488779
*page 1 0 970 720 iA
@ports
port 173 GND_EARTH 230 160 h
port 202 GND_EARTH 580 160 h
port 231 GND_EARTH 230 300 h
port 260 GND_EARTH 580 300 h
@parts
part 169 r 200 70 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R1
a 0 xp 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=1.55k
part 198 r 550 70 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=R2
a 0 xp 9 0 15 0 hln 100 REFDES=R2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=1.55k
part 199 C 720 130 v
a 0 x 0:13 0 0 0 hln 100 PKGREF=C2
a 0 xp 9 0 25 30 hln 100 REFDES=C2
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 45 hln 100 VALUE=0.1u
part 201 VPULSE 450 100 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V2
a 1 xp 9 0 20 10 hcn 100 REFDES=V2
a 1 u 0 0 0 0 hcn 100 TR=1us
a 1 u 0 0 0 0 hcn 100 TF=1us
a 1 u 0 0 0 0 hcn 100 V1=0
a 1 u 0 0 0 0 hcn 100 V2=5
a 1 u 0 0 0 0 hcn 100 PER=200ms
a 1 u 0 0 0 0 hcn 100 PW=100ms
part 230 VPULSE 100 240 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V3
a 1 xp 9 0 20 10 hcn 100 REFDES=V3
a 1 u 0 0 0 0 hcn 100 TR=1us
a 1 u 0 0 0 0 hcn 100 TF=1us
a 1 u 0 0 0 0 hcn 100 V1=0
a 1 u 0 0 0 0 hcn 100 V2=5
a 1 u 0 0 0 0 hcn 100 PER=200ms
a 1 u 0 0 0 0 hcn 100 PW=100ms
part 227 r 200 210 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=R3
a 0 xp 9 0 15 0 hln 100 REFDES=R3
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=1.55k
part 256 r 550 210 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=R4
a 0 xp 9 0 15 0 hln 100 REFDES=R4
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=1.55k
part 228 C 370 270 v
a 0 u 13 0 10 40 hln 100 VALUE=0.1u
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=C3
a 0 xp 9 0 20 30 hln 100 REFDES=C3
part 170 C 370 130 v
a 0 u 13 0 15 40 hln 100 VALUE=0.1u
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=C1
a 0 xp 9 0 25 30 hln 100 REFDES=C1
part 259 VPULSE 450 240 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V4
a 1 xp 9 0 20 10 hcn 100 REFDES=V4
a 1 u 0 0 0 0 hcn 100 TR=1us
a 1 u 0 0 0 0 hcn 100 TF=1us
a 1 u 0 0 0 0 hcn 100 V1=0
a 1 u 0 0 0 0 hcn 100 V2=5
a 1 u 0 0 0 0 hcn 100 PER=200ms
a 1 u 0 0 0 0 hcn 100 PW=100ms
part 258 L 630 210 h
a 0 xp 9 0 20 -5 hln 100 REFDES=L4
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=500mH
a 0 x 0:13 0 0 0 hln 100 PKGREF=L4
part 257 C 720 270 v
a 0 x 0:13 0 0 0 hln 100 PKGREF=C4
a 0 xp 9 0 25 30 hln 100 REFDES=C4
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 40 hln 100 VALUE=0.1u
part 171 L 280 70 h
a 0 u 13 0 20 25 hln 100 VALUE=1pH
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=L1
a 0 xp 9 0 25 0 hln 100 REFDES=L1
part 200 L 630 70 h
a 0 u 13 0 15 25 hln 100 VALUE=100mH
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=L2
a 0 xp 9 0 25 0 hln 100 REFDES=L2
part 229 L 280 210 h
a 0 u 13 0 15 25 hln 100 VALUE=200mH
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=L3
a 0 xp 9 0 25 0 hln 100 REFDES=L3
part 172 VPULSE 100 100 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
a 1 u 0 0 0 0 hcn 100 TR=1us
a 1 u 0 0 0 0 hcn 100 TF=1us
a 1 u 0 0 0 0 hcn 100 V1=0
a 1 u 0 0 0 0 hcn 100 V2=5
a 1 u 0 0 0 0 hcn 100 PER=200ms
a 1 u 0 0 0 0 hcn 100 PW=100ms
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 175 nodeMarker 480 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin3
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin1
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin3
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vin1
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 177 nodeMarker 710 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout3
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout1
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout3
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=Vout1
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
@conn
w 154
a 0 up 0:33 0 0 0 hln 100 V=
s 240 70 280 70 153
a 0 up 33 0 260 69 hct 100 V=
w 162
a 0 up 0:33 0 0 0 hln 100 V=
s 370 160 230 160 163
a 0 up 33 0 300 159 hct 100 V=
s 370 130 370 160 165
s 100 160 100 140 167
s 230 160 100 160 174
w 183
a 0 up 0:33 0 0 0 hln 100 V=
s 590 70 630 70 182
a 0 up 33 0 610 69 hct 100 V=
w 191
a 0 up 0:33 0 0 0 hln 100 V=
s 720 160 580 160 192
a 0 up 33 0 650 159 hct 100 V=
s 720 130 720 160 194
s 450 160 450 140 196
s 580 160 450 160 203
w 212
a 0 up 0:33 0 0 0 hln 100 V=
s 240 210 280 210 211
a 0 up 33 0 260 209 hct 100 V=
w 220
a 0 up 0:33 0 0 0 hln 100 V=
s 370 300 230 300 221
a 0 up 33 0 300 299 hct 100 V=
s 370 270 370 300 223
s 100 300 100 280 225
s 230 300 100 300 232
w 241
a 0 up 0:33 0 0 0 hln 100 V=
s 590 210 630 210 240
a 0 up 33 0 610 209 hct 100 V=
w 249
a 0 up 0:33 0 0 0 hln 100 V=
s 720 300 580 300 250
a 0 up 33 0 650 299 hct 100 V=
s 720 270 720 300 252
s 450 300 450 280 254
s 580 300 450 300 261
w 156
a 0 sr 0:3 0 180 68 hcn 100 LABEL=Vin1
a 0 up 0:33 0 0 0 hln 100 V=
s 100 70 200 70 157
a 0 sr 3 0 180 68 hcn 100 LABEL=Vin1
a 0 up 33 0 125 69 hct 100 V=
s 100 100 100 70 159
w 150
a 0 sr 0:3 0 345 68 hcn 100 LABEL=Vout1
a 0 up 0:33 0 0 0 hln 100 V=
s 340 70 370 70 271
a 0 sr 3 0 345 68 hcn 100 LABEL=Vout1
a 0 up 33 0 355 69 hct 100 V=
s 370 70 370 100 151
w 185
a 0 sr 0:3 0 530 68 hcn 100 LABEL=Vin2
a 0 up 0:33 0 0 0 hln 100 V=
s 450 70 550 70 186
a 0 sr 3 0 530 68 hcn 100 LABEL=Vin2
a 0 up 33 0 475 69 hct 100 V=
s 450 100 450 70 188
w 179
a 0 sr 0:3 0 695 68 hcn 100 LABEL=Vout2
a 0 up 0:33 0 0 0 hln 100 V=
s 690 70 720 70 273
a 0 up 33 0 705 69 hct 100 V=
a 0 sr 3 0 695 68 hcn 100 LABEL=Vout2
s 720 70 720 100 180
w 214
a 0 sr 0:3 0 180 208 hcn 100 LABEL=Vin3
a 0 up 0:33 0 0 0 hln 100 V=
s 100 210 200 210 215
a 0 sr 3 0 180 208 hcn 100 LABEL=Vin3
a 0 up 33 0 125 209 hct 100 V=
s 100 240 100 210 217
w 243
a 0 sr 0:3 0 530 208 hcn 100 LABEL=Vin4
a 0 up 0:33 0 0 0 hln 100 V=
s 480 210 550 210 276
a 0 sr 3 0 530 208 hcn 100 LABEL=Vin4
s 450 210 480 210 244
a 0 up 33 0 475 209 hct 100 V=
s 450 240 450 210 246
w 208
a 0 sr 0:3 0 345 208 hcn 100 LABEL=Vout3
a 0 up 0:33 0 0 0 hln 100 V=
s 340 210 370 210 275
a 0 sr 3 0 345 208 hcn 100 LABEL=Vout3
a 0 up 33 0 355 209 hct 100 V=
s 370 210 370 240 209
w 237
a 0 sr 0:3 0 695 208 hcn 100 LABEL=Vout4
a 0 up 0:33 0 0 0 hln 100 V=
s 690 210 710 210 269
a 0 sr 3 0 695 208 hcn 100 LABEL=Vout4
a 0 up 33 0 705 209 hct 100 V=
s 720 210 720 240 238
s 710 210 720 210 277
@junction
j 240 70
+ p 169 2
+ w 154
j 200 70
+ p 169 1
+ w 156
j 370 100
+ p 170 2
+ w 150
j 370 130
+ p 170 1
+ w 162
j 340 70
+ p 171 2
+ w 150
j 280 70
+ p 171 1
+ w 154
j 100 100
+ p 172 +
+ w 156
j 100 140
+ p 172 -
+ w 162
j 230 160
+ s 173
+ w 162
j 590 70
+ p 198 2
+ w 183
j 550 70
+ p 198 1
+ w 185
j 690 70
+ p 200 2
+ w 179
j 630 70
+ p 200 1
+ w 183
j 450 100
+ p 201 +
+ w 185
j 450 140
+ p 201 -
+ w 191
j 580 160
+ s 202
+ w 191
j 240 210
+ p 227 2
+ w 212
j 200 210
+ p 227 1
+ w 214
j 370 240
+ p 228 2
+ w 208
j 370 270
+ p 228 1
+ w 220
j 340 210
+ p 229 2
+ w 208
j 280 210
+ p 229 1
+ w 212
j 100 240
+ p 230 +
+ w 214
j 100 280
+ p 230 -
+ w 220
j 230 300
+ s 231
+ w 220
j 590 210
+ p 256 2
+ w 241
j 550 210
+ p 256 1
+ w 243
j 720 240
+ p 257 2
+ w 237
j 720 270
+ p 257 1
+ w 249
j 690 210
+ p 258 2
+ w 237
j 630 210
+ p 258 1
+ w 241
j 450 240
+ p 259 +
+ w 243
j 450 280
+ p 259 -
+ w 249
j 580 300
+ s 260
+ w 249
j 720 100
+ p 199 2
+ w 179
j 720 130
+ p 199 1
+ w 191
j 480 210
+ p 175 pin1
+ w 243
j 710 210
+ p 177 pin1
+ w 237
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
