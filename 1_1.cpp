#include <iostream>
#include <string>

class Character {
private:
    std::string name;  // ��� ���������
    int health;        // ������� ��������
    int attack;        // ������� �����
    int defense;       // ������� ������
    static const int MAX_HEALTH = 100;  // ������������ ��������

public:
    // �����������
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
    }

    // ��������� �������� ��������
    int getHealth() const {
        return health;
    }

    // ����� ���������� � ���������
    void displayInfo() const {
        std::cout << "Name: " << name
            << ", HP: " << health
            << ", Attack: " << attack
            << ", Defense: " << defense << std::endl;
    }

    // ����� ������� ���������
    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.takeDamage(damage);
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    // ������� ���������
    void heal(int amount) {
        if (amount > 0) {
            health += amount;
            if (health > MAX_HEALTH) {
                health = MAX_HEALTH;
            }
            std::cout << name << " heals for " << amount << " HP. Current HP: " << health << std::endl;
        }
    }

    // ��������� �����
    void takeDamage(int amount) {
        if (amount > 0) {
            health -= amount;
            if (health < 0) {
                health = 0;
            }
        }
    }
};

int main() {
    // ������� ����������
    Character hero("Hero", 100, 20, 10);
    Character monster("Monstrik", 50, 15, 5);

    // ���������� �� ���
    std::cout << "=== Before Battle ===" << std::endl;
    hero.displayInfo();
    monster.displayInfo();

    // �����
    std::cout << "\n=== Battle Begins ===" << std::endl;
    hero.attackEnemy(monster);
    monster.displayInfo();

    // ������ �������
    std::cout << "\n=== Healing Monstrik ===" << std::endl;
    monster.heal(30); // ��������, ����� �������� �� ��������� ��������
    monster.displayInfo();

    // ������� ������ ���� �����
    std::cout << "\n=== Hero Takes Damage ===" << std::endl;
    hero.takeDamage(50);
    hero.displayInfo();

    // ����� �������� ���������� ����� ���������
    std::cout << "\n=== Hero Heals ===" << std::endl;
    hero.heal(70);  // �������� ����������� �� ���������
    hero.displayInfo();

    return 0;
}
