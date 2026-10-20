#include <iostream>
using namespace std;
class LinkedList{
    private:
    struct Node{
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
    int n;
    void printReverse(const Node* p) {
        if (p == nullptr) return;
        printReverse(p->next);
        cout << p->data << " ";
    }

    public:
    LinkedList() {
        head = tail= nullptr;
        n = 0;
    }

    bool isEmpty(){
        return n == 0;
    }
    int size() {
        return n;
    }
    int get(int i) {
        if (i == n -1) {
            return tail->data;
        }
        Node* p =head;
        for (int j= 0;j<i;j++) {
            p = p->next;
        }
        return p->data;
    }
    void addFirst(int x) {
        Node* p = new Node(x);
        p->next = head;
        head = p;

        if (n == 0)
            tail = p;

        n++;
    }
    void addLast(int x) {
        Node* p = new Node(x);

        if (n == 0)
            head = tail = p;
        else {
            tail->next = p;
            tail = p;
        }

        n++;
    }
    void insert(int i, int x) {
        if (i == 0) {
            addFirst(x);
            return;
        }

        if (i == n) {
            addLast(x);
            return;
        }
        Node* previous = head;

        for (int j = 0; j < i - 1; j++)
            previous = previous->next;

        Node* p = new Node(x);
        p->next = previous->next;
        previous->next = p;
        n++;
    }

    int removeFirst() {
        Node* p = head;
        int x = p->data;

        head = head->next;
        delete p;
        n--;

        if (n == 0)
            tail = nullptr;

        return x;
    }

    int remove(int i) {
        if (i == 0)
            return removeFirst();

        Node* previous = head;

        for (int j = 0; j < i - 1; j++)
            previous = previous->next;

        Node* p = previous->next;
        int x = p->data;

        previous->next = p->next;

        if (p == tail)
            tail = previous;

        delete p;
        n--;
        return x;
    }
    int removeLast() {
        return remove(n - 1);
    }
};
class StackLinkedList {
    private:
    LinkedList list;
    public:
    bool isEmpty() {
        return list.isEmpty();
    }
    int size() {
        return list.size();
    }
    void push(int x) {
        list.addFirst(x);
    }
    int pop() {
        return list.removeFirst();
    }
    int top() {
        return list.get(0);
    }
 };

  class QueueLinkedList {
    private:
    LinkedList list;
    public:
    bool isEmpty() {
        return list.isEmpty();
    }
    int size() {
        return list.size();
    }
    void enqueue(int x) {
        list.addLast(x);
    }
    int dequeue() {
        return list.removeFirst();
    }

    int front() {
        return list.get(0);
    }
    
 };
int main() {
    StackLinkedList sl;
    QueueLinkedList ql;
    for (int x : {10, 20, 30}) {
        sl.push(x);
        ql.enqueue(x);
    }

    cout << "Stack bang LinkedList" << '\n';
    cout << sl.top() << '\n';
    cout << sl.pop() << '\n';
    cout << sl.top() << '\n';
    cout << sl.size() << '\n';
    
    cout << "Queue bang LinkedList" << '\n';
    cout << ql.front() << '\n';
    cout << ql.dequeue() << '\n';
    cout << ql.front() << '\n';
    cout << ql.size() << "\n\n";

}