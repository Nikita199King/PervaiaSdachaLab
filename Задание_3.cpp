#include <iostream>
#include <string>

class Weapon {
private:
    std::string name;
    int damage;
    float weight;

public:
    // �����������
    Weapon(const std::string& n, int d, float w)
        : name(n), damage(d), weight(w) {
    }

    // ���������� ��������� +
    Weapon operator+(const Weapon& other) const {
        return Weapon(name + " & " + other.name, damage + other.damage, weight + other.weight);
    }

    // ���������� ��������� >
    bool operator>(const Weapon& other) const {
        return damage > other.damage;
    }

    // ����� ��� ����������� ���������� �� ������
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "Weapon: " << weapon.name << ", Damage: " << weapon.damage
            << ", Weight: " << weapon.weight << " kg";
        return os;
    }
};

int main() {
    Weapon sword("Sword", 50, 3.5);
    Weapon bow("Bow", 35, 1.5);
    Weapon axe("Axe", 65, 4.0);

    // ������������ ���������� ��������� +
    Weapon combinedWeapon = sword + bow;
    std::cout << combinedWeapon << std::endl; // ����� ������ ������

    // ������������ ���������� ��������� >
    if (axe > sword) {
        std::cout << "Axe is stronger than Sword!" << std::endl;
    }
    else {
        std::cout << "Sword is stronger than or equal to Axe!" << std::endl;
    }

    return 0;
}
