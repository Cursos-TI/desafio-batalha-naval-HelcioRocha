#include <stdio.h>
//#include <windows.h>
#include <string.h>

void printTab(int t[10][10])
{
    int i, j;
    char letra = 'a';

    printf("\n");

    for (j = 0; j < 10; j++)
    {
        j == 0 ? printf("    (%c)", letra) : printf("(%c)", letra);
        letra++;
    }

    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf("(%d)", i + 1);

        for (j = 0; j < 10; j++)
        {
            (i == 9 && j == 0) ? printf(" %d", t[i][j]) : printf("  %d", t[i][j]);
        }

        printf("\n");
    }
}
 
int main() {

    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);

    int tab[10][10];                               // tabuleiro
    int i, j, ih, iv, jh, jv;                      // índices
    int navioh[3], naviov[3];                      // vetores (navios)
    char mais1='s', entrada[20], letra;            // auxiliares para controle da execução

                                                   
    for(i = 0; i < 3; i++) {                       // carrega navios
        navioh[i] = 3;
        naviov[i] = 3;
    }

    do {                                           // executa até jogador escolher não

    for (i = 0; i < 10; i++)                       // zera tabuleiro
    for (j = 0; j < 10; j++)
        tab[i][j] = 0;

    printTab(tab);                                 // print tabuleiro

    do {                                           // lê e critica as coordenadas 
    printf("\nEscolha as coordenadas do navio horizontal.\n");
    printf("Coluna: ");
    scanf(" %c", &letra);
    jh=letra-'a';
    printf("Linha: ");
    scanf(" %d", &ih);
    ih--;
    if (ih<0 || jh>7 || jh<0 || ih>9)
    {
        printf("\n* Ao menos uma coordenada está errada! *\n");
    }
    } while (ih<0 || jh>7 || jh<0 || ih>9);
    printf("\n");
    do {
    printf("\nEscolha as coordenadas do navio vertical.\n");
    printf("Coluna: ");
    scanf(" %c", &letra);
    jv=letra-'a';
    printf("Linha: ");
    scanf(" %d", &iv);
    iv--;
    if (iv<0 || iv>7 || jv<0 || jv>9)
    {
        printf("\n* Ao menos uma coordenada está errada! *\n");
    }
    } while (iv<0 || iv>7 || jv<0 || jv>9);

    i=0;                                           // posicionamento do navio horizontal
    for (j=jh; j<=jh+2; j++) {
       
        if (tab[ih][j] == navioh[i]) {             // navios sobrepostos
                printf("\nOs navios colidiram :(\n");
                printf("\nEscolha novas coordenadas.\n");
                break;
        }
            else {
                tab[ih][j] = navioh[i];            // navio ok
            }
        i++;
    }

    j=0;                                           // posicionamento do navio vertical
    for (i=iv; i<=iv+2; i++) {
       
        if (tab[i][jv] == naviov[j]) {             // navios sobrepostos
                printf("\nOs navios colidiram :(\n");
                printf("\nEscolha novas coordenadas.\n");
                break;
        }
            else {
                tab[i][jv] = naviov[j];            // navio ok
            }
        j++;
    }

    printTab(tab);                                 // print tabuleiro com navios posicionados

    printf("\n\n");
    while (getchar() != '\n');                     // controle da excução
    printf("Quer jogar novamente? (s)im ou (n)ão : ");
        do {
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