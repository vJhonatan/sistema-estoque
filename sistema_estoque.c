#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_STRING 20
#define MAX_NOME_LEN 100

// GERADOR DE CODIGOS
int gerarCodigo(int codes[], int count)
{
    int i, novoCodigo, repetido;

    do
    {
        repetido = 0;
        novoCodigo = (rand() % 900) + 100;
        for (i = 0; i < count; i++)
        {
            if (codes[i] == novoCodigo)
            {
                repetido = 1;
                break;
            }
        }
    }
    while (repetido);
    return novoCodigo;
}

int main()
{

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    // VARIÁVEIS
    int cont, op, i, count = 0, code[MAX_STRING], qtd[MAX_STRING], qtdIncremento, encontrado = 0, codigo_pesquisa, nomeDuplicado = 0;
    char nomeProduto[MAX_STRING][MAX_NOME_LEN], pesquisaProduto[MAX_NOME_LEN];

    // Loop Sistema
    do
    {
inicio:
        // Primeiro Switch / Menu Inicial
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");

        printf("\t\t\t\t\t\t (1) REGISTRO DE PRODUTOS\n");
        printf("\t\t\t\t\t\t (2) ENTRADA E SAÍDA DE PRODUTOS\n");
        printf("\t\t\t\t\t\t (3) CONSULTA DE PRODUTOS\n\n");

        printf("\t\t\t\t\t\t (0) ENCERRAR PROGRAMA\n");

        printf("\t\t\t\t\t\t_________________________\n\n");

        printf("\t\t\t\t\t\t  ESCOLHA UMA OPÇÃO -> ");
        scanf("%d", &op);

        switch (op)
        {
        // REGISTRO DE PRODUTOS
        case 1:
            do
            {
                system("cls");
                printf("\n\n\n\n\n\n\t\t\t\t\t\t    REGISTRO DE PRODUTOS\n\n\n");

                printf("\t\t\t\t\t\t     NOME DO PRODUTO: ");
                scanf(" %[^\n]", nomeProduto[count]);

                printf("\n\t\t\t\t\t\t        QUANTIDADE: ");
                scanf("%d", &qtd[count]);

                // Verificar se o produto já existe
                for (i = 0; i < count; i++)
                {
                    if (strcmp(nomeProduto[i], nomeProduto[count]) == 0)
                    {
                        nomeDuplicado = 1;
                        break;
                    }
                }

                if (nomeDuplicado)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\t\t\t\t\t  REGISTRO DE PRODUTOS\n\n\n");
                    printf("\n\n\t\t\t\t\t\t  PRODUTO JÁ EXISTE!\n");
                    Sleep(2000);
                    continue;
                }

                code[count] = gerarCodigo(code, count);
                count++;

                system("cls");
                printf("\n\n\n\n\n\n\t\t\t\t\t\t   REGISTRO DE PRODUTOS\n\n\n");
                printf("\t\t\t\t\t\t   PRODUTO CADASTRADO!");
                Sleep(1500);
                system("cls");

registros:
                printf("\n\n\n\n\n\n\t\t\t\t\t\t         REGISTROS\n\n");

                printf("\t\t    ___________________________________________________________________________________\n");
                printf("\t\t   |                          |                          |                             |\n");
                printf("\t\t   |        PRODUTO           |          CÓDIGO          |          QUANTIDADE         |\n");
                printf("\t\t   |                          |                          |                             |\n");
                printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");

                for (i = 0; i < count; i++)
                {
                    printf("\t\t   | %-24s | %-24d | %-27d |\n", nomeProduto[i], code[i], qtd[i]);
                    printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");
                }

                printf("\n\n\t\t\t\t\t\tCADASTRAR OUTRO PRODUTO? \n\t\t\t\t\t\t ( 1. SIM  |  2. NÃO )\n");
                printf("\t\t\t\t\t\t_________________________\n\n");

                printf("\t\t\t\t\t\t  ESCOLHA UMA OPÇÃO -> ");
                scanf("%d", &cont);

                if (cont != 1 && cont != 2)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                    printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                    Sleep(1300);
                    system("cls");
                    goto registros;
                    break;
                }

            }
            while (cont == 1);
            break;

        case 2:
pesquisa:
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t\t\t\t       ESTOQUE SENAI\n\n\n\n");

            printf("\t\t\t\t\t\t CÓDIGO / NOME DO PRODUTO\n");
            printf("\t\t\t\t\t\t_________________________\n\n");

            printf("\t\t\t\t\t\t      PESQUISAR -> ");
            scanf("%s", pesquisaProduto);

            if (sscanf(pesquisaProduto, "%d", &codigo_pesquisa) == 1)
            {
                // PESQUISA POR CÓDIGO
                for (i = 0; i < count; i++)
                {
                    if (code[i] == codigo_pesquisa)
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\t\t\t\t\t\t        ESTOQUE SENAI\n\n\n\n");

                        printf("\t\t    ___________________________________________________________________________________\n");
                        printf("\t\t   |                          |                          |                             |\n");
                        printf("\t\t   |        PRODUTO           |          CÓDIGO          |          QUANTIDADE         |\n");
                        printf("\t\t   |                          |                          |                             |\n");
                        printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");
                        printf("\t\t   |                          |                          |                             |\n");
                        printf("\t\t   | %-24s | %-24d | %-27d |\n", nomeProduto[i], code[i], qtd[i]);
                        printf("\t\t   |__________________________|__________________________|_____________________________|\n\n\n");


                        printf("\t\t\t\t\t\t   (1) ADICIONAR AO ESTOQUE\n");
                        printf("\t\t\t\t\t\t   (2) REMOVER DO ESTOQUE\n");

                        printf("\t\t\t\t\t\t  ____________________________\n\n");

                        printf("\t\t\t\t\t\t     ESCOLHA UMA OPÇÃO -> ");
                        scanf("%d",&op);

                        // ENTRADA DE PRODUTOS
                        if (op == 1)
                        {
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ENTRADA DE PRODUTOS\n\n\n");

                            printf("\t\t\t\t    ________________________________________________________\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |        PRODUTO           |          QUANTIDADE         |\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |--------------------------|-----------------------------|\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   | %-24s | %-27d |\n", nomeProduto[i], qtd[i]);
                            printf("\t\t\t\t   |__________________________|_____________________________|\n\n\n");

                            printf("\t\t\t\t\t   DIGITE A QUANTIDADE QUE DESEJA ADICIONAR\n");
                            printf("\t\t\t\t\t\t ____________________________\n\n");

                            printf("\t\t\t\t\t\t\t      -> ");
                            scanf("%d", &qtdIncremento);
                            qtd[i] += qtdIncremento;

                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ENTRADA DE PRODUTOS\n\n\n");
                            printf("\t\t\t\t\t\t    ADICIONADO AO ESTOQUE!");
                            Sleep(1000);

                            goto inicio;
                            encontrado = 1;

                            // SAIDA DE PRODUTOS
                        }
                        else if(op == 2)
                        {
saida3:
                            system("cls");
                            qtdIncremento = 0;
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      SAÍDA DE PRODUTOS\n\n\n");

                            printf("\t\t\t\t    ________________________________________________________\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |        PRODUTO           |          QUANTIDADE         |\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |--------------------------|-----------------------------|\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   | %-24s | %-27d |\n", nomeProduto[i], qtd[i]);
                            printf("\t\t\t\t   |__________________________|_____________________________|\n\n\n");

                            printf("\t\t\t\t\t   DIGITE A QUANTIDADE QUE DESEJA REMOVER\n");
                            printf("\t\t\t\t\t\t ____________________________\n\n");

                            printf("\t\t\t\t\t\t\t      -> ");
                            scanf("%d", &qtdIncremento);
                            qtd[i] -= qtdIncremento;

                            if(qtd[i] < 0)
                            {
                                qtd[i] += qtdIncremento;
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t\t\t      SAÍDA DE PRODUTOS\n\n\n");
                                printf("\t\t\t\t     ERRO! QUANTIDADE ESCOLHIDA EXCEDE O ESTOQUE ATUAL.\n\n\n\n\n\n\n\n\n\n");
                                Sleep(2300);
                                system("cls");
                            }
                            else
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t\t\t      SAÍDA DE PRODUTOS\n\n\n");
                                printf("\t\t\t\t\t\t    REMOVIDO DO ESTOQUE!");
                                Sleep(1000);
                                goto inicio;
                            }

                            encontrado = 1;
                        }
                        else
                        {
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                            printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                            Sleep(1300);
                            system("cls");
                            goto inicio;
                            break;
                        }
                    }
                }
            }
            else
            {
                // PESQUISA POR NOME
                for (i = 0; i < count; i++)
                {
                    if (strcmp(pesquisaProduto, nomeProduto[i]) == 0)
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\t\t\t\t\t\t      ENTRADA DE PRODUTOS\n\n\n\n");

                        printf("\t\t    ___________________________________________________________________________________\n");
                        printf("\t\t   |                          |                          |                             |\n");
                        printf("\t\t   |        PRODUTO           |          CÓDIGO          |          QUANTIDADE         |\n");
                        printf("\t\t   |                          |                          |                             |\n");
                        printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");
                        printf("\t\t   |                          |                          |                             |\n");
                        printf("\t\t   | %-24s | %-24d | %-27d |\n", nomeProduto[i], code[i], qtd[i]);
                        printf("\t\t   |__________________________|__________________________|_____________________________|\n\n\n");

                        printf("\t\t\t\t\t\t   (1) ADICIONAR AO ESTOQUE\n");
                        printf("\t\t\t\t\t\t   (2) REMOVER DO ESTOQUE\n\n");
                        printf("\t\t\t\t\t\t   (0) VOLTAR\n");


                        printf("\t\t\t\t\t\t  ____________________________\n\n");

                        printf("\t\t\t\t\t\t     ESCOLHA UMA OPÇÃO -> ");
                        scanf("%d",&op);

                        // ENTRADA DE PRODUTOS
                        if (op == 1)
                        {
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ENTRADA DE PRODUTOS\n\n\n");

                            printf("\t\t\t\t    ________________________________________________________\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |        PRODUTO           |          QUANTIDADE         |\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |--------------------------|-----------------------------|\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   | %-24s | %-27d |\n", nomeProduto[i], qtd[i]);
                            printf("\t\t\t\t   |__________________________|_____________________________|\n\n\n");

                            printf("\t\t\t\t\t   DIGITE A QUANTIDADE QUE DESEJA ADICIONAR\n");
                            printf("\t\t\t\t\t\t ____________________________\n\n");

                            printf("\t\t\t\t\t\t\t      -> ");
                            scanf("%d", &qtdIncremento);
                            qtd[i] += qtdIncremento;

                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ENTRADA DE PRODUTOS\n\n\n");
                            printf("\t\t\t\t\t\t    ADICIONADO AO ESTOQUE!");
                            Sleep(1000);

                            goto inicio;
                            encontrado = 1;

                            // SAIDA DE PRODUTOS
                        }
                        else if(op == 2)
                        {
saida:
                            system("cls");
                            qtdIncremento = 0;
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      SAÍDA DE PRODUTOS\n\n\n");

                            printf("\t\t\t\t    ________________________________________________________\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |        PRODUTO           |          QUANTIDADE         |\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   |--------------------------|-----------------------------|\n");
                            printf("\t\t\t\t   |                          |                             |\n");
                            printf("\t\t\t\t   | %-24s | %-27d |\n", nomeProduto[i], qtd[i]);
                            printf("\t\t\t\t   |__________________________|_____________________________|\n\n\n");

                            printf("\t\t\t\t\t   DIGITE A QUANTIDADE QUE DESEJA REMOVER\n");
                            printf("\t\t\t\t\t\t ____________________________\n\n");

                            printf("\t\t\t\t\t\t\t      -> ");
                            scanf("%d", &qtdIncremento);
                            qtd[i] -= qtdIncremento;

                            // VERIFICANDO SE EXISTE A QUANTIDADE CERTA PRA REMOVER
                            if(qtd[i] < 0)
                            {
                                qtd[i] += qtdIncremento;
saida2:
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t\t\t      SAÍDA DE PRODUTOS\n\n\n");
                                printf("\t\t\t\t     ERRO! QUANTIDADE ESCOLHIDA EXCEDE O ESTOQUE ATUAL.\n\n\n\n");
                                Sleep(2300);

                                printf("\t\t\t\t\t\t   (1) TENTAR NOVAMENTE\n\n");
                                printf("\t\t\t\t\t\t   (0) IR PARA O INCIO\n\n");
                                printf("\t\t\t\t\t\t____________________________\n\n");

                                printf("\t\t\t\t\t\t   ESCOLHA UMA OPÇÃO -> ");
                                scanf("%d",&op);

                                if(op == 1)
                                {
                                    goto saida;
                                }
                                else if (op == 0)
                                {
                                    goto inicio;
                                }
                                else
                                {
                                    system("cls");
                                    printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                                    printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                                    Sleep(1300);
                                    system("cls");
                                    goto saida2;
                                }
                            }
                            else
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t\t\t      SAÍDA DE PRODUTOS\n\n\n");
                                printf("\t\t\t\t\t\t    REMOVIDO DO ESTOQUE!");
                                Sleep(1200);
                                goto inicio;
                            }

                            encontrado = 1;
                        }
                        else if (op == 0)
                        {
                            goto inicio;
                        }
                        else
                        {
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                            printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                            Sleep(1300);
                            system("cls");
                            goto inicio;
                        }
                        encontrado = 1;
                    }
                }
            }
            // VERIFICANDO SE O CODIGO OU NOME EXISTE
