#ifndef no_H_INCLUDED
#define no_H_INCLUDED

class no
{
    public:

    no();

    char getchar();

    int getfreq();

    bool getraizpai();

    no* getpai();

    no* getesq();

    no* getdir();

    void setesq(no* e);

    void setdir(no* d);

    void setsen(no* es,no* di);

    void setraizpai(bool a);

    void setpai(no *p);

    void setinfo(char na,int fr);

    private:

    no *esq,*dir,*pai;

    bool raizpai;

    char n;

    int frequencia;

};
#endif
