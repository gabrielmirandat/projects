% Objective: build a histogram filter for Probabilistic Robotics
% chapter 8.

% P(Xt-1,Xt,Zt,Mt) = P(Xt|Xt-1,Mt)  -> motion model
%                    P(Xt-1)        -> posterior
%                    P(Zt|Xt)       -> sensor model
%                    P(Mt)          -> motor moviment

% The map is represented by 100 cells in horizontal
% The doors is located in cells 30, 43 and 75
% In one timeStamp, the robot moves 4 cells

% P(Xt|m)     -> Prediction                 -> belBar(Xt)
% P(Xt|m,z)   -> Estimation or Correction   -> bel(Xt)

% |X| = 100 (cells)
% |Z| = 2   (see door, dont)
% |M| = 2   (move forward 3 cells, stay)
% dimensoes: % (i, j, k, l) -> XP, XA, ZA, MA

%% BUILDING PROBABILITIES

% P(Xt|Xtm1,Mt) -> 100x100x1x2
% modelo do movimento
P_XAdXPMA = zeros(100, 100, 1, 2);
for j = 1:100
    % m = 1
    dist = 10*pdf('Normal', 0:99, j-4, 1) + 0.01*ones(1,100);
    P_XAdXPMA(:, j, 1, 1) = dist/sum(dist);
    % m = 2
    dist = 10*pdf('Normal', 0:99, j-1, 1) + 0.01*ones(1,100);
    P_XAdXPMA(:, j, 1, 2) = dist/sum(dist);
end

% P(Xt-1) begins uniform
P_XP = ones(100, 1, 1, 1)/100;
% sum(P_XP)

% P(Zt|Xt) is constant and depends on map
P_ZAdXA = 10*pdf('Normal', 0:99, 30, 0.8) + ...
    10*pdf('Normal', 0:99, 43, 0.8) + ...
    10*pdf('Normal', 0:99, 75, 0.8) +  + 0.01*ones(1,100);  
P_ZAdXA = P_ZAdXA/sum(P_ZAdXA);
P_ZAdXA = [P_ZAdXA ; 1-P_ZAdXA];
P_ZAdXA = permute(P_ZAdXA, [3 2 1 4]);

% P(MA) is uniform
P_MA = ones(1, 1, 1, 2)/2;


%% EXECUTING
% first move, after measure

% P(Xt|m)     -> Prediction                 -> belBar(Xt)
% P(Xt|m,z)   -> Estimation or Correction   -> bel(Xt)

% P(Xt|m) = E_Xt-1{P(Xt|Xt-1,Mt).P(Xt-1)}
% P(Xt|m,z) = (P(Zt|Xt).P(Xt|m)/n

% 20 iterations
% Needs define the values for motor and sensor
iterations = 20;
motor = [1, 1, 1, 1, 2, 1, 1, 1, 2, 1, ...
         1, 1, 1, 1, 1, 2, 1, 1, 1, 1];

measure = [2, 2, 2, 2, 2, 2, 1, 2, 2, 2, ...
            1, 1, 2, 2, 2, 2, 2, 2, 2, 1];
            

P_XAXPdm = zeros(100, 100, 1, 1);

P_XAdm = zeros(100); 
P_XAdmz = zeros(1,100,1,1); 

bar(1:100,P_XP, 0.4);
pause();

for it = 1:iterations
    for i = 1:100
        for j = 1:100
            P_XAXPdm(i,j,1,1) = P_XAdXPMA(i,j,1,motor(it))*P_XP(i,1,1,1);
        end
    end
    P_XAdm = sum(P_XAXPdm, 1);
    
    for j = 1:100
    	P_XAdmz(1,j,1,1) = P_ZAdXA(1,j,measure(it),1)*P_XAdm(1,j,1,1);
    end
	P_XAdmz = P_XAdmz/sum(P_XAdmz, 2);
    
    P_XP = permute(P_XAdmz, [2 1 3 4]);
    
    xlim([1 100])
    bar(1:100,P_XP, 0.4);
    pause();
end
