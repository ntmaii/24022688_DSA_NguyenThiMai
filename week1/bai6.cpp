#include <iostream>
using namespace std;
void xoaPhanTuThuK(int n, int a[], int k) {
    int b[1000];
    k--;
    int index = 0;
    for (int i = 0;i<n;i++) {
        if (i != k) {
            b[index] = a[i];
            index++;
        }
    }
    for (int i = 0 ;i<n-1;i++) {
        cout << b[i] << " ";
    }
}
void chenPhanTuYVaoViTriM(int n, int a[],int y, int m) {
    int c[1000];
    m--;
    for (int i = 0;i<n+ 1;i++) {
        if (i < m) {
            c[i] = a[i];
        } else if ( i == m) {
            c[i] = y;
        } else {
            c[i] = a[i-1];
        }
    }
    for (int i = 0;i<n+1;i++) {
        cout << c[i]<<" ";
    }
}

int main() {
    int n;cin>>n;
    int a[1000];
    for (int i =0;i<n;i++) {
        cin >> a[i];
    }
    int k; cin >> k;
    xoaPhanTuThuK(n, a, k);
    cout << endl;
    int y, m;
    cin >> y >> m;
    chenPhanTuYVaoViTriM(n, a, y, m);
}
// time o (n), memory o(1)