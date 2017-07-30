Grouping Data for communication

Mandar mensagens é custoso
Antes mandamos a,b e n em 3 mensagens separadas
Queremos mandar tudo em uma só

3 mecanismos:
- parâmetro cont (mas precisam estar contíguos na mem - vetor, struct)
- datatypes derivados
- MPI_Pack e MPI_Unpack

float a,b;
int n;

message: type, relative from &a
{(MPI_FLOAT,0),(MPI_FLOAT,16),(MPI_INT,24)}

// build general derived datatypes
int MPI_Type_struct(	
	int 			count 			/*in*/
	int 			block_lenghts[] /*in*/
	MPI_Aint 		displacements[] /*in*/
	MPI_Datatype    typelist[]		/*in*/
	MPI_Datatype*	new_mpi_t		/*out*/)


// to compute adresses. Returns byte adress of location in adress
MPI_Adress(
	void*		location	/*in*/
	MPI_Aint*	address		/*out*/)

// we can't use new_mpi_t until call to MPI_Type_commit 
int MPI_Type_commit(
	MPI_Datatype*	new_mpi_t	/*in/out*/)

MPI_Type_contiguous	
MPI_Type_vector
MPI_Type_indexed

int MPI_Type_vector(
	int 			count 			/*in*/,
	int 			block_lenght    /*in*/,
	int 			stride			/*in*/,			
	MPI_Datatype 	element_type    /*in*/,
	MPI_Datatype 	new_mpi_t		/*out*/)

int MPI_Type_contiguous(
	int 			count 			/*in*/,		
	MPI_Datatype 	old_type    	/*in*/,
	MPI_Datatype 	new_mpi_t		/*out*/)

int MPI_Type_indexed(
	int 			count 			/*in*/,
	int 			block_lenghts[] /*in*/,
	int 			displacements[]	/*in*/,			
	MPI_Datatype 	old_type    	/*in*/,
	MPI_Datatype 	new_mpi_t		/*out*/)

MPI_Pack     // store noncontiguous data in contiguous memory
MPI_Unpack 	 // copy from contiguous to noncontiguous

int MPI_Pack(
	void* 			pack_data	/*in*/
	int 			in_count	/*in*/
	MPI_Datatype	datatype 	/*in*/
	void* 			buffer 		/*out*/
	int 			buffer_size /*in*/
	int* 			position  	/*in/out*/
	MPI_Comm 		comm  		/*in*/)

int MPI_Unpack(
	void* 			buffer		/*in*/
	int 			size		/*in*/
	int*			position	/*in/out*/
	void*			unpack_data	/*out*/
	int 			count 		/*in*/
	MPI_Datatype	datatype 	/*in*/
	MPI_Comm 		comm  		/*in*/)

Temos
count.c - manda subvetor entre 2 processos
send_col.c - manda uma coluna de matriz entre dois processos.
send_row.c - manda linha de matriz entre dois processos.
send_col_to_row.c - manda uma coluna pra linha de outro processo.
send_triangle.c - manda triangulo de cima de matriz entre dois processos.
sparse_row.c - manda pedaços de vetor entre dois processos.