#ifndef LISTA_H_INCLUDED
#include "ListD.h"
#endif // LISTA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
Lista inicLista()
{
    Lista lst = NULL;
    lst = (Lista)malloc(sizeof(Tlista));
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    lst->iterador = NULL;
    lst->longitude=0;
    return lst;
}
void posLista( Lista lst, int pos)
{
    int i=0;
    pListaNo pAuxNo;
    if(lst->iterador==NULL)
    {
        printf("O iterador nao esta definido.O programa sera encerrado\n");
        exit(1);
    }
    else
    {
        if(pos<lst->longitude && pos>0 && lst->longitude>0)
        {
            pAuxNo=lst->primeiro;
            while(i<pos)
            {
                pAuxNo=pAuxNo->prox;
                i++;
            }
            lst->iterador=pAuxNo;
        }
    }
}
void elimLista( Lista lst)
{
    //Iterador Primeiro
        if(lst->iterador == lst->primeiro){
            lst->primeiro = lst->iterador->prox;
            lst->iterador->prox->ant = NULL;
        }
        //Iterador Ultimo
        else if(lst->iterador == lst->ultimo){
            lst->ultimo = lst->iterador->ant;
            lst->iterador->ant->prox = NULL;
        }
        //Iterador no meio
        else{
            lst->iterador->ant->prox = lst->iterador->prox;
            lst->iterador->prox->ant = lst->iterador->ant;
        }
        lst->longitude--;

}
void PesquisaLinha(Lista lst[tamvet],NOMESESTACOES elem)
{
    int pos=-1,i;
    Lista aux=NULL;
    for(i=0; i<tamvet; i++)
    {
        primLista(lst[i]);
        while(!fimLista(lst[i]))
        {
            if(strcmp(lst[i]->iterador->ESTACOES,elem)==0)
            {
                pos=i;
                aux=lst[pos];
                printLista(aux);
                break;
            }
            segLista(lst[i]);
        }
    }
    if(pos==-1)
    {
        printf("O nome digitado nao existe na linha, por favor digite um nome existente na linha do metro(Dica:exiba a lista).\n");
    }
}
void ExibirLista(Lista lst[tamvet])
{
    int i;
    for(i=0; i<tamvet; i++)
    {
        printLista(lst[i]);
    }
}
void printLista(Lista lst)
{
    printf("Tamanho da lista %i\n",lst->longitude);
    primLista(lst);
    while(!fimLista(lst))
    {
        infoLista(lst);
        segLista(lst);
    }
    printf("\n");
}
void infoLista(Lista lst)
{
    printf("=>%s",lst->iterador->ESTACOES);
}


void anxLista( Lista lst, NOMESESTACOES elem)
{
    pListaNo novoNo;
    //alocar e inicializar o novoNo
    novoNo = (pListaNo) malloc(sizeof(struct ListaNo));
    strcpy(novoNo->ESTACOES,elem);
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    if(lst->longitude==0)
    {
        lst->primeiro=novoNo;
        lst->ultimo=novoNo;
    }
    else
    {
        if(lst->iterador==NULL)
        {
            printf("Lista indefinida\n");
            exit(1);
        }
        else
        {
            if(lst->iterador==lst->ultimo)
            {
                novoNo->ant=lst->iterador;
                lst->iterador->prox=novoNo;
                lst->ultimo=novoNo;
            }
            else
            {
                lst->iterador->prox->ant=novoNo;
                lst->iterador->prox=novoNo;
                novoNo->ant=lst->iterador;
                novoNo->prox=lst->iterador->prox;
            }
        }
    }
    lst->iterador = novoNo;
    lst->longitude++;
}

//: adiciona um elemento antes do iterador
void insLista( Lista lst, NOMESESTACOES elem)
{
    pListaNo novoNo;
    //alocar e inicializar o novoNo
    novoNo = (pListaNo) malloc(sizeof(struct ListaNo));
    //novoNo->info = elem;
    strcpy(novoNo->ESTACOES,elem);
    novoNo->prox = NULL;
    novoNo->ant = NULL;

    //lista vazia
    if(lst->longitude == 0)
    {
        //por o primeiro e ultimo sobre o novoNo
        lst->primeiro = novoNo;
        lst->ultimo = novoNo;
    }
    else  // lista esta cheia
    {
        // o iterador deve estar definido
        // se estiver indefinido esta funcao nao pode ser usada
        if(lst->iterador == NULL)
        {
            printf("insLista: o iterador esta indefinido. O programa sera encerrado. \n");
            exit(1);
        }

        //iterador esta sobre o primeiro elemento
        if(lst->iterador == lst->primeiro)
        {
            novoNo->prox = lst->primeiro; // lst->iterador;
            lst->iterador->ant = novoNo; // lst->primeiro->ant
            lst->primeiro = novoNo;
        }
        else  //iterador esta sobre o algum outro elemento ou
        {
            // sobre o ultimo elemento
            //ligar o novoNo com o noh seguinte

            //tratamento para refazer as ligacoes
            novoNo->prox = lst->iterador;
            novoNo->ant = lst->iterador->ant;
            lst->iterador->ant->prox = novoNo;
            lst->iterador->ant = novoNo;
        }

    }

    //por o iterador sobre o novoNo
    lst->iterador = novoNo;
    //incrementar a quantidade de elementos
    lst->longitude++; // lst->longitude = lst->longitude + 1;
}

//: retorna a quantidade de elementos da lista
int longLista( Lista lst)
{
    // lista deve existir
    if(lst == NULL)
    {
        printf("Lista lst nao foi alocada. O Programa sera encerrado\n");
        exit(1);
    }
    else
        return lst->longitude;
}

//: coloca o iterador sobre o primeiro elemento da lista
void primLista(Lista lst)
{
    lst->iterador = lst->primeiro;
}

// : coloca o iterador sobre o útlimo elemento da lista
void ultLista(Lista lst)
{
    lst->iterador = lst->ultimo;
}

// : avança o iterador uma posição
void segLista( Lista lst )
{

    if(lst->iterador == NULL)
    {
        printf("o iterador esta indefinido. O programa sera encerrado. \n");
        exit(1);
    }

    lst->iterador = lst->iterador->prox;

}

//; //: retorna o elemento sob o iterador

//: retorna verdadeiro se o iterador estiver indefinido
int fimLista( Lista lst)
{

    return(lst->iterador == NULL);

    if(lst->iterador == NULL)
        return 1;
    else
        return 0;
}
