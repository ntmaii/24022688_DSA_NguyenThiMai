#include <iostream>
using namespace std;

int M;

enum State {
    EMPTY,      // Chưa từng chứa phần tử
    OCCUPIED,   // Đang chứa phần tử
    DELETED     // Ô từng chứa phần tử nhưng đã xóa
};

struct Cell {
    int data = 0;
    State state = EMPTY;
};

// Hàm băm
int hashIndex(int key) {
    int r = key % M;
     if (r < 0)
        return r + M;
    else
        return r;
}

// Trả về vị trí tìm thấy, hoặc -1 nếu không thấy
int search(Cell table[], int key) {
    int start = hashIndex(key);

    for (int i = 0; i < M; i++) {
        int pos = (start + i) % M;

        if (table[pos].state == EMPTY)
            return -1;

        if (table[pos].state == OCCUPIED &&
            table[pos].data == key)
            return pos;
    }

    return -1;
}

// Thêm phần tử
bool insert(Cell table[], int key) {
    if (search(table, key) != -1)
        return false;

    int start = hashIndex(key);

    for (int i = 0; i < M; i++) {
        int pos = (start + i) % M;

        // Dùng được ô trống hoặc ô đã xóa
        if (table[pos].state != OCCUPIED) {
            table[pos].data = key;
            table[pos].state = OCCUPIED;
            return true;
        }
    }

    return false; // Bảng đầy
}

// Xóa phần tử
bool removeKey(Cell table[], int key) {
    int pos = search(table, key);

    if (pos == -1)
        return false;

    table[pos].state = DELETED;
    return true;
}

// In bảng băm
void display(Cell table[]) {
    for (int i = 0; i < M; i++) {
        cout << i << ": ";

        if (table[i].state == OCCUPIED)
            cout << table[i].data;
        else if (table[i].state == DELETED)
            cout << "Da xoa";
        else
            cout << "Trong";

        cout << '\n';
    }
}

int main() {
    cout << "Nhap so o cua bang bam: ";
    cin >> M;

    if (M <= 0)
        return 0;

    Cell* table = new Cell[M]{};

    for (int key : {10, 21, 32, 5, 16}) {
        if (!insert(table, key))
            cout << "Khong them duoc " << key << '\n';
    }

    cout << "\nBANG BAM BAN DAU:\n";
    display(table);

    int pos = search(table, 21);

    if (pos != -1)
        cout << "\nTim thay 21 tai o " << pos << '\n';
    else
        cout << "\nKhong tim thay 21\n";

    removeKey(table, 21);

    cout << "\nSAU KHI XOA 21:\n";
    display(table);

    delete[] table;
    return 0;
}