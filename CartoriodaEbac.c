#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro()
{
	char arquivo[40]; //nome do arquivo
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s le cada caracter e armazena na string
	
	strcpy(arquivo, cpf); //copia os valores das strings num arquivo
	
	FILE *file; //comando inicial para criar o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo no modo escrever
	fprintf(file, cpf); //escreve o valor de cpf no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acrescentar dados no arquivo (append)
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o primeiro nome: ");
	scanf("%s", &nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //acrescentar dados no arquivo (append)
	fprintf(file, ",");
	fclose(file);
		
	printf("Digite o sobrenome: ");
	scanf("%s", &sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //acrescentar dados no arquivo (append)
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", &cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//coleta informacao do usuario
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir o arquivo para ler
	
	if(file == NULL)//caso o cpf digitado nao exista no registro, exibe mensagem de erro
	{
			printf("\nArquivo n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Informa��es do usu�rio:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}	
		
	system("pause");	
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s", cpf);//coleta informacao do usuario
		
		remove(cpf);
	
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)//verifica se o cpf digitado existe no banco de dados. caso n�o exista exibe mensagem de erro
		{
			printf("Usu�rio n�o cadastrado!\n\n");
			system("pause");
		}
		
				
		
}

int main()
{
	int opcao=0; //vari�vel para escolha do menu
	int loop=1; //vari�vel para repeti��o do loop
	
	for(loop=1;loop=1;)
	{
		system("cls"); //limpeza da tela
		
		setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem
	 
	 	printf("### Cart�rio da EBAC ###\n\n"); //titulo e inicio do menu
	 	printf("Escolha a op��o desejada do menu:\n\n");
	 	printf("\t1 - Registrar nomes\n");
	 	printf("\t2 - Consultar nomes\n");
	 	printf("\t3 - Deletar nomes\n"); 
	 	printf("\n\nDigite o n�mero da op��o:   ");//fim do menu
	 
	 
	 	scanf("%d", &opcao); //escolha do usu�rio armazenada na vari�vel
	 
	 	system("cls"); //limpeza da tela
	 	
	 	switch(opcao) //substituicao do if - inicio da escolha
	 	
	 	{
	 		case 1:
	 		registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
					
			default:
			printf("Op��o inv�lida!\n");
	 		system("pause");
			break;
			
		}	// fim da escolha
	}
	 
	 printf("\n\nSoftware by Luci"); //sei que n�o aparece mas deixei aqui para pr�ximas aulas
}


