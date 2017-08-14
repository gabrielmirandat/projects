gcc iterative_dfs.c -o iterative_dfs
gcc recursive_dfs.c -o recursive_dfs
gcc serial_bitonic.c -o serial_bitonic
mpicc parallel_bitonic.c 1_cio.c -o parallel_bitonic

# ./iterative_dfs
# ./recursive_dfs
# ./serial_bitonic
# mpiexec -n 4 parallel_bitonic
