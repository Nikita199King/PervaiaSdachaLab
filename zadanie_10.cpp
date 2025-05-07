#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <algorithm>

// Base class User
class User {
private:
    std::string name;
    int id;
    int accessLevel;

public:
    User(const std::string& name, int id, int accessLevel)
        : name(name), id(id), accessLevel(accessLevel) {
        if (name.empty()) throw std::invalid_argument("Name cannot be empty.");
        if (accessLevel < 0) throw std::invalid_argument("Access level cannot be negative.");
    }

    virtual ~User() = default;

    const std::string& getName() const { return name; }
    int getId() const { return id; }
    int getAccessLevel() const { return accessLevel; }

    void setName(const std::string& newName) {
        if (newName.empty()) throw std::invalid_argument("Name cannot be empty.");
        name = newName;
    }

    void setId(int newId) { id = newId; }
    void setAccessLevel(int level) {
        if (level < 0) throw std::invalid_argument("Access level cannot be negative.");
        accessLevel = level;
    }

    virtual void displayInfo() const {
        std::cout << "Name: " << name
            << ", ID: " << id
            << ", Access Level: " << accessLevel;
    }
};

// Derived classes
class Student : public User {
private:
    std::string group;

public:
    Student(const std::string& name, int id, int accessLevel, const std::string& group)
        : User(name, id, accessLevel), group(group) {
    }

    void displayInfo() const override {
        User::displayInfo();
        std::cout << ", Group: " << group << std::endl;
    }
};

class Teacher : public User {
private:
    std::string department;

public:
    Teacher(const std::string& name, int id, int accessLevel, const std::string& department)
        : User(name, id, accessLevel), department(department) {
    }

    void displayInfo() const override {
        User::displayInfo();
        std::cout << ", Department: " << department << std::endl;
    }
};

class Administrator : public User {
public:
    Administrator(const std::string& name, int id, int accessLevel)
        : User(name, id, accessLevel) {
    }

    void displayInfo() const override {
        User::displayInfo();
        std::cout << ", Role: Administrator" << std::endl;
    }
};

// Resource class
class Resource {
private:
    std::string name;
    int requiredAccessLevel;

public:
    Resource(const std::string& name, int requiredAccessLevel)
        : name(name), requiredAccessLevel(requiredAccessLevel) {
    }

    bool checkAccess(const User& user) const {
        return user.getAccessLevel() >= requiredAccessLevel;
    }

    void displayInfo() const {
        std::cout << "Resource: " << name
            << ", Required Access Level: " << requiredAccessLevel << std::endl;
    }

    const std::string& getName() const { return name; }
};

// Template class for Access Control System
template<typename T>
class AccessControlSystem {
private:
    std::vector<std::unique_ptr<T>> items;

public:
    void addItem(std::unique_ptr<T> item) {
        items.push_back(std::move(item));
    }

    void displayAll() const {
        for (const auto& item : items) {
            item->displayInfo(); // Polymorphism here
        }
    }

    const std::vector<std::unique_ptr<T>>& getAllItems() const {
        return items;
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream out(filename);
        if (!out.is_open()) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        for (const auto& item : items) {
            out << item->getName() << std::endl;
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream in(filename);
        if (!in.is_open()) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        std::string name;
        while (std::getline(in, name)) {
            items.push_back(std::make_unique<Resource>(name, 2)); // Simplified example
        }
    }

    template<typename Compare>
    void sortItems(Compare comp) {
        std::sort(items.begin(), items.end(), comp);
    }
};

int main() {
    try {
        std::vector<std::unique_ptr<User>> users;
        users.push_back(std::make_unique<Student>("Ivan Petrov", 1, 2, "Group A"));
        users.push_back(std::make_unique<Teacher>("Anna Smirnova", 2, 5, "Physics"));
        users.push_back(std::make_unique<Administrator>("Dmitry Ivanov", 3, 7));

        std::cout << "User Information:\n";
        for (const auto& user : users) {
            user->displayInfo();
            std::cout << std::endl;
        }

        std::vector<std::unique_ptr<Resource>> resources;
        resources.push_back(std::make_unique<Resource>("Library", 3));
        resources.push_back(std::make_unique<Resource>("Lab", 5));

        std::cout << "\nAccess Check:\n";
        for (const auto& resource : resources) {
            for (const auto& user : users) {
                std::cout << user->getName() << " -> " << resource->getName() << ": ";
                std::cout << (resource->checkAccess(*user) ? "Access Granted" : "Access Denied") << std::endl;
            }
        }

        // Using template class
        AccessControlSystem<Resource> resSystem;
        resSystem.addItem(std::make_unique<Resource>("Room 101", 2));
        resSystem.addItem(std::make_unique<Resource>("Computer Lab", 4));
        resSystem.displayAll();

        // File operations
        resSystem.saveToFile("resources.txt");
        AccessControlSystem<Resource> loadedSystem;
        loadedSystem.loadFromFile("resources.txt");
        std::cout << "\nLoaded Resources from File:\n";
        loadedSystem.displayAll();

        // Sorting users by access level
        std::sort(users.begin(), users.end(), [](const std::unique_ptr<User>& a, const std::unique_ptr<User>& b) {
            return a->getAccessLevel() > b->getAccessLevel();
            });

        std::cout << "\nSorted Users by Access Level:\n";
        for (const auto& user : users) {
            user->displayInfo();
            std::cout << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
