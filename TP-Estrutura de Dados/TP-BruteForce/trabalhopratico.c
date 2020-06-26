//Eduardo de Paiva Dias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ========================================================================= */
//estrutura de lista encadeada
typedef struct {
    //espaco de permutacao
    int indice;
    //soma dos valores
    int valor_permutacao;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct{
    TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

//Funcoes de lista
//faz lista vazia
void FLVazia(TipoLista *Lista){
    Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}
//verifica se lista esta vazia
int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

//insere na lista
void Insere(TipoItem x, TipoLista *Lista){
    Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = x;
    Lista -> Ultimo -> Prox = NULL;
}

//imprime o conteudo da lista
void Imprime(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Primeiro -> Prox;
    while (Aux != NULL){
        printf("%d ", Aux -> Item.indice);
        printf("%d\n", Aux -> Item.valor_permutacao);
        Aux = Aux -> Prox;
    }
}

/* ========================================================================= */


//bruteforce
void gerarPermutacao(int *entrada, int tamanho, int qtdElementos, TipoLista *lista){
    //vetor de posicao
    int *controle;
    int *aux;
    int n, i, j, k, y ;
    int soma=0;
    TipoItem itemaux;

    //vetor aux que contem os valores a ser permutados pelo espaço
    aux = (int *) calloc( (tamanho+1), sizeof(int)) ;

    n = qtdElementos;

    controle = (int *) calloc( (tamanho+1), sizeof(int)) ;

    while ( controle[tamanho] == 0 ) {
        for ( j = 0; j < tamanho; j++ ) {
            //da a posicao para entrada que atribui para aux
            aux[j] = entrada[controle[j]] ;
        }
        //soma os valores do vetor
        for(y=0; y<tamanho; y++){
            soma=soma+aux[y];
            //printf("%d ", aux[y]);
        }
        //printf("\n");
        //verifica se o valor e valido para ser colocado na lista
        if(soma>0 && verificaIguais(*lista, soma)!=1){
            itemaux.valor_permutacao=soma;
            itemaux.indice=tamanho;
            Insere(itemaux, &(*lista));
        }

        soma=0;
        controle[0]++ ;
        //serve como um controle para permutar todas os possiveis valores
        for (i = 0; i < tamanho; i++ ) {
            if ( controle[i] == n ) {
                controle[i] = 0 ;
                controle[i+1]++ ;
            }
        }
    }
    free(controle);
    free(aux);
}

//Verifica se um valor de soma é igual a outro, é igual o de baixo (poderia usar a mesma função)
int verificaResposta(TipoLista lista, int acharentrada){
    TipoApontador Aux;
    Aux = lista.Primeiro->Prox;
    while (Aux != NULL){
        if((Aux->Item.valor_permutacao ) == acharentrada){
            return 1;
        }
        Aux = Aux -> Prox;
    }
    return 0;
}

//Verifica se um valor de soma é igual a outro, é igual o de cima (poderia usar a mesma função)
int verificaIguais(TipoLista lista, int soma){
    TipoApontador Aux;
    Aux = lista.Primeiro->Prox;
    while (Aux != NULL){
        if((Aux->Item.valor_permutacao ) == soma){
            return 1;
        }
        Aux = Aux -> Prox;
    }
    return 0;
}

//remove um recipiente e como é um vetor puxa todos seus sucessores para trás
void removerRecipiente(int *recipiente, int entradanumero, int qtdrecipiente){
    int i;
    int aux;
    //acha o que é igual
    for(i=0; i<qtdrecipiente; i++){
        if(recipiente[i]==entradanumero){
            aux=i;
        }
    }
    //puxa pra tras
    for(i=aux; i<qtdrecipiente; i++){
        recipiente[i]=recipiente[i+1];
    }
    //faz o mesmo com negativo
    for(i=0; i<qtdrecipiente; i++){
        if(recipiente[i]==(-1*entradanumero)){
            aux=i;
        }
    }
    for(i=aux; i<qtdrecipiente; i++){
        recipiente[i]=recipiente[i+1];
    }
}

//permuta e logo depois verifica se existe a resposta
int validarpermutacao(TipoLista *lista, int *recipiente, int qtdrecipiente, int acharentrada){
    int i;
    int achar=0;
    for(i=1; achar!=1; i++){
        gerarPermutacao(recipiente, i, qtdrecipiente, &(*lista));
        achar=verificaResposta(*lista, acharentrada);
        //Imprime(*lista);
    }
    return i-1;
}

//So tenta retirar um recipiente se ele existe
int verificaSeRecipienteExisteParaRetirar(int *recipiente, int entradanumero, int qtdrecipiente){
    int i;
    for(i=0; i<qtdrecipiente; i++){
        if(entradanumero==recipiente[i]){
            return 1;
        }
    }
    return 0;
}


void main(){

    int entradanumero=5;
    char entradachar='a';
    int *recipiente;
    int qtdrecipiente=0;
    int resposta=0;
    //Cria a lista para guardar a permutaçao e com quantos espacos ela foi feita
    TipoLista lista;
    FLVazia(&lista);

    //cria vetor dinamico para recipientes/potes
    recipiente = (int *)malloc(0*sizeof(int));

    //continua digitando ate EOF
    while(scanf("%d %c", &entradanumero, &entradachar)!= EOF ){
        if(entradachar=='i'){
            //so aceita potes maiores que 0
            if(entradanumero>0){
                //preenche recipientes com seu positivo e negativo
                //nao consegui colocar realloc em uma funcao pois da muito erro
                qtdrecipiente++;
                recipiente =(int *)realloc( recipiente, qtdrecipiente*sizeof(int)) ;
                recipiente[qtdrecipiente-1]=entradanumero;
                qtdrecipiente++;
                recipiente = (int *)realloc( recipiente, qtdrecipiente*sizeof(int)) ;
                recipiente[qtdrecipiente-1]=-entradanumero;
            }
        }
        if(entradachar=='p'){
            if(qtdrecipiente>0){ //verifica se recipiente existe para medir
                //so pode medir coisas positivas
                if(entradanumero>0){
                    //permuta e procura se acha a resposta
                    resposta=validarpermutacao(&lista, recipiente, qtdrecipiente, entradanumero);
                    printf("%d", resposta);
                    FLVazia(&lista);
                }
            }
        }
        if(entradachar=='r'){
            //remove recipiente e seu negativo
            //nao consegui colocar realloc em uma funcao
            if(verificaSeRecipienteExisteParaRetirar(recipiente, entradanumero, qtdrecipiente)==1){
                removerRecipiente(recipiente, entradanumero, qtdrecipiente);
                qtdrecipiente=qtdrecipiente-2;
                recipiente =(int *)realloc( recipiente, qtdrecipiente*sizeof(int)) ;
            }
        }
    }

    free(recipiente);
}
