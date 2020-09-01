#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void selection_sort (float * vetor, int TAMANHO_VETOR);
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
	
	selection_sort (vetor, TAMANHO_VETOR);
}


void selection_sort (float * vetor, int TAMANHO_VETOR)
{
	int pos_min, i, j;
	float aux;

	for (i=0; i < TAMANHO_VETOR-1; i++)
	{
		pos_min = i;
		for (j = i+1; j < TAMANHO_VETOR; j++)		
		{
			if (vetor[j] < vetor [pos_min])
			{
				pos_min = j;	
			}	
		}
		if (pos_min != i)
		{
			aux = vetor[i];
			vetor[i] = vetor[pos_min];
			vetor[pos_min] = aux;
		}	 	
	}
	mostra_notas (vetor, TAMANHO_VETOR);		
}

void mostra_notas(float *vetor, int TAMANHO_VETOR)
{
	int i;
	
	for (i = 0; i < TAMANHO_VETOR ; i++)								
	{
		printf("\nOrdenado por Selection_sort: Posição %i: \t %.2f\n", i+1, vetor[i]);	
	}
}
