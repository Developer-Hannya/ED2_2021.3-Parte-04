#include <iostream>

#include "no.h"
#include "huffman.h"

using namespace std;

no::no()
{

    esq = NULL;

    dir = NULL;

};

void no::setinfo(char na,int fr)
{
    na = n;

    frequencia = fr;

};

no *no::getesq()
{
    return esq;
};
no *no::getdir()
{
    return dir;
};

char no::getchar()
{
    return n;
};

int no::getfreq()
{
    return frequencia;
};

void no::setesq(no* e)
{
    e = esq;
};

void no::setdir(no* d)
{
    d = dir;
};

no* no::getpai()
{
    return pai;
};

bool no::getraizpai()
{
    return raizpai;
};

void no::setsen(no* es,no* di)
{

    es = esq;

    di = dir;

};

 void no::setraizpai(bool a)
 {
    raizpai = a;
 };

 void no::setpai(no *p)
 {
    p = pai;
 };
