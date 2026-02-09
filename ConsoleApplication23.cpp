#include <iostream>
using namespace std;
class CharStack {
private:
    char* data;
    int top;
    int capacity;

public:
    CharStack(int size) {
        capacity = size;
        data = new char[capacity];
        top = -1;
    }

    ~CharStack() {
        delete[] data;
    }

    bool push(char c) {
        if (isFull()) return false;
        data[++top] = c;
        return true;
    }

    bool pop(char& c) {
        if (isEmpty()) return false;
        c = data[top--];
        return true;
    }

    bool peek(char& c) const {
        if (isEmpty()) return false;
        c = data[top];
        return true;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    int count() const {
        return top + 1;
    }

    void clear() {
        top = -1;
    }
};

class DynamicCharStack {
private:
    char* data;
    int top;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        char* newData = new char[newCapacity];

        for (int i = 0; i <= top; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicCharStack(int size = 5) {
        capacity = size;
        data = new char[capacity];
        top = -1;
    }

    ~DynamicCharStack() {
        delete[] data;
    }

    void push(char c) {
        if (top == capacity - 1) {
            resize();
        }
        data[++top] = c;
    }

    bool pop(char& c) {
        if (isEmpty()) return false;
        c = data[top--];
        return true;
    }

    bool peek(char& c) const {
        if (isEmpty()) return false;
        c = data[top];
        return true;
    }

    bool isEmpty() const {
        return top == -1;
    }

    int count() const {
        return top + 1;
    }

    void clear() {
        top = -1;
    }
};

int main() {
    cout << "Фіксований стек:\n";
    CharStack s1(3);
    s1.push('A');
    s1.push('B');
    s1.push('C');

    char ch;
    while (!s1.isEmpty()) {
        s1.pop(ch);
        cout << ch << " ";
    }

    cout << "\n\nДинамічний стек:\n";
    DynamicCharStack s2(2);
    s2.push('X');
    s2.push('Y');
    s2.push('Z');

    while (!s2.isEmpty()) {
        s2.pop(ch);
        cout << ch << " ";
    }

    return 0;
}

