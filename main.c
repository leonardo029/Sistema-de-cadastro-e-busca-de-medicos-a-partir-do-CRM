#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//Struct responsável por armazenar os dados que serão utilizados;
typedef struct node{

    //Informações do nó da árvore;
    int CRM;
    struct node *left, *right;
    int height;

    //Informações do médico;
    char name_doctor[120];
    double cpf;
    double phone;
    char specialty[40];

}Node;

//Função responsável por cadastrar um novo médico;
void register_doctor(Node **root, int crm){

    if(*root == NULL){

        *root = (Node*) malloc(sizeof(Node));
        (*root)->CRM = crm;
        (*root)->right = NULL;
        (*root)->left = NULL;

        printf("Insira o nome do medico:\n");
        getchar();
        scanf("%[^\n]", (*root)->name_doctor);

        printf("Insira o CPF do medico. Modelo: XXXXXXXXXXX\n");
        scanf("%lf", &(*root)->cpf);

        getchar();
        printf("Insira a especialida do medico:\n");
        scanf("%[^\n]", (*root)->specialty);

        printf("Insira o telefone do medico. Modelo: DDD9XXXXXXXX\n");
        scanf("%lf", &(*root)->phone);

    }

    else{
        if(crm < ((*root)->CRM)){
            register_doctor(&((*root)->left), crm);
        }
        else if(crm > (*root)->CRM){
            register_doctor(&((*root)->right), crm);
        }
        else{
            printf("\nO CRM inserido ja consta em nosso banco de dados!\n\n");
        }
    }
};

//Função responsável por procurar um médico já cadastrado;
void search_doctor(Node *root, int key){

	if(root == NULL){
        printf("\nMedico nao encontrado em nosso banco de dados!\n\n");
    }
  
    else{
        if(root->CRM == key){

            printf("\nMedico encontrado!\n\n");
            printf("Nome: %s\n", root->name_doctor);
            printf("Especialidade: %s\n", root->specialty);
            printf("CRM: %d\n", root->CRM);
            printf("CPF: %0.lf\n", root->cpf);
            printf("Telefone: %0.lf\n\n", root->phone);

        }
        else{
            if(key < root->CRM){
                search_doctor(root->left, key);
            }
            else{
                search_doctor(root->right, key);
            }
        }
    }
  
};

//Função responsável por calcular a altura de um nó da árvore (usar para auxiliar em outras funções);
int node_height(Node *node)
{
    if(node == NULL)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

//Função responsável por retornar a altura da árvore (usar no menu);
int tree_height(Node *root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        int l = tree_height(root->left); //variável que recebe a altura da subárvore esquerda (l = left)
        int r = tree_height(root->right); //variável que recebe a altura da subárvore direita (r = right)
        if(l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }
}

//Função que retorna o maior entre dois valores
int largest_value(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//Função responsável por calcular e retornar o fator de balanceamento
int balancing_factor(Node *node)
{
    if(node)
    {
        return (node_height(node->left) - node_height(node->right)); 
    }
    else
    {
        return 0;
    }
}

//Função de rotação esquerda
Node *left_rotation(Node *root)
{
    Node *newRoot, *son;

    newRoot = root->right;
    son = newRoot->left;
    newRoot->left = root;
    root->right = son;

    root->height = largest_value(node_height(root->left), node_height(root->right)) + 1;
    newRoot->height = largest_value(node_height(newRoot->left), node_height(newRoot->right)) + 1;

    return newRoot;
}

//Função de rotação direita
Node *right_rotation(Node *root)
{
    Node *newRoot, *son;

    newRoot = root->left;
    son = newRoot->right;
    newRoot->right = root;
    root->left = son;

    root->height = largest_value(node_height(root->left), node_height(root->right)) + 1;
    newRoot->height = largest_value(node_height(newRoot->left), node_height(newRoot->right)) + 1;

    return newRoot;
}

//Função rotação dupla 1 (esquerda-direita)
Node *leftRight_rotation(Node *root)
{
    root->left = left_rotation(root->left);
    return right_rotation(root);
}

//Função rotação dupla 2  (direita-esquerda)
Node *rightLeft_rotation(Node *root)
{
    root->right = right_rotation(root->right);
    return left_rotation(root);
}

//Função responsável por balancear a árvore após inserir ou remover um elemento
Node *balancing(Node *root)
{
    int bf = balancing_factor(root);
    if(bf < -1 && balancing_factor(root->right) <= 0)
    {
        root = left_rotation(root);
    } 
    else if(bf > 1 && balancing_factor(root->left) >= 0)
    {
        root = right_rotation(root);
    }
    else if(bf > 1 && balancing_factor(root->left) < 0)
    {
        root = leftRight_rotation(root);
    }
    else if(bf < -1 && balancing_factor(root->right) > 0)
    {
        root = rightLeft_rotation(root);
    }

    return root;
}

//Função responsável por descadastrar um médico;
Node *remove_doctor(Node *root, int key)
{
    if (root == NULL) //Verifica se a raiz é nula caso seja, notifica o erro.
    {
        printf("Médico não encontrado!");
        return NULL;
    }
    else
    {
        if (root->CRM == key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                printf("Médico removido!: %d ! \n", key);
                return NULL;
            }
            else
            {
                if (root->left != NULL && root->right != NULL)
                {
                    Node *aux = root->left;
                    while (aux->right != NULL)
                    {
                        aux = aux->right;
                        root->CRM = aux->CRM;
                        aux->CRM = key;
                        printf("Médico alterado: %d ! \n", key);
                        root->left = remove_doctor(root->left, key);
                        return root;
                    }
                }
                else
                {
                    Node *aux;
                    if (root->left != NULL)
                    {
                        aux = root->left;
                    }
                    else
                    {
                        aux = root->right;
                        free(root);
                        printf("Médico associado removido: %d !\n", key);
                        return aux;
                    }
                }
            }
        }
        else
        {
            if (key < root->CRM)
            {
                root->left = remove_doctor(root->left, key);
            }
            else
            {
                root->right = remove_doctor(root->right, key);
            }
        }

        root->height = largest_value(node_height(root->left), node_height(root->right)) + 1;
        root = balancing(root);

        return root;
    }
}

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
    int search_crm, register_crm, remove_crm, option;

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
                    scanf("%d", &register_crm);
            		register_doctor(&no, register_crm);
                break;
            
            case 2:
                    printf("Insira o CRM do médico a ser removido:\n");    
                    scanf("%d", &remove_crm);         
            		remove_doctor(no, remove_crm);
                break;

            case 3:
            		printf("Insira o CRM a ser buscado:\n");
                    scanf("%d", &search_crm);
            		search_doctor(no, search_crm);
                break;
            
            case 4:
                    printf("Altura da arvore: %d\n\n", tree_height(no));
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