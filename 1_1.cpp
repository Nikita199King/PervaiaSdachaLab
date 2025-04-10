#include <iostream>
#include <string>

class Character {
private:
    std::string name;  // Имя персонажа
    int health;        // Текущее здоровье
    int attack;        // Уровень атаки
    int defense;       // Уровень защиты
    static const int MAX_HEALTH = 100;  // Максимальное здоровье

public:
    // Конструктор
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
    }

    // Получение текущего здоровья
    int getHealth() const {
        return health;
    }

    // Вывод информации о персонаже
    void displayInfo() const {
        std::cout << "Name: " << name
            << ", HP: " << health
            << ", Attack: " << attack
            << ", Defense: " << defense << std::endl;
    }

    // Атака другого персонажа
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

    // Лечение персонажа
    void heal(int amount) {
        if (amount > 0) {
            health += amount;
            if (health > MAX_HEALTH) {
                health = MAX_HEALTH;
            }
            std::cout << name << " heals for " << amount << " HP. Current HP: " << health << std::endl;
        }
    }

    // Получение урона
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
    // Создаем персонажей
    Character hero("Hero", 100, 20, 10);
    Character monster("Monstrik", 50, 15, 5);

    // Информация до боя
    std::cout << "=== Before Battle ===" << std::endl;
    hero.displayInfo();
    monster.displayInfo();

    // Битва
    std::cout << "\n=== Battle Begins ===" << std::endl;
    hero.attackEnemy(monster);
    monster.displayInfo();

    // Монстр лечится
    std::cout << "\n=== Healing Monstrik ===" << std::endl;
    monster.heal(30); // Проверка, чтобы здоровье не превышало максимум
    monster.displayInfo();

    // Наносим прямой урон герою
    std::cout << "\n=== Hero Takes Damage ===" << std::endl;
    hero.takeDamage(50);
    hero.displayInfo();

    // Герой пытается вылечиться сверх максимума
    std::cout << "\n=== Hero Heals ===" << std::endl;
    hero.heal(70);  // Проверка ограничения по максимуму
    hero.displayInfo();

    return 0;
}
