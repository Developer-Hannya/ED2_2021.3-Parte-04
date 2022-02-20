#include <iostream>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< Updated upstream
=======
#include <fstream>
#include <string.h>
#include "huffman.h"
#include "no.h"
#include "TikTokData.h"
#include "moduloteste.h"

>>>>>>> Stashed changes
using namespace std;

void callCompression()
{

}

void callDecompression()
{

    FILE *arq,*arq2;
    double descomp[100];
    double n[100];
    int resultados;
<<<<<<< Updated upstream
    int i,j=0;
=======

    int i,x=0, j = 0;

>>>>>>> Stashed changes
    arq = fopen("reviewsComp.bin", "rb");
    if (arq == NULL)  // Se houve erro na abertura
    {
        cout<<"Problemas na abertura do arquivo"<< endl;
        return;
    }
<<<<<<< Updated upstream
   resultados= fread(n, sizeof n,100, arq);
   for(i=0;i<resultados;i++){
    descomp[j]=n[i];
   }
   arq2 = fopen("reviewsOrig.bin", "wb");
   fwrite(n, sizeof(int), 100, arq2);
=======

    resultados = fread(n, sizeof n, 100, arq);

    for(i = 0; i < resultados; i++)
    {
        for(j=x; j<sizeof n; j++)
        {
            if(n[j] != n[j+1])
                break;
        }
        descomp[j] = n[x];
        x=j+1;

    }

    arq2 = fopen("reviewsOrig.bin", "wb");

    fwrite(descomp, sizeof(int), 100, arq2);
>>>>>>> Stashed changes

    fclose(arq);
    fclose(arq2);

}

void callMetrics()
{

}

void callMenu()
{

    int n;

    cout << "qual operac,a~o voce^ deseja executar: \n[1]Comprimir reviews \n[2]Descomprimir arquivo bina'rio \n[3]Executar uma seque^ncia de compresso~es e computar me'tricas" << endl;

    cin >> n;

    switch(n)
    {

    case 1:

        callCompression();

        break;

    case 2:

        callDecompression();

        break;

    case 3:

        callMetrics();

        break;

    default:

        cout << "Operac,a~o inva'lida. Tente novamente." << endl;

        break;

    }

}

int main()
{

    callMenu();

    return 0;

}
