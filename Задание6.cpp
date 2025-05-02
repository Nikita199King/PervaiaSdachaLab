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
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty, cannot pop.");
        }
        items.erase(items.begin()); // ������� ������ �������
    }

    // ����� ��� ��������� ������� ��������
    T front() const {
        if (isEmpty()) {
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
    Queue<int> intQueue;

    try {
        // ��������� ������� pop() �� ������ �������
        intQueue.pop(); // ��� ������� ����������
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl; // ��������� ����������
    }

    // ���������� ��������� � �������
    intQueue.push(10);
    intQueue.push(20);

    try {
        // ��������� �������� ������ �������
        std::cout << "Front element: " << intQueue.front() << std::endl;

        // ������ ������� pop() ��� �������� ��������
        intQueue.pop();

        // ��������, ��� �������� � �������
        std::cout << "Front element after pop: " << intQueue.front() << std::endl;

        // ������ ���������� �������
        intQueue.pop();

        // ��������� ����� ������� pop() �� ������ �������
        intQueue.pop(); // ��� ����� ������� ����������
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl; // ��������� ����������
    }

    return 0;
}
