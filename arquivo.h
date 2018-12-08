
int tam,i=0;
char c, c2,c1;
FILE *arq, *arqW;
char* prov = "provisorio.txt";

void copiarArq(char* url1, char*url2){
	char buffer[16] = {0};

	arq = fopen(url2, "r");
	
	arqW = fopen(url1, "w");
	while (!feof(arq)){		
			fputs(fgets(buffer, sizeof(buffer), arq), arqW);
		
	}
		fclose(arq);
		fclose(arqW);
		
		remove(url2);
	}

void arq_insereAresta(char* url,char s, char s2, int custo){

char buffer[16] = {0};
i=0;
	arq = fopen(url, "r");
	
	arqW = fopen(prov, "w");
		
		fscanf(arq,"%d\n",&tam);
	
		
		sprintf(buffer, "%d\n", tam);
		fputs(buffer, arqW);
		while(i<tam){
		
			fscanf(arq, "%c\n", &c);	
			fputc(c, arqW);
			fputc('\n', arqW);
			i++;
			
		}

		while (!feof(arq)){
			fscanf(arq, "\n%c %c %i", &c1, &c2, &i);
			if(c!=' '){
				sprintf(buffer, "%c %c %i", c1, c2, i);
				c=' ';
			}else{
				sprintf(buffer, "\n%c %c %i", c1, c2, i);
			}
			if(c1==s && c2==s2){
				fclose(arq);
			fclose(arqW);
			return ;
				
			}
		
			fputs(buffer, arqW);
			
		
	}
	sprintf(buffer, "\n%c %c %i", s, s2, custo);
	fputs(buffer, arqW);
		fclose(arq);
			fclose(arqW);
			copiarArq(url, prov);
			
		
		}
	
	
void arq_removeAresta(char* url,char s, char s2){
char buffer[16] = {0};
i=0;
	
	arq = fopen(url, "r");
	
	arqW = fopen(prov, "w");
		
		fscanf(arq,"%d\n",&tam);
		
		
		sprintf(buffer, "%d\n", tam);
		fputs(buffer, arqW);
		while(i<tam){
		
			fscanf(arq, "%c\n", &c);
			fputc(c, arqW);
			fputc('\n', arqW);
			i++;
			
		}

		while (!feof(arq)){
			fscanf(arq, "\n%c %c %i", &c1, &c2, &i);
			if(c!=' '){
				sprintf(buffer, "%c %c %i", c1, c2, i);
				if(!(c1==s && c2==s2)||(c1==s2 && c2==s))
				c=' ';
				}else{
				sprintf(buffer, "\n%c %c %i", c1, c2, i);
				}		
			if((c1==s && c2==s2)||(c1==s2 && c2==s)){
			
			//g= remove_aresta(g, c, c2, i);

			
			}else{
			fputs(buffer, arqW);
			
			}
		
	}
		fclose(arq);
			fclose(arqW);
			copiarArq(url, prov);
		
		}

void arq_removeVertice(char* url,char s){
	char buffer[16] = {0};
	i=0;
	arq = fopen(url, "r");
	
	arqW = fopen(prov, "w");
		
		fscanf(arq,"%d\n",&tam);
		tam--;
		sprintf(buffer, "%d\n", tam);
		fputs(buffer, arqW);
		while(i<tam+1){
		
		fscanf(arq, "%c\n", &c);
		if(c!=s){
		fputc(c, arqW);
		fputc('\n', arqW);

		}
		
		
		
		i++;
		}

		while (!feof(arq)){
			fscanf(arq, "\n%c %c %i", &c1, &c2, &i);
			if(c==s){
				
				sprintf(buffer, "%c %c %i", c1, c2, i);
				c=' ';
			}else{
			
				if(c!=' '){
				sprintf(buffer, "%c %c %i", c1, c2, i);
				if(!(c1==s || c2==s))
				c=' ';			
				
				}else{
				sprintf(buffer, "\n%c %c %i", c1, c2, i);
				}			
			}
			if(c1!=s && c2!=s){
			
			fputs(buffer, arqW);
			}else{
			//g= remove_aresta(g, c, c2, i);
			
			}
		
	}
		fclose(arq);
			fclose(arqW);
			copiarArq(url, prov);
		
		}

	
	
void arq_insereVertice(char* url,char s){
char buffer[16] = {0};
i=0;
	
	arq = fopen(url, "r");
	
	arqW = fopen(prov, "w");
		
		
		fscanf(arq,"%d\n",&tam);
		tam++;
		sprintf(buffer, "%d\n", tam);
		
		fputs(buffer, arqW);
		while(i<tam-1){
		
		fscanf(arq, "%c\n", &c);
		if(c==s){
			fclose(arq);
			fclose(arqW);
			return;
		}
		fputc(c, arqW);
		fputc('\n', arqW);
		//printf("inseri a aresta %c\n",c);

		i++;
		}
		
		fputc(s,arqW);

		while (!feof(arq)){
			fscanf(arq, "\n%c %c %i", &c, &c2, &i);
			//printf("inseri a relacao da aresta %c com a %c de valor %i\n",c, c2, i);
			
			sprintf(buffer, "\n%c %c %i", c, c2, i);
			fputs(buffer, arqW);
		
	}
		fclose(arq);
			fclose(arqW);
			copiarArq(url, prov);
		
		}
