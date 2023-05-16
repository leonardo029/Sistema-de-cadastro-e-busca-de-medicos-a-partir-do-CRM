#include <stdlib.h>
#include <stdio.h>

void print_menu(){

    printf("-------------------MENU--------------------\n");
    printf("1 - Cadastrar medico\n");
    printf("2 - Remover medico\n");
    printf("3 - Buscar medico\n");
    printf("4 - Numero de medicos cadastrados\n");
    printf("5 - Sair\n");
    printf("-------------------------------------------\n");

}

int main(){
    
    int option;

    do{
        print_menu();
        printf("Insira uma opcao: ");
        scanf("%d",&option);

        switch(option){

            case 1:
                break;
            
            case 2:
                break;

            case 3:
                break;
            
            case 4:
                break;
            
            case 5:
                break;
            default:
                printf("Erro!!\nOpcao selecionada nao existe. Insira novamente!!\n");

        }

    }while(option != 5);

    return 0;
}
