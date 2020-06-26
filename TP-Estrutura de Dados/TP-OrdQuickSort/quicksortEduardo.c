//FEITO POR EDUARDO DIAS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

long long int comparacao=0;
long long int movimentacao=0;


//~~~~~~~~~~~~~~~~~QUICK SORT INSERÇÃO 10%~~~~~~~~~~~~~~~~~~

//Obtem a mediana
int obterMedianaInsercao10(int i, int j, int meio){
    int vetorAux[4];

    vetorAux[1]=i;
    vetorAux[2]=meio;
    vetorAux[3]=j;

    InsercaoMediana10(vetorAux, 3);

    return vetorAux[2];

}

//Ordeno um vetor que contem os numeros primeiro/meio/ultimo para obter a mediana
//Foi usado o Inserção para ordenar por ser muito rapido em vetores pequenos
void InsercaoMediana10(int *vetorAux, int n){
    int i, j;
    int x;
    for (i = 2; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
        }
        vetorAux[j+1] = x;
    }
}

//Ordena nos 10%
void Insercao10(int *vetorAux, int n, int primeiroElemento){
    int i, j;
    int x;
    for (i = primeiroElemento+1; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        comparacao++;
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
            comparacao++;
            movimentacao++;
        }
        vetorAux[j+1] = x;
    }
}

//Particiona
void ParticaoInsercao10(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    x = obterMedianaInsercao10(A[*i], A[*j], A[(*i+*j)/2]); /* obtem o pivo x */


    do{
        while (x > A[*i]){
            (*i)++;
            comparacao++;
        }
        comparacao++;
        while (x < A[*j]){
            (*j)--;
            comparacao++;
        }
        comparacao++;
        if (*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
            movimentacao++;
        }
    }while (*i <= *j);
}

void OrdenaInsercao10(int Esq, int Dir, int *A, float auxPorcentagem){
    int i, j;
    ParticaoInsercao10(Esq, Dir, &i, &j, A);
        if (Esq < j){
            if(j-Esq <= auxPorcentagem){
                Insercao10(A, j, Esq);
            }
            else{
                OrdenaInsercao10(Esq, j, A, auxPorcentagem);

            }
        }
        if (i < Dir){
            if(Dir-i <= auxPorcentagem){
                Insercao10(A, Dir, i);
            }
            else{
                OrdenaInsercao10(i, Dir, A, auxPorcentagem);

            }
        }
}

void QuickSortInsercao10(int *A, int n,float auxPorcentagem){
    OrdenaInsercao10(1, n, A, auxPorcentagem);
}

//end~~~~~~~~~~~~~~~~~QUICK SORT INSERÇÃO 10%~~~~~~~~~~~~~~~~~~


//~~~~~~~~~~~~~~~~~QUICK SORT INSERÇÃO 5%~~~~~~~~~~~~~~~~~~

//Obtem a mediana
int obterMedianaInsercao5(int i, int j, int meio){
    int vetorAux[4];

    vetorAux[1]=i;
    vetorAux[2]=meio;
    vetorAux[3]=j;

    InsercaoMediana5(vetorAux, 3);

    return vetorAux[2];

}

//Ordeno um vetor que contem os numeros primeiro/meio/ultimo para obter a mediana
//Foi usado o Inserção para ordenar por ser muito rapido em vetores pequenos
void InsercaoMediana5(int *vetorAux, int n){
    int i, j;
    int x;
    for (i = 2; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
        }
        vetorAux[j+1] = x;
    }
}

//Ordena nos 5%
void Insercao5(int *vetorAux, int n, int primeiroElemento){
    int i, j;
    int x;
    for (i = primeiroElemento+1; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        comparacao++;
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
            comparacao++;
            movimentacao++;
        }
        vetorAux[j+1] = x;
    }
}

//Particiona
void ParticaoInsercao5(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    x = obterMedianaInsercao5(A[*i], A[*j], A[(*i+*j)/2]); /* obtem o pivo x */


    do{
        while (x > A[*i]){
            (*i)++;
            comparacao++;
        }
        comparacao++;
        while (x < A[*j]){
            (*j)--;
            comparacao++;
        }
        comparacao++;
        if (*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
            movimentacao++;
        }
    }while (*i <= *j);
}

