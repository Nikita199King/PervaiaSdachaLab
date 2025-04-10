#include <iostream>
#include <string>

// Класс Character
class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
        std::cout << "Character " << name << " created!\n";
    }

    ~Character() {
        std::cout << "Character " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "Character: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
};

// Класс Monster
class Monster {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Monster(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
        std::cout << "Monster " << name << " created!\n";
    }

    ~Monster() {
        std::cout << "Monster " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "Monster: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }
};

// Класс Weapon
class Weapon {
private:
    std::string name;
    int damage;
    float weight;

public:
    Weapon(const std::string& n, int dmg, float w)
        : name(n), damage(dmg), weight(w) {
        std::cout << "Weapon " << name << " created!\n";
    }

    ~Weapon() {
        std::cout << "Weapon " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "Weapon: " << name
            << ", Damage: " << damage
            << ", Weight: " << weight << " kg" << std::endl;
    }
};

int main() {
    {
        Character hero("Knight", 100, 20, 10);
        Monster goblin("Goblin", 50, 15, 5);

        Weapon sword("Steel Sword", 25, 3.5f);
        Weapon axe("Battle Axe", 35, 5.2f);
        Weapon bow("Longbow", 20, 2.1f);

        std::cout << "\n=== Info ===\n";
        hero.displayInfo();
        goblin.displayInfo();

        std::cout << "\n=== Weapons ===\n";
        sword.displayInfo();
        axe.displayInfo();
        bow.displayInfo();
    }

    std::cout << "\n=== End of Program ===\n";
    return 0;
}
