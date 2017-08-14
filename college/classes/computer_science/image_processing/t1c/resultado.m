function[]= resultado(numero,mat)
    [~,tam] = size(mat);
    
    disp(sprintf('RESULTADO IMAGEM %d\n',numero));
    for i=1:tam
      if mat(2,i)==0
        disp(sprintf('A mancha %d não possui buraco(s).->TIPO A\n',i));
      else
        disp(sprintf('A mancha %d possui %d buraco(s).->TIPO B\n',i,mat(2,i)));
      end
    end
    
    waitfor(msgbox(sprintf('A imagem %d possui %d manchas.\nMais resultados na janela de comando.',numero,tam)));