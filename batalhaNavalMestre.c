#include <stdio.h>
//#include <windows.h>
#include <string.h>


// ============================================================
// Função para imprimir o tabuleiro
// ============================================================

void printTab(char t[10][10])
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
                printf(" %c", t[i][j]);
            else
                printf("  %c", t[i][j]);
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
    char tab[10][10];

    int joct=2;
    int ioct=1;
    int jcru=7;
    int icru=0;
    int jcon=4;
    int icon=6;

    int i,j,iaux;

    // ----------------------------------------------------
    // Zera o tabuleiro
    // ----------------------------------------------------

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                tab[i][j] = '0';
            }
        }

    // Exibe o tabuleiro vazio
        printTab(tab);

    // ----------------------------------------------------
    // Monta o octaedro
    // ----------------------------------------------------

    i = ioct;
    j = joct;
    iaux = 1;
    while (i < ioct+5) {
        switch (iaux) {
        case 1:
            tab[i][j]='&';
            break;
        case 2:
            tab[i][j-1]='&';
            tab[i][j]='&';
            tab[i][j+1]='&';
            break;
        case 3:
            tab[i][j-2]='&';
            tab[i][j-1]='&';
            tab[i][j]='&';
            tab[i][j+1]='&';
            tab[i][j+2]='&';
            break;
        case 4:
            tab[i][j-1]='&';
            tab[i][j]='&';
            tab[i][j+1]='&';
            break;
        case 5:
            tab[i][j]='&';
            break;
        }
        i++;
        iaux++;
    }

    // ----------------------------------------------------
    // Monta a cruz
    // ----------------------------------------------------

    i = icru;
    j = jcru;
    iaux = 1;
    while (i < icru+5) {
        switch (iaux) {
        case 1:
            tab[i][j]='#';
            break;
        case 2:
            tab[i][j]='#';
            break;
        case 3:
            tab[i][j-2]='#';
            tab[i][j-1]='#';
            tab[i][j]='#';
            tab[i][j+1]='#';
            tab[i][j+2]='#';
            break;
        case 4:
            tab[i][j]='#';
            break;
        case 5:
            tab[i][j]='#';
            break;
        }
        i++;
        iaux++;
    }

    // ----------------------------------------------------
    // Monta o cone
    // ----------------------------------------------------

    i = icon;
    j = jcon;
    iaux = 1;
    while (i < icon+3) {
        switch (iaux) {
        case 1:
            tab[i][j]='*';
            break;
        case 2:
            tab[i][j-1]='*';
            tab[i][j]='*';
            tab[i][j+1]='*';
            break;
        case 3:
            tab[i][j-2]='*';
            tab[i][j-1]='*';
            tab[i][j]='*';
            tab[i][j+1]='*';
            tab[i][j+2]='*';
            break;
        }
        i++;
        iaux++;
    }
    
    printTab(tab);

return 0;
}