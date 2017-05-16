# Objective: build a histogram filter for Probabilistic Robotics
# chapter 8.

# P(Xt-1,Xt,Zt,Mt) = P(Xt|Xt-1,Mt)  -> motion model
#                    P(Xt-1)        -> posterior
#                    P(Zt|Xt)       -> sensor model
#                    P(Mt)          -> motor moviment

# The map is represented by 100 cells in horizontal
# The doors is located in cells 30, 43 and 75
# In one timeStamp, the robot moves 4 cells

# P(Xt|m)     -> Prediction                 -> belBar(Xt)
# P(Xt|m,z)   -> Estimation or Correction   -> bel(Xt)

# |X| = 100 (cells)
# |Z| = 2   (see door, dont)
# |M| = 2   (move forward 3 cells, stay)

### BUILDING PROBABILITIES

## P(Xt|Xt-1,Mt) -- OK
P_XAdXPMA = ones(100,100,2);
for xa = 1:100
  for xp = 1:100
    for ma = 1:2
      
      # move 3 cells
      if(ma==1)
        if(xa - xp == 3)
          P_XAdXPMA(xa,xp,ma) = 7;
        elseif (xa - xp == 4 || xa - xp == 2)
          P_XAdXPMA(xa,xp,ma) = 5;
        elseif(xa - xp == 5 || xa - xp == 1)  
          P_XAdXPMA(xa,xp,ma) = 2;
        endif
      endif
      
      # stay
      if(ma==2)
        if(xa - xp == 0)
          P_XAdXPMA(xa,xp,ma) = 7;
        elseif (xa - xp == 1 || xa - xp == -1)
          P_XAdXPMA(xa,xp,ma) = 5;
        elseif(xa - xp == 2 || xa - xp == -2)  
          P_XAdXPMA(xa,xp,ma) = 2;
        endif
      endif
    
    endfor
  endfor
endfor

# normalization 
for xa = 1:100
  norm = sum(sum(P_XAdXPMA(xa,:,:)));
  for xp = 1:100
    for ma = 1:2
      P_XAdXPMA(xa,xp,ma) = 1.* P_XAdXPMA(xa,xp,ma)/ norm;
    endfor
  endfor
endfor
    

## P(Xt-1) begins uniform -- OK
P_XP = ones(1,100)*1./100;
# sum(P_XP)

## P(Zt|Xt) is constant and depends on map -- OK
P_ZAdXA(1,:) = [1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , ...
                1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , ...
                1 ,1 ,1 ,1 ,1 ,1 ,3 ,5 ,7 ,10, ...
                7 ,5 ,3 ,1 ,1 ,1 ,1 ,1 ,1 ,3 , ...
                5 ,7 ,10,7 ,5 ,3 ,1 ,1 ,1 ,1 , ...
                1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , ...
                1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , ...
                1 ,3 ,5 ,7 ,10,7 ,5 ,3 ,1 ,1 , ...
                1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , ...
                1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ];

P_ZAdXA(2,:) = [8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 , ...
                8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 , ...
                8 ,8 ,8 ,8 ,8 ,8 ,7 ,5 ,3 ,1 , ...
                3 ,5 ,7 ,8 ,8 ,8 ,8 ,8 ,8 ,7 , ...
                5 ,3 ,1 ,3 ,5 ,7 ,8 ,8 ,8 ,8 , ...
                8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 , ...
                8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 , ...
                8 ,7 ,5 ,3 ,1 ,3 ,5 ,7 ,8 ,8 , ...
                8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 , ...
                8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ];            
                
# normalization 
P_ZAdXA(1,:) = P_ZAdXA(1,:)*1./sum(P_ZAdXA(1,:));
P_ZAdXA(2,:) = P_ZAdXA(2,:)*1./sum(P_ZAdXA(2,:));
# sum(P_ZAdXA(1,:))
# sum(P_ZAdXA(2,:))
# bar(P_ZAdXA);

## P(MA) is uniform
P_MA = [0.5 0.5];


### EXECUTING
# first move, after measure

# P(Xt|m)     -> Prediction                 -> belBar(Xt)
# P(Xt|m,z)   -> Estimation or Correction   -> bel(Xt)

# P(Xt|m) = E_Xt-1{P(Xt|Xt-1,Mt).P(Xt-1)}
# P(Xt|m,z) = (P(Zt|Xt).P(Xt|m)/n

# 20 iterations
# Needs define the values for motor and sensor
iterations = 20;
motor = [1, 1, 1, 1, 2, 1, 1, 1, 2, 1, ...
         1, 1, 1, 1, 1, 2, 1, 1, 1, 1];

measures = [2, 2, 2, 2, 2, 2, 1, 2, 2, 2, ...
            1, 1, 2, 2, 2, 2, 2, 2, 2, 1];
            
P_XAdm = ones(1, 100);   
P_XAdmz = ones(1, 100);        

for it = 1:iterations
    for allx = 1: 100
      P_XAdm(1,allx) = sum(P_XAdXPMA(allx,:,motor(1,it))) * sum(P_XP(1,:));
    endfor
    
    for allx = 1: 100
      P_XAdmz(1,allx) =  P_ZAdXA(measures(1,it), allx) * P_XAdm(1, allx);
    endfor
    
    P_XP(1,:) = P_XAdmz(1,:)*1./sum(P_XAdmz(1,:));
    
    bar(P_XP, "hist");
    
    input ("Press enter! ")
    pause();
endfor






















