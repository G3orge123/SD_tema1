#include <iostream>
#include <fstream>
using namespace std;

void count_sort(int a[], int max, int n) {
    int count[max + 1] = {0};
    int b[n];
    int i;
    for (i = 0; i < n; i++)
        ++count[a[i]];
    for (i = 1; i <= max; i++)
        count[i] = count[i] + count[i - 1];
    for (i = n - 1; i >= 0; i--)
        b[--count[a[i]]] = a[i];
    for (i = 0; i < n; i++)
        a[i] = b[i];
}

int main() {
    int a[1000001], i, n, max = 0;

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
        if (a[i] > max) max = a[i];
    }
    input.close(); // Închide fișierul de intrare

    count_sort(a, max, n);

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








