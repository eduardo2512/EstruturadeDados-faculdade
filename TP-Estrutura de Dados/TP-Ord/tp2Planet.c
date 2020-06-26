//EDUARDO DE PAIVA DIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCT DE ITEM/PLANETA
typedef struct TipoItem {
    int indice; //mes
    char cadeiachar[18]; //nome caracter
    int valor_tempo; //tempo
}TipoItem;

//Implementacao Luiz e Raquel
void merge(TipoItem vetor[], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 =  fim - meio;

    //Arrays auxiliares
    TipoItem *inicioAux;
    TipoItem *fimAux;
    inicioAux = (TipoItem*)malloc((n1) * sizeof(TipoItem));
    fimAux = (TipoItem*)malloc((n2) * sizeof(TipoItem));

    //Copia vetor para os auxiliares
    for (i = 0; i < n1; i++)
        inicioAux[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        fimAux[j] = vetor[meio + 1+ j];

    //Merge
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2){
        if (inicioAux[i].valor_tempo <= fimAux[j].valor_tempo){
            vetor[k] = inicioAux[i];
            i++;
        }
        else{
            vetor[k] = fimAux[j];
            j++;
        }
        k++;
    }

    //Copia os elementos de inicioAux remanescentes
    while (i < n1){
        vetor[k] = inicioAux[i];
        i++;
        k++;
    }

    //Copia os elementos de fimAux remanescentes
    while (j < n2){
        vetor[k] = fimAux[j];
        j++;
        k++;
    }
    free(inicioAux);
    free(fimAux);
    //Libera Memoria
}

