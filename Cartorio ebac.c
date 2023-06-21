#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar do string
int registro() //Fun��o respons�vel por cadastrar os �suarios no sistema
{
	//Inicio cria��o de vari�vel/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//Inicio cria��o de vari�vel/string
	
	printf("Digite o CPF a ser Cadastrado:"); //Coletando inform��o do usu�rio
	scanf("%s", cpf); //%s Refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o Arquivo
	file = fopen(arquivo, "w"); //Cria o Arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da Variavel
	fclose(file); // Fecha o Arquivo
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informa��o
	fprintf (file, ","); //Salva o valor da Variavel "," significa separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser Cadastrado:"); //Coletando inform��o do usu�rio
	scanf("%s", nome); //%s Refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informa��o
	fprintf(file,nome); //Salva o valor da Variavel
	fclose(file); //Fechao arquivo
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informa��o
	fprintf (file, ","); //Salva o valor da Variavel "," significa separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser Cadastrado:"); //Coletando inform��o do usu�rio
	scanf("%s", sobrenome); //%s Refere-se a string
	
	file = fopen(arquivo,"a"); //Cria o Arquivo e "a" significa atualizar a informa��o
	fprintf(file,sobrenome); //Salva o valor da Variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informa��o
	fprintf (file, ","); //Salva o valor da Variavel "," significa separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser Cadastrado: "); //Coletando inform��o do usu�rio
	scanf("%s",cargo); //%s Refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informa��o
	fprintf(file,cargo); //Salva o valor da Variavel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o sistem e espera por uma tecla
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //Inicio cria��o de vari�vel/string
	char conteudo[200]; //Inicio cria��o de vari�vel/string
	
	printf("Digite o Cpf a ser consultado: "); //Coletando inform��o do usu�rio
	scanf("%s",cpf); //%s Refere-se a string
	
	FILE *file; //Cria o Arquivo
	file = fopen(cpf, "r"); //Cria o Arquivo e o "r" significa ler
	
	if(file == NULL) //Arquivo n�o localizado
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); //Resposta do arquivo nao localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Procurando arquivo, parando somente se for nulo...
	{
		printf("\Essas s�o as informa��es do usu�rio: "); 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
		
		printf(" <Cart�riro da EBAC>\n\n"); //Inicio do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "  );//Fim do Menu
	
 		scanf("%d", &opcao); //Armazenamento da Escolha do Usu�rio
 	
 		system("cls"); //Respons�vel pro limpar a tela
 		
 		switch(opcao) //Chamada de fun��es
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
	 		printf("Essa op��o n�o est� disponivel\n"); 
	 		system("pause");
	 		break;
	 		// fim da sele��o
	 	}
	}
 	
}
	


