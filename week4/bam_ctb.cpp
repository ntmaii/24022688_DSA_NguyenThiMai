#include <iostream>
using namespace std;

const int M = 10;

struct Node {
    int data;
    Node* next;
};

// Hàm băm
int hashIndex(int key) {
    int r = key % M;
    if (r < 0)
        return r + M;
    else
        return r;
}

// Tìm kiếm
bool search(Node* table[], int key) {
    int index = hashIndex(key);
    Node* p = table[index];

    while (p != nullptr) {
        if (p->data == key)
            return true;

        p = p->next;
    }

    return false;
}

// Thêm vào đầu danh sách
bool insert(Node* table[], int key) {
    if (search(table, key))
        return false;

    int index = hashIndex(key);

    Node* p = new Node;
    p->data = key;
    p->next = table[index];

    table[index] = p;
    return true;
}

// Xóa phần tử
bool removeKey(Node* table[], int key) {
    int index = hashIndex(key);

    Node* p = table[index];
    Node* previous = nullptr;

    while (p != nullptr && p->data != key) {
        previous = p;
        p = p->next;
    }

    if (p == nullptr)
        return false; // Không tìm thấy

    if (previous == nullptr)
        table[index] = p->next; // Xóa nút đầu
    else
        previous->next = p->next; // Xóa nút giữa hoặc cuối

    delete p;
    return true;
}

// In bảng băm
void display(Node* table[]) {
    for (int i = 0; i < M; ++i) {
        cout << i << ": ";

        Node* p = table[i];

        while (p != nullptr) {
            cout << p->data << " -> ";
            p = p->next;
        }

        cout << "NULL\n";
    }
}


int main() {
    Node* table[M] = {};

    int a[] = {10, 21, 32, 5, 16};

    for (int key : a)
        insert(table, key);

    cout << "BANG BAM BAN DAU:\n";
    display(table);

    int key = 21;

    if (search(table, key))
        cout << "\nTim thay " << key << '\n';
    else
        cout << "\nKhong tim thay " << key << '\n';

    removeKey(table, key);

    cout << "\nBANG BAM SAU KHI XOA 21:\n";
    display(table);

    return 0;
}