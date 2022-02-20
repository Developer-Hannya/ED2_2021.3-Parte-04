#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "no.h"
#include "huffman.h"
#include "TikTokData.h"

using namespace std;

huffman::huffman(int N)
{
    TikTokData temp;

    fstream r;

    r.open("data.bin",ios::binary);

    if(!r.is_open())
    {

        cout << "ERRO:Nao foi possivel abrir o arquivo." << endl;

        return;

    }

    for(int i = 0;i < N; i++)
    {

        srand(time(NULL));

        int ale = rand() % 3500000;

        r.read((char*) &temp,ale*sizeof(TikTokData));

        char *te = temp.getReview();

        for(int i = 0;i < 900;i++)
        {
            if(te[i] >= 33 && te[i] <= 126)
               reviews.push_back(te[i]);
        }
    }

    raiz = NULL;

    r.close();

};

void huffman::lista()
{

    bool achado;

    for(int i = 0;i < reviews.size();i++)
    {
        no *temp;

        if(raiz == NULL)
        {

            no *novo = new no();

            novo->setinfo(reviews.at(i),1);

            raiz = novo;

            primeiro = novo;

            ind++;

        }

        temp = raiz;

        while(temp->getdir() != NULL)
        {

            if(reviews.at(i) == temp->getchar())
            {

                temp->setinfo(temp->getchar(),temp->getfreq() + 1);

                achado = true;

            }

            temp = temp->getdir();

        }

        if(achado == false)
        {

            no *nov = new no();

            nov->setinfo(reviews.at(i),1);

            nov->setesq(temp);

            temp->setdir(nov);

            ind++;

        }
        else
           achado = false;
    }
};

void huffman::montador()
{
    no *a,*b;

    while(ind > 1)
    {
        menores(a,b);

        if(a->getchar() == '+')
        {
            no *novo = new no();

            novo->setinfo('+',a->getfreq()+b->getfreq());

            a->getesq()->setdir(a->getdir());

            a->getdir()->setesq(a->getesq());

            b->getesq()->setdir(b->getdir());

            b->getdir()->setesq(b->getesq());


            a->setsen(NULL,NULL);

            b->setsen(NULL,NULL);

            a->setpai(novo);

            b->setpai(novo);

            a->setraizpai(true);

            a->getesq()->setraizpai(false);

            a->getdir()->setraizpai(false);

            b->setraizpai(true);

            ind--;

        }

        else if(b->getchar() == '+')
        {
            no *novo = new no();

            novo->setinfo('+',a->getfreq()+b->getfreq());

            a->getesq()->setdir(a->getdir());

            a->getdir()->setesq(a->getesq());

            b->getesq()->setdir(b->getdir());

            b->getdir()->setesq(b->getesq());


            a->setsen(NULL,NULL);

            b->setsen(NULL,NULL);

            a->setpai(novo);

            b->setpai(novo);

            a->setraizpai(true);

            b->setraizpai(true);

            b->getesq()->setraizpai(false);

            b->getdir()->setraizpai(false);

            ind--;

        }

        else if(a->getchar() == '+' && b->getchar() == '+')
        {

            no *novo = new no();

            novo->setinfo('+',a->getfreq()+b->getfreq());

            a->getesq()->setdir(a->getdir());

            a->getdir()->setesq(a->getesq());

            b->getesq()->setdir(b->getdir());

            b->getdir()->setesq(b->getesq());


            a->setsen(NULL,NULL);

            b->setsen(NULL,NULL);

            a->setpai(novo);

            b->setpai(novo);

            a->setraizpai(true);

            a->getesq()->setraizpai(false);

            a->getdir()->setraizpai(false);

            b->setraizpai(true);

            b->getesq()->setraizpai(false);

            b->getdir()->setraizpai(false);

            ind--;

        }

        else
        {

           no *novo = new no();

           novo->setinfo('+',a->getfreq()+b->getfreq());

           a->getesq()->setdir(a->getdir());

           a->getdir()->setesq(a->getesq());

           b->getesq()->setdir(b->getdir());

           b->getdir()->setesq(b->getesq());


           a->setsen(NULL,NULL);

           b->setsen(NULL,NULL);

           a->setpai(novo);

           b->setpai(novo);

           a->setraizpai(true);

           b->setraizpai(true);

           ind--;

        }
    }
};

void huffman::menores(no *m,no *n)
{

    m = primeiro;

    n = primeiro->getdir();

    no *temp = n->getdir();


    if(primeiro != NULL)
    {

        while(temp != NULL)
        {
            if(temp->getpai() != NULL && temp->getpai()->getfreq() < n->getfreq() && temp->getpai()->getfreq() != m->getfreq() && temp->getraizpai() == true)
                n = temp->getpai();

            else if(temp->getpai() != NULL && temp->getpai()->getfreq() < m->getfreq() && temp->getpai()->getfreq() != n->getfreq() && temp->getraizpai() == true)
                m  = temp->getpai();

            else if(temp->getfreq() < n->getfreq() && temp->getfreq() != m->getfreq() && temp->getpai() == NULL)
                n = temp;

            else if(temp->getfreq() < m->getfreq() && temp->getfreq() != n->getfreq() && temp->getpai() == NULL)
                m = temp;

            temp = temp->getdir();

        }
    }
};
