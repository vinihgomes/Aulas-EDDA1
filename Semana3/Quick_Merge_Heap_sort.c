#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
// DECLARA��O DE FUN��ES GLOBAIS :D
float abastece_notas(float * notas);
float merge_sort(float * notas, int inicio, int fim);
float heap_sort(float * notas);
void quick_sort(float * notas, int ini, int fim);
void troca (float *A, float *B); 


// Var�aveis globais (s� pra facilitar a passagem de par�metros)
int TAMANHO_VETOR, inicio = 0, fim;

// C�digo MAIN - Pergunta quantas notas ser�o recebidas, chama fun��o para preencher com valores aleat�rios e pergunta qual m�todo de ordena��o deseja realizar.
int main(){
	int opc, i;
	float *notas;
	setlocale (LC_ALL, "Portuguese"); 								

	printf("Informe quantas notas deseja alocar: \n");
	scanf("%d", &TAMANHO_VETOR);
	notas = (float *) malloc (TAMANHO_VETOR * sizeof(float));

	abastece_notas(notas);
	
	for (i = 0; i < TAMANHO_VETOR ; i++)								
	{
		printf("\nPosi��o alocada %d: %.2f", i+1, notas[i]);	
	}
	fim = TAMANHO_VETOR;
		
	printf("\nPronto, iremos para a pr�xima etapa! Aperte qualquer tecla para continuar:");
	getch();
	system("cls");
	printf("Informe qual m�todo de ordena��o deseja utilizar: \n");
	printf("1 - Merge sort\n");
	printf("2 - Heap sort\n");
	printf("3 - Quick sort\n");
	scanf("%d", &opc);
	
	switch(opc){
		case 1: 
			merge_sort(notas, inicio, fim);
			for (i = 1; i <= TAMANHO_VETOR ; i++)								
			{
				printf("\nOrdenado por Merge Sort: Posi��o %i: \t %.2f\n", i, notas[i]);	
			}
		break;
		case 2: 
			heap_sort(notas);
			for (i = 0; i < TAMANHO_VETOR ; i++)								
			{
				printf("\nOrdenado por Heap Sort: Posi��o %i: \t %.2f\n", i+1, notas[i]);	
			}
		break;
		case 3: 
			quick_sort(notas, inicio, fim);
			for (i = 1; i <= TAMANHO_VETOR ; i++)								
			{
				printf("\nOrdenado por Quick Sort: Posi��o %i: \t %.2f\n", i, notas[i]);	
			}
		break;
		default: printf("\nOp��o inv�lida");
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////	OK	OK	OK	OK	OK	OK	OK	OK	OK			


// Ordena��o atrav�s de Merge Sort - Fun��o recursiva, chama a ela mesma e tamb�m a fun��o auxiliar MERGE
float merge_sort (float * notas, int inicio, int fim) 
{
	float merge(float * notas, int inicio, int meio, int fim);		
	int  meio;
	if ( inicio < fim )
	{
	    meio = (inicio + fim) / 2;        /*calcula o meio                        */
	    merge_sort (notas, inicio, meio); /*ordena o subvetor esquerdo            */
	    merge_sort (notas, meio+1, fim ); /*ordena o subvetor direito             */
	    merge (notas, inicio, meio, fim); /*funde os subvetores esquerdo e direito*/
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////	OK	OK	OK	OK	OK	OK	OK	OK	OK			

// Fun��o merge, auxiliar do merge sort  
float merge (float * vetor, int inicio, int meio, int fim)
{
  int tamEsq, tamDir, i, idxEsq, idxDir;
  float *vetor_Esq;
  float *vetor_Dir;
  tamEsq = meio - inicio + 1; /* tamanho do subvetor esquerdo */
  tamDir = fim  - meio;       /* tamanho do subvetor direito  */	
  /* Tenta alocar tamEsq posi��es para abastecer o subvetor esquerdo */   
  vetor_Esq = (float *) malloc (tamEsq * sizeof (float)); 
  if (vetor_Esq == NULL)
  { printf ("malloc devolveu NULL!\n");
    getch();
    exit (EXIT_FAILURE);
  }        
  /* Tenta alocar tamDir posi��es para abastecer o subvetor direito */   
  vetor_Dir = (float *) malloc (tamDir * sizeof (float)); 
  if (vetor_Dir == NULL)
  { printf ("malloc devolveu NULL!\n");
    getch();
    exit (EXIT_FAILURE);
  }   
  for (i=0; i<tamEsq; i++)          /* inicializar vetor_Esq */
    vetor_Esq[i] = vetor[inicio+i]; /* elementos do subvetor esquerdo */
  for (i=0; i<tamDir; i++)          /* inicializar vetor_Dir */
    vetor_Dir[i] = vetor[meio+1+i]; /* elementos do subvetor direito */
  idxEsq = 0; /* �ndice do subvetor auxiliar esquerdo */
  idxDir = 0; /* �ndice do subvetor auxiliar direito  */
  for ( i=inicio; i<=fim; i++ )     /* intercala os vetores */
    if (idxEsq < tamEsq)
       if (idxDir < tamDir)
          if (vetor_Esq[idxEsq] < vetor_Dir[idxDir])
            vetor[i] = vetor_Esq[idxEsq++];
          else
	 vetor[i] = vetor_Dir[idxDir++];
       else
          vetor[i] = vetor_Esq[idxEsq++];
    else
       vetor[i] = vetor_Dir[idxDir++];   
}
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////	OK	OK	OK	OK	OK	OK	OK	OK	OK			
 

// M�todo de ordena��o atrav�s de Heap sort, cria um vetor onde remove o valor pai (maior) e ap�s isso � chamada as fun��es auxiliares
float heap_sort(float * notas){
	int esquerdo(int i) ;
	int direito(int i); 
	int pai(int i); 
	void BuildHeap(float *notas);

  
    int i, atual;
	
	BuildHeap(notas);

    for(i=TAMANHO_VETOR-1; i>0; i--)   /* percorre da �ltima at� a pen�ltima posi��o do vetor */	
    {   /* (se todas as posi��es at� a pen�ltima estiverem ordenadas, a �ltima tamb�m estar�) */
        troca(  &notas[0], &notas[i]  );       /* troca a posi��o corrente do heap com a raiz */
        
        /* i n�o pertence mais ao vetor */
        /* (o vetor vai diminuindo de tamanho, pois a �ltima posi��o CERTAMENTE ter� o maior valor) */
        
        /* ajusta o heap */
        atual = 0;
        while ( direito(atual) <= (i-1)                                       /* Enquanto tiver 2 filhos                                  */
                &&                                                                       /* E                                                                    */
	( notas[atual] < notas[esquerdo(atual)] ||     /* o pai for menor que um dos dois filhos...     */
                 notas[atual] < notas[direito(atual)] ) )
        {   /*...troca o pai com o maior dos filhos */
            if ( notas[esquerdo(atual)] > notas[direito(atual)] )
            {
               troca(  &notas[atual], &notas[esquerdo(atual)]  ); /*troca o atual com o filho esquerdo*/
               atual = esquerdo(atual);
            } 
            else 
            {
                troca(  &notas[atual], &notas[direito(atual)]  ); /*troca o atual com o filho direito*/
                atual = direito(atual);
            }
        }
        /* Verificar se sobrou um filho (esquerdo) maior que o atual */
        if ( esquerdo(atual) <= i-1 && notas[atual] < notas[esquerdo(atual)] )
        {
            troca(  &notas[atual], &notas[esquerdo(atual)]  ); /*troca o atual com o filho esquerdo*/
            atual = esquerdo(atual);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////	OK	OK	OK	OK	OK	OK	OK	OK	OK


// Fun��o auxiliar de Heap Sort.			
int esquerdo(int i) 
{
  return (2*i+1);
}

// Fun��o auxiliar de Heap Sort.			
int direito(int i) 
{
  return (2*i+2);
}

// Fun��o auxiliar de Heap Sort.			
int pai(int i) 
{
  return ( (i-1)/2 );
}

//  Constr�i um heap de m�ximo (desce desde a posi��o 1 at� os elementos que n�o s�o folhas).  Rearranja um vetor[1..TAMANHO_VETOR] de modo a transform�-lo em heap.
void BuildHeap(float *vetor)
{
   int i, atual;
   /* percorre todo o vetor a partir do segundo elemento    */
   /* pois o primeiro � a raiz do heap e antes dele nada  h�*/
   for(i=1; i<TAMANHO_VETOR; i++) 
   {
      atual = i;
      /* enquanto o atual for maior que o pai...*/
      while(atual > 0 && vetor[atual] > vetor[pai(atual)]) 
      {
           /*...troca o atual com o pai... */
           troca(  &vetor[atual], &vetor[pai(atual)] ); 
           /*...e o atual passa a ser o pai */
           atual = pai(atual); 
      }
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////	OK	OK	OK	OK	OK	OK	OK	OK	OK

//Fun��o de ordena��o Quick Sort
void quick_sort	(float * notas, int inicio, int fim) 
{   
	int particiona (float * notas, int ini, int pivo); 
   	int pivo;
   	if ( inicio < fim ) /* Caso base */ 
   	{        
        pivo = particiona ( notas, inicio, fim ); /* Particiona o vetor*/ 
        quick_sort( notas, inicio,    pivo-1 );    /* Ordena do in�cio do vetor at� antes do piv� */
        quick_sort( notas, pivo+1, fim);      /* Ordena desde ap�s o piv� at� o fim do vetor */
   	} 
}
	
//Fun��o auxiliar quick sort
int particiona (float * vetor, int inicio, int pivo) 
{    
    int   i;
    int   p_maior = inicio; /* a posi��o do maior � a do in�cio do vetor */    
    
    for ( i=inicio; i<pivo; i++ ) /* percorre o vetor da posi��o ini at� a do piv� */
    {        
       if ( vetor[i] < vetor[pivo] ) /*se o elemento da posi��o atual for menor que o piv�...*/
       {            
            troca(  &vetor[i], &vetor[p_maior] ); /*...troca o atual com o maior */
            p_maior++; /* o maior avan�a uma posi��o */
       }    
   }     
   /* percorrido o vetor, o piv� troca de posi��o com a do maior elemento... */
   troca(  &vetor[p_maior], &vetor[pivo] ); 
   return p_maior; /* ... e o maior elemento passa a ser o novo piv� */ 
}



// Fun��o auxiliar de Heap sort e merge sort
void troca (float *A, float *B) 
{
  float aux = *A; 
  *A = *B; 
  *B = aux;
}


// Fun��o para gerar n�meros aleat�rios para o vetor notas. Os valores ap�s o % podem ser alterados para obter n�meros de acordo com seus crit�rios
float abastece_notas (float * notas)
{  
int i;
   for (i=0; i<TAMANHO_VETOR; i++)
      do 
      {
         notas[i] = rand()%10*1.13;
      }
      while (notas[i] > 10);
}	
