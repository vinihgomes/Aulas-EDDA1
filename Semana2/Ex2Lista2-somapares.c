#include <stdio.h>
#include <locale.h> 
#include <stdlib.h> 
#include <locale.h>

#define TAMANHO_VET 5

int somapares (int * vetor);

int main()
{
	setlocale (LC_ALL, "Portuguese"); 									//1
	int i, vetor[TAMANHO_VET], res_soma;								//1

	for (i = 0; i < TAMANHO_VET ; i++)									//n+1
	{
		printf("Informe o valor da posição %d do vetor: \n", i+1);		//n
		scanf("%i", &vetor[i]);											//n
	}
	res_soma = somapares(vetor);										//1
	printf("\n\nA soma é %i \n\n", res_soma);							//1
}

int somapares (int *vetor) 
{
	int i, res=0;														//1
	for (i = 0; i < TAMANHO_VET; i++)									//n+1	
	{
		if (vetor[i] % 2 == 0)											//n
			res += vetor[i];											//n
	}
	return res;															//1
}
																		
																		//8 + 6n
