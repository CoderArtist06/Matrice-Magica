#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

void genNumMatrix(int , int [DIM][DIM], int ); // Genera una Matrice con dei Num Casuali
int contR(int [DIM][DIM], int); // Controllo righe
int contC(int [DIM][DIM], int); // Controllo colonne
int contD(int [DIM][DIM], int); // Controllo diagonale

int main() {
    int n = 0; // Grandezza Matrice
    int N = 0; // N numeri che devono essere generati all'interno della matrice
    int M[DIM][DIM]; // Matrice default

    printf("--------------------------------------------------------------------\n");
    printf("Facciamo un piccolo gioco:\nil gioco consiste nel farti generare una matrice magica.\nBuona fortuna!\n");
    printf("--------------------------------------------------------------------\n");
    // Richiesta della grandezza della Matrice
    do {
        printf("Inserisci la grandezza della matrice (max %d):\n", DIM);
        fflush(stdin);
        scanf("%d",&n);
    } while (n > DIM || n <= 0);
    printf("--------------------------------------------------------------------\n");

    N = n * n;

    genNumMatrix(N, M, n); // Generazione numeri casuali

    int i, j;
    
    // Visualizza la matrice con i numeri generati
    printf("La Matrice è stata creata e popolata da dei numeri casuali:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    // Chiamate alle funzioni di controllo
    int x = contR(M, n); // Controllo delle righe
    int y = contC(M, n); // Controllo delle colonne
    int z = contD(M, n); // Controllo delle diagonali

    printf("--------------------------------------------------------------------\n");
    // Verifica se la matrice è magica
    if (x == 1 || y == 1 || z == 1) {
        printf("Hai Perso.\nNon è una Matrice Magica\n");
    } else {
        printf("Hai Vinto.\nE' una Matrice Magica\n");
    }
    printf("--------------------------------------------------------------------\n");

    return 0;
}

void genNumMatrix(int N, int M[DIM][DIM], int n) {
    int a[N];
    int i, j;

    // Inizializza il generatore di numeri casuali sull'ora attuale
    srand(time(0));

    // Generatore di num casuali
    for (i = 0; i < N; i++) {
        a[i] = rand() % N + 1; // Genera un numero casuale tra 1 e N

        // Controllo delle ripetizioni
        for (j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                i--; // Decrementa l'indice se il numero è già presente
                break;
            }
        }
    }

    // Popola la matrice con i numeri generati
    int x = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = a[x++]; // Assegna i numeri generati alla matrice
        }
    }
}

int contR(int M[DIM][DIM], int n) {
    int somma = 0; 
    int somme[DIM]; // Array per memorizzare le somme delle righe

    // Calcola la somma di ogni riga e la salva nell'array somme
    for (int i = 0; i < n; i++) {
        somma = 0; // Reset della somma per ogni riga
        for (int j = 0; j < n; j++) {
            somma += M[i][j]; // Somma gli elementi della riga
        }
        somme[i] = somma; // Salva la somma della riga
    }

    // Confronta le somme di tutte le righe
    for (int i = 1; i < n; i++) {
        if (somme[i] != somme[0]) {
            return 1; // Se una somma è diversa, la matrice non è magica
        }
    }

    return 0; // Se tutte le somme delle righe sono uguali
}

int contC(int M[DIM][DIM], int n) {
    int somma = 0; 
    int somme[DIM]; // Array per memorizzare le somme delle colonne

    // Calcola la somma di ogni colonna e la salva nell'array somme
    for (int j = 0; j < n; j++) {
        somma = 0; // Reset della somma per ogni colonna
        for (int i = 0; i < n; i++) {
            somma += M[i][j]; // Somma gli elementi della colonna
        }
        somme[j] = somma; // Salva la somma della colonna
    }

    // Confronta le somme di tutte le colonne
    for (int j = 1; j < n; j++) {
        if (somme[j] != somme[0]) {
            return 1; // Se una somma è diversa, la matrice non è magica
        }
    }

    return 0; // Se tutte le somme delle colonne sono uguali
}

int contD(int M[DIM][DIM], int n) {
    int somma_diag_principale = 0; // Somma della diagonale principale
    int somma_diag_secondaria = 0; // Somma della diagonale secondaria

    // Calcola la somma delle diagonali
    for (int i = 0; i < n; i++) {
        somma_diag_principale += M[i][i]; // Somma gli elementi della diagonale principale
        somma_diag_secondaria += M[i][n - i - 1]; // Somma gli elementi della diagonale secondaria
    }

    // Confronta le somme delle diagonali
    if (somma_diag_principale != somma_diag_secondaria) {
        return 1; // Se le diagonali non sono uguali, la matrice non è magica
    }

    return 0; // Se le somme delle diagonali sono uguali
}