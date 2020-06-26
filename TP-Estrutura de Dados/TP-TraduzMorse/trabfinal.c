//FEITO POR EDUARDO DIAS
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <string.h>

//Estrutura de Arvore
typedef struct TipoRegistro {
  char Chave;
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;
typedef TipoApontador TipoDicionario;

//Estrutura que guarda o a correspondencia da letra em morse
typedef struct GuardaMorse{
    char letra;
    char morse[10];
}GuardaMorse;

//Estrutura que guarda o codigo morse inteiro
typedef struct GuardaFraseMorse{
    char frase[1000];
}GuardaFraseMorse;

//Estrutura que guarda cada frase codificada
typedef struct GuardaFrase{
    char frase[1000];
}GuardaFrase;

//Inicializa a arvore
void Inicializa(TipoApontador *Dicionario){
    *Dicionario = NULL;
}
//Prenche a arvore com as letras apartir dos . e - usando recursividade
void preenche_arvore(TipoApontador *p, char *morse, char letra, int i, int max){
    if(morse[i]=='.'){
        //Se completar o ultimo . ou - da letra ele volta
        if(i>=max){
            TipoRegistro x;
            x.Chave=letra;
			Insere(x, &(*p)->Esq);
            return;
		}
	i=i+1;
	return preenche_arvore(&(*p)->Esq, morse, letra, i, max);
	}
	if(morse[i]=='-'){
        //Se completar o ultimo . ou - da letra ele volta
		if(i>=max){
            TipoRegistro x;
            x.Chave=letra;
			Insere(x, &(*p)->Dir);
			return;
		}
	i=i+1;
	return preenche_arvore(&(*p)->Dir, morse, letra, i, max);
	}

}

//Le o arquivo txt que contem os caracteres e o morse correspondente
int readFile(GuardaMorse *GuardaMorse){
    int cont=0;
    FILE *fp;
    int tam;
    fp = fopen("morse.txt","r");
    if(!fp){
        printf("Erro na abertura do arquivo");
        return;
    }
    while(!feof(fp)){
         fscanf(fp,"%c", &GuardaMorse[cont].letra);
         fscanf(fp," %s\n",GuardaMorse[cont].morse);
         cont++;
    }
    //fecha arquivo
    fclose(fp);
    return cont;
}

//Busca a letra correspondente apartir de ler a entrada
char BuscaLetra(char *morse, TipoApontador *p, int i, int max){

    //se tiver / ele da espaço
    if(morse[i]=='/'){
        return ' ';
    }
    if(morse[i]=='.'){
        if(i>=max){
            return ((*p)->Esq->Reg.Chave);
        }
        i=i+1;
        return BuscaLetra(morse, &(*p)->Esq, i, max);

    }
    if(morse[i]=='-'){
        if(i>=max){
            return ((*p)->Dir->Reg.Chave);
        }
        i=i+1;
        return BuscaLetra(morse, &(*p)->Dir, i, max);
    }
}

//Printa a arvore em pre ordem
void preOrdem(TipoApontador no, int tamanho, GuardaMorse *GuardaMorse){
    if (no != NULL) {
        if(no->Reg.Chave!='}'){
            printf("%c ",no->Reg.Chave);
            procuraCaracter(tamanho, GuardaMorse, no->Reg.Chave);
            printf("\n");
        }
        preOrdem(no->Esq, tamanho, GuardaMorse);
        preOrdem(no->Dir, tamanho, GuardaMorse);

    }
}

//Procura e printa os . e - da arvore para printar a arvore em pre ordem
void procuraCaracter(int tamanho, GuardaMorse *GuardaMorse, char letra){
    int i;
    for(i=0; i<tamanho; i++){
        if(letra==GuardaMorse[i].letra){
            printf("%s", GuardaMorse[i].morse);
        }
    }
}

//Insere na arvore as letras
void Insere(TipoRegistro x, TipoApontador *p){
    if (*p == NULL){
        *p = (TipoApontador)malloc(sizeof(TipoNo));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
}

//Le o arquivo morse.txt e preenche a arvore
int ler_arquivo_preencher_arvore(TipoApontador *p, GuardaMorse *GuardaMorse){
    //Insere a raiz o "}" é como se fosse um espaço vazio
    TipoRegistro x;
    int tamanho1, i, max;
    x.Chave='}';
    Insere(x, &(*p));

    //le o arquivo que contem os correspondentes de letra para morse
    tamanho1=readFile(GuardaMorse);
    for(i=0; i<tamanho1; i++){
        max=strlen(GuardaMorse[i].morse);
        preenche_arvore(&(*p), GuardaMorse[i].morse, GuardaMorse[i].letra, 0, max-1);
    }
    return tamanho1;
}

//traduz o codigo morse digitado
void traduzir_morse(TipoApontador *Dicionario, char *codificado, char *entradamorse, GuardaFrase *GuardaFrase, GuardaFraseMorse *GuardaFraseMorse){
    int i, auxiliar;
    int inicio, fim;
    int contador;
    inicio=0;
    int j=0;
    //pega o tamanho da struct que contem cada frase em morse
    contador=strlen(GuardaFraseMorse);
    for(auxiliar=0; auxiliar<contador; auxiliar++){
        strcpy(entradamorse, GuardaFraseMorse[auxiliar].frase);
        for(i=0; i<strlen(entradamorse)+2; i++){
            //entra no if se achar um espaço ou o \0
            if(entradamorse[i]==' ' || entradamorse[i] == '\0'){
                fim=i;
                //Traduz cada letra do morse e coloca em um vetor de caracter
                codificado[j]=BuscaLetra(entradamorse, &(*Dicionario), inicio, fim-1);
                inicio=fim+1;
                //avança para a proxima letra ser traduzida
                j++;
            }
        }
        inicio=0;
        j=0;
        fim=0;
        //Atribui cada frase traduzida para a struct frase
        strcpy(GuardaFrase[auxiliar].frase, codificado);
        //limpa o vetor codificado
        for(i=0; i<strlen(codificado); i++){
            codificado[i]=' ';
        }
        //limpa o vetor entradamorse
        for(i=0; i<strlen(entradamorse); i++){
            entradamorse[i]=' ';
        }
    }
}
//Le as entradas do usuario ou do arquivo .in
int ler_entradas(char *entradamorse, GuardaFraseMorse *GuardaFraseMorse){
    int i, aux;
    int contador=0;
    //limpa buffer do teclado se existir
    fflush(stdin);
    do{
        aux=gets(entradamorse);
        //coloca cada frase da entrada em uma struct
        strcpy(GuardaFraseMorse[contador].frase, entradamorse);
        contador++;
        //limpa a entradamorse
        for(i=0; i<strlen(entradamorse); i++){
            entradamorse[i]=' ';
        }
    //continua ate nao ter mais entradas
    }while(aux!=NULL && strncmp(GuardaFraseMorse[contador-1].frase,"",1)!= 0);
    fflush(stdin);

    return contador;
}


int main(int argc, char *argv[]){

    TipoNo *Dicionario;
    TipoRegistro x;
    //Aloca a arvore em uma struct
    GuardaMorse GuardaMorse[100];
    //Aloca a frase em morse em uma struct
    GuardaFraseMorse GuardaFraseMorse[1000];
    //Aloca cada frase traduzida em uma struct
    GuardaFrase GuardaFrase[1000];
    //Auxilia para alocar cada codificaçao
    char codificado[1000];
    //Obtem cada entrada
    char entradamorse[1000];

    //inicializa a arvore
    Inicializa(&Dicionario);

    int tamanho1, tamanho2;
    int i;
    //habilita o preordem ou nao se nao estiver no argumentos no terminal
    int habilitapreordem=0;
    int contador=0;


    //Le os argumentos utilizados no terminal e retorna para ver se precisa printar pre ordem
    for(i=0; i<argc; i++){
        if(i==1){
            if(strncmp(argv[1],"-a", 2)==0){
                habilitapreordem=1;
            }

        }
    }

    //Le o arquivo morse e preenche a arvore com as letras correspondentes aos . e -
    tamanho1=ler_arquivo_preencher_arvore(&Dicionario, GuardaMorse);


    //Le a entrada do teclado ou do arquivo .in
    contador=ler_entradas(entradamorse, GuardaFraseMorse);



    //Traduz o morse
    traduzir_morse(&Dicionario, codificado, entradamorse, GuardaFrase, GuardaFraseMorse);


    //printa a saida
    for(i=0; i<strlen(GuardaFrase); i++){
        printf("%s\n", GuardaFrase[i].frase);
    }


    //printa pre ordem
    if(habilitapreordem==1){
        printf("\n");
        preOrdem(Dicionario, tamanho1, GuardaMorse);
    }

}
