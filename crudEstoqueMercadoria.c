#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>



//protótipos
void incluir (void);
void listar (void);
void consultar (void); 
void alterar(void);
void excluir(void);
void sair(void);


void main (void){
setlocale(LC_ALL,"");  
int opcao;
  do{      
        do{  
	    system("cls");
		printf ("\n\n\n\n\n\n\n"); 
		printf    ("\t########################################################\n");
		printf    ("\t#                                                      #\n");
		printf    ("\t#           Programa para Gestão de Estoque           #\n");
		printf    ("\t#                                                      #\n"); 
		printf    ("\t########################################################\n\n\n");
		printf ("\n Digite uma das opcoes\n\n");
	    printf ("\n 1 - Incluir"); 
		printf ("\n 2 - Alterar");
        printf ("\n 3 - Excluir");
        printf ("\n 4 - Consultar"); 
	    printf ("\n 5 - Listar");    
	    printf ("\n 6 - Sair"); 
	    printf ("\n\n\n Opcao:");
	    scanf("%d",&opcao);
		}
		while (opcao<1 || opcao>6);
		switch (opcao){ 
			case 1:  
			    incluir ();
			    break;
			case 2:
				alterar();
				break;
			case 3:
			    excluir();
			    break;
			case 4:  
			    consultar ();
				break;
			case 5:  
	 		    listar ();
				break;
			case 6:
				sair();
				break;
			
		}
	}while(1);
}

void incluir(){
	char produto[4][20],produto1[4][20],nome[4][20]={"o código","a descrição","a marca","a quantidade"};
	int escolha,i,x=0;
    FILE *fp;
    fp=fopen("produtos.txt", "r+");
    if (fp == NULL){
        fp=fopen("produtos.txt", "w+");
        fclose(fp);
        return;
    }
    fclose(fp);
    
	for(i=0;i<4;i++){
		printf("Digite %s  do produto: ",nome[i]);
        scanf("%s",&produto[i]);
	}
	fp=fopen("produtos.txt","r");
	while (fscanf(fp,"%s  %s  %s  %s",&produto1[0],&produto1[1],&produto1[2],&produto1[3])!=EOF){
        if(strcmp(produto1[0],produto[0])==0){
        	x++;	
	    }
    }
    
    if(x>0){
	    printf("Código já cadastrado! digite: \n1 - para continuar cadastro \n2 - para alterar cadastro existente");
        scanf("%d",&escolha);
        while(escolha<1 || escolha>2){
        	printf("Opção invalida! digite: \n1 - para continuar cadastro \n2 - para alterar cadastro existente");
			scanf("%d",&escolha);
            system("cls");
        }
        switch (escolha){
        	case 1:
        		fclose(fp);
        		fopen("produtos.txt","a");
        	    fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
                fclose(fp);
                printf("produto cadastrado com sucesso!");
                Sleep(5000);
                break;
            case 2:
                fclose(fp);
                alterar();
                break;
	    }
	}
	else{
        fclose(fp);
        fopen("produtos.txt","a");
	    fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
        fclose(fp);
    }
}



void listar (){
	char produto[4][20],x;
    FILE *fp;
    fp=fopen("produtos.txt", "r+");
    if (fp == NULL){
        printf("Arquivo inexistente!");
        return;
    }
 
    while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
        printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
    }
    fclose(fp);
    system("pause");
}



void consultar(){
char produto[4][20],codigo[20];
int escolha=0,x=0;
FILE *fp = fopen("produtos.txt", "r");
if (fp == NULL){
printf("Arquivo inexistente!");
return;
}
while(escolha<1 || escolha>2){
printf("Digite:\n 1 - para usar o código\n 2 - para usar a descrição");
scanf("%d",&escolha);
system("cls");
}
switch (escolha){
	case 1:
		printf("Digite o Código do Produto: ");
		scanf("%s",&codigo);
		break;
	case 2:
		printf("Digite o nome do Produto: ");
		scanf("%s",&codigo);
		break;
}
while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
	if(escolha == 1){
		if(strcmp(produto[0],codigo)==0){
			printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
			x++;
		}	
	}
	else{
		if(strcmp(produto[1],codigo)==0){
			printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
			x++;
		}
	}
}
if(x==0){
	printf("produto não encontrado! \nDeseja ver todos os produtos cadastrados? \n1 - Sim \n2 - não");
	scanf("%d",&escolha);
	if(escolha == 1){
		listar();
	}
}
system("pause");
}



