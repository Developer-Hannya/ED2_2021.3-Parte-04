#ifndef huffman_H_INCLUDED
#define huffman_H_INCLUDED

#include <string>
#include "no.h"

class huffman
{
    public:

    huffman(int N);

    void lista();

    void montador();

    void menores(no *m, no *n);

    private:

    int n, ind = 0;

    no *raiz, *primeiro;

    std::string reviews;

};

#endif
