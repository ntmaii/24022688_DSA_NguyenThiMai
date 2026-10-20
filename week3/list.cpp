#include <iostream>
using namespace std;
class List {
    private:
    int a[1000];
    int n;
    public:
    List() {
        n = 0;
    }
    bool isEmpty() {
        return n == 0;
    }
    int size() {
        return n;
    }
    int get(int i) {
        return a[i];
    }
    // chèn x vào vị trí i
    void insert(int i, int x) {
        for (int j = n;j>i;j--) {
            a[j] = a[j-1];
        }
        a[i] = x;
        n++;
    }
    // xóa vị trí i
    int remove(int i) {
        int x = a[i];
        for (int j = i;j<n-1;j++) {
            a[j] = a[j+1];
        }
        n--;
        return x;
    }
    void addFirst(int x) {
        insert(0,x);
    }

    void addLast(int x) {
        insert(n,x);
    }

    int removeFirst() {
        return remove(0);
    }

    int removeLast() {
        return remove(n-1);
    }

    void printReverse() {
        for (int i = n-1;i >=0;i--) {
            cout << a[i] << " ";
        }
    }
};

class StackList {
    private:
    List list;
    public:
    bool isEmpty() {
        return list.isEmpty();
    }
    int size() {
        return list.size();
    }
    void push(int x) {
        list.addLast(x);
    }
    int pop() {
        return list.removeLast();
    }
    int top() {
        return list.get(list.size()-1);
    }
 };

 class QueueList {
    private:
    List list;
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
    StackList sl;
    QueueList ql;
    for (int x : {10, 20, 30}) {
        sl.push(x);
        ql.enqueue(x);
    }

    cout << "Stack bang List" << '\n';
    cout << sl.top() << '\n';
    cout << sl.pop() << '\n';
    cout << sl.top() << '\n';
    cout << sl.size() << '\n';
    
    cout << "Queue bang list" << '\n';
    cout << ql.front() << '\n';
    cout << ql.dequeue() << '\n';
    cout << ql.front() << '\n';
    cout << ql.size() << "\n\n";
}