naoEncontrado:
            if (!encontrado)
            {
                system("cls");
                printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                printf("\t\t\t\t\t\t  PRODUTO NÃO ENCONTRADO\n\n\n\n");

                printf("\t\t\t\t\t\t   (1) BUSCAR NOVAMENTE\n\n");

                printf("\t\t\t\t\t\t   (0) IR PARA O INCIO\n\n");
                printf("\t\t\t\t\t\t____________________________\n\n");

                printf("\t\t\t\t\t\t   ESCOLHA UMA OPÇÃO -> ");
                scanf("%d",&op);

                if(op == 1)
                {
                    goto pesquisa;
                }
                else if (op == 0)
                {
                    goto inicio;
                }
                else
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                    printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                    Sleep(1300);
                    system("cls");
                    goto naoEncontrado;
                }
            }
            break;

            // CONSULTA DE PRODUTOS
consulta3:
        case 3:
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");

            printf("\t\t\t\t\t\t (1) LISTAR PRODUTOS REGISTRADOS\n");
            printf("\t\t\t\t\t\t (2) PESQUISAR PRODUTOS\n\n");

            printf("\t\t\t\t\t\t (0) IR PARA O MENU\n");

            printf("\t\t\t\t\t\t_________________________\n\n");

            printf("\t\t\t\t\t\t  ESCOLHA UMA OPÇÃO -> ");
            scanf("%d", &op);

            switch(op)
            {
            case 1:
                // LISTAR TODOS REGISTROS
consulta:
                system("cls");
                printf("\n\n\n\n\n\n\t\t\t\t\t\t         REGISTROS\n\n");

                printf("\t\t    ___________________________________________________________________________________\n");
                printf("\t\t   |                          |                          |                             |\n");
                printf("\t\t   |        PRODUTO           |          CÓDIGO          |          QUANTIDADE         |\n");
                printf("\t\t   |                          |                          |                             |\n");
                printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");

                for (i = 0; i < count; i++)
                {
                    printf("\t\t   | %-24s | %-24d | %-27d |\n", nomeProduto[i], code[i], qtd[i]);
                    printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");
                }
                printf("\t\t   |__________________________|__________________________|_____________________________|\n\n\n");

                printf("\t\t\t\t\t\t    (0) IR PARA O MENU\n");

                printf("\t\t\t\t\t\t _________________________\n\n");

                printf("\t\t\t\t\t\t            -> ");
                scanf("%d", &op);

                if(op == 0)
                {
                    system("cls");
                    goto inicio;
                }
                else
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                    printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                    Sleep(1300);
                    goto consulta;
                }
                break;

            case 2:
                // PESQUISAR ITENS REGISTRADOS
