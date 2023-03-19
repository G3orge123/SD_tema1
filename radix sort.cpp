#include <iostream>
#include <fstream>
using namespace std;

void count_sort(int a[], int max, int exp, int n) {
    int count[10] = {0};
    int b[n];
    int i;
    for (i = 0; i < n; i++)
        ++count[(a[i] / exp) % 10];
    for (i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];
    for (i = n - 1; i >= 0; i--)
        b[--count[(a[i] / exp) % 10]] = a[i];
    for (i = 0; i < n; i++)
        a[i] = b[i];
}

void radix_sort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        count_sort(a, max, exp, n);
    }
}

int main() {
    int a[100001], i, n;

    ifstream input("input.txt"); // Deschide fișierul pentru citire
    if (!input) {
        cerr << "Nu s-a putut deschide fișierul de intrare." << endl;
        return 1;
    }

    input >> n;
    if (n > 1000000) {
        cerr << "Avertisment: Acest algoritm poate fi lent pentru mai mult de 10000 de elemente." << endl;
    }
    for (i = 0; i < n; i++) {
        input >> a[i];
    }
    input.close(); // Închide fișierul de intrare

    radix_sort(a, n);

    ofstream output("output.txt"); // Deschide fișierul pentru scriere
    if (!output) {
        cerr << "Nu s-a putut deschide fișierul de ieșire." << endl;
        return 1;
    }

    for (i = 0; i < n; i++) {
        output << a[i] << " ";
    }
    output << endl;
    output.close(); // Închide fișierul de ieșire

    return 0;
}



