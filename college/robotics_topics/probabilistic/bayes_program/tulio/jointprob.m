% P(ABC) = P(A)P(B|C)P(C|A)
 
set = [1 2 3 4 5];
PABC = zeros(5, 5, 5);
PA = ones(1, 5)/5;
PBgC = [5 4 3 2 1; 3 4 3 2 1; 1 2 3 2 1; 1 2 3 4 3; 1 2 3 4 5];
PCgA = [3 1 1 1 1; 3 3 1 1 1; 3 3 3 1 1; 3 3 3 3 1; 3 3 3 3 3];
 
% tem q normalizar as linhas pq botei pesos e nao probabilidades
for i = set
    PBgC(i, :) = PBgC(i, :)/sum(PBgC(i, :));
    PCgA(i, :) = PCgA(i, :)/sum(PCgA(i, :));
end
 
% padronizando as dimensoes
% dim = 1 -> A, dim = 2 -> B, dim = 3 -> C
PA = permute(PA, [2 1 3]);
PBgC = permute(PBgC, [3 2 1]);
PCgA = permute(PCgA, [1 3 2]);
 
% P(A=i,B=j,C=k) = P(A=i)*P(C=k|A=i)*P(B=j|C=k)
% PABC(i, j, k) = PA(i, 1, 1) * PBgC(1, j, k) * PCgA(i, 1, k)
for i = set
    for j = set
        for k = set
            PABC(i, j, k) = PA(i, 1, 1) * PBgC(1, j, k) * PCgA(i, 1, k);
            % 3 dimensions  1 dimension   2 dimensions    2 dimensions
        end
    end
end
 
% P(A) = Soma[PABC, BC]
pA = sum(sum(PABC, 2), 3);
err1 = (pA - PA);
 
% P(BC) = Soma[P(ABC), A]
pBC = sum(PABC, 1);
% P(C) = Soma[P(ABC), AB]
pC = sum(sum(PABC, 1), 2);
% P(B|C) = P(BC)/P(C)
% P(B=j|C=k) = P(B=j,C=k)/P(C=k)
for j = set
    for k = set
        pBgC(1, j, k) = pBC(1, j, k)/pC(1, 1, k);
    end
end
err2 = (pBgC - PBgC);
 
% P(CA) = Soma[P(ABC), B]
pCA = sum(PABC, 2);
% P(A) = Soma[PABC, BC]
pA = sum(sum(PABC, 2), 3);
% P(C|A) = P(CA)/P(A)
% P(C=k|A=i) = P(C=k,A=i)/P(A=i)
for i = set
    for k = set
        pCgA(i, 1, k) = pCA(i, 1, k)/pA(i, 1, 1);
    end
end
err3 = (pCgA - PCgA);