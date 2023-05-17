#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Struct responsável por armazenar os dados que serão utilizados;
typedef struct node{

    //Informações do nó da árvore;
    int CRM;
    struct node *left, *right;

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
int search_doctor(Node *root, int key){

	if(root == NULL){
        printf("Médico não encontrado em nosso banco de dados!\n");
        return(-1);
    }
  
    else{
        if(root->CRM == key){
            printf("Médico encontrado!\n\n");
            printf("Nome: %s\n", root->name_doctor);
            printf("Especialidade: %s\n", root->specialty);
            printf("CRM: %d\n", root->CRM);
            printf("CPF: %d\n", root->cpf);
            printf("Telefone: %d\n\n", root->phone);
            return(0);
        }
        else{
            if(key < root->CRM){
                return search_doctor(root->left, key);
            }
            else{
                return search_doctor(root->right, key);
            }
        }
    }
  
};

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
    Node *no = NULL;
    int search_crm;
    
    int option;

    do{
        print_menu();
        printf("Insira uma opcao: ");
        scanf("%d",&option);

        switch(option){

            case 0:
                break;

            case 1:
            		register_doctor();
                break;
            
            case 2:
            		remove_doctor();
                break;

            case 3:
            		printf("Insira o CRM a ser buscado: ");
                    scanf("%d", &search_crm);
            		search_doctor(no, search_crm);
                break;
            
            case 4:
            		tree_height();
                break;

            case 5:
            		test();
                break;

            default:
                printf("Erro!!\nOpcao selecionada nao existe. Insira novamente!!\n");

        }

    }while(option != 0);

    return 0;
}