void OrdenaInsercao5(int Esq, int Dir, int *A, float auxPorcentagem){
    int i, j;
    ParticaoInsercao5(Esq, Dir, &i, &j, A);
        if (Esq < j){
            if(j-Esq <= auxPorcentagem){
                Insercao5(A, j, Esq);
            }
            else{
                OrdenaInsercao5(Esq, j, A, auxPorcentagem);

            }
        }
        if (i < Dir){
            if(Dir-i <= auxPorcentagem){
                Insercao5(A, Dir, i);
            }
            else{
                OrdenaInsercao5(i, Dir, A, auxPorcentagem);

            }
        }
}

void QuickSortInsercao5(int *A, int n,float auxPorcentagem){
    OrdenaInsercao5(1, n, A, auxPorcentagem);
}




//end~~~~~~~~~~~~~~~~~QUICK SORT INSERÇÃO 5%~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~QUICK SORT INSERÇÃO 1%~~~~~~~~~~~~~~~~~~

//Obtem a mediana
int obterMedianaInsercao1(int i, int j, int meio){
    int vetorAux[4];
    int a, b, temp;

    vetorAux[1]=i;
    vetorAux[2]=meio;
    vetorAux[3]=j;

    InsercaoMediana1(vetorAux, 3);

    return vetorAux[2];

}

//Ordeno um vetor que contem os numeros primeiro/meio/ultimo para obter a mediana
//Foi usado o Inserção para ordenar por ser muito rapido em vetores pequenos
void InsercaoMediana1(int *vetorAux, int n){
    int i, j;
    int x;
    for (i = 2; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
        }
        vetorAux[j+1] = x;
    }
}

//Ordena nos 1%
void Insercao1(int *vetorAux, int n, int primeiroElemento){
    int i, j;
    int x;
    for (i = primeiroElemento+1; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        comparacao++;
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
            comparacao++;
            movimentacao++;
        }
        vetorAux[j+1] = x;
    }
}

//Particiona o Quick Sort no inicio
void ParticaoInsercao1(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    //Obtem a mediana e coloca para o pivo
    x = obterMedianaInsercao1(A[*i], A[*j], A[(*i+*j)/2]); /* obtem o pivo x */


    do{
        while (x > A[*i]){
            (*i)++;
            comparacao++;
        }
        comparacao++;
        while (x < A[*j]){
            (*j)--;
            comparacao++;
        }
        comparacao++;
        if (*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
            movimentacao++;
        }
    }while (*i <= *j);
}

void OrdenaInsercao1(int Esq, int Dir, int *A, float auxPorcentagem){
    int i, j;
    ParticaoInsercao1(Esq, Dir, &i, &j, A);
        if (Esq < j){
            if(j-Esq <= auxPorcentagem){
                Insercao1(A, j, Esq);
            }
            else{
                OrdenaInsercao1(Esq, j, A, auxPorcentagem);

            }
        }
        if (i < Dir){
            if(Dir-i <= auxPorcentagem){
                Insercao1(A, Dir, i);
            }
            else{
                OrdenaInsercao1(i, Dir, A, auxPorcentagem);

            }
        }
}

void QuickSortInsercao1(int *A, int n,float auxPorcentagem){
    OrdenaInsercao1(1, n, A, auxPorcentagem);
}

//end~~~~~~~~~~~~~~~~~QUICK SORT INSERÇÃO 1%~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~QUICK SORT NAO RECURSIVO~~~~~~~~~~~~~~~~~~

typedef struct {
    int dir;
    int esq;
}TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;
typedef struct {
    TipoApontador Fundo, Topo;
    int Tamanho;
}TipoPilha;

void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha){
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipoItem x, TipoPilha *Pilha){
    TipoApontador Aux;
    Aux = (TipoApontador) malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item){
    TipoApontador q;
    if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    free(q);
    Pilha->Tamanho--;
}


void ParticaoNaoRec(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; /* obtem o pivo x */
    do{
        comparacao++;
        while (x > A[*i]){
            (*i)++;
            comparacao++;
        }
        comparacao++;
        while (x < A[*j]){
            (*j)--;
            comparacao++;
        }
        if (*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
            movimentacao++;

        }
    }while (*i <= *j);
}

