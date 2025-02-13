#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;
    double *numeros;

    // Obtém a quantidade de números
    printf("Quantos números na sua série (N): ");
    scanf("%d", &N);

    // Aloca memória dinamicamente para os números
    numeros = (double *)malloc(N * sizeof(double));

    // Verifica se a alocação de memória foi bem-sucedida
    if (numeros == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Obtém os números da série
    printf("Entre com números: \n");
    for (int i = 0; i < N; i++) {
        printf("> ");
        scanf("%lf", &numeros[i]);
    }

    // Calcula o valor mínimo
    double minimo = numeros[0];
    for (int i = 1; i < N; i++) {
        if (numeros[i] < minimo) {
            minimo = numeros[i];
        }
    }

    // Calcula o valor máximo
    double maximo = numeros[0];
    for (int i = 1; i < N; i++) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
    }

    // Calcula a média
    double soma = 0;
    for (int i = 0; i < N; i++) {
        soma += numeros[i];
    }
    double media = soma / N;

    // Calcula a mediana
    double *numeros_ordenados = (double *)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        numeros_ordenados[i] = numeros[i];
    }
    // Ordena os números usando o algoritmo Bubble Sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (numeros_ordenados[j] > numeros_ordenados[j + 1]) {
                double temp = numeros_ordenados[j];
                numeros_ordenados[j] = numeros_ordenados[j + 1];
                numeros_ordenados[j + 1] = temp;
            }
        }
    }
    double mediana;
    if (N % 2 == 0) {
        mediana = (numeros_ordenados[N / 2 - 1] + numeros_ordenados[N / 2]) / 2;
    } else {
        mediana = numeros_ordenados[N / 2];
    }
    free(numeros_ordenados);

    // Calcula o desvio padrão populacional
    double soma_diff_quad = 0;
    for (int i = 0; i < N; i++) {
        double diff = numeros[i] - media;
        soma_diff_quad += diff * diff;
    }
    double desvio_padrao = sqrt(soma_diff_quad / N);

    // Imprime os resultados
    printf("Valor mínimo: %.1lf\n", minimo);
    printf("Valor Máximo: %.1lf\n", maximo);
    printf("Média: %.2lf\n", media);
    printf("Mediana: %.2lf\n", mediana);
    printf("Desvio padrão: %lf\n", desvio_padrao);

    // Libera a memória alocada dinamicamente
    free(numeros);

    return 0;
}
