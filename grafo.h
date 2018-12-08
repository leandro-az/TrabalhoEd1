#include "arquivo.h"
//editor: Leandro Silva Azevedo de Almeida;



//---------------Estrutura de uma Aresta do grafo ----------------------------------------------------------------------------------
typedef struct aresta{
   int visitado;
   float custo;
   char id_aresta;
   struct aresta *prox_aresta;

}Aresta;

//---------------------Estrutura de um Grafo com seus vertices e arestas-------------------------------------------------------------

typedef struct grafo{
   int visitado;
   char id_vertice;
   Aresta *pri_aresta;
   struct grafo *prox_vertice;

}Grafo;
Grafo *criarGrafo(char* url, Grafo *g);
void seta_Vertice_Visitado(Grafo *g, char id_vert, int i);
void verifica_se_conexo1(Grafo *g);
void verifica_Se_ExisteCaminho_e_OMaisBarato1(Grafo *g, char inicio, char fim);
//------------------variaveis globais utilizadas pelas operacoes abaixo-----------------------------------------------------------------

Grafo *global1=NULL;
Grafo *global2=NULL;
int contConexo=0;
Aresta *listaDeArestasT=NULL;
Aresta *listaDeArestasF=NULL;

//----------------------------------------------------------------------------------------------------------------------------------------

//----------------------Inicialisação do Grafo ----------------------------------------------------------------------------------------

Grafo *inicializa(){
  return NULL;
}


//--------------------------Faz a busca na Lista de Vertices do Grafo para vericiar se um vertice ja existe ----------------------------

Grafo *busca_vertice(Grafo *g,char id_vert){

      if(g==NULL){
       return g;
    }else{
       if(g->id_vertice==id_vert){
           return g;
        }else{
            return busca_vertice(g->prox_vertice,id_vert);
          }
      }
}
//-------------------------------Insere um vertice na lista de Grafo -----------------------------------------------------------------------
Grafo *insere_vertice(Grafo *g,char id_vert){

      //verifica se  o vertice ja existe para não inserir novamente:
   Grafo *temp = busca_vertice(g,id_vert);
      if(temp!=NULL){
         printf("Vertice informado ja existente!\n\n");
         return g;
    //--------------------------------------------------------------
      }else{
        temp=(Grafo*)malloc(sizeof(Grafo));
        temp->id_vertice=id_vert;
        temp->pri_aresta=NULL;
        temp->prox_vertice=g;
        temp->visitado=0;
        //printf("Vertice incluido com sucesso!\n");
        return temp;
      }
}

//------------------------Busca uma aresta em um determinado em um vertice de um grafo -------------------------------------------------------

Aresta *busca_aresta(Grafo *g,char id_vert1,char id_vert2){

// verifica primeiro se os vertices existem, lembrando que como nao é um grafo orientado se existe uma aresta de A para B entao existe uma aresta de B para A
    Grafo *temp1= busca_vertice(g,id_vert1);
    Grafo *temp2= busca_vertice(g,id_vert2);
    Aresta *aux=NULL;
    if(temp1==NULL){
      return NULL;
    }else{
      if(temp2==NULL){
        return NULL;

 //---------------------------------------------------------

      }else{

 //--------------------Verifica se Aresta existe , se existe retorna seu enderenço caso contrario retorna null:
       aux=temp1->pri_aresta;
       while((aux) && (aux->id_aresta != id_vert2)){
          aux=aux->prox_aresta;
       }
    }
    }
    return aux;

//-------------------------------------------------------------

}

//Verifica somente se o vertice existe sem se preocupar em avisar o usuario ----------------------------------------------------------------------------
int verifica_se_tem_aresta(Aresta *a,char id_vert1){

if(a==NULL){
return 0;
}else{
  if(a->id_aresta==id_vert1){
    return 1;
  }else{
    return verifica_se_tem_aresta(a->prox_aresta,id_vert1);
  }
}

}

//-------------------------------------------------------------


//-----------------------Insere aresta entre dois vertices --------------------------------------------------------------------------------

