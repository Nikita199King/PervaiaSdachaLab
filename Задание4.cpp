#include <iostream>
#include <memory>
#include <vector>

class Inventory {
private:
    std::vector<std::unique_ptr<std::string>> items; // ������ ����� ���������� �� ������

public:
    // ����� ��� ���������� ��������
    void addItem(const std::string& item) {
        items.push_back(std::make_unique<std::string>(item));
    }

    // ����� ��� ����������� ���������
    void displayInventory() const {
        std::cout << "Inventory:\n";
        for (const auto& item : items) {
            std::cout << "- " << *item << std::endl; // �������������� ��������� ��� ��������� ������
        }
    }
};

int main() {
    Inventory inventory;

    // ��������� �������� � ���������
    inventory.addItem("Sword");
    inventory.addItem("Health Potion");
    inventory.addItem("Bow");

    // ���������� ���������
    inventory.displayInventory();

    return 0;
}