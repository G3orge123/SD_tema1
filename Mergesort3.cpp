#include <iostream>
#include <fstream>
using namespace std;

void merge(int *, int, int, int);
void merge_sort(int *a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, right, mid);
    }
}

void merge(int *a, int left, int right, int mid) {
    int i, j, k, c[50];
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j <= right) {
        c[k] = a[j];
        j++;
        k++;
    }
    for (i = left; i < k; i++)
        a[i] = c[i];
}

int main() {
    int a[100001], n, i;

    ifstream input("input.txt"); // Deschide fișierul pentru citire
    if (!input) {
        cerr << "Nu s-a putut deschide fișierul de intrare." << endl;
        return 1;
    }

    input >> n;
    if (n > 1000000) {
        cerr << "Avertisment: Acest algoritm poate fi lent pentru mai mult de 10000 de elemente." << endl;
    }
    for (i = 1; i <= n; i++) {
        input >> a[i];
    }
    input.close(); // Închide fișierul de intrare

    merge_sort(a, 1, n);

    ofstream output("output.txt"); // Deschide fișierul pentru scriere
    if (!output) {
        cerr << "Nu s-a putut deschide fișierul de ieșire." << endl;
        return 1;
    }

    for (i = 1; i <= n; i++) {
        output << a[i] << " ";
    }
    output << endl;
    output.close(); // Închide fișierul de ieșire

    return 0;
}