void alterar(){
	char produto[4][20],codigo1[20],descricao1[20],marca1[20],quantidade1[20],newcodigo[20],newdescricao[20],newmarca[20],newquantidade[20];
    int escolha1,escolha2,x=0,posicao_cursor;
    FILE *fp,*fp1;
    
    
	fp=fopen("produtos.txt", "r");
	if (fp == NULL){
        printf("Arquivo inexistente!");
        return;
    }
    fclose(fp);
    printf("Digite o que deseja Alterar: \n1 - código \n2 - Descrição \n3 - Marca \n4 - quantidade: \nescolha:");
    scanf("%d",&escolha1);
	switch(escolha1){
		case 1:
			fp=fopen("produtos.txt", "r+");
		    printf("Digite o código do produto que deseja alterar:");
		    scanf("%s",&codigo1);
	        while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
		            if(strcmp(produto[0],codigo1)==0){
			            printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
			            x++;
			        }
		    }
		    fclose(fp);
			if(x>1){
				printf("Deseja alterar o código de todos os produtos acima? \n1 - sim \n2 - não");
			    scanf("%d",&escolha2);
			    while(escolha2<1 || escolha2>2){
			        printf("Opção Invalida!");
			        printf("Deseja mesmo alterar o código atual? \n1 - sim \n2 - não");
			        scanf("%d",&escolha2);	
				}
			    if(escolha2==1){
			        printf("Digite o novo codigo do produto: ");
			        scanf("%s",&newcodigo);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
						while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							if(strcmp(produto[0],codigo1)==0){ 
								fprintf(fp1,"%s  %s  %s  %s ",newcodigo,produto[1],produto[2],produto[3]);
							}
							else{
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
							}	
						}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);	
			    }
			    else{
			    	printf("Digite a descrição do produto que deseja alterar o código:");
			    	scanf("%s",&descricao1);
			    	printf("Digite o novo codigo do produto: ");
			        scanf("%s",&newcodigo);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
						while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							if(strcmp(produto[0],codigo1)==0 && strcmp(produto[1],descricao1)==0){ 
								fprintf(fp1,"%s  %s  %s  %s ",newcodigo,produto[1],produto[2],produto[3]);
							}
							else{
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
							}	
						}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);
			    	
				}
			 	
	    	}
	    	else if(x==1){
	    		printf("Digite o novo codigo do produto: ");
			    scanf("%s",&newcodigo);
			    fp=fopen("produtos.txt", "r+"); 
 				fp1=fopen("produtos2.txt","w+");   
				while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						if(strcmp(produto[0],codigo1)==0){ 
							fprintf(fp1,"%s  %s  %s  %s ",newcodigo,produto[1],produto[2],produto[3]);
						}
						else{
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}	
				}
				fclose(fp);
				fclose(fp1);
				fp1=fopen("produtos2.txt", "r+");
				fp=fopen("produtos.txt", "w+");
					while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
					}
				fclose(fp1);
				fclose(fp);	
			}
			else{
				printf("Produto não encontrado, verifique novamente:");
				Sleep(2000);
				
			}
	         break;
	    case 2:
	    	fp=fopen("produtos.txt", "r+");
		    printf("Digite o código do produto que deseja alterar:");
		    scanf("%s",&codigo1);
	        while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
		            if(strcmp(produto[0],codigo1)==0){
			            printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
			            x++;
			        }
		    }
		    fclose(fp);
			if(x>1){
				printf("Deseja mesmo alterar a descrição atual do/dos produtos acima? \n1 - sim \n2 - não");
			    scanf("%d",&escolha2);
			    while(escolha2<1 || escolha2>2){
			        printf("Opção Invalida!");
			        printf("Deseja mesmo alterar o código atual? \n1 - sim \n2 - não");
			        scanf("%d",&escolha2);	
				}
			    if(escolha2==1){
			        printf("Digite a nova descrição do produto: ");
			        scanf("%s",&newdescricao);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
						while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							if(strcmp(produto[0],codigo1)==0){ 
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],newdescricao,produto[2],produto[3]);
							}
							else{
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
							}	
						}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);	
			    }
			    else{
			    	printf("Digite a descrição do produto que deseja alterar:");
			    	scanf("%s",&descricao1);
			    	printf("Digite a nova descrição: ");
			        scanf("%s",&newdescricao);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
				    while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
					    if(strcmp(produto[0],codigo1)==0 && strcmp(produto[1],descricao1)==0){ 
						    fprintf(fp1,"%s  %s  %s  %s ",produto[0],newdescricao,produto[2],produto[3]);
						}
						else{
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}	
					}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);
			    }
			}
			else if(x==1){
	    		printf("Digite a nova descrição: ");
			    scanf("%s",&newdescricao);
			    fp=fopen("produtos.txt", "r+"); 
 				fp1=fopen("produtos2.txt","w+");   
				while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						if(strcmp(produto[0],codigo1)==0){ 
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],newdescricao,produto[2],produto[3]);
						}
						else{
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}	
				}
				fclose(fp);
				fclose(fp1);
				fp1=fopen("produtos2.txt", "r+");
				fp=fopen("produtos.txt", "w+");
					while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
					}
				fclose(fp1);
				fclose(fp);	
			}
			else{
				printf("Produto não encontrado, verifique novamente:");
				Sleep(2000);	
			}
	        break;
	        
	    case 3:
	    	fp=fopen("produtos.txt", "r+");
		    printf("Digite o código do produto que deseja alterar:");
		    scanf("%s",&codigo1);
	        while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
		            if(strcmp(produto[0],codigo1)==0){
			            printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
			            x++;
			        }
		    }
		    fclose(fp);
			if(x>1){
				printf("Deseja mesmo alterar a marca de todos os produtos acima? \n1 - sim \n2 - não");
			    scanf("%d",&escolha2);
			    while(escolha2<1 || escolha2>2){
			        printf("Opção Invalida!");
			        printf("Deseja mesmo alterar o código atual? \n1 - sim \n2 - não");
			        scanf("%d",&escolha2);	
				}
			    if(escolha2==1){
			        printf("Digite a nova marca do produto: ");
			        scanf("%s",&newmarca);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
						while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							if(strcmp(produto[0],codigo1)==0){ 
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],newmarca,produto[3]);
							}
							else{
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
							}	
						}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);	
			    }
			    else{
			    	printf("Digite a descrição do produto que deseja alterar:");
			    	scanf("%s",&descricao1);
			    	printf("Digite a nova marca: ");
			        scanf("%s",&newmarca);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
				    while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
					    if(strcmp(produto[0],codigo1)==0 && strcmp(produto[1],descricao1)==0){ 
						    fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],newmarca,produto[3]);
						}
						else{
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}	
					}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);
			    }
			}
			else if(x==1){
	    		printf("Digite a nova marca: ");
			    scanf("%s",&newmarca);
			    fp=fopen("produtos.txt", "r+"); 
 				fp1=fopen("produtos2.txt","w+");   
				while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						if(strcmp(produto[0],codigo1)==0){ 
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],newmarca,produto[3]);
						}
						else{
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}	
				}
				fclose(fp);
				fclose(fp1);
				fp1=fopen("produtos2.txt", "r+");
				fp=fopen("produtos.txt", "w+");
					while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
					}
				fclose(fp1);
				fclose(fp);	
			}
		else{
				printf("Produto não encontrado, verifique novamente:");
				Sleep(2000);	
			}
		break;
		case 4:
	    	fp=fopen("produtos.txt", "r+");
		    printf("Digite o código do produto que deseja alterar:");
		    scanf("%s",&codigo1);
	        while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
		            if(strcmp(produto[0],codigo1)==0){
			            printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
			            x++;
			        }
		    }
		    fclose(fp);
			if(x>1){
				printf("Deseja mesmo alterar a marca de todos os produtos acima? \n1 - sim \n2 - não");
			    scanf("%d",&escolha2);
			    while(escolha2<1 || escolha2>2){
			        printf("Opção Invalida!");
			        printf("Deseja mesmo alterar o código atual? \n1 - sim \n2 - não");
			        scanf("%d",&escolha2);	
				}
			    if(escolha2==1){
			        printf("Digite a nova quantidade do produto: ");
			        scanf("%s",&newquantidade);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
						while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							if(strcmp(produto[0],codigo1)==0){ 
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[1],newquantidade);
							}
							else{
								fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
							}	
						}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);	
			    }
			    else{
			    	printf("Digite a descrição do produto que deseja alterar:");
			    	scanf("%s",&descricao1);
			    	printf("Digite a nova quantidade: ");
			        scanf("%s",&newquantidade);
			        fp=fopen("produtos.txt", "r+"); 
 					fp1=fopen("produtos2.txt","w+");   
				    while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
					    if(strcmp(produto[0],codigo1)==0 && strcmp(produto[1],descricao1)==0){ 
						    fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],newquantidade);
						}
						else{
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}	
					}
					fclose(fp);
					fclose(fp1);
					fp1=fopen("produtos2.txt", "r+");
					fp=fopen("produtos.txt", "w+");
						while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
							fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}
					fclose(fp1);
					fclose(fp);
			    }
			}
			else if(x==1){
	    		printf("Digite a nova quantidade: ");
			    scanf("%s",&newquantidade);
			    fp=fopen("produtos.txt", "r+"); 
 				fp1=fopen("produtos2.txt","w+");   
				while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						if(strcmp(produto[0],codigo1)==0){ 
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],newquantidade);
						}
						else{
							fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
						}	
				}
				fclose(fp);
				fclose(fp1);
				fp1=fopen("produtos2.txt", "r+");
				fp=fopen("produtos.txt", "w+");
					while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
						fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
					}
				fclose(fp1);
				fclose(fp);	
			}
		else{
				printf("Produto não encontrado, verifique novamente:");
				Sleep(2000);	
			}
		break;			
	}	
}


