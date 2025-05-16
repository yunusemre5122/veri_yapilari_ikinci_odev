#include <stdio.h>
#include <stdlib.h>

// Azalan sırada sıralama (Büyükten küçüğe)
void azalanSirala(int dizi[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (dizi[i] < dizi[j]) {
                int gecici = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = gecici;
            }
        }
    }
}

// Özel sıralama: bir büyük bir küçük olacak şekilde
void ozelSiralama(int dizi[], int n) {
    azalanSirala(dizi, n); // önce büyükten küçüğe sırala

    int sonuc[n]; // geçici dizi
    int bas = 0, son = n - 1;
    int indeks = 0;

    while (bas <= son) {
        if (indeks < n) {
            sonuc[indeks++] = dizi[bas++]; // en büyük
        }
        if (indeks < n) {
            sonuc[indeks++] = dizi[son--]; // en küçük
        }
    }

    // Sonuç dizisini orijinal diziye kopyala
    for (int i = 0; i < n; i++) {
        dizi[i] = sonuc[i];
    }
}

int main() {
    int dizi[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(dizi) / sizeof(dizi[0]);

    printf("Orijinal dizi: ");
    for (int i = 0; i < n; i++)
        printf("%d ", dizi[i]);

    ozelSiralama(dizi, n);

    printf("\nOzel siralanmis dizi (Bir buyuk, bir kucuk): ");
    for (int i = 0; i < n; i++)
        printf("%d ", dizi[i]);

    printf("\n");
    return 0;
}
