#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::vector<T> items; // ������ ��� �������� ��������� �������

public:
    // ����� ��� ���������� �������� � �������
    void push(const T& item) {
        items.push_back(item);
    }

    // ����� ��� �������� �������� �� �������
    void pop() {
        if (items.empty()) {
            throw std::out_of_range("Queue is empty, cannot pop.");
        }
        items.erase(items.begin()); // ������� ������ �������
    }

    // ����� ��� ��������� ������� ��������
    T front() const {
        if (items.empty()) {
            throw std::out_of_range("Queue is empty, cannot access front.");
        }
        return items.front(); // ���������� ������ �������
    }

    // ����� ��� ��������, ����� �� �������
    bool isEmpty() const {
        return items.empty();
    }

    // ����� ��� ��������� ������� �������
    size_t size() const {
        return items.size();
    }
};

int main() {
    // ������ ������������� ������� ��� �����
    Queue<std::string> stringQueue;
    stringQueue.push("First");
    stringQueue.push("Second");
    stringQueue.push("Third");

    std::cout << "String Queue:\n";
    while (!stringQueue.isEmpty()) {
        std::cout << stringQueue.front() << std::endl;
        stringQueue.pop();
    }

    // ������ ������������� ������� ��� ����� �����
    Queue<int> intQueue;
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);

    std::cout << "\nInteger Queue:\n";
    while (!intQueue.isEmpty()) {
        std::cout << intQueue.front() << std::endl;
        intQueue.pop();
    }

    return 0;
}