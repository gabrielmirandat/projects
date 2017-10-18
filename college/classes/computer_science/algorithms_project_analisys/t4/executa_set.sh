#!/bin/bash

rm resultados.txt 2> /dev/null
rm graph/* 2> /dev/null

a_f=("1  2  0  0  1  0"
     "2  2  0  0  1  0"
     "4  2  0  0  1  0"
     "8  2  0  0  1  0"
     "16  4  0  0  1  0"
     "2  1  1  0  1  0"
     "1  1  1  0  1  0"
     "1  1  1  1  1  2"
     "1  4  0  1  2  0"
     "8  4  0  8  2  0")

g=( 0 1 2 3)

n=( 50 100 200 400 800 1000 2000 4000 8000 16000 32000 64000 128000)

start=`date +%s`
for i in "${a_f[@]}"
do
  echo "### af_$i"
  for j in "${g[@]}"
  do
    for k in "${n[@]}"
    do
      echo "## g_$j n_$k"
      ./calcula_recorrencia $i $j $k >> resultados.txt
    done
  done
done
end=`date +%s`

echo ""
echo "Execução: $((end-start))s"
