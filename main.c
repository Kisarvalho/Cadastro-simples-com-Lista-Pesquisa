#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 200 //Definindo no programa inteiro o numero de linhas SIZE 200
#include "caminhos.h"

//Declarando as variaveis do cadastro fora da main


char nome[SIZE] [50]; //Variavel do nome, com o numero de linha definido com limite de 50 caracteres
char email[SIZE] [50];
int cpf[SIZE];
int n_cadastro;
int opcao;

void cadastro(); //função cadastro
void pesquisa();//Função pesquisa
void lista();

int main(void)
{
    do{
        system("cls");
        printf("\n----Menu----\n");
        printf("1- Cadastrar\n2- Listar todos os clientes\n3- Pesquisar\n4- Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
            switch(opcao){
                case 1:
                    cadastro();
                break;

                case 2:
                    lista();
                break;

                case 3:
                    pesquisa();
                break;

                case 4:
                    system("exit");
                break;

                default:
                    printf("Opcao Invalida!");
                    getchar();
                    getchar();
                break;
            }
    }while(opcao!=4);
}

//Função Lista
void lista(){
    int i;
        for(i=0;i<SIZE;i++){
            if(cpf[i]>0){
                printf("\nNome: %s \nEmail: %s \nCPF:%d", nome[i], email[i], cpf[i]);
                printf("\n");
            }else{
                break;
            }
        }
        getchar();
        getchar();
}

//Função Cadastro
void cadastro()
{
    static int linha;
    do{
        printf("\nDigite o nome: ");
        scanf("%s", &nome[linha]);
        printf("\nDigite o email: ");
        scanf("%s", &email[linha]);
        printf("\nDigite o CPF: ");
        scanf("%d", &cpf[linha]);
        printf("\nDigite 1 para continuar ou outro valor para sair ");
        scanf("%d", &opcao);
        linha++;
    }while(opcao==1);
    //Fim da função cadastro
}

//Função Pesquisa
void pesquisa()
{
    int cpfPesquisa;
    char emailPesquisa[50];
    int i; //Linhas

    do{
        printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar por email: ");
        scanf("%d", &opcao);
            switch(opcao){
            case 1:
            printf("\nDigite o CPF: ");
            scanf("%d", &cpfPesquisa);
                for(i=0;i<SIZE;i++){
                    if(cpf[i]==cpfPesquisa){
                        printf("\nNome: %s \nEmail: %s \nCPF:%d", nome[i], email[i], cpf[i]);
                        printf("\n");
                    }
                }
                break;

            case 2:
                printf("\nDigite o E-mail: ");
                scanf("%s", emailPesquisa);
                    for(i=0;i<SIZE;i++){
                        if(strcmp(email[i], emailPesquisa)==0){
                            printf("\nNome: %s \nEmail: %s \nCPF:%d", nome[i], email[i], cpf[i]);
                            printf("\n");
                        }
                    }
                break;

            default:
                printf("\n Opcao Invalida");
                break;
            }
        printf("\nDigite 1 para continuar pesquisando: ");
        scanf("%d", &opcao);
    }while(opcao==1);
}