void QuickSortNaoRec(int  *A, int n){
    TipoPilha pilha;
    TipoItem item; // campos esq e dir
    int esq, dir, i, j;
    FPVazia(&pilha);
    esq = 1;
    dir = n;
    item.dir = dir;
    item.esq = esq;
    Empilha(item, &pilha);
    do{
        if (dir > esq) {
            ParticaoNaoRec(esq,dir,&i, &j,A);
            if ((j-esq)>(dir-i)) {
                item.dir = j;
                item.esq = esq;
                Empilha(item, &pilha);
                esq = i;
            }
            else {
                item.esq = i;
                item.dir = dir;
                Empilha(item, &pilha);
                dir = j;
            }
        }
        else {
            Desempilha(&pilha,&item);
            dir = item.dir;
            esq = item.esq;
        }
    }while (!Vazia(pilha));
}

//end~~~~~~~~~~~~~~~~~QUICK SORT NAO RECURSIVO~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~QUICK SORT PRIMEIRO ELEMENTO~~~~~~~~~~~~~~~~~~
void ParticaoPrimeiroElemento(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    x = A[*i]; /* obtem o pivo x */
    do{
        comparacao++;
        while (x > A[*i]){
            (*i)++;
            comparacao++;
        }
        comparacao++;
        while (x < A[*j]){
            (*j)--;
            comparacao++;
        }
        if (*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
            movimentacao++;
        }
    }while (*i <= *j);
}

void OrdenaPrimeiroElemento(int Esq, int Dir, int *A){
    int i, j;
    ParticaoPrimeiroElemento(Esq, Dir, &i, &j, A);
    if (Esq < j){
        OrdenaPrimeiroElemento(Esq, j, A);
    }
    if (i < Dir){
        OrdenaPrimeiroElemento(i, Dir, A);
    }
}

void QuickSortPrimeiroElemento(int *A, int n){
    OrdenaPrimeiroElemento(1, n, A);
}

//end~~~~~~~~~~~~~~~~~QUICK SORT PRIMEIRO ELEMENTO~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~QUICK SORT MEDIANA~~~~~~~~~~~~~~~~~~

//Obtem a mediana
int obterMediana(int i, int j, int meio){
    int vetorAux[4];

    vetorAux[1]=i;
    vetorAux[2]=meio;
    vetorAux[3]=j;

    InsercaoMediana(vetorAux, 3);
    return vetorAux[2];

}

//Ordeno um vetor que contem os numeros primeiro/meio/ultimo para obter a mediana
//Foi usado o Inserção para ordenar por ser muito rapido em vetores pequenos
void InsercaoMediana(int *vetorAux, int n){
    int i, j;
    int x;
    for (i = 2; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
        }
        vetorAux[j+1] = x;
    }
}

void ParticaoMediana(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    x = obterMediana(A[*i], A[*j], A[(*i+*j)/2]); /* obtem o pivo x */
    do{
        comparacao++;
        while (x > A[*i]){
            (*i)++;
            comparacao++;
        }
        comparacao++;
        while (x < A[*j]){
            (*j)--;
            comparacao++;
        }
        if (*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
            movimentacao++;
        }
    }while (*i <= *j);
}

void OrdenaMediana(int Esq, int Dir, int *A){
    int i, j;
    ParticaoMediana(Esq, Dir, &i, &j, A);
    if (Esq < j){
        OrdenaMediana(Esq, j, A);
    }
    if (i < Dir){
        OrdenaMediana(i, Dir, A);
    }
}

void QuickSortMediana(int *A, int n){
    OrdenaMediana(1, n, A);
}



//end~~~~~~~~~~~~~~~~~QUICK SORT MEDIANA~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~QUICK SORT CLASSICO~~~~~~~~~~~~~~~~~~
void ParticaoClassico(int Esq, int Dir, int *i, int *j, int *A){
    int x, w;
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; /* obtem o pivo x */
    do{
        comparacao++;
        while (x > A[*i]){
            (*i)++;
            comparacao++;
        }
        comparacao++;
        while (x < A[*j]){
            (*j)--;
            comparacao++;
        }

        if (*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
            movimentacao++;

        }
    }while (*i <= *j);
}

