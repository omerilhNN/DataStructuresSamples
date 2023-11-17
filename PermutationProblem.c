#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate_permutations(int *data, int start, int end) {
    if (start == end) {
        // Permütasyonu ekrana yazdır
        for (int i = 0; i <= end; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // Elemanları yer değiştir
            swap(&data[start], &data[i]);

            // Recursive çağrı
            generate_permutations(data, start + 1, end);

            // Yer değiştirme işlemi geri alınır (backtrack)
            swap(&data[start], &data[i]);
        }
    }
}

int main() {
    int n;

    // Kullanıcıdan dizi boyutunu al
    printf("Dizi boyutunu girin: ");
    scanf("%d", &n);

    // Kullanıcıdan verileri al
    int data[n];
    printf("Dizi elemanlarını girin: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Permütasyonları oluştur ve ekrana yazdır
    printf("Permütasyonlar:\n");
    generate_permutations(data, 0, n - 1);

    return 0;
}