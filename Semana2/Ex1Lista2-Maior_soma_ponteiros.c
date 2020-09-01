#include <stdio.h>
#include <locale.h> 
#include <stdlib.h> 
#include <locale.h>

#define TAMANHO_VET 5

float soma (float * vetor);
float maior (float * vetor);

float main()
{
	setlocale (LC_ALL, "Portuguese");
	int i;
	float vetor[TAMANHO_VET], res_soma, res_maior;

	for (i = 0; i < TAMANHO_VET ; i++)
	{
		printf("Informe o valor da posição %d do vetor: \n", i+1);
		scanf("%f", &vetor[i]);
	}

	res_soma = soma(vetor);
	printf("\n\nA soma é %.2f \n\n", res_soma);
				
	res_maior = maior(vetor);
	printf("\n\nO maior é %.2f \n\n", res_maior);		
}

float soma (float * vetor) 
{
	setlocale (LC_ALL, "Portuguese");
	int i;
	float res=0;
	printf ("\nres= %.2f\ttamanho_vet = %d", res, TAMANHO_VET);
	for (i = 0; i < TAMANHO_VET; i++)
	{
		res += vetor[i];
		printf("\nres= %.2f\ttamanho_vet = %d", res, TAMANHO_VET);
	}
	return res;
}

float maior (float * vetor)
{
	setlocale (LC_ALL, "Portuguese");
	int i;
	float res = vetor[0];
	printf("\nmaior= %.2f\ttamanho_vet = %i", res, TAMANHO_VET);
	for (i = 1; i < TAMANHO_VET; i++) 
	{
		if(vetor[i] > res) 	
			res=vetor[i]; 
		printf("\nmaior= %.2f\ttamanho_vet = %i", res, TAMANHO_VET); 	
	} 
	return res;
}





