#ifndef huffman_H_INCLUDED
#define huffman_H_INCLUDED 

#include <string>
#include <iostream>
#include "no.h"

using namespace std;

class huffman
{
    public:
    huffman(int N);
    void lista();
    void montador();
    void menores(no* m,no* n);

    private:
    int n,ind = 0;
    no *raiz;
    no *primeiro;
    string reviews;

};

#endif