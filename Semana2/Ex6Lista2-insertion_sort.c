#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void insertion_sort (float * vetor, int TAMANHO_VETOR);
void mostra_notas(float * vetor, int TAMANHO_VETOR);

int main()
{
	setlocale (LC_ALL, "Portuguese"); 								
	int i, TAMANHO_VETOR;
	float *vetor;													
	printf("Informe o numero de componentes do vetor\n");
	scanf("%d", &TAMANHO_VETOR);
	vetor = (float *) malloc (TAMANHO_VETOR * sizeof(float));	
	for (i = 0; i < TAMANHO_VETOR ; i++)								
	{
		printf("Informe o valor da posição %d do vetor: \n", i+1);		
		scanf("%f", &vetor[i]);											
	}
	insertion_sort (vetor, TAMANHO_VETOR);
}
void insertion_sort(float * vetor, int TAMANHO_VETOR)
{
 	float escolhido;
	int anterior, i;
	for (i = 1; i < TAMANHO_VETOR; i++)
	{
		escolhido = vetor[i];
		anterior = i - 1;
 		while ( (anterior >= 0) && (vetor[anterior] > escolhido) )
		{
 			vetor[anterior + 1] = vetor[anterior];
 			anterior--;
		}
	vetor[anterior + 1] = escolhido;
 	}
 	mostra_notas (vetor, TAMANHO_VETOR);
}

void mostra_notas(float *vetor, int TAMANHO_VETOR)
{
	int i;
	for (i = 0; i < TAMANHO_VETOR ; i++)								
	{
		printf("\nOrdenado por Insertion_sort: Posição %i: \t %.2f\n", i+1, vetor[i]);	
	}
}
