#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

float abastece_notas(float * notas);
int busca_linear (float n, float * notas, int i);
int busca_binaria (float n, float * notas, int ini, int fim);
void troca (float *A, float *B); 
void quick_sort(float * notas, int ini, int fim);

int TAMANHO_VETOR;

int main(){
	int opc, i, j;
	float *notas, n;
	setlocale (LC_ALL, "Portuguese"); 								

	printf("Informe quantas notas deseja alocar: \n");
	scanf("%d", &TAMANHO_VETOR);
	notas = (float *) malloc (TAMANHO_VETOR * sizeof(float));

	abastece_notas(notas);
	
	for (i = 0; i < TAMANHO_VETOR ; i++)								
	{
		printf("\nPosição alocada %d:\t %.2f", i+1, notas[i]);	
	}
	
	printf("\nInforme o valor a ser pesquisado: \n");
	scanf ("%f", &n);
	
	printf("\nPronto, iremos para a próxima etapa! Aperte qualquer tecla para continuar:");
	getch();
	system("cls");
	printf("Informe qual método de busca deseja utilizar: \n");
	printf("1 - Busca Linear\n");
	printf("2 - Busca Binária\n");
	scanf("%d", &opc);
	switch(opc){
		case 1: 
			j = busca_linear(n, notas, 0);
			if (j < 0)
				printf("\nNão existe o valor buscado dentro do vetor gerado.");
			else
				printf("\n\nO valor buscado se encontra na posição %d do vetor", j);
			free(notas);
		break;
		case 2: 
			quick_sort(notas, 0 , TAMANHO_VETOR);
			for (i = 1; i <= TAMANHO_VETOR ; i++)								
			{
				printf("\nOrdenado por Quick Sort: Posição %i: \t %.2f\n", i, notas[i]);	
			}
			j = busca_binaria(n, notas, 0, TAMANHO_VETOR);
			if (j < 0)
				printf("\nNão existe o valor buscado dentro do vetor gerado.");
			else
				printf("\n\nO valor buscado se encontra na posição %d do vetor", j);
			free(notas);
		break;

		default: printf("\nOpção inválida");
	}
}




///////////////////////////////////////////////////////// QUESTAO 2 ///////////////////////////////////////////////////////////////
int busca_linear (float n, float * notas, int i){
	if (i < TAMANHO_VETOR){
		printf("\nComparando posição %d do vetor, que contém o valor %.2f com a busca que é %.2f",i+1, notas[i], n);
		if (notas[i++]==n)
			return i;
		else
			busca_linear(n, notas, i);
	}
	else return -1;	
	
}

int busca_binaria (float n, float * notas, int ini, int fim){	
	int meio;
	if (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (notas[meio]==n)
			return meio;
		if (notas[meio]>n)
			busca_binaria (n, notas, ini, meio-1);
		else
			busca_binaria (n, notas, meio+1, fim);
	}
	else return -1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void quick_sort	(float * notas, int ini, int fim) 
{   
	int particiona (float * notas, int ini, int pivo); 

	
   	int pivo;
   	if ( ini < fim ) /* Caso base */ 
   	{        
        pivo = particiona ( notas, ini, fim ); /* Particiona o vetor*/ 
        quick_sort( notas, ini,    pivo-1 );    /* Ordena do início do vetor até antes do pivô */
        quick_sort( notas, pivo+1, fim);      /* Ordena desde após o pivô até o fim do vetor */
   	} 
}
	
//Função auxiliar quick sort
int particiona (float * vetor, int ini, int pivo) 
{    
    int   i;
    int   p_maior = ini; /* a posição do maior é a do início do vetor */    
    
    for ( i=ini; i<pivo; i++ ) /* percorre o vetor da posição ini até a do pivô */
    {        
       if ( vetor[i] < vetor[pivo] ) /*se o elemento da posição atual for menor que o pivô...*/
       {            
            troca(  &vetor[i], &vetor[p_maior] ); /*...troca o atual com o maior */
            p_maior++; /* o maior avança uma posição */
       }    
   }     
   /* percorrido o vetor, o pivô troca de posição com a do maior elemento... */
   troca(  &vetor[p_maior], &vetor[pivo] ); 
   return p_maior; /* ... e o maior elemento passa a ser o novo pivô */ 
}

void troca (float *A, float *B) 
{
  float aux = *A; 
  *A = *B; 
  *B = aux;
}

float abastece_notas (float * notas)
{  
int i;
   for (i=0; i<TAMANHO_VETOR; i++)
      do 
      {
         notas[i] = rand()%100*1.13;
      }
      while (notas[i] > 100);
}	
