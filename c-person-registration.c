/**
 * @file c-person-registration.c
 * @author Henrique Dourado (hmdourado08@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-10
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <string.h>

//Estruturas para os Dados dos usuários
struct Data {
    int dia;
    int mes;
    int ano;
};

union Documento {
    char passaporte[8];
    char cpf[12];
};

enum Nacionalidade {BRASILEIRO, ESTRANGEIRO};

typedef struct {
    char nome[30];
    float peso;
    int idade;
    struct Data data;
    enum Nacionalidade nacao;
    union Documento docs;
} Cadastro;


int main (){
    
    //Variáveis utilizadas a partir das estruturas de dados
    Cadastro pessoa[5];
    char entradaNacionalidade[30];
    
    //Laço de repetição para coletar os dados dos 5 usuários
    for (int i = 0; i < 5; i++){
        setbuf(stdin, NULL);   
        printf("\nDigite o %d nome: ", i+1);
        fgets (pessoa[i].nome, 30, stdin);
        pessoa[i].nome[strcspn(pessoa[i].nome, "\n")] = '\0';
        setbuf(stdin, NULL);
        
        printf("Digite a idade %s: ", pessoa[i].nome);
        scanf ("%d", &pessoa[i].idade);
        setbuf(stdin, NULL);
        
        printf("Digite o peso %s: ", pessoa[i].nome);
        scanf ("%f", &pessoa[i].peso);
        
        printf("Digite sua data de nascimento nesse formato (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &pessoa[i].data.dia, &pessoa[i].data.mes, &pessoa[i].data.ano);
        setbuf(stdin, NULL);       
        
        //Lógica que repete a entrada até que uma nacionalidade válida seja informada
        int nacionalidadeValida = 0;
        while (nacionalidadeValida == 0){

            printf("Digite sua nacionalidade (BRASILEIRO OU ESTRANGEIRO): ");
            fgets (entradaNacionalidade, 30, stdin);
            entradaNacionalidade[strcspn(entradaNacionalidade, "\n")] = '\0';
            setbuf(stdin, NULL);

            //Condições para Nacionalidade e Documento de Identificação
            if (
                strcmp(entradaNacionalidade, "BRASILEIRO") == 0 ||
                strcmp(entradaNacionalidade, "Brasileiro") == 0 ||
                strcmp(entradaNacionalidade, "brasileiro") == 0
            ) {

                nacionalidadeValida = 1;
                pessoa[i].nacao = BRASILEIRO;

                printf("Digite seu CPF %s (Somente números): ", pessoa[i].nome);
                fgets (pessoa[i].docs.cpf, 12, stdin);
                pessoa[i].docs.cpf[strcspn(pessoa[i].docs.cpf, "\n")] = '\0';
                setbuf(stdin, NULL);
                
            } else if (
                strcmp(entradaNacionalidade, "ESTRANGEIRO") == 0 ||
                strcmp(entradaNacionalidade, "Estrangeiro") == 0 ||
                strcmp(entradaNacionalidade, "estrangeiro") == 0
            ) {

                nacionalidadeValida = 1;
                pessoa[i].nacao = ESTRANGEIRO;

                printf("Digite seu Passaporte %s (Sem espaços): ", pessoa[i].nome);
                fgets (pessoa[i].docs.passaporte, 8, stdin);
                pessoa[i].docs.passaporte[strcspn(pessoa[i].docs.passaporte, "\n")] = '\0';
                setbuf(stdin, NULL);

            // Condição caso usuário digite incorretamente
            } else {
                printf("\nNacionalidade Invalida\n\n");
            
            }
        }    

    }

    //Exibição de informações do cadastro
    printf ("\n----------INFORMAÇÕES CADASTRADAS-----------\n");

    for (int i = 0; i < 5; i++){
        printf("\n--------CADASTRO %d --------\n", i+1);
        printf("\nNome: %s", pessoa[i].nome);
        printf("\nIdade: %d anos", pessoa[i].idade);
        printf("\nPeso: %.2f kg", pessoa[i].peso);
        printf("\nData de Nascimento: %02d/%02d/%04d", pessoa[i].data.dia, pessoa[i].data.mes, pessoa[i].data.ano);

        //Lógica para exibição de CPF já formatado no padrão correto
        if (pessoa[i].nacao == BRASILEIRO){
            printf("\nNacionalidade: BRASILEIRO");
            printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",
            pessoa[i].docs.cpf[0],
            pessoa[i].docs.cpf[1],
            pessoa[i].docs.cpf[2],
            pessoa[i].docs.cpf[3],
            pessoa[i].docs.cpf[4],
            pessoa[i].docs.cpf[5],
            pessoa[i].docs.cpf[6],
            pessoa[i].docs.cpf[7],
            pessoa[i].docs.cpf[8],
            pessoa[i].docs.cpf[9],
            pessoa[i].docs.cpf[10]);

        } else if (pessoa[i].nacao == ESTRANGEIRO){
            printf("\nNacionalidade: ESTRANGEIRO");
            printf("\nPassaporte: %s\n", pessoa[i].docs.passaporte);
        }    
    }

    return 0;
}