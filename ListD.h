#ifndef LISTD_H_INCLUDED
#define LISTD_H_INCLUDED
#define tam 100
#define tamvet 7
typedef char NOMESESTACOES[tam];

typedef struct ListaNo
{
    NOMESESTACOES ESTACOES;
    struct ListaNo *prox,*ant;
} *pListaNo;

typedef struct
{
    pListaNo primeiro, ultimo, iterador;
    int longitude;
}Tlista, * Lista;

void PesquisaLinha(Lista lst[tamvet],NOMESESTACOES elem);
void ExibirLista(Lista lst[tamvet]);
void printLista(Lista lst);
void infoLista(Lista lst); //ok
Lista inicLista( void ); // : cria e retorna uma lista vazia ok
void anxLista( Lista lst, NOMESESTACOES elem); //: adiciona um elemento depois do iterador ok
void insLista( Lista lst, NOMESESTACOES elem); //: adiciona um elemento antes do iterador ok
void elimLista( Lista lst); //: elimina o elemento que está sob o iterador
void primLista(Lista lst); //: coloca o iterador sobre o primeiro elemento da lista ok
void ultLista(Lista lst); // : coloca o iterador sobre o útlimo elemento da lista ok
void segLista( Lista lst ); // : avança o iterador uma posição ok
void posLista( Lista lst, int pos); //: coloca o iterador sobre a posição pos
int longLista( Lista lst); //: retorna a quantidade de elementos da lista ok
int fimLista( Lista lst); //: retorna verdadeiro se o iterador estiver indefinido ok


#endif // LISTD_H_INCLUDED

