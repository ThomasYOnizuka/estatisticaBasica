#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ordenar(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double calcular_media(int *arr, int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
    }
    return soma / n;
}

double calcular_desvio_padrao(int *arr, int n, double media) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += pow(arr[i] - media, 2);
    }
    return sqrt(soma / n);  // Desvio padrão populacional
}

double calcular_mediana(int *arr, int n) {
    ordenar(arr, n);
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

int main() {
    int n;

   
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

   
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

  
    printf("Digite os %d números: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

  
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    double media = calcular_media(arr, n);
    double desvio_padrao = calcular_desvio_padrao(arr, n, media);
    double mediana = calcular_mediana(arr, n);

   
    printf("\nResultados:\n");
    printf("Máximo: %d\n", max);
    printf("Mínimo: %d\n", min);
    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Desvio Padrão: %.2f\n", desvio_padrao);

   
    free(arr);

    return 0;
}