void OrdenaClassico(int Esq, int Dir, int *A){
    int i, j;
    ParticaoClassico(Esq, Dir, &i, &j, A);

    if (Esq < j){
        OrdenaClassico(Esq, j, A);
    }

    if (i < Dir){
        OrdenaClassico(i, Dir, A);
    }
}

void QuickSortClassico(int *A, int n){
    OrdenaClassico(1, n, A);
}
//end~~~~~~~~~~~~~~~~~QUICK SORT CLASSICO~~~~~~~~~~~~~~~~~~

//OBTEM MEDIANA DO TEMPO

void InsercaoTempo(float *vetorAux, int n){
    int i, j;
    int x;
    for (i = 2; i <= n; i++){
        x = vetorAux[i];
        j = i - 1;
        vetorAux[0] = x;  /* sentinela */
        while (x < vetorAux[j]){
            vetorAux[j+1] = vetorAux[j];
            j--;
        }
        vetorAux[j+1] = x;
    }
}

//END OBTEM MEDIANA DO TMEPO

//PREENCHE O ARQUIVO

void preencher_arquivo(char *nomearquivo, char *variacao, char *tipo, int tamanho, int comparacao, int movimentacao, float tempoexecucao){

    FILE *arq;


    arq = fopen(nomearquivo, "w");
        if(arq == NULL)
            printf("Erro, nao foi possivel abrir o arquivo\n");
        else{
                fprintf(arq, "%s", variacao);
                fprintf(arq, "%s", tipo);
                fprintf(arq, "%d", tamanho);
                fprintf(arq, "%d", comparacao);
                fprintf(arq, "%d", movimentacao);
                fprintf(arq, "%.2f", tempoexecucao);

            }
            fclose(arq);


}

void preencher_arquivo_vetor(char *nomearquivo, int *vetorA, int tamanho){

    FILE *arq;
    int i;

    arq = fopen(nomearquivo, "w");
        if(arq == NULL)
            printf("Erro, nao foi possivel abrir o arquivo\n");
        else{
            for(i=0; i<tamanho; i++){
                fprintf(arq, "%d", vetorA[i]);
            }
            fprintf(arq, "\n");
        }
        fclose(arq);
}

//END PREENCHER ARQUIVO