void insere_aresta(Grafo *g,char id_vert1,char id_vert2,float valor, char* url){



//verifica se os vertices existem:

    Grafo *temp1= busca_vertice(g,id_vert1);
    Grafo *temp2= busca_vertice(g,id_vert2);

    if(temp1==NULL){
       printf("O Vertice %c nao existe no grafo! Por favor insira o vertice e depois tente novamente !\n\n",id_vert1);
       if(temp2==NULL){
        printf("O Vertice %c nao existe no grafo! Por favor insira o vertice e depois tente novamente !\n\n",id_vert2);
      }
      return;

    }
      if(temp2==NULL){
        printf("O Vertice %c nao existe no grafo! Por favor insira o vertice e depois tente novamente !\n\n",id_vert2);
        return;
//-------------------------------------------------------------

//verifica se aresta existe, se ja existe para e retorna :

      }
        Aresta *aux1=busca_aresta(g,id_vert1,id_vert2);
        if(aux1!=NULL){
        printf("Aresta ja existe!\n\n");
         return;

 //---------------------------------------------------------------


 //insere a aresta nos dois sentidos , de A para B e de B para A:
        }else{
             aux1=(Aresta*)malloc(sizeof(Aresta));
             Aresta *aux2=(Aresta*)malloc(sizeof(Aresta));

             aux1->id_aresta=id_vert2;
             aux1->custo=valor;
             aux1->prox_aresta=temp1->pri_aresta;
             temp1->pri_aresta=aux1;

             aux2->id_aresta=id_vert1;
             aux2->custo=valor;
             aux2->prox_aresta=temp2->pri_aresta;
             temp2->pri_aresta=aux2;
			arq_insereAresta(url,id_vert1,id_vert2,valor);

        }
        // printf("Aresta adicionada com sucesso!\n");
//-----------------------------------------------------------------------------------



}


// -------------------------------Essa parte Toda refere-se a Retirada de arestas-------------------------------------------------------------------



//--------------- metodo que elimina a aresta -------------------------

Aresta *remove_aresta(Aresta *a,char id_vert){
if(a==NULL){
  return a;
}else{

  if(a->id_aresta==id_vert){
     return a->prox_aresta;
  }else{
    a->prox_aresta=remove_aresta(a->prox_aresta,id_vert);
    return a;
  }

}
}

//-------------------------------------------------------------

//Metodo intermediario que encontra o vertice para tirar a aresta ---------------

void retira_aresta1(Grafo *g,char id_vert1,char id_vert2){



if(g==NULL){
 return;
}else{

    Grafo *temp1= busca_vertice(g,id_vert1);

    if(temp1==NULL){

       return;
    }else{
//verifica se chegamos no vertice que possui a aresta em questao, se sim remove a aresta nos dois sentidos ---------------
      if(g->id_vertice==id_vert1){
       g->pri_aresta=remove_aresta(g->pri_aresta,id_vert2);
       retira_aresta1(g,id_vert2,id_vert1);

        }else{
         retira_aresta1(g->prox_vertice,id_vert1,id_vert2);
         retira_aresta1(g->prox_vertice,id_vert2,id_vert1);
        }


}
//------------------------------------------------------------------------
}
}

// metedo que verifica se as arestas existem e se prepara para retirar se positivo ---------------------------------------------------------------------------------------------

void retira_aresta(Grafo *g,char id_vert1,char id_vert2,char* url){

Grafo *temp1= busca_vertice(g,id_vert1);
Grafo *temp2= busca_vertice(g,id_vert2);
if(g==NULL ){
    return;
}else{

if(!temp2){
printf("O vertice %c nao existe no grafo! Por favor tente outra operacao !\n\n",id_vert2);

}
if(!temp1){
printf("O vertice %c nao existe no grafo! Por favor tente outra operacao !\n\n",id_vert1);

}
Aresta *aux = busca_aresta(g,id_vert1,id_vert2);
if(aux==NULL){
 printf("Aresta não existe! \n\n");
 return;
}else{
retira_aresta1(g,id_vert1,id_vert2);
retira_aresta1(g,id_vert2,id_vert1);
arq_removeAresta(url, id_vert1, id_vert2);
printf("Aresta removida com sucesso!\n\n");
}
}

}
//------------------------------------------------------------------------




//-------------------------------------------------------------------------


//-----------------------------------------Mostra Grafico -----------------------------------------------------------------------------

