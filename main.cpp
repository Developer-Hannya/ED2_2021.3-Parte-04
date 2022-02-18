#include <iostream>

using namespace std;

void callCompression() {

}

void callDecompression() {

}

void callMetrics() {

}

void callMenu() {

    int n;

    cout << "qual operac,a~o voce^ deseja executar: \n[1]Comprimir reviews \n[2]Descomprimir arquivo bina'rio \n[3]Executar uma seque^ncia de compresso~es e computar me'tricas" << endl;

    cin >> n;

    switch(n) {

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
