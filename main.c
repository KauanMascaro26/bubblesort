#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

void bubbleSort(int *V, int N) {
	int i, continua, aux, fim = N;
	do {
		continua = 0;
		for (i = 0; i < fim - 1; i++) {
			if (V[i] > V[i+1]) {
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				continua = i;
			}
		}
		fim--;
	} while (continua != 0);
}

void imprimirArray(int *arr, int tamanho) {
	int i;
	for (i = 0; i < tamanho; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
	int N, i;

	printf("Digite o número de elementos: ");
	scanf("%d", &N);

	int *arr = (int *)malloc(N * sizeof(int));
	if (arr == NULL) {
		printf("Erro de alocação de memória!\n");
		return 1;
	}

	printf("Digite os elementos:\n");
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Array original: ");
	imprimirArray(arr, N);

	bubbleSort(arr, N);

	printf("Array ordenado: ");
	imprimirArray(arr, N);

	free(arr);

	return 0;
}

