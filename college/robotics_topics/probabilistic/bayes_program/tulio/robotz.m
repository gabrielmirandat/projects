% P(OML0L1L2) = P(O)P(M|O)P(L0|O)P(L1|O)P(L2|O)
 
% conjuntos de valores
setO = [-135 -90 -45 0 45 90 135 180];
setM = [-1 0 1];
setL = [0 1 2];
 
% probabilidade conjunta. dimensoes:
% (i, j, k, l, m) -> O, M, L0, L1, L2
POML0L1L2 = zeros(8, 3, 3, 3, 3);
 
% probabilidades dadas
PO = ones(8, 1, 1, 1, 1)/8;
PMgO = [0.9 0.05 0.05; 0.9 0.05 0.05; 0.9 0.05 0.05; 0.05 0.9 0.05; ...
    0.05 0.05 0.9; 0.05 0.05 0.9; 0.05 0.05 0.9; 0.05 0.05 0.9];
PL0gO = [0.8 0.15 0.05; 0.5 0.3 0.2; 0.1 0.3 0.6; 0.02 0.08 0.9; ...
    0.1 0.3 0.6; 0.5 0.3 0.2; 0.8 0.15 0.05; 0.8 0.15 0.05];
PL0gO = permute(PL0gO, [1 3 2 4 5]);
PL1gO = [0.02 0.08 0.9; 0.1 0.3 0.6; 0.5 0.3 0.2; 0.8 0.15 0.05; ...
    0.8 0.15 0.05; 0.5 0.3 0.2; 0.1 0.3 0.6; 0.8 0.15 0.05];
PL1gO = permute(PL1gO, [1 3 4 2 5]);
PL2gO = [0.5 0.3 0.2; 0.8 0.15 0.05; 0.8 0.15 0.05; 0.8 0.15 0.05; ...
    0.5 0.3 0.2; 0.1 0.3 0.6; 0.02 0.08 0.9; 0.1 0.3 0.6];
PL2gO = permute(PL2gO, [1 3 4 5 2]);
 
% P(O=i,M=j,L0=k,L1=l,L2=m) =
% P(O=i)P(M=j|O=i)P(L0=k|O=i)P(L1=l|O=i)P(L2=m|O=i)
for i = 1:8
    for j = 1:3
        for k = 1:3
            for l = 1:3
                for m = 1:3
                    POML0L1L2(i, j, k, l, m) = PO(i, 1, 1, 1, 1)* ...
                        PMgO(i, j, 1, 1, 1) * PL0gO(i, 1, k, 1, 1) * ...
                        PL1gO(i, 1, 1, l, 1) * PL2gO(i, 1, 1, 1, m);
                end
            end
        end
    end
end
 
% P(O|L0=k,L1=l,L2=m) = P(O,L0=k,L1=l,L2=m)/P(L0=k,L1=l,L2=m) =
% sum[P(OM,L0=k,L1=l,L2=m), M]/sum[P(OM,L0=k,L1=l,L2=m), [O M]]
POgL0L1L2 = zeros(8, 1, 3, 3, 3);
POL0L1L2 = sum(POML0L1L2, 2);
PL0L1L2 = sum(sum(POML0L1L2, 1), 2);
for i = 1:8
    for k = 1:3
        for l = 1:3
            for m = 1:3
                POgL0L1L2(i, 1, k, l, m) = POL0L1L2(i, 1, k, l, m)/ ...
                    PL0L1L2(1, 1, k, l, m);
            end
        end
    end
end
 
% P(O|l0=1,l1=2,l2=0)
% stem(setO, POgL0L1L2(:, 1, 2, 3, 1));
bar(setO, POgL0L1L2(:, 1, 2, 3, 1));