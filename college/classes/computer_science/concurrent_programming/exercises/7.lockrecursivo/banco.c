#define OK 1

pthread_mutex_t l = ...;

int saldo = 0;

debitar(int v)
{
	pthread_mutex_lock(&l);
	saldo = saldo - v;
	pthread_mutex_unlock(&l);
}

creditar(int v)
{
	pthread_mutex_lock(&l);
	saldo = saldo + v;
	pthread_mutex_unlock(&l);	
}

saque(int v)
{
	pthread_mutex_lock(&l);
	if((saldo - v) >= 0)
	{
		debitar(v);
		pthread_mutex_unlock(&l);
		return OK;
	}
	pthread_mutex_unlock(&l);
	return !OK
}