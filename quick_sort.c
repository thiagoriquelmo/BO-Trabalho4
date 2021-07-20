#include <stdio.h>
#include <time.h>

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

int * preencher_vetor(int qnt){

    int i;
    int *numeros = malloc(sizeof(int) * qnt);
    FILE *ptr = fopen("numeros.txt", "r");

    if(ptr != NULL){
        for(i = 0; i < qnt; i++){
            fscanf(ptr, "%d", &numeros[i]);
        }
    }else{
        printf("Arquivo nao encontrado\n");
    }
    fclose(ptr);
    return numeros;
}

void arquivo_ordenado(int *numero,int qnt){
    int i;
    FILE *ptr;
    ptr = fopen("numerosordenado100000000.txt", "w");
    if(ptr != NULL){
            /*Por enquanto o programa so cria o arquivo, mas nao faz nada*/
        srand(time(NULL));
        for(i = 0; i < qnt; i++){
            fprintf(ptr, "%d ", numero[i]);
        }
    }else{
        printf("Erro ao criar o arquivo\n");
    }
    fclose(ptr);
}

void controller(){

    int entrada;

    printf("Quick Sort\nDigite a opcao desejada\n1 - 10.000.000 numeros\n2 - 30.000.000 numeros\n3 - 50.000.000 numeros\n4 - 70.000.000 numeros\n5 - 100.000.000 numeros\n");
    scanf("%d", &entrada);
    if(entrada == 1){
        int * numeros = preencher_vetor(10000000);
        clock_t begin = clock();
        quick_sort(numeros, 0 , 10000000 - 1);
        clock_t end = clock();
        printf("Tempo gasto: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
        arquivo_ordenado(numeros,10000000);
        free(numeros);
        controller();
    }
    else if(entrada == 2){
        int * numeros = preencher_vetor(30000000);
        clock_t begin = clock();
        quick_sort(numeros, 0 , 30000000 - 1);
        clock_t end = clock();
        printf("Tempo gasto: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
        arquivo_ordenado(numeros,30000000);
        free(numeros);
        controller();
    }
    else if(entrada == 3){
        int * numeros = preencher_vetor(50000000);
        clock_t begin = clock();
        quick_sort(numeros, 0 , 50000000 - 1);
        clock_t end = clock();
        printf("Tempo gasto: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
        arquivo_ordenado(numeros,50000000);
        free(numeros);
        controller();
    }
    else if(entrada == 4){
        int * numeros = preencher_vetor(70000000);
        clock_t begin = clock();
        quick_sort(numeros, 0 , 70000000 - 1);
        clock_t end = clock();
        printf("Tempo gasto: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
        arquivo_ordenado(numeros,70000000);
        free(numeros);
        controller();
    }
    else if(entrada == 5){
        int * numeros = preencher_vetor(100000000);
        clock_t begin = clock();
        quick_sort(numeros, 0 , 100000000 - 1);
        clock_t end = clock();
        printf("Tempo gasto: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
        arquivo_ordenado(numeros,100000000);
        free(numeros);
        controller();
    }
}

int main()
{
    controller();
	return 0;
}
