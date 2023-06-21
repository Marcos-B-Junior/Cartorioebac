#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar do string
int registro() //Função responsável por cadastrar os úsuarios no sistema
{
	//Inicio criação de variável/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//Inicio criação de variável/string
	
	printf("Digite o CPF a ser Cadastrado:"); //Coletando informção do usuário
	scanf("%s", cpf); //%s Refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o Arquivo
	file = fopen(arquivo, "w"); //Cria o Arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da Variavel
	fclose(file); // Fecha o Arquivo
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informação
	fprintf (file, ","); //Salva o valor da Variavel "," significa separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser Cadastrado:"); //Coletando informção do usuário
	scanf("%s", nome); //%s Refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informação
	fprintf(file,nome); //Salva o valor da Variavel
	fclose(file); //Fechao arquivo
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informação
	fprintf (file, ","); //Salva o valor da Variavel "," significa separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser Cadastrado:"); //Coletando informção do usuário
	scanf("%s", sobrenome); //%s Refere-se a string
	
	file = fopen(arquivo,"a"); //Cria o Arquivo e "a" significa atualizar a informação
	fprintf(file,sobrenome); //Salva o valor da Variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informação
	fprintf (file, ","); //Salva o valor da Variavel "," significa separar
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser Cadastrado: "); //Coletando informção do usuário
	scanf("%s",cargo); //%s Refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o Arquivo e "a" significa atualizar a informação
	fprintf(file,cargo); //Salva o valor da Variavel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o sistem e espera por uma tecla
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //Inicio criação de variável/string
	char conteudo[200]; //Inicio criação de variável/string
	
	printf("Digite o Cpf a ser consultado: "); //Coletando informção do usuário
	scanf("%s",cpf); //%s Refere-se a string
	
	FILE *file; //Cria o Arquivo
	file = fopen(cpf, "r"); //Cria o Arquivo e o "r" significa ler
	
	if(file == NULL) //Arquivo não localizado
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n"); //Resposta do arquivo nao localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Procurando arquivo, parando somente se for nulo...
	{
		printf("\Essas são as informações do usuário: "); 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usuário não se encontra no sistema!.\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
		
		printf(" <Cartóriro da EBAC>\n\n"); //Inicio do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "  );//Fim do Menu
	
 		scanf("%d", &opcao); //Armazenamento da Escolha do Usuário
 	
 		system("cls"); //Responsável pro limpar a tela
 		
 		switch(opcao) //Chamada de funções
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
	 		printf("Essa opção não está disponivel\n"); 
	 		system("pause");
	 		break;
	 		// fim da seleção
	 	}
	}
 	
}
	