void mostraGrafo(Grafo *g){
    if(g){
      Aresta *p= g->pri_aresta;
      printf("Vertice %c :\n",g->id_vertice);
      while(p){
      printf("---> ");
      printf("%c ( %.2f ) \n",p->id_aresta,p->custo);
      p=p->prox_aresta;

      }
      printf("\n");
      mostraGrafo(g->prox_vertice);
    }
}


//----------------------------------------------Libera o grafico ---------------------------------------------------------------------------------------

void libera_arestas(Aresta *are){
     if(are!=NULL){
        libera_arestas(are->prox_aresta);
        free(are);
     }
}

void libera_grafo(Grafo *g){
   if(g!=NULL){
      libera_grafo(g->prox_vertice);
      libera_arestas(g->pri_aresta);
      free(g);


   }

}



// metodo que retira o vertice chamado pelo programador ---------------------------------------------------------------------------------------------


Grafo *retira_vertice1(Grafo *g , char id_vert){
     if(g==NULL){
       return g;
     }else{

          if(g->id_vertice==id_vert){
             return retira_vertice1(g->prox_vertice,id_vert);
          }else{

          if(verifica_se_tem_aresta(g->pri_aresta,id_vert)==1){
             g->pri_aresta=remove_aresta(g->pri_aresta,id_vert);

          }
            //retira_no1(g,id_vert);
            g->prox_vertice=retira_vertice1(g->prox_vertice,id_vert);
            return g;
        }

        }


     }

// metodo chamado pelo usuario para verificar se pode retirar o vertice e se der, retira chamando o outro metodo---------------------------------------------------------------------------------
Grafo *retira_vertice(Grafo *g, char id_vert, char* url){
     if(g==NULL){
       return g;
     }else{
        Grafo *temp=busca_vertice(g,id_vert);
        if(temp==NULL){
        printf("Vertice informado nao se encontra no grafo!\n\n");
        return g;
          }else{
            g=retira_vertice1(g,id_vert);
			arq_removeVertice(url, id_vert);
            printf("Vertice removido com sucesso!\n\n");
            return g;

        }
    }
}
//-----------------------------------------Chamada do metodo para tratar possiveis probelmas ---------------------------------------------
void verifica_se_conexo(Grafo *g){
    if(g==NULL){
      printf("O Grafo não possui nenhum vertice!\n");
      return ;
    }else{
      global1=g;
      seta_Vertice_Visitado(global1,g->id_vertice,1);
      verifica_se_conexo1(g);

      if(contConexo==(tamanho_grafo(global1))){

        printf("Grafo Conexo!\n\n");
      }else{

        printf("Grafo desconexo!\n\n");
      }
    }

    // zera o visistado de todo o grafo para que possa ser realizado uma nova operacao no fututo --------
    global2=global1;
    while(global2){
      seta_Vertice_Visitado(global1,global2->id_vertice,0);
      global2=global2->prox_vertice;
    }
     contConexo=0;
     global1=NULL;
     global2=NULL;
}
//-----------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------Metodo para verificar se o grafo e conexo -------------------------------------------------------------------

//Seta todas as arestas com o valor de i necessario -----------

void seta_Aresta_Visitado(Aresta *a, char id_vert, int i){
    if(a==NULL){
    return;
    }

    if(a->id_aresta==id_vert){
      a->visitado=i;
    }else{
     seta_Aresta_Visitado(a->prox_aresta,id_vert,i);
    }
}
//-------------------------------------------------------------


//Seta o vertice com o valor do de i necessario -------------------

void seta_Vertice_Visitado(Grafo *g, char id_vert, int i){
   if(g==NULL){
    return;
   }
    if(g->id_vertice==id_vert){
       g->visitado=i;
       seta_Vertice_Visitado(g->prox_vertice,id_vert,i);
    }else{
       seta_Aresta_Visitado(g->pri_aresta,id_vert,i);
       seta_Vertice_Visitado(g->prox_vertice,id_vert,i);

    }

}

//-------------------------------------------------------------------


//Retorna a quantidade de vertices-----------------------------------


int tamanho_grafo(Grafo *g){
   if(g==NULL){
     return 0;
   }else{
     return 1+ tamanho_grafo(g->prox_vertice);
   }
}

//--------------------------------------------------------------------

