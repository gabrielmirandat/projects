% P(Xtm1,Xt,Zt,Mt) = P(Xt|Xtm1,Mt)*P(Xtm1)*P(Zt|Xt)*P(Mt)
% dimensoes: % (i, j, k, l) -> Xtm1, Xt, Zt, Mt
% Xt -> 100 valores, Xtm1 -> 100 valores, Zt -> 2 valores, Mt -> 3 valores
 
% P(Xt|Xtm1,Mt) -> 100x100x1x3
% modelo do movimento
PXtgXtm1Mt = zeros(100, 100, 1, 3);
for j = 1:100
    % m = -1
    dist = pdf('Normal', 0:99, j-2, 1);
    PXtgXtm1Mt(:, j, 1, 1) = dist/sum(dist);
    % m = 0
    dist = pdf('Normal', 0:99, j-1, 1);
    PXtgXtm1Mt(:, j, 1, 2) = dist/sum(dist);
    % m = 1
    dist = pdf('Normal', 0:99, j, 1);
    PXtgXtm1Mt(:, j, 1, 3) = dist/sum(dist);
end
 
% P(Xtm1) -> 100x1x1x1
% informaзгo prйvia, inicialmente o robф nгo sabe onde estб
PXtm1 = ones(100, 1, 1, 1)/100;
 
% P(Zt|Xt) -> 1x100x2x1
% modelo do sensor, suponha que o sensor й gaussiano
tempNormal = pdf('Normal', 0:99, 20, 0.8) + ...
    pdf('Normal', 0:99, 30, 0.8) + pdf('Normal', 0:99, 70, 0.8);
tempNormal = tempNormal/sum(tempNormal);
PZtgXt = [1-tempNormal; tempNormal];
PZtgXt = permute(PZtgXt, [3 2 1 4]);
 
% P(Mt) -> 1x1x1x3
% informaзгo sobre o movimento, uniforme
PMt = ones(1, 1, 1, 3)/3;
 
% mapeia valores dos conjuntos Mt e Zt em нndices
dictMt = containers.Map([-1 0 1],[1 2 3]);
dictZt = containers.Map([0 1],[1 2]);
 
% prй alocando
% P(Xt,Xtm1|mt) = P(Xt|Xtm1,mt)*P(Xtm1) -> 100x100x1x1
PXtXtm1gmt = zeros(100, 100, 1, 1);
% P(Xt|mt,zt) -> 1x100x1x1
PXtgmtzt = zeros(1, 100, 1, 1);
 
% plota o primeiro grбfico, com a curva uniforme
h = bar(0:99, PXtm1);
xlim([0 99]);
 
mt = 0;
zt = 0;
 
% mtSet = [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 -1 9];
% ztSet = [0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 1 1 1  1 9];
 
n = 1;
 
while mt == -1 || mt == 0 || mt == 1
    % movimentaзгo e prediзгo
    % mt = mtSet(n);
    mt = inputdlg('Valor de mt:', 's');
    mt = str2double(mt);
    if mt == -1 || mt == 0 || mt == 1 
        % P(Xt|mt) = sum[P(Xt|Xtm1,mt)*P(Xtm1), Xtm1] -> 1x100x1x1
        % P(Xt|mt) = sum[P(Xt,Xtm1|mt), Xtm1]
        for i = 1:100
            for j = 1:100
                PXtXtm1gmt(i,j,1,1) = PXtgXtm1Mt(i,j,1,dictMt(mt)) * PXtm1(i,1,1,1);
            end
        end
        PXtgmt = sum(PXtXtm1gmt, 1);
        % mostra o grбfico da prediзгo
        set(h, 'YData', PXtgmt);
    end
    % inputdlg(strcat('m = ', num2str(mt)));
    % sensoriamento e correзгo
    % zt = ztSet(n);
    zt = inputdlg('Valor de zt:', 's');
    zt = str2double(zt);
    if zt == 0 || zt == 1
        % P(Xt|mt,zt) = n*P(zt|Xt)*P(Xt|mt)
        for j = 1:100
            PXtgmtzt(1,j,1,1) = PZtgXt(1,j,dictZt(zt),1) * PXtgmt(1,j,1,1);
        end
        PXtgmtzt = PXtgmtzt/sum(PXtgmtzt, 2);
        % mostra o grбfico da correзгo
        set(h, 'YData', PXtgmtzt);
        % P(Xtm1) = P(Xt|mt,zt)
        PXtm1 = permute(PXtgmtzt, [2 1 3 4]);
    end
    % inputdlg(strcat('z = ', num2str(zt)));
    % n = n + 1;
end