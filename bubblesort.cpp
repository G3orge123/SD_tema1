#include <iostream>
#include <fstream>
using namespace std;

void bubble_sort(int *a, int left, int right) {
    int i, j, k;
    i = left;
    k = right;
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    }
}

int main() {
    int a[100001], i, j, n;

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

    bubble_sort(a, 0, n);

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