// verifica se ainda tem aresta sem marcacao -------------------------

int aindaTemArestaLivre(Aresta *a){
     if(a==NULL){
        return 0;
     }else{
       if(a->visitado==0){
         return 1;
       }else{
         return aindaTemArestaLivre(a->prox_aresta);
       }
     }

}
//----------------------------------------------------------------------

//Retorna o proximo aresta do grafico que ainda nao foi visitada e se nao tem retorna null---------------

Grafo *retorna_Novo_Comeco_Grafo(Grafo *g, Aresta *a){
    Aresta *aux=a;
    while( (aux) && (aux->visitado ==1)){
       aux=aux->prox_aresta;
    }
    if( aux == NULL){
      return NULL;
    }else{
       return busca_vertice(g,aux->id_aresta);
    }
}

//---------------- Metodo que faz o teste se conexo -------------------------------------------------------------------------------------------------------------------------------

void verifica_se_conexo1(Grafo *g){

   if(g==NULL){
    return;
   }else{

     Aresta *aux=g->pri_aresta;
     seta_Vertice_Visitado(global1,g->id_vertice,1);
      contConexo=contConexo+1;
       while(aux){
          if(aux->visitado!=1){

           global2=busca_vertice(global1,aux->id_aresta);
            verifica_se_conexo1(global2);


          }
           aux=aux->prox_aresta;
       }

       // seta_Vertice_Visitado(global1,g->id_vertice,0);
   }

}
// --------------- verifica o custo de um determinado caminho --------------------------------------------
float custoCaminho( Aresta *a){
    if(a==NULL){
     return 0.0;
    }else{
      return (a->custo + custoCaminho(a->prox_aresta));
    }

}

//------------------------------------------------------------------------------------------------------


//--------------imprime o caminho da lista de arestas formadas pelo caminho minimo -----------------------

void imprimeCaminho(Aresta *a){
     if(a!=NULL){
        imprimeCaminho(a->prox_aresta);
        printf("--> %c (%.2f) ",a->id_aresta,a->custo);
     }
}

//--------------------------------------------------------------------------------------------------------







void verifica_Se_ExisteCaminho_e_OMaisBarato1(Grafo *g, char inicio, char fim){
        if(g==NULL){
          return;
        }else{
        // verificamos se a aresta e o ponto final que buscamos ---------------------------------------
           Aresta *aux = g->pri_aresta;
           while(aux){

     //-------Se sim adicionamos na lista de aresta temporario , calculamos seu valor saindo da origem ate ele e verificamos se o custo e
     // menor do que a que esta na lista de aresta final , se sim salvamos esse  novo caminho como candidato de lisa final e depois retiramos esse elemento da lista de temporario
     // para continuar a busca do menor caminho.

            if(aux->visitado!=1){
              if(aux->id_aresta==fim){
                 Aresta *novo=(Aresta*)malloc(sizeof(Aresta));
                 novo->id_aresta=fim;
                 novo->custo=aux->custo;
                 novo->prox_aresta=listaDeArestasT;
                 listaDeArestasT=novo;
                 if(custoCaminho(listaDeArestasF)==0 || (custoCaminho(listaDeArestasT)<=custoCaminho(listaDeArestasF))){
                     listaDeArestasF=listaDeArestasT;

                     //imprimeCaminho(listaDeArestasT);

                 }
                   listaDeArestasT=listaDeArestasT->prox_aresta;
                 }else{

      // Se não entao adcionamos esse candidato na lista de temporario marcamos como visitado , chamamos o metodo recurssivamente para verificar se atraves dele cheamos ate o ponot final
      // retornamos e retiramos ele da lista de temporario e desmarcamos como visitado para verificar todos os caminhos possiveis.


                   Aresta *novo=(Aresta*)malloc(sizeof(Aresta));
                    novo->id_aresta=aux->id_aresta;
                    novo->custo=aux->custo;
                    novo->prox_aresta=listaDeArestasT;
                    listaDeArestasT=novo;
                    seta_Vertice_Visitado(global1,aux->id_aresta,1);
                    global2=busca_vertice(global1,aux->id_aresta);
                    verifica_Se_ExisteCaminho_e_OMaisBarato1(global2,aux->id_aresta,fim);
                    listaDeArestasT=listaDeArestasT->prox_aresta;
                    seta_Vertice_Visitado(global1,aux->id_aresta,0);

                  }
            }
                  aux=aux->prox_aresta;
              }
           }

        }


