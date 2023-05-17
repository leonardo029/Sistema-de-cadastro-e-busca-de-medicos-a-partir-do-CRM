#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Struct responsável por armazenar os dados que serão utilizados;
typedef struct node{

    //Informações do nó da árvore;
    int CRM;
    struct node *left, *right;
    struct doctor *data;

    //Informações do médico;
    char name_doctor[120];
    int cpf;
    int phone;
    char specialty[30];

}Node;

//Função responsável por cadastrar um novo médico;
void register_doctor();

//Função responsável por descadastrar um médico;
Node* remove_doctor();

//Função responsável por procurar um médico já cadastrado;
void search_doctor();

//Função responsável por retornar a altura da árvore;
void tree_height();

//Função responsável por iniciar os testes;
void test();

//Função responsável por printar o menu de opções do programa;
void print_menu(){

    printf("-------------------MENU--------------------\n");
    printf("1 - Cadastrar médico\n");
    printf("2 - Remover médico\n");
    printf("3 - Buscar médico\n");
    printf("4 - Altura da árvore\n");
    printf("5 - Iniciar teste\n");
    printf("0 - Sair\n");
    printf("-------------------------------------------\n");

}

int main(){

    setlocale(LC_ALL, "");
    
    int option;

    do{
        print_menu();
        printf("Insira uma opcao: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            		register_doctor();
                break;
            
            case 2:
            		remove_doctor();
                break;

            case 3:
            		search_doctor();
                break;
            
            case 4:
            		tree_height();
                break;

            case 5:
            		test();
                break;
            
            case 0:
                break;
            default:
                printf("Erro!!\nOpcao selecionada nao existe. Insira novamente!!\n");

        }

    }while(option != 0);

    return 0;
}