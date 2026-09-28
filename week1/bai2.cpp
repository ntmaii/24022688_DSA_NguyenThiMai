#include <iostream>
using namespace std;
void SapXepTangDan(int n, int a[]) {
    for (int i = 0;i<n-1;i++){
        for (int j = i+1;j<n;j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main() {
    int n; 
    cin >> n;
    int a[100];
    for (int i = 0;i<n;i++) {
        cin >> a[i];
    }
    SapXepTangDan(n, a);
    for (int i = 0;i< n;i++) {
        cout << a[i] << " ";
    }
}
//time o(n^2), memory o(1)