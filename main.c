#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Struct responsável por armazenar os dados que serão utilizados;
typedef struct node{

    //Informações do nó da árvore;
    unsigned int CRM;
    struct node *left, *right;

    //Informações do médico;
    char name_doctor[120];
    int cpf[11];
    int phone[11];
    char specialty[30];

}Node;

//Função responsável por cadastrar um novo médico;
void register_doctor(Node *root, unsigned int crm){

    if(root == NULL){

        Node *newRoot = malloc(sizeof(Node));
        newRoot->CRM = crm;
        newRoot->right = NULL;
        newRoot->left = NULL;

        printf("Insira o nome do medico:\n");
        getchar();
        scanf("%[^\n]", newRoot->name_doctor);

        printf("Insira o CPF do medico. Modelo: XXXXXXXXXXX\n");
        scanf("%d", newRoot->cpf);

        getchar();
        printf("Insira a especialida do medico:\n");
        scanf("%s", newRoot->specialty);

        printf("Insira o telefone do medico:\n");
        scanf("%d", newRoot->phone);

    }

    else{
        if(crm < root->CRM){
            return (register_doctor(root->left, crm));
        }
        else if(crm > root->CRM){
            return (register_doctor(root->right, crm));
        }
        else{
            printf("O CRM inserido ja consta em nosso banco de dados!\n\n");
        }
    }
};

//Função responsável por descadastrar um médico;
//Node* remove_doctor();

//Função responsável por procurar um médico já cadastrado;
int search_doctor(Node *root, unsigned int key){

	if(root == NULL){
        printf("Medico nao encontrado em nosso banco de dados!\n");
        return(-1);
    }
  
    else{
        if(root->CRM == key){
            int i, j;

            printf("Medico encontrado!\n\n");
            printf("Nome: %s\n", root->name_doctor);
            printf("Especialidade: %s\n", root->specialty);
            printf("CRM: %u\n", root->CRM);
            printf("CPF: ");
                for(i=0; i<12; i++){
                    printf("%d", root->cpf[i]);
                }
            printf("\n");
            printf("Telefone: ");
                for(j=0; j<12; j++){
                    printf("%d", root->phone[j]);
                }
            printf("\n\n");

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
//void tree_height();

//Função responsável por iniciar os testes;
//void test();

//Função responsável por printar o menu de opções do programa;
void print_menu(){

    printf("-------------------MENU--------------------\n");
    printf("1 - Cadastrar medico\n");
    printf("2 - Remover medico\n");
    printf("3 - Buscar medico\n");
    printf("4 - Altura da arvore\n");
    printf("5 - Iniciar teste\n");
    printf("0 - Sair\n");
    printf("-------------------------------------------\n");

}

int main(){

    setlocale(LC_ALL, "");
    Node *no = NULL;
    unsigned int search_crm, register_crm;
    int option;

    do{
        print_menu();
        printf("Insira uma opcao: ");
        scanf("%d",&option);
        printf("\n");

        switch(option){

            case 0:
                printf("\nObrigado por utilizar nosso sistema!\nAte logo!\n\n");
                break;

            case 1:
                    printf("Insira o CRM a ser cadastrado:\n");
                    scanf("%u", &register_crm);
            		register_doctor(no, register_crm);
                break;
            
            case 2:
            		//remove_doctor();
                break;

            case 3:
            		printf("Insira o CRM a ser buscado:\n");
                    scanf("%u", &search_crm);
            		search_doctor(no, search_crm);
                break;
            
            case 4:
            		//tree_height();
                break;

            case 5:
            		//test();
                break;

            default:
                printf("\nErro!!\nA opcao selecionada nao existe. Tente novamente!!\n\n");

        }

    }while(option != 0);

    return 0;
}