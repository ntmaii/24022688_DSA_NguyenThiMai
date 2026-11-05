#include <iostream>
using namespace std;

void merge(int* a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* b = new int[n1];
    int* c = new int[n2];

    for (int i = l; i <= r; i++) {
        if (i <= m) {
            b[i - l] = a[i];
        } else {
            c[i - m - 1] = a[i];
        }
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = c[j++];
        }
    }


    while (i < n1) {
        a[k++] = b[i++];
    }

    while (j < n2) {
        a[k++] = c[j++];
    }

}

void sort(int* a, int l, int r) {
    if (r <= l) return;

    int m = (l+r) / 2;

    sort(a, l, m);
    sort(a, m + 1, r);

    merge(a, l, m, r);
}