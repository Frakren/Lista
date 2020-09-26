#include <stdio.h>
#include <stdlib.h>
#include "funcaoLista.c"
void menuLista();
void tadMenu();
void tadMenu()
{
    printf("1-Insere na lista(insLista )\n");
    printf("2-Elimina na lista(elimLista )\n");
    printf("3-Primeiro No(primLista)\n");
    printf("4-Ultimo No(ultLista)\n");
    printf("5-Segue para o prox No(ultLista)\n");
    printf("6-Informacao da lista(infoLista)\n");
    printf("7-Longitude da lista(longLista)\n");
    printf("8-Verifica se a lista esta no final(fimLista)\n");
    printf("0-Voltar\n");
}

void menuLista()
{
    printf("1-Carregar Lista\n");
    printf("2-Limpar Lista\n");
    printf("3-Exibir Lista\n");
    printf("4-Pesquisar linhas\n");
    printf("5-TAD\n");
    printf("0-sair\n");
}

int main()
{
    FILE *Arquivo=NULL;
    Lista Estacoes[7];
    char string[tam],aux[tam],pesquisa[tam];
    int i=0,j=0,k=0,Menu;
    do
    {
        menuLista();
        scanf("%i",&Menu);
        system("cls");
        switch(Menu)
        {
        case 1:
            Arquivo=fopen("entrada.txt","r");
            if(Arquivo==NULL)
            {
                printf("Impossivel Realizar a leitura, porfavor verifique \nse a entrada do arquivo esta correta\n");
                return 0;
            }
            else
            {
                i=0,j=0,k=0;
                while((fgets(string,tam,Arquivo))!=NULL)
                {
                    i=0;
                    Estacoes[k]=inicLista();
                    if(strcmp(string,"7\n")!=0)
                    {
                        while(string[i]!='\0')
                        {
                            if(string[i]!=' ' && string[i]!='\n')
                            {
                                aux[j]=string[i];
                                j++;
                            }
                            else
                            {
                                if(string[i]!='\n')
                                {
                                    aux[j]='\0';
                                    j=0;
                                    anxLista(Estacoes[k],aux);
                                }
                            }
                            i++;
                        }
                        aux[j]='\0';
                        anxLista(Estacoes[k],aux);
                        j=0;
                        k++;
                    }
                }
            }
            fclose(Arquivo);
            break;
        case 2:
            if(Arquivo==NULL)
            {
                printf("Falha ao carregar, por favor verifique se o arquivo foi carregado\n");
                system("pause");
                system("cls");
            }
            else
            {
                for(i=0; i<tamvet; i++)
                {
                    free(Estacoes[i]);
                    Estacoes[i]=NULL;
                }
            }
            break;
        case 3:
            if(Arquivo==NULL)
            {
                printf("Falha ao carregar, por favor verifique se o arquivo foi carregado\n");
                system("pause");
                system("cls");
            }
            else
            {
                if(Estacoes[0]==NULL)
                {
                    printf("Nao existe linhas salvas\n");
                }
                else
                {
                    ExibirLista(Estacoes);
                    system("pause");
                    system("cls");
                }
            }
            break;
        case 4:
            if(Arquivo==NULL)
            {
                printf("Falha ao carregar, por favor verifique se o arquivo foi carregado\n");
            }
            else
            {
                printf("Digite o nome da linha da estacao\n");
                scanf("%s",pesquisa);
                PesquisaLinha(Estacoes,pesquisa);
                system("pause");
                system("cls");
            }
            break;
        case 5:
            do
            {
                tadMenu();
                scanf("%i",&Menu);
                system("cls");
                switch(Menu)
                {
                case 1:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        char stringAux[tam];
                        int indice,posEstacao;
                        printf("Digite mais o nome da estacao que deseja inserir\n");
                        scanf("%s",stringAux);
                        printf("Digite em qual linha que deseja inserir a estacao\n");
                        scanf("%i",&indice);
                        printf("Digite em que posicao que deseja adicionar\n");
                        scanf("%i",&posEstacao);
                        posLista(Estacoes[indice],posEstacao);
                        insLista(Estacoes[indice],stringAux);
                        printLista(Estacoes[indice]);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        int indice,pesq;
                        printf("Digite qual linha que deseja iniciar a eliminacao\n");
                        scanf("%i",&indice);
                        printf("Digite qual posicao que deseja excluir\n");
                        scanf("%i",&pesq);
                        posLista(Estacoes[indice],pesq);
                        elimLista(Estacoes[indice]);
                        printLista(Estacoes[indice]);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        int indice;
                        printf("Digite qual linha que deseja colocar o iterador na primeira posicao\n");
                        scanf("%i",&indice);
                        primLista(Estacoes[indice]);
                        infoLista(Estacoes[indice]);
                        printf("\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        int indice;
                        printf("Digite qual linha que deseja colocar na ultima posicao\n");
                        scanf("%i",&indice);
                        ultLista(Estacoes[indice]);
                        infoLista(Estacoes[indice]);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        int indice;
                        printf("Digite qual linha que deseja colocar o iterador na posicao seguinte\n");
                        scanf("%i",&indice);
                        segLista(Estacoes[indice]);
                        infoLista(Estacoes[indice]);
                        printf("\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        int indice;
                        printf("Digite qual linha que deseja colocar o iterador para exibir a informacao do mesmo\n");
                        scanf("%i",&indice);
                        printLista(Estacoes[indice]);
                    }
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        int indice;
                        printf("Digite qual linha que deseja saber o tamanho da linha\n");
                        scanf("%i",&indice);
                        printf("O tamanho da linha %i e %i\n",indice,longLista(Estacoes[indice]));
                    }
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    if(Estacoes[0]==NULL)
                    {
                        printf("Nao existe linhas salvas\n");
                    }
                    else
                    {
                        int indice;
                        printf("Digite a estacao que deseja verificar se o iterador esta no final da linha\n");
                        scanf("%i",&indice);
                        if(fimLista(Estacoes[indice]))
                        {
                            printf("O iterador esta no final da lista\n");
                        }
                        else
                        {
                            printf("O iterador nao esta no final da lista\n");
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
                case 0:
                    break;
                default:
                    printf("Opcao invalida, por favor digite uma das opcao validas\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(Menu!=0);
            Menu=-1;
            system("cls");
            break;
        case 0:
            printf("Programa Encerrado\n");
            break;
        default:
            printf("Opcao invalida, por favor digite uma das opcao validas\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(Menu!=0);
    return 0;
}
