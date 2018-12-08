#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "grafo.h"





int main(int argc, char *argv[]){

char nome1[100];
printf("Diga o nome do Arquivo para iniciar:");
scanf("%s",&nome1);
printf("\n");
Grafo *g=inicializa();


    char nome;
    char ini;
    char seg;
    float custo;

int seletor = 0;

g=criarGrafo(nome1,g);
getchar();

printf("|-------------------------------------------------------------------------------|\n|----------------------------------Trabalho de ED-------------------------------|\n|-------------------------------------------------------------------------------|\n\n");
printf("Desenvolvido pelos alunos:\n Leandro Silva Azevedo\n Caroline Rosa\n Victor Freitas\n\n");
//usado para abrir o arquivo diretamente do CMD



while(seletor!=8){
//getchar();
printf("Selecione uma acao para realizar com o grafo:\n"
       " 1: Inserir novo vertice\n"
       " 2: Remover vertice existente\n"
       " 3: Inserir nova aresta\n"
       " 4: Remover aresta existente\n"
       " 5: Verificar se o grafo e conexo\n"
       " 6: Verificar existencia de caminho entre vertices\n"
       " 7: Imprimir o grafo completo\n"
       " 8: Sair do Programa\n -----> : ");

       scanf("%d",&seletor);
       printf("\n\n");
       //getchar();


    if(seletor<1 || seletor>8){
         getchar();
         printf("Valor informado Invalido, por favor tente outra opcao a seguir!\n\n");
        seletor=0;

    }

   if (seletor == 1){
    getchar();
    printf("Diga o nome do novo vertice:");

    nome = getchar();
    getchar();
    printf("\n");
    char aux = g->id_vertice;
    g=insere_vertice(g,nome);
	arq_insereVertice(nome1,nome);
    if(aux!=g->id_vertice){
      printf("Vertice inserido com sucesso!\n");
      seletor=0;
    }

    printf("\n");

   }

     if (seletor == 2){
       getchar();
       printf ("Diga o nome do vertice a ser removido: ");
        //getchar();
        nome = getchar();
        getchar();
        printf("\n");
        g=retira_vertice(g,nome,nome1);
        seletor=0;

       }

    if (seletor == 3){
    getchar();
    printf("Diga o nome do vertice de origem: ");
    //getchar();
    ini = getchar();
    getchar();
    printf("Diga o nome do vertice seguinte: ");
    seg = getchar();
    getchar();
    printf("Agora, informe o custo: ");
    scanf("%f",&custo);
    //getchar();
    printf("\n");
      insere_aresta(g,ini,seg,custo,nome1);

   seletor=0;

    }
       if (seletor == 4){
        getchar();
        printf("Diga o nome do vertice de origem: ");
        //getchar();
        ini = getchar();
        getchar();
        printf("Diga o nome do vertice seguinte: ");
        seg = getchar();
        getchar();
        printf("\n");
        retira_aresta(g,ini,seg, nome1);
         seletor=0;
         }

        if (seletor == 5){
            getchar();
            printf("\n");
             verifica_se_conexo(g);
        seletor=0;
           }


        if (seletor == 6){
                getchar();
                printf ("Escolha o vertice de partida: ");
                 //getchar();
                 ini = getchar();
                 getchar();
                printf("Diga o nome do vertice de chegada: ");
                seg = getchar();
                getchar();
                printf("\n");
                verifica_Se_ExisteCaminho_e_OMaisBarato(g,ini,seg);
              seletor=0;
                }

        if (seletor == 7){
             getchar();
            mostraGrafo(g);
            printf("\n");
            seletor=0;
        }

        if(seletor==8){
           //getchar();
           seletor=8;

        }



}

return 0;
}


