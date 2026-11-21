#include <stdio.h>

#define TAM 10

void exibirCabecalho(void);
void lerPontuacoes(int v[], int n);
void copiarVetor(int origem[], int destino[], int n);
void exibirVetor(int v[], int n);
int bubbleSort(int v[], int n);
int selectionSort(int v[], int n);
int insertionSort(int v[], int n);
int vetoresiguais(int a[], int b[], int n);

int main(void) {
    int original[TAM];
    int bubble[TAM];
    int selection[TAM];
    int insertion[TAM];
    
    int compBubble = 0;
    int compSelection = 0;
    int compInsertion = 0;
    
    int iguaisBS, iguaisBI;

    exibirCabecalho();
    lerPontuacoes(original, TAM);

    printf("\nOriginal:   ");
    exibirVetor(original, TAM);

    copiarVetor(original, bubble, TAM);
    copiarVetor(original, selection, TAM);
    copiarVetor(original, insertion, TAM);

    compBubble = bubbleSort(bubble, TAM);
    compSelection = selectionSort(selection, TAM);
    compInsertion = insertionSort(insertion, TAM);

    printf("Bubble:     ");
    exibirVetor(bubble, TAM);
    printf("Selection:  ");
    exibirVetor(selection, TAM);
    printf("Insertion:  ");
    exibirVetor(insertion, TAM);

    iguaisBS = vetoresiguais(bubble, selection, TAM);
    iguaisBI = vetoresiguais(bubble, insertion, TAM);
    
    if (iguaisBS && iguaisBI) {
        printf("Resultados equivalentes: SIM\n");
    } else {
        printf("Resultados equivalentes: NAO\n");
    }

    int menor = bubble[0];
    int maior = bubble[TAM - 1];
    float mediana = (float)(bubble[4] + bubble[5]) / 2.0;

    printf("Menor: %d | Maior: %d | Mediana: %.2f\n", menor, maior, mediana);
    printf("Comparacoes: Bubble %d | Selection %d | Insertion %d\n", compBubble, compSelection, compInsertion);

    return 0;
}

void exibirCabecalho(void) {
    printf("               RANKLAB                  \n");
    printf("     Central de Ordenacao Inteligente   \n");
    printf("========================================\n");
}

void lerPontuacoes(int v[], int n) {
    int i, valor;
    printf("Digite %d pontuacoes entre 0 e 100:\n", n);
    for (i = 0; i < n; i++) {
        do {
            scanf("%d", &valor);
            if (valor < 0 || valor > 100) {
                printf("Valor invalido! Digite novamente um valor entre 0 e 100 para a posicao %d: ", i + 1);
            }
        } while (valor < 0 || valor > 100);
        v[i] = valor;
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void exibirVetor(int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int bubbleSort(int v[], int n) {
    int i, j, temp;
    int comparacoes = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

int selectionSort(int v[], int n) {
    int i, j, min_idx, temp;
    int comparacoes = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = v[i];
            v[i] = v[min_idx];
            v[min_idx] = temp;
        }
    }
    return comparacoes;
}

int insertionSort(int v[], int n) {
    int i, j, chave;
    int comparacoes = 0;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        
        while (j >= 0) {
            comparacoes++;
            if (v[j] > chave) {
                v[j + 1] = v[j];
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = chave;
    }
    return comparacoes;
}

int vetoresiguais(int a[], int b[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}