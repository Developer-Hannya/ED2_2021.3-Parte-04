#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
    int i,j=0;
    arq = fopen("reviewsComp.bin", "rb");
    if (arq == NULL)  // Se houve erro na abertura
    {
        cout<<"Problemas na abertura do arquivo"<< endl;
        return;
    }
   resultados= fread(n, sizeof n,100, arq);
   for(i=0;i<resultados;i++){
    descomp[j]=n[i];
   }
   arq2 = fopen("reviewsOrig.bin", "wb");
   fwrite(n, sizeof(int), 100, arq2);

    fclose(arq);

    std::ifstream file;

    std::string info;


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