void main(int argc, char *argv[]){
    //Vetor Crescente ou Decrescente ou Aleatorio
    srand(time(0));
    int *vetorA;
    int i;

    char variacao[10]; //variacao do quicksort
    char tipo[10]; //tipo
    int n,tamanho;   //tamanho
    float auxPorcentagem=0; //Porcentagem para ser usada nos quick sort 1% 5% 10%
    int contadorteste=0; //auxilia os 20 testes do vetor

    int habilitaVetor=0;
    int habilitaArquivo=0;
    int habilitaCriarArquivo=0;
    char nomeArquivo[20];

    for(i=0; i<argc; i++){
        if(i==1){
            strcpy(variacao,argv[i]);
        }
        if(i==2){
            strcpy( tipo,argv[i]);
        }
        if(i==3){
            n=atoi(argv[i]);
        }
        if(i==4){
            if(strncmp(argv[4],"-p", 2)==0){
                habilitaVetor=1;
            }
            if(strncmp(argv[4],">", 1)==0){
                habilitaArquivo=1;
            }
        }
        if(i==5){
            habilitaCriarArquivo=1;
            strcpy(nomeArquivo,argv[5]);
        }

        if(i==6){
            if(strncmp(argv[6],"-p", 2)==0){
                habilitaVetor=1;
            }
        }
    }



    char salvarTipo[10];   //sem uso
    char salvarVariacao[10]; //sem uso
    strcpy(salvarTipo, tipo); //sem uso
    strcpy(salvarVariacao, variacao); //sem uso

    tamanho=n+1;

    long long int totalComparacao, totalMovimentacao;
    totalComparacao=0;
    totalMovimentacao=0;

    float time_spent=0.0; //timer
    float vetorTimer[21]; //Contem todos os tempos para pegar a mediana

    //TAMANHO tem que ser 1 a mais pois nao se usa a posiçao 0 para ordenar
    vetorA=malloc (tamanho * sizeof (int));

    //Testa 20 vezes
    for(contadorteste=0; contadorteste<20; contadorteste++){
        comparacao=0;
        movimentacao=0;



        if(strncmp(tipo,"Ale",3)==0){
            for(i=1; i<tamanho; i++){
                vetorA[i]=rand()%tamanho;
            }
        }

        if(strncmp(tipo,"OrdC",4)==0){
            for(i=1; i<tamanho; i++){
                vetorA[i]=i;
            }
        }

        int aux=1;
        if(strncmp(tipo,"OrdD",4)==0){
            for(i=n; i>0; i--){
                vetorA[aux]=i;
                aux++;
            }
        }

        if(habilitaVetor==1){
           for(i=1; i<n+1; i++){
                printf("%d ",vetorA[i]);
            }
            printf("\n\n");
            if(habilitaArquivo==1 && habilitaCriarArquivo==1){
                preencher_arquivo_vetor(nomeArquivo,vetorA,n+1);
            }
        }


        //INICIA O TIMER

        clock_t begin=clock();


        //QUICK SORT CLASSICO
        if(strncmp(variacao,"QC",2)==0){
            QuickSortClassico(vetorA, n);
        }
        //QUICK SORT MEDIANA
        if(strncmp(variacao,"QM3",3)==0){
            QuickSortMediana(vetorA,n);
        }
        //QUICK SORT PRIMEIRO ELEMENTO
        if(strncmp(variacao,"QPE",3)==0){
            QuickSortPrimeiroElemento(vetorA,n);
        }
        //QUICK SORT NAO RECURSIVO
        if(strncmp(variacao,"QNR",3)==0){
            QuickSortNaoRec(vetorA, n);
        }
        //QUICK SORT INSERÇÃO 1%
        if(strncmp(variacao,"QI1P",4)==0){

            auxPorcentagem=n-1;
            auxPorcentagem=auxPorcentagem*0.01;
            QuickSortInsercao1(vetorA,n,auxPorcentagem);
        }

        //QUICK SORT INSERÇÃO 5%
        if(strncmp(variacao,"QI5P",4)==0){

            auxPorcentagem=n-1;
            auxPorcentagem=auxPorcentagem*0.05;
            QuickSortInsercao5(vetorA,n,auxPorcentagem);
        }

        //QUICK SORT INSERÇÃO 5%
        if(strncmp(variacao,"QI10P",5)==0){

            auxPorcentagem=n-1;
            auxPorcentagem=auxPorcentagem*0.10;
            QuickSortInsercao10(vetorA,n,auxPorcentagem);
        }

        //END TIMER
        clock_t end = clock();

        //COLOCA O TEMPO DE EXECUCAO NUMA VARIAVEL
        time_spent= (float)(end-begin)/CLOCKS_PER_SEC;
        time_spent=time_spent*1000000;


        totalComparacao=totalComparacao+comparacao;
        totalMovimentacao=totalMovimentacao+movimentacao;
        //PREENCHE O TEMPO DE EXECUCAO EM UM VETOR PARA PEGAR A MEDIANA
        vetorTimer[contadorteste+1]=time_spent;
        //printf("\n%f", time_spent);
    }
    totalComparacao=totalComparacao/20;
    totalMovimentacao=totalMovimentacao/20;

    //Ordena para pegar a mediana do tempo
    InsercaoTempo(vetorTimer, 21);


    //Preenche o arquivo se as condicoes forem verdadeiras
    if(habilitaArquivo==1 && habilitaCriarArquivo==1){
        preencher_arquivo(nomeArquivo, variacao, tipo, n, totalComparacao, totalMovimentacao, vetorTimer[12]);
    }

    //Printa na tela somente se nao escrever no arquivo, do contrario a saida constara no arquivo
    printf("%s ", variacao);
    printf("%s ", tipo);
    printf("%d ", n);
    printf("%d ", totalComparacao);
    printf("%d ", totalMovimentacao);
    printf("%.2f ", vetorTimer[12]);

    free(vetorA);

}
