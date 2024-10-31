
//  Primeiro Projeto
//
//  Created by Patricia Benchimol on 2024-10-14.
//

#include <stdio.h> //Biblioteca de comunicação com usuário
#include <stdlib.h> //Bliblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alicação de texo por região
#include <string.h> //biblioteca responsavel por cuidar das string
#include <stdio.h>

int registrar()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF para cadastrar: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file, "%s", cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file=fopen(arquivo, "a");
    fprintf(file," - ");
    fclose(file);
    
    printf("Digite o nome para cadastrar: ");
    scanf("%s",nome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);
    
    file=fopen(arquivo, "a");
    fprintf(file," ");
    fclose(file);
    
    printf("Digite o sobrenome para cadastrar: ");
    scanf("%s",sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file,"%s", sobrenome);
    fclose(file);
    
    file=fopen(arquivo, "a");
    fprintf(file," - ");
    fclose(file);

    printf("Digite o cargo para cadastrar: ");
    scanf("%s",cargo);
    file = fopen(arquivo, "a");
    fprintf(file,"%s", cargo);
    fclose(file);
    
    printf("\n Pressione enter para continuar!");
    while ((getchar()) != '\n');
    getchar();
    
    return 0;
}

int consultar()
{
    char cpf[40];
    char conteudo[100];
    
    printf("Digite o CPF para consultar: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if (file==NULL)
    {
        printf("Cadastro nao localizado! \n\n");
    }
    while(fgets(conteudo, 100, file) != NULL)
    {
        printf("\nAqui estao as informacoes do usuario: \n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    printf("\n Pressione enter para continuar!");
    while ((getchar()) != '\n');
    getchar();
    return 0;
}

int deletar()
{
    char cpf [40];
    
    printf("Digite o CPF do usuario que deseja deletar: ");
    scanf("%s",cpf);
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("Usuario nao se encontra no sistema! \n");
        printf("\n Pressione enter para continuar!");
        while ((getchar()) != '\n');
        getchar();
    }
    return 0;
}

int main()
    {
    int opcao=0; //Definindo variaveis
    
    int x=1;
    
    for(x=1;(x=1);)
    {
        system("clear");
        
        setlocale(LC_ALL, "Portuguese");
    
        printf("\t CADASTRO DE ALUNOS DA EBAC\n\n"); //Inicio do menu
        printf("Escolha a opção desejada no menu abaixo:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("OPCAO: "); //Fim do menu
            
        scanf("%d" , &opcao); //Armazenando a escolha do usuario
        
        system("clear");
    
        switch(opcao)
        {
            case 1:
                registrar();
                break;
            
            case 2:
                consultar();
                break;
            
            case 3:
                deletar();
                break;
                
            case 4:
                printf("Obrigada por utilizar o sistema.\n");
                return 0;
                break;
            
            default:
            printf("Esta opcao nao esta disponivel\n\n");
            while ((getchar()) != '\n');
            getchar();
            break;
                    
        }
    }

}
