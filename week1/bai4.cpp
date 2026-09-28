#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}
void RutGon(int a, int b) {
    int ucln = gcd(a,b);
    a /= ucln;
    b /= ucln;
    if(b < 0) {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b;
}
int main() {
    int a, b;
    cin >> a >> b;
    RutGon(a,b);
}
// time o(log(min(a,b))) memory o(log(min(a,b)))