void excluir(){
	char codigo1[20],produto[4][20],descricao[20];
	int x=0,escolha2;
	FILE *fp,*fp1;
	
    printf("Digite o código do produto que deseja excluir: ");
    scanf("%s",&codigo1);
    
    fp=fopen("produtos.txt", "r+");
	while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
		if(strcmp(produto[0],codigo1)==0){
			printf("Cod: %s --- Descricao: %s --- marca: %s --- quantidade: %s\n",produto[0],produto[1],produto[2],produto[3]);
			x++;
		}
	}
	fclose(fp);
    if(x>=1){
		printf("Deseja Excluir todos os produtos acima? \n1 - sim \n2 - não");
		scanf("%d",&escolha2);
		while(escolha2<1 || escolha2>2){
			printf("Opção Invalida!");
			printf("Deseja Excluir todos os produtos? \n1 - sim \n2 - não");
			scanf("%d",&escolha2);	
		}
		if(escolha2==1){
			fp=fopen("produtos.txt", "r+"); 
 			fp1=fopen("produtos2.txt","w+");   
			while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
				if(strcmp(produto[0],codigo1)!=0){ 
					fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
				}
				else{
					Sleep(1);
				}	
			}
			fclose(fp);
			fclose(fp1);
			fp1=fopen("produtos2.txt", "r+");
			fp=fopen("produtos.txt", "w+");
			while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
					fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
			}
			fclose(fp1);
			fclose(fp);	
		}
		else{
			printf("Digite a descrição do produto que deseja excluir:");
			scanf("%s",&descricao);
			fp=fopen("produtos.txt", "r+"); 
 			fp1=fopen("produtos2.txt","w+");   
			while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
				if(strcmp(produto[0],codigo1)!=0 && strcmp(produto[1],descricao)!=0){ 
					fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
				}
				else{
					Sleep(1);
				}	
			}
			fclose(fp);
			fclose(fp1);
			fp1=fopen("produtos2.txt", "r+");
			fp=fopen("produtos.txt", "w+");
			while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
					fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
			}
			fclose(fp1);
			fclose(fp);
		}
    }
    else if(x==1){
    	printf("Deseja Excluir o produto acima? \n1 - sim \n2 - não");
		scanf("%d",&escolha2);
		while(escolha2<1 || escolha2>2){
			printf("Opção Invalida!");
			printf("Deseja Excluir o produto acima? \n1 - sim \n2 - não");
			scanf("%d",&escolha2);	
		}
		if(escolha2==1){
			fp=fopen("produtos.txt", "r+"); 
 			fp1=fopen("produtos2.txt","w+");   
			while (fscanf(fp,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
				if(strcmp(produto[0],codigo1)!=0){ 
					fprintf(fp1,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
				}
				else{
					Sleep(1);
				}	
			}
			fclose(fp);
			fclose(fp1);
			fp1=fopen("produtos2.txt", "r+");
			fp=fopen("produtos.txt", "w+");
			while (fscanf(fp1,"%s  %s  %s  %s",&produto[0],&produto[1],&produto[2],&produto[3])!=EOF){
					fprintf(fp,"%s  %s  %s  %s ",produto[0],produto[1],produto[2],produto[3]);
			}
			fclose(fp1);
			fclose(fp);	
		}
    	
	}
	else{
	    printf("produto não encontrado!");	
		system("cls");	
	}
}

void sair(){
     exit(EXIT_SUCCESS);
}