consultaCod:
                system("cls");
                printf("\n\n\n\n\n\n\t\t\t\t\t\t       ESTOQUE SENAI\n\n\n\n");

                printf("\t\t\t\t\t\t CÓDIGO / NOME DO PRODUTO\n");
                printf("\t\t\t\t\t\t_________________________\n\n");

                printf("\t\t\t\t\t\t      PESQUISAR -> ");
                scanf("%s", pesquisaProduto);

                encontrado = 0; // Inicializa a variável 'encontrado'

                if (sscanf(pesquisaProduto, "%d", &codigo_pesquisa) == 1)
                {
                    // PESQUISA POR CÓDIGO
                    for (i = 0; i < count; i++)
                    {
                        if (code[i] == codigo_pesquisa)
                        {
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t        ESTOQUE SENAI\n\n\n\n");

                            printf("\t\t    ___________________________________________________________________________________\n");
                            printf("\t\t   |                          |                          |                             |\n");
                            printf("\t\t   |        PRODUTO           |          CÓDIGO          |          QUANTIDADE         |\n");
                            printf("\t\t   |                          |                          |                             |\n");
                            printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");
                            printf("\t\t   |                          |                          |                             |\n");
                            printf("\t\t   | %-24s | %-24d | %-27d |\n", nomeProduto[i], code[i], qtd[i]);
                            printf("\t\t   |__________________________|__________________________|_____________________________|\n\n\n");

                            encontrado = 1;

                            printf("\t\t\t\t\t\t    (0) IR PARA O MENU\n");

                            printf("\t\t\t\t\t\t _________________________\n\n");

                            printf("\t\t\t\t\t\t            -> ");
                            scanf("%d", &op);

                            if (op == 0)
                            {
                                system("cls");
                                goto inicio;
                            }
                            else
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                                printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                                Sleep(1300);
                                goto consultaCod;
                            }
                        }
                    }
                }
                else
                {
                    // PESQUISA POR NOME
pesquisaNome:
                    system("cls");
                    for (i = 0; i < count; i++)
                    {
                        if (strcmp(pesquisaProduto, nomeProduto[i]) == 0)
                        {
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ENTRADA DE PRODUTOS\n\n\n\n");

                            printf("\t\t    ___________________________________________________________________________________\n");
                            printf("\t\t   |                          |                          |                             |\n");
                            printf("\t\t   |        PRODUTO           |          CÓDIGO          |          QUANTIDADE         |\n");
                            printf("\t\t   |                          |                          |                             |\n");
                            printf("\t\t   |--------------------------|--------------------------|-----------------------------|\n");
                            printf("\t\t   |                          |                          |                             |\n");
                            printf("\t\t   | %-24s | %-24d | %-27d |\n", nomeProduto[i], code[i], qtd[i]);
                            printf("\t\t   |__________________________|__________________________|_____________________________|\n\n\n");

                            encontrado = 1;

                            printf("\t\t\t\t\t\t    (0) IR PARA O MENU\n");

                            printf("\t\t\t\t\t\t _________________________\n\n");

                            printf("\t\t\t\t\t\t            -> ");
                            scanf("%d", &op);

                            if (op == 0)
                            {
                                system("cls");
                                goto inicio;
                            }
                            else
                            {
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                                printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                                Sleep(1300);
                                goto pesquisaNome;
                            }
                        }
                    }
                }

                // VERIFICANDO SE O CODIGO OU NOME EXISTE
