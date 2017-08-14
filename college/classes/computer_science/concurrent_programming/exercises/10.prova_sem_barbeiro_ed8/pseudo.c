barbeiro()
{
	while(1)
	{
		wait(cliente_cadeira)
		// corta
		post(cabelo_cortado)
	}

}

cliente()
{
	while(1)
	{
		if(trywait(cadeiras)==0)
		{

			wait(cadeira_b)
			post(cadeiras)
			post(cliente_cadeira)
			wait(cabelo_cortado)
			post(cadeira_b)

		}
		else
		{
			foi embora
		}
	}
}