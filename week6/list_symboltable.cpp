#include <iostream>
using namespace std;
struct arrayST {
    string key;
    int value;
};
arrayST table[100];
int cnt = 0;

// Trả về vị trí của key, hoặc -1 nếu không tìm thấy
int findArray(string key) {
    for (int i = 0; i < cnt; i++) {
        if (table[i].key == key) {
            return i;
        }
    }
    return -1;
}

void putArray(string key, int value) {
    int index = findArray(key);

    if (index != -1) {
        table[index].value = value;
    } else if (cnt < 100) {
        table[cnt].key = key;
        table[cnt].value = value;
        cnt++;
    } else {
        cout << "Mang da day\n";
    }
}
int main() {
    putArray("x", 10);
    putArray("y", 20);
    putArray("x", 30);
    int index = findArray("x");
    if (index != -1) {
        cout << "Mang: x = " << table[index].value << '\n';
    }
}