opInvalida:
                if (!encontrado)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                    printf("\t\t\t\t\t\t  PRODUTO NÃO ENCONTRADO\n\n\n\n");

                    printf("\t\t\t\t\t\t   (1) BUSCAR NOVAMENTE\n\n");

                    printf("\t\t\t\t\t\t   (0) IR PARA O INCIO\n\n");
                    printf("\t\t\t\t\t\t____________________________\n\n");

                    printf("\t\t\t\t\t\t   ESCOLHA UMA OPÇÃO -> ");
                    scanf("%d", &op);

                    if (op == 1)
                    {
                        goto consultaCod;
                    }
                    else if (op == 0)
                    {
                        goto inicio;
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                        printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                        Sleep(1300);
                        goto opInvalida;
                    }
                }
                break;
            case 0:
                goto inicio;
                break;
            default:
                system("cls");
                printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
                printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
                Sleep(1300);
                system("cls");
                goto consulta3;
                break;
            }
            break;

        // ENCERRAR PROGRAMA
        case 0:
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
            printf("\t\t\t\t\t\t   PROGRAMA ENCERRADO\n\n\n\n\n\n\n\n\n\n\n\n\n");
            cont = 0;
            break;

        default:
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t\t\t\t      ESTOQUE SENAI\n\n\n");
            printf("\t\t\t\t\t    OPÇÃO INVÁLIDA! TENTE NOVAMENTE..\n\n\n\n\n\n\n\n\n\n");
            Sleep(1300);
            system("cls");
            goto inicio;
            break;
        }

    }
    while (op != 0);

    return 0;
}
