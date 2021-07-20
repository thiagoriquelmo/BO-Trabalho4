//Autor: Thiago Riquelmo Marques Nascimento

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


#include <iostream>

using namespace std;

#define MAX_VALORES 100

class Lista{
public:
    int valores[MAX_VALORES];
    unsigned tamanho;
    bool trocou;

    Lista() {         
        tamanho=0;
    }
    ~Lista() {}

    void insere(int valor){
        //erro: nao tem mais espaco
        if (tamanho == MAX_VALORES){
            cout << "Sem espaço"<< endl;
            return;
        }

        else{
            valores[tamanho]=valor;
            tamanho++;
        }
        
    }

    void imprime(){
        cout << endl << "Do inicio ao fim" << endl;
        for(unsigned i = 0; i < tamanho; i++){
            cout<< "<" << valores[i] << "> ";
        } 
        cout<<"\n";
    }

    int partition(int *vetor, int left, int right)
{
	int i, j, aux, pivo = vetor[right];

    i = (left - 1);

    for (j = left; j <= right- 1; j++)
    {
        if (vetor[j] < pivo)
        {
            i++;
            aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
        }
    }
	aux = vetor[i+1];
	vetor[i+1] = vetor[right];
	vetor[right] = aux;
    return i + 1;
}

void quick_sort(int *vetor, int left, int right)
{
	int p;
	 if (left < right)
    {
        p = partition(vetor, left, right);
        quick_sort(vetor, left, p - 1);
        quick_sort(vetor, p + 1, right);
    }
}

};

#endif
