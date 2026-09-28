#include <iostream>
using namespace std;
double Tong(int n, int m, double a[100][100]) {
    double sum = 0;
    for (int i = 0; i<n;i++) {
        for (int j= 0;j<m;j++) {
            sum += a[i][j];
        }
    }
    return sum;
}
void xoaDongThuK(int n, int m, double a[100][100],int k) {
    double b[100][100];
    k--;
    int row = 0;
    for (int i = 0;i<n;i++) {
        if (i!=k ) {
            for (int j = 0; j<m;j++) {
                b[row][j] = a[i][j];
            }
            row++;
        }
    }
    for (int i = 0;i<n-1;i++) {
        for (int j = 0; j<m;j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    double a[100][100];
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    cout << Tong(n, m, a) << '\n';
    int i ; cin >> i;
    xoaDongThuK(n,m,a,i);
}
// time o (nm) memory o(1)