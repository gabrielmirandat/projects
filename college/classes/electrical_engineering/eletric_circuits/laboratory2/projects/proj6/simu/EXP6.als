* Schematics Aliases *

.ALIASES
R_R1            R1(1=Vout1 2=0 )
R_R3            R3(1=Vin1 2=$N_0001 )
R_R2            R2(1=Vin1 2=$N_0002 )
V_V1            V1(+=$N_0002 -=0 )
V_V2            V2(+=$N_0001 -=0 )
C_C1            C1(1=Vin1 2=$N_0003 )
L_L1            L1(1=$N_0003 2=Vout1 )
R_R4            R4(1=Vout2 2=0 )
R_R5            R5(1=Vin2 2=$N_0004 )
R_R6            R6(1=Vin2 2=$N_0005 )
V_V3            V3(+=$N_0005 -=0 )
V_V4            V4(+=$N_0004 -=0 )
R_R7            R7(1=Vout3 2=0 )
R_R8            R8(1=Vin3 2=$N_0006 )
R_R9            R9(1=Vin3 2=$N_0007 )
V_V5            V5(+=$N_0007 -=0 )
V_V6            V6(+=$N_0006 -=0 )
L_L2            L2(1=$N_0008 2=Vout2 )
C_C2            C2(1=Vin2 2=$N_0008 )
C_C3            C3(1=Vin3 2=$N_0009 )
L_L3            L3(1=$N_0009 2=Vout3 )
_    _(Vout1=Vout1)
_    _(Vin1=Vin1)
_    _(Vout2=Vout2)
_    _(Vin2=Vin2)
_    _(Vout3=Vout3)
_    _(Vin3=Vin3)
.ENDALIASES