//MergeSort
void mergeSort(TipoItem vetor[], int inicio, int fim){
    if (inicio < fim)
    {
        int meio = inicio+(fim-inicio)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void alterar_indice(TipoItem vetor[], int qtdelementos, int horastotais){
    int i, j;
    int soma=0, soma2=0;
    int posicaoinicial=0;
    int indiceinicial=1;
    for(i=0; i<qtdelementos; i++){
        //SOMA OS ELEMENTOS
        soma=soma+vetor[i].valor_tempo;
        //CONFERE SE A SOMA ESTOROU
        if(soma>=horastotais){
            //SE A SOMA FOR IGUAL AO HORAS TOTAIS ELE MUDA SEU INDICE
            if(soma==horastotais){
                for(j=posicaoinicial; j<=i; j++){
                    vetor[j].indice=indiceinicial;
                }
            posicaoinicial=i+1;
            soma=0;
            indiceinicial=indiceinicial+1;
            }
            //SE A SOMA PASSAR HORAS TOTAIS ELE MUDA O INDICE ATE A ANTERIOR
            else{
                soma2 = 0;
                for(j=posicaoinicial; j<=i-1 ; j++){
                    soma2+=vetor[j].valor_tempo;
                    if(soma2<=horastotais){
                        vetor[j].indice=indiceinicial;
                    }
                }
                posicaoinicial=i;
                soma=vetor[i].valor_tempo;
                indiceinicial=indiceinicial+1;
            }
        }
    }
    //ELEMENTOS QUE NAO TIVEREM SEU INDICE NA ULTIMA CHAMADA EH MUDADO AQUI
    for(j=posicaoinicial; j<qtdelementos; j++){
        if(vetor[j].indice==0){
            vetor[j].indice=indiceinicial;
        }
    }
}


//Implementacao Nivio Ziviani
void ContagemChar(TipoItem *vetor, int n, int k){
    int i, j;
    int vetAsc[256];
    TipoItem *vetorAux;
    vetorAux = (TipoItem*)malloc((n+1) * sizeof(TipoItem));

    //PRRENCHE VETOR ASCII COM 0
    for ( i = 0; i <= 256 - 1; i++){
        vetAsc[i] = 0;
    }
    //CONTA QUANTIDADE DE CARACTERES
    for ( i = 1; i <= n; i++){
        j = (int) vetor[i].cadeiachar[k];
        vetAsc[j] = vetAsc[j] + 1;
    }
    for (i = 1; i <= 256 - 1; i++){
        vetAsc[i] = vetAsc[i] + vetAsc[i-1];
    }
    //PREENCHE O VETOR AUX
    for (i = n; i > 0; i--){
        j = (int) vetor[i].cadeiachar[k];
        vetorAux[vetAsc[j]] = vetor[i];
        vetAsc[j] = vetAsc[j] - 1;
    }
    //PASSA DE AUX PRO VETOR ORIGINAL
    for (i = 1; i <= n; i++){
        vetor[i] = vetorAux[i];
    }
    free(vetorAux);
}

void Radixsort(TipoItem *A, int n, int TamString){
    int i;
    //CADA REPETICAO E UM CARACTER DO VETOR
    for (i = TamString - 1; i >= 0; i--)
        ContagemChar (A, n, i);
}


int totalElementosporIndice(TipoItem vetor[], int qtdElementos, int indiceTotal){
    int i;
    int auxTotal=0;
    //CONTA A QUANTIDADE DE CARACTERES NESSE INDICE
    for(i=0; i<qtdElementos; i++){
        if(indiceTotal == vetor[i].indice){
            auxTotal++;
        }
    }
    return auxTotal;
}


void ordenarPorIndice(TipoItem vetor[], int qtdElementos, int qtdcaracter){
    int i, j;
    int indiceTotal=vetor[qtdElementos-1].indice;
    TipoItem *vetorAux;
    int posicaoInicial, PosicaoFinal, y, elementosIndice;
    posicaoInicial=0;
    PosicaoFinal=0;
    elementosIndice=0;

    //CRIA UM VETOR AUXILIAR
    vetorAux = (TipoItem*)malloc((qtdElementos+1) * sizeof(TipoItem));


    //Ordena por indice
    for(i=1; i<=indiceTotal; i++){

        PosicaoFinal=PosicaoFinal + totalElementosporIndice(vetor, qtdElementos, i);
        for(j=posicaoInicial, y=1; j<PosicaoFinal; j++, y++){
            //PASSA ELEMENTOS DE CERTO INDICE PRO VETOR AUXILIAR
            vetorAux[y]=vetor[j];
            elementosIndice++;
        }
        //ORDENA POR CARACTER ESSE VETOR AUXILIAR
        Radixsort(vetorAux, elementosIndice, (qtdcaracter+1));
        for(j=posicaoInicial, y=1; j<PosicaoFinal; j++, y++){
            //COLOCA NO VETOR ORIGINAL
            vetor[j]=vetorAux[y];
        }
        posicaoInicial=PosicaoFinal;
        elementosIndice=0;

    }
}

//IMPRIME
void Imprime(TipoItem vetor[], int qtdElementos){
    int i;
    for(i=0; i<qtdElementos; i++){
        printf("%d ", vetor[i].indice);
        printf("%s ", vetor[i].cadeiachar);
        printf("%d ", vetor[i].valor_tempo);
        printf("\n");
    }
}

void main(){
    TipoItem *vetor;
    int i, j;
    int horastotais, qtdelementos, qtdcaracter;

    //LE AS HORAS TOTAIS/ QUANTIDADE DE ELEMENTOS / QUANTIDADE DE CARACTER
    scanf("%d%d%d", &horastotais, &qtdelementos, &qtdcaracter);

    //CRIA UM VETOR DINAMICO DE ITEM
    vetor = (TipoItem*)malloc((qtdelementos+1) * sizeof(TipoItem));

    //PREENCHE O VALOR DE TEMPO E DE CARACETERES/NOME
    for(i=0; i<qtdelementos; i++){
        scanf("%d%s", &vetor[i].valor_tempo, vetor[i].cadeiachar);
        vetor[i].indice=0;
    }

    //CHAMA MERGE
    mergeSort(vetor,0,qtdelementos-1);
    //CHAMA ALTERAR INDICE/MES
    alterar_indice(vetor, qtdelementos, horastotais);
    //ORDENA O VETOR EM INDICES PELOS CARACTERES
    ordenarPorIndice(vetor,qtdelementos,qtdcaracter);
    //IMPRIME NA TELA
    Imprime(vetor, qtdelementos);
    free(vetor);

}
