mpicc 1a.c -o 1a -lm
mpicc 1b.c -o 1b -lm


# mpiexec -n 4 1a
# mpiexec -n 4 1b