//---------------- metodo chamado no menu princiapla para verificar menor caminho tratando os erros---------------------------------


void verifica_Se_ExisteCaminho_e_OMaisBarato(Grafo *g, char inicio, char fim){
       if(g==NULL){
         printf("Grafo Vazio !\n");
        return;
       }else{

         Grafo *aux1=busca_vertice(g,inicio);
         Grafo *aux2 = busca_vertice(g,fim);
              if(aux1==NULL){
                 printf("O vertice %c não existe no grafo! Por favor tente outra operacao !\n",inicio);
                  if(aux2==NULL){
                   printf("O vertice %c não existe no grafo!Por favor tente outra opercao !\n",fim);
                  }
                  printf("\n");

              return;
              }
                  if(aux2==NULL){
                   printf("O vertice %c não existe no grafo! Por favor tente outra operacao !\n\n",fim);
                   return;
                  }
        //---Aqui salvamos a referencia do grafo original para nao perdela,buscamos o lugar de partida,setamos o primeiro lugar visitado e chamaos o metodo principal ---------
                   global1=g;
                   global2=busca_vertice(global1,inicio);
                   seta_Vertice_Visitado(global1,global2->id_vertice,1);
                  verifica_Se_ExisteCaminho_e_OMaisBarato1(global2,inicio,fim);

             //---------------------------------------------------------------------------------------------------------------------------


             //------------------------------Aqui mostramos o resultado apos a busca------------------------------------------------------
                if(listaDeArestasF!=NULL){
                       printf("%c ",inicio);
                     imprimeCaminho(listaDeArestasF);
                     printf("\n");

                     printf("Com custo total de: %.2f\n",custoCaminho(listaDeArestasF));
                  }else{

                    printf("O caminho não existe !\n\n");
                  }
//-------------------------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------Aqui zeramos as variaveis para que o processo possa ocorrer novamente no futuro -----------------------------



                      global2=global1;
                 while(global2){
               seta_Vertice_Visitado(global1,global2->id_vertice,0);
               global2=global2->prox_vertice;
               }
                  listaDeArestasF=NULL;
                  listaDeArestasT=NULL;
                  //libera_arestas(listaDeArestasT);
                  //libera_arestas(listaDeArestasF);
                  global1=NULL;
                  global2=NULL;
//------------------------------------------------------------------------------------------------------------------------------------------------------
             }

}

Grafo* criarGrafo(char* url, Grafo *g){

	int tam,i=0;
	float f=0;
	char c, c2;
	FILE* arq;


// leitura do tamanho do arquivo-----------------------------
	arq = fopen(url, "r");

	while(arq==NULL ){
		fclose(arq);
	  printf("Não foi possível Encontrar o arquivo informado por favor digite novamente!:");
	  scanf("%s",url);
	  arq = fopen(url, "r");
	}


printf("Arquivo encontrado com sucesso !\n\n");

 	   fscanf(arq,"%i\n",&tam);

	while(feof(arq)){
		printf("Arquivo vazio por favor insira um arquivo válido!:");
		fclose(arq);
		scanf("%s",url);
		arq = fopen(url, "r");
		printf("\n");
		while(arq==NULL ){
				fclose(arq);
				printf("Não foi possível Encontrar o arquivo informado por favor digite novamente!:");
				scanf("%s",url);
				arq = fopen(url, "r");
		}
		fscanf(arq,"%i\n",&tam);

	}

	while(i<tam){

		fscanf(arq, "%c\n", &c);
		g= insere_vertice(g, c);
		//printf("inseri a aresta %c\n",c);

		i=i+1;

	}

	while (!feof(arq)){
			fscanf(arq, "%c %c %f\n", &c, &c2, &f);
			//printf("inseri a relacao da aresta %c com a %c de valor %f\n",c, c2, f);
			insere_aresta(g,  c, c2, f,url);

	}



	fclose(arq);
    return g;
}

//------------------------------------------------------------------------------------------------------FIM--------------------------------------------------------------------------------------------------------------------
