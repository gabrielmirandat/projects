/*Estes sao os codigos de comando para o nosso */
opencv_createsamples -info inst.info -num 52 -w 38 -h 38 -vec inst.vec
opencv_createsamples -vec inst.vec -w 38 -h 38  /*opcional: ver imagens carregadas*/
opencv_traincascade -data data -vec inst.vec -bg bg.txt -numPos 52 -numNeg 456 -numStages 20 -w 38 -h 38 -featureType LBP

/**novo**/
#p/ listar negativos, na pasta bg digite
$ find ../../../all_samples/140cinzaNeg/normal/ -name '*.png' > bg_normal.txt
$ find ../../../all_samples/140cinzaNeg/any/ -name '*.jpg' > bg_any.txt

#p/ listar positivos, na pasta inst
$ find ../../../all_samples/140cinzaPos/normalMINxMIN -name '*.png' -exec identify -format '%i 1 0 0 %w %h' \{\} \; > inst_MINxMIN.info

#p/ treinar com opencv_traincascade
opencv_createsamples -info inst/inst_MINxMIN.info -num 2010 -w 20 -h 20 -vec inst_MINxMIN.vec
opencv_createsamples -vec inst_MINxMIN.vec -w 20 -h 20  /*opcional: ver imagens carregadas*/
opencv_traincascade -data datas/data_MINxMIN_normal_any -vec inst_MINxMIN.vec -bg bg_normal_any.txt -numPos 1800 -numNeg 6203 -numStages 10 -w 20 -h 20 -featureType LBP

#p/ treinar com haartraining
opencv_createsamples -info inst/inst_MINxMIN.info -vec inst_MINxMIN.vec -w 20 -h 20
opencv_haartraining -data datas/data_MINxMIN_normal_any -vec inst_MINxMIN.vec -bg bgs/bg_normal_any.txt -nstages 5 -minhitrate 0.999 -maxfalsealarm 0.5 -npos 1800 -nneg 3600 -w 20 -h 20 -nonsym -mem 1024



bg_normal_any.txt

