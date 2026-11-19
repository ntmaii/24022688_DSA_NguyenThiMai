# include <iostream>
using namespace std;
struct Node {
    string key;
    int value;
    Node* next;
};

Node* head = nullptr;
// Trả về node chứa key, hoặc nullptr nếu không tìm thấy
Node* findList(string key) {
    Node* current = head;

    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void putList(string key, int value) {
    Node* found = findList(key);

    if (found != nullptr) {
        found->value = value;
    } else {
        Node* newNode = new Node{key, value, head};
        head = newNode;
    }
}

int main() {
    putList("x", 10);
    putList("y", 20);
    putList("x", 30);
     Node* found = findList("x");
    if (found != nullptr) {
        cout << "Linked list: x = " << found->value << '\n';
    }
    return 0;
}