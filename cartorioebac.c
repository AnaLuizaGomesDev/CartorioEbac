#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registrar()//Função responsável por cadastrar os usuários no sistema
{//inicio da função

    setlocale(LC_ALL, "Portuguese_Brazil.1252");//definindo a linguagem
    
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//atribuindo as variaveis
	
	printf("\tBem vindo(a) ao menu de cadastro!\n\n");//inicio do menu de cadastrar nomes
	printf("Digite o cpf a ser cadastrado:");//coletando informação do usuário
	scanf("%s", cpf);//solicita o usuario que insira o cpf, %s refere-se a string
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo no banco de dados
	
	if ((file = fopen(arquivo, "r")) != NULL) { // garante que não adicione o mesmo cpf duas vezes
        fclose(file);
        system("cls");
        printf("-> Ja existe um arquivo com esse cpf!\n\n");
        system("pause");
    return 0;//volta para o menu caso o arquivo ja exista
	}
	

	file = fopen(arquivo, "w");
	fprintf(file, "%s", cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	getchar();//Limpa o buffer
	scanf("%[^\n]s", nome);//o computador lê todo o texto que você escreveu até que você pressione "Enter", útil para nomes compostos
	
	file=fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	getchar();//Limpa o buffer
	scanf("%[^\n]s", sobrenome);//o computador lê todo o texto que você escreveu até que você pressione "Enter", útil para mais de um sobrenome
	
	file=fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo da pessoa cadastrada:");
	getchar();
	scanf("%[^\n]s", cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("cls");
	printf("-> O usuario foi cadastrado com sucesso!\n\n");
	
    system("pause");
}//fim da função

int adicionar_nome()
{//inicio da função

    setlocale(LC_ALL, "Portuguese_Brazil.1252");//definindo a linguagem
    
	char opcao;
	int novo_nome=1;
	//atribuindo variaveis
	
	while(novo_nome){
	    system("cls");
    	printf("Deseja adicionar um novo usuario?\n\n");//pergunta se deseja cadastrar um novo usuario
    	printf("Digite 's' ou 'n':");
    	scanf(" %c", &opcao);//armazena a resposta
    	    
    	    if(opcao == 'n' || opcao =='N')
			{
				system("cls");
    	    	novo_nome= 0;
    	    	printf("Voltando para o Menu Principal...\n\n");
    	    	system("pause");
    	    	return 0;
			}
			else if(opcao == 's' || opcao == 'S')
			{
				system("cls");
				printf("Indo para o menu de registro...\n\n");
				system("pause");
				system("cls");
				registrar();
			}
			else 
			{
			    system("cls");
                printf("Opcao indisponivel. Por favor, escolha 's' para sim ou 'n' para nao.\n\n");//caso a resposta nao esteja dentro do esperado
                system("pause");
            }
   }
}//fim da função

int consultar()//Função responsável por consultar os nomes do sistema
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	//inserindo as variaveis
	
	printf("\tBem vindo(a) ao Menu de consulta de nomes!\n\n");//inicio do menu de consulta de nomes
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE*file;
	file=fopen(cpf,"r");//abre o arquivo "cpf", "r" = read/ler
	
	if(file == NULL)// se o arquivo for nulo
	{
		system("cls");
		printf("-> Nao foi possivel abrir o arquivo, nao localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto o arquivo tiver informação e for diferente de nulo
	{
		printf("\nEssas sao as informacoes do usuario:");
		
		token = strtok(conteudo, ",");//variavel utilizado para dividir a string em linhas
		printf("\n\nCPF: %s\n", token);//informação que aparece antes dos dados do cpf
		
		token = strtok(NULL, ",");//variavel utilizado para dividir a string em linhas
		printf("Nome: %s\n", token);//informação que aparece antes dos dados do nome
		
		token = strtok(NULL, ",");//variavel utilizado para dividir a string em linhas
		printf("Sobrenome: %s\n", token);//informação que aparece antes dos dados do sobrenome
		
		token = strtok(NULL, ",");//variavel utilizado para dividir a string em linhas
		printf("Cargo: %s\n", token);//informação que aparece antes dos dados do cargo
	}
	
	fclose(file);
	
	printf("\n");
	system("pause");
	//fim do menu de consultar nomes
}

int consultar_novo()//Função que pergunta se deseja consultar outro usuário
{//inicio da função

	setlocale(LC_ALL, "Portuguese_Brazil.1252");//definindo a linguagem
	
	char opcao;
	int novo_nome=1;
	//atribuindo as variáveis
	
	while(novo_nome){
	    system("cls");
    	printf("Deseja consultar um novo usuario?\n\n");//pergunta se deseja consultar um novo usuario
    	printf("Digite 's' ou 'n':");
    	scanf(" %c", &opcao);//armazena a resposta
    	    
    	    if(opcao == 'n' || opcao =='N')
			{
				system("cls");
    	    	novo_nome= 0;
    	    	printf("Voltando para o Menu Principal...\n\n");
    	    	system("pause");
    	    	return 0;
			}
			else if(opcao == 's' || opcao == 'S')
			{
				system("cls");
				printf("Indo para o menu de consulta...\n\n");
				system("pause");
				system("cls");
				consultar();
			}
			else
			{
			    system("cls");
                printf("Opcao indisponivel. Por favor, escolha 's' para sim ou 'n' para nao.\n\n");//caso a opcao nao esteja dentro do esperado
                system("pause");
            }
   }
}//fim da função

int deletar()//Função responsável por deletar o usuário
{//inicio da função
	setlocale(LC_ALL, "Portuguese_Brazil.1252");//definindo a linguagem
	
	char cpf[40];
	int opcao=0;
	//inserindo as variaveis
	
	printf("\tBem vindo(a) ao Menu de deletar nomes!\n\n");//inicio do menu de deletar nomes
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	FILE*file;
	file=fopen(cpf,"r");//verifica se o cpf inserido esta no sistema
	
	if(file == NULL)
	{
		system("cls");
		printf("-> O usuario de CPF: %s nao se encontra no sistema!\n\n", cpf);//caso o usuario nao esteja no sistema
		system("pause");
		return 0;
	}
	fclose(file);
	
	printf("\nDeseja mesmo deletar o usuario de CPF: %s ?", cpf);//confirmação de deletar o usuario
	printf("\n\t1 - Sim\n");
	printf("\t2 - Nao\n");
	printf("\nOpcao: ");
	scanf("%d", &opcao);
	
	switch(opcao)//inicio da seleção de opções
	{
		case 1://caso queira deletar o usuario
			system("cls");
			remove(cpf);//remove o usuario do sistema
			printf("-> O usuario de CPF: %s foi deletado com sucesso!\n\n", cpf);
			system("pause");
		break;
		
		case 2:
			system("cls");//caso nao queira deletar o usuario do sistema
			printf("-> O usuario de CPF: %s nao foi deletado!\n\n", cpf);
			system("pause");
		break;
		
		default:
			system("cls");//caso insira um valor que nao corresponde a nenhuma das opções
			printf("-> O usuario de CPF: %s nao existe!\n\n", cpf);
			system("pause");
		break;
	}//fim da seleção de opções
	
}//fim da função

int deletar_novo()//Função responsável por perguntar se deseja deletar outro usuario
{//inicio da função
    
    setlocale(LC_ALL, "Portuguese_Brazil.1252");//definindo a linguagem
    
	char opcao;
	int novo_nome=1;
	//atribuindo variaveis
	
	while(novo_nome){
	    system("cls");
    	printf("Deseja deletar outro usuario?\n\n");//pergunta se deseja deletar outro usuário
    	printf("Digite 's' ou 'n':");
    	scanf(" %c", &opcao);//armazena a resposta do usuário
    	    
    	    if(opcao == 'n' || opcao =='N')
			{
				system("cls");
    	    	novo_nome= 0;
    	    	printf("Voltando para o Menu Principal...\n\n");
    	    	system("pause");
    	    	return 0;
			}
			else if(opcao == 's' || opcao == 'S')
			{
				system("cls");
				printf("Indo para o menu de Deletar Usuario...\n\n");
				system("pause");
				system("cls");
				deletar();//chama a função deletar novamente
			}
			else
			{
			    system("cls");
                printf("Opcao indisponivel. Por favor, escolha 's' para sim ou 'n' para nao.\n\n");//caso a opcao nao esteja dentro do esperado
                system("pause");
            }
   }
}//fim da função

int main()//Função do menu principal
{//inicio da função
	char opcao_registro;
	int opcao=0; //definindo variáveis
	int x=1;
	
	for(x=1;x=1;){	
	
	    system("cls");
	
    	setlocale(LC_ALL, "Portuguese_Brazil.1252");//definindo a linguagem
	
    	printf("### Cartorio da Ebac ###\n\n");//início do menu
	    printf("Escolha a opcao desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");//fim do menu
    	printf("Opcao: ");
	
    	scanf("%d", &opcao);//armazenando a escolha do usuário
	
    	system("cls");//limpar a tela
    	
    	switch(opcao)//inicio da seleção
    	{
    		case 1:
    	    registrar();
			adicionar_nome();
			break;	
       		    
    		case 2:
    		consultar();
    		consultar_novo();
    	    break;
    		
    		case 3:
    		deletar();
    		deletar_novo();
    		break;
    		    
    		default:
    		printf("Essa opcao nao esta disponivel!\n");
    		system("pause");
    		break;
    		//fim da seleção
		}
    }
}//fim da função
