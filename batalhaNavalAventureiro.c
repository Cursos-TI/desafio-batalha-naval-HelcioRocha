#include <stdio.h>
//#include <windows.h>
#include <string.h>


// ============================================================
// Função para imprimir o tabuleiro
// ============================================================

void printTab(int t[10][10])
{
    int i, j;
    char letra = 'a';

    printf("\n");

    // Imprime as letras das colunas
    for (j = 0; j < 10; j++)
    {
        if (j == 0)
            printf("    (%c)", letra);
        else
            printf("(%c)", letra);

        letra++;
    }

    printf("\n");

    // Imprime as linhas e os valores do tabuleiro
    for (i = 0; i < 10; i++)
    {
        printf("(%d)", i + 1);

        for (j = 0; j < 10; j++)
        {
            if (i == 9 && j == 0)
                printf(" %d", t[i][j]);
            else
                printf("  %d", t[i][j]);
        }

        printf("\n");
    }
}


// ============================================================
// Programa principal
// ============================================================

int main()
{
    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);

    // --------------------------------------------------------
    // Declaração das variáveis
    // --------------------------------------------------------

    // Tabuleiro 10 x 10
    int tab[10][10];

    // Índices das posições dos navios
    int i, j;
    int ih, iv;                 // Navio horizontal e vertical
    int jh, jv;
    int id1, id2;               // Navios diagonais
    int jd1, jd2;

    // Vetores que representam os quatro navios
    int navioh[3];
    int naviov[3];
    int naviod1[3];
    int naviod2[3];

    // Variáveis para entrada de dados
    char entrada[20];
    char letra;

    // Direção dos navios diagonais
    char dir1 = ' ';
    char dir2 = ' ';

    // Controle da repetição do jogo
    char mais1 = 's';


    // ========================================================
    // Carrega os navios
    // ========================================================

    for (i = 0; i < 3; i++)
    {
        navioh[i] = 3;
        naviov[i] = 3;
        naviod1[i] = 3;
        naviod2[i] = 3;
    }


    // ========================================================
    // LOOP PRINCIPAL
    // ========================================================

    do
    {
        // ----------------------------------------------------
        // Zera o tabuleiro
        // ----------------------------------------------------

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                tab[i][j] = 0;
            }
        }

        // Exibe o tabuleiro vazio
        printTab(tab);


        // ====================================================
        // NAVIO HORIZONTAL
        // ====================================================

        do
        {
            printf("\nEscolha as coordenadas do navio horizontal.\n");

            // ------------------------------------------------
            // Coluna
            // ------------------------------------------------

            printf("Coluna: ");

            fgets(entrada, sizeof(entrada), stdin);

            letra = entrada[0];
            jh = letra - 'a';

            // ------------------------------------------------
            // Linha
            // ------------------------------------------------

            printf("Linha: ");

            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, "%d", &ih) != 1)
            {
                ih = 0;
            }
            else
            {
                // Converte de 1-10 para índice 0-9
                ih--;
            }

            // ------------------------------------------------
            // Validação
            // ------------------------------------------------

            if (ih < 0 || ih > 9 ||
                jh < 0 || jh > 7)
            {
                printf("\n* Ao menos uma coordenada está errada! *\n");
            }

        } while (ih < 0 || ih > 9 ||
                 jh < 0 || jh > 7);


        // ====================================================
        // NAVIO VERTICAL
        // ====================================================

        do
        {
            printf("\nEscolha as coordenadas do navio vertical.\n");

            // ------------------------------------------------
            // Coluna
            // ------------------------------------------------

            printf("Coluna: ");

            fgets(entrada, sizeof(entrada), stdin);

            letra = entrada[0];
            jv = letra - 'a';

            // ------------------------------------------------
            // Linha
            // ------------------------------------------------

            printf("Linha: ");

            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, "%d", &iv) != 1)
            {
                iv = 0;
            }
            else
            {
                // Converte de 1-10 para índice 0-9
                iv--;
            }

            // ------------------------------------------------
            // Validação
            // ------------------------------------------------

            if (iv < 0 || iv > 7 ||
                jv < 0 || jv > 9)
            {
                printf("\n* Ao menos uma coordenada está errada! *\n");
            }

        } while (iv < 0 || iv > 7 ||
                 jv < 0 || jv > 9);


        // ====================================================
        // PRIMEIRO NAVIO DIAGONAL
        // ====================================================

        do
        {
            printf("\nEscolha as coordenadas e a direção "
                   "horizontal do primeiro navio diagonal.\n");

            printf("*OBS* A direção vertical é sempre abaixo.\n");


            // ------------------------------------------------
            // Coluna
            // ------------------------------------------------

            printf("Coluna: ");

            fgets(entrada, sizeof(entrada), stdin);

            letra = entrada[0];
            if (letra < 'a' || letra > 'j')
        {
            jd1 = -1;
        }
            else
        {
            jd1 = letra - 'a';
        }


            // ------------------------------------------------
            // Linha
            // ------------------------------------------------

            printf("Linha: ");

            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, "%d", &id1) != 1)
            {
                id1 = 0;
            }
            else
            {
                id1--;
            }


            // ------------------------------------------------
            // Direção
            // ------------------------------------------------

            printf("e(esquerda) ou d(ireita): ");

            fgets(entrada, sizeof(entrada), stdin);

            dir1 = entrada[0];


            // ------------------------------------------------
            // Validação
            // ------------------------------------------------

            if (id1 < 0 || id1 > 7 ||
                jd1 < 0 || jd1 > 9 ||
                (dir1 == 'd' && jd1 > 7) ||
                (dir1 == 'e' && jd1 < 2) ||
                (dir1 != 'e' && dir1 != 'd'))
            {
            printf("\n* Coordenadas ou direção inválida! *\n");
            }

        } while (id1 < 0 || id1 > 7 ||
                 jd1 < 0 || jd1 > 9 ||
                (dir1 == 'd' && jd1 > 7) ||
                (dir1 == 'e' && jd1 < 2) ||
                (dir1 != 'e' && dir1 != 'd'));


        // ====================================================
        // SEGUNDO NAVIO DIAGONAL
        // ====================================================

        do
        {
            printf("\nEscolha as coordenadas e a direção "
                   "horizontal do segundo navio diagonal.\n");

            printf("*OBS* A direção vertical é sempre abaixo.\n");


            // ------------------------------------------------
            // Coluna
            // ------------------------------------------------

            printf("Coluna: ");

            fgets(entrada, sizeof(entrada), stdin);

            letra = entrada[0];
            if (letra < 'a' || letra > 'j')
        {
            jd2 = -1;
        }
            else
        {
            jd2 = letra - 'a';
        }


            // ------------------------------------------------
            // Linha
            // ------------------------------------------------

            printf("Linha: ");

            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, "%d", &id2) != 1)
            {
                id2 = 0;
            }
            else
            {
                id2--;
            }


            // ------------------------------------------------
            // Direção
            // ------------------------------------------------

            printf("e(esquerda) ou d(ireita): ");

            fgets(entrada, sizeof(entrada), stdin);

            dir2 = entrada[0];


            // ------------------------------------------------
            // Validação
            // ------------------------------------------------

            if (id2 < 0 || id2 > 7 ||
                (dir2 == 'd' && jd2 > 7) ||
                (dir2 == 'e' && jd2 < 2) ||
                (dir2 != 'e' && dir2 != 'd'))
        {
            printf("\n* Coordenadas ou direção inválida! *\n");
        }

        } while (id2 < 0 || id2 > 7 ||
            (dir2 == 'd' && jd2 > 7) ||
            (dir2 == 'e' && jd2 < 2) ||
            (dir2 != 'e' && dir2 != 'd'));


        // ====================================================
        // POSICIONAMENTO DO NAVIO HORIZONTAL
        // ====================================================

        i = 0;

        for (j = jh; j <= jh + 2; j++)
        {
            // Se a casa não estiver vazia, houve colisão
            if (tab[ih][j] != 0)
            {
                printf("\nOs navios colidiram :(\n");
                printf("\nEscolha novas coordenadas.\n");
                break;
            }

            // Posiciona o navio
            tab[ih][j] = navioh[i];

            i++;
        }


        // ====================================================
        // POSICIONAMENTO DO NAVIO VERTICAL
        // ====================================================

        j = 0;

        for (i = iv; i <= iv + 2; i++)
        {
            // Verifica se a casa já está ocupada
            if (tab[i][jv] != 0)
            {
                printf("\nOs navios colidiram :(\n");
                printf("\nEscolha novas coordenadas.\n");
                break;
            }

            // Posiciona o navio
            tab[i][jv] = naviov[j];

            j++;
        }


        // ====================================================
        // POSICIONAMENTO DO PRIMEIRO NAVIO DIAGONAL
        // ====================================================

        j = 0;

        switch (dir1)
        {
            // ------------------------------------------------
            // Diagonal para a esquerda
            // ------------------------------------------------

            case 'e':

                for (i = id1; i <= id1 + 2; i++)
                {
                    // Verifica colisão
                    if (tab[i][jd1] != 0)
                    {
                        printf("\nOs navios colidiram :(\n");
                        printf("\nEscolha novas coordenadas.\n");
                        break;
                    }

                    // Posiciona o navio
                    tab[i][jd1] = naviod1[j];

                    // Próxima casa: uma linha abaixo
                    // e uma coluna à esquerda
                    jd1--;
                    j++;
                }

                break;


            // ------------------------------------------------
            // Diagonal para a direita
            // ------------------------------------------------

            case 'd':

                for (i = id1; i <= id1 + 2; i++)
                {
                    // Verifica colisão
                    if (tab[i][jd1] != 0)
                    {
                        printf("\nOs navios colidiram :(\n");
                        printf("\nEscolha novas coordenadas.\n");
                        break;
                    }

                    // Posiciona o navio
                    tab[i][jd1] = naviod1[j];

                    // Próxima casa: uma linha abaixo
                    // e uma coluna à direita
                    jd1++;
                    j++;
                }

                break;
        }


        // ====================================================
        // POSICIONAMENTO DO SEGUNDO NAVIO DIAGONAL
        // ====================================================

        j = 0;

        switch (dir2)
        {
            // ------------------------------------------------
            // Diagonal para a esquerda
            // ------------------------------------------------

            case 'e':

                for (i = id2; i <= id2 + 2; i++)
                {
                    // Verifica colisão
                    if (tab[i][jd2] != 0)
                    {
                        printf("\nOs navios colidiram :(\n");
                        printf("\nEscolha novas coordenadas.\n");
                        break;
                    }

                    // Posiciona o navio
                    tab[i][jd2] = naviod2[j];

                    jd2--;
                    j++;
                }

                break;


            // ------------------------------------------------
            // Diagonal para a direita
            // ------------------------------------------------

            case 'd':

                for (i = id2; i <= id2 + 2; i++)
                {
                    // Verifica colisão
                    if (tab[i][jd2] != 0)
                    {
                        printf("\nOs navios colidiram :(\n");
                        printf("\nEscolha novas coordenadas.\n");
                        break;
                    }

                    // Posiciona o navio
                    tab[i][jd2] = naviod2[j];

                    jd2++;
                    j++;
                }

                break;
        }


        // ====================================================
        // Exibe o tabuleiro com os navios
        // ====================================================

        printTab(tab);


        // ====================================================
        // Pergunta se o jogador deseja jogar novamente
        // ====================================================

        printf("\n\n");

        printf("Quer jogar novamente? (s)im ou (n)ão: ");

        do
        {
            fgets(entrada, sizeof(entrada), stdin);

            mais1 = entrada[0];

            if (mais1 != 's' && mais1 != 'n')
            {
                printf("*Digite s ou n*\n");
            }

        } while (mais1 != 's' && mais1 != 'n');

    } while (mais1 == 's');


    printf("Saindo...\n");

    return 0;
}