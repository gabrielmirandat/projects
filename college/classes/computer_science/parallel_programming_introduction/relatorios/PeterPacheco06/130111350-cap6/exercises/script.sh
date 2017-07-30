mpicc ex1_get_data3.c -o ex1_get_data3
mpicc ex2_get_data4.c -o ex2_get_data4
mpicc ex3_send_matrix_entry.c -o ex3_send_matrix_entry
mpicc pa1a_send_col.c -o pa1a_send_col
mpicc pa1b_send_row.c -o pa1b_send_row
mpicc pa3_send_col_to_row.c -o pa3_send_col_to_row
mpicc pa4_sparse_row.c -o pa4_sparse_row

# mpiexec -n 4 exec