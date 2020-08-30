#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void bubble_sort(float * vetor, int TAMANHO_VETOR);
void mostra_notas(float * vetor, int TAMANHO_VETOR);


int main()
{
	setlocale (LC_ALL, "Portuguese"); 									//1
	int i, TAMANHO_VETOR;
	float *vetor;														//1

	printf("Informe o numero de componentes do vetor\n");
	scanf("%d", &TAMANHO_VETOR);
	
	vetor = (float *) malloc (TAMANHO_VETOR * sizeof(float));
	
	
	for (i = 0; i < TAMANHO_VETOR ; i++)									//n+1
	{
		printf("Informe o valor da posição %d do vetor: \n", i+1);		//n
		scanf("%f", &vetor[i]);											//n
	}
	
	bubble_sort(vetor, TAMANHO_VETOR);
}



void bubble_sort(float * vetor, int TAMANHO_VETOR) 
{
	int i, j;
	float aux;
	for (j = 0; j < TAMANHO_VETOR-1; j++)
	{
		for (i = 0; i < TAMANHO_VETOR-1; i++) 
		{
			printf ("\nComparando %.2f com %.2f ", vetor[i], vetor[i+1]);
			if (vetor [i] > vetor[i+1])
			{
				printf ("-> empurra %.2f para o fundo");
				printf ("-> troca com %.2f", vetor[i], vetor[i+1]);
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor [i+1] = aux;
			}
			if (j < TAMANHO_VETOR-1)
				mostra_notas(vetor, TAMANHO_VETOR);
		}
	}
}

void mostra_notas(float *vetor, int TAMANHO_VETOR)
{
	int i;
	
	for (i = 0; i < TAMANHO_VETOR ; i++)									//n+1
	{
		printf("\nOrdenado por Bubble_sort: Posição %i: \t %.2f\n", i+1, vetor[i]);		//n
	}
}
