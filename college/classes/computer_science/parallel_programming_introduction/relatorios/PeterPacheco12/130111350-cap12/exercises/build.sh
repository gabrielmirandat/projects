mpicc bcast.c send.c -o bcast -lm
#mpiexec -n 6 bcast
mpicc ping_pong.c -o ping_pong -lm
#mpiexec -n 2 ping_pong

