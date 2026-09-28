#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[1000];
    double sum = 0;
    for (int i = 0;i<n;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    double avg = sum / n ;
    for (int i =0;i<n;i++) {
        if (a[i] >= avg) {
            cout<< a[i] << " ";
        }
    }
}
// time o(n) memory o(1)