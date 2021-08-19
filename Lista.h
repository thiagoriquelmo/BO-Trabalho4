//Autor: Thiago Riquelmo Marques Nascimento

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>

using namespace std;

#define MAX_VALORES 100

class Lista
{
public:
    int valores[MAX_VALORES];
    unsigned tamanho, acessos;

    Lista()
    {
        tamanho = 0;
        acessos = 0;
    }
    ~Lista() {}

    void insere(int valor)
    {
        //!erro: nao tem mais espaco
        if (tamanho == MAX_VALORES)
        {
            cout << "Sem espaço" << endl;
            return;
        }

        else
        {
            valores[tamanho] = valor;
            tamanho++;
        }
    }

    void imprime()
    {
        cout << endl
             << "Do inicio ao fim" << endl;
        for (unsigned i = 0; i < tamanho; i++)
        {
            cout << "<" << valores[i] << "> ";
        }
        cout << "\n";
    }

    void swap(int *vetor, unsigned pos1, unsigned pos2){
        int aux;
        aux = vetor[pos1];
        vetor[pos1] = vetor[pos2];
        vetor[pos2] = aux;
    }

    int partition(int *vetor, int left, int right)
    {
        int centro = left, pivo = vetor[right];

        for (int i = left; i <= right - 1; i++)
        {
            if (vetor[i] < pivo)
            {
                swap(vetor, centro, i);
                centro++;
                acessos++;
            }
        }

        swap(vetor, centro, right);
        acessos++;
        return centro;
    }

    void quick_sort(int *vetor, int left, int right, bool interacoes, bool imprimir)
    {
        int p;
        if (left < right)
        {
            p = partition(vetor, left, right);
            if (imprimir)
            {
                imprime();
            }
            quick_sort(vetor, left, p - 1, false, imprimir);
            quick_sort(vetor, p + 1, right, false, imprimir);
        }
        if(interacoes){
            cout<< "O numero de acessos foi de "<< acessos <<" vezes!"<<endl;
        }
        
    }
};

#endif
