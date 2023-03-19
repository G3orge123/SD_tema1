#include <iostream>
#include <fstream>
using namespace std;

void shell_sort(int a[], int n) {
    for (int gap = n/2; gap >= 1; gap /= 2) {
        for (int j = gap; j < n; j++) {
            for (int i = j - gap; i >= 0; i -= gap) {
                if (a[i + gap] > a[i]) {
                    break;
                } else {
                    swap(a[i + gap], a[i]);
                }
            }
        }
    }
}

int main() {
    int a[100001], n;
    ifstream input("input.txt");
    if (!input) {
        cerr << "Nu s-a putut deschide fișierul de intrare." << endl;
        return 1;
    }

    input >> n;

    if (n > 100000) {
        cerr << "Avertisment: Acest algoritm poate fi lent pentru mai mult de 10000 de elemente." << endl;
    }

    for (int i = 0; i < n; i++) {
        input >> a[i];
    }
    input.close();

    shell_sort(a, n);

    ofstream output("output.txt");
    if (!output) {
        cerr << "Nu s-a putut deschide fișierul de ieșire." << endl;
        return 1;
    }

    for (int p = 0; p < n; p++) {
        output << a[p] << " ";
    }
    output << endl;
    output.close();

    return 0;
}
