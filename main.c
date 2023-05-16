#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct node{

    int CRM;
    struct node *left, *right;
    struct doctor *data;

}Node;

typedef struct doctor{

	    char *name_doctor;
      int cpf;
      int phone;
      char *specialty;

}Doctor;

void register_doctor();

Node* remove_doctor();

void search_doctor();

void tree_size();

void print_menu(){

    printf("-------------------MENU--------------------\n");
    printf("1 - Cadastrar medico\n");
    printf("2 - Remover medico\n");
    printf("3 - Buscar medico\n");
    printf("4 - Numero de medicos cadastrados\n");
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
            		tree_size();
                break;
            
            case 0:
                break;
            default:
                printf("Erro!!\nOpcao selecionada nao existe. Insira novamente!!\n");

        }

    }while(option != 0);

    return 0;
}