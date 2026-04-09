#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <list>
#include <iostream>
#include <string>



class Name {
private:
    std::string personal_name; // имя
    std::string surname;       // фамилия
    std::string patronymic;    // отчество
    std::string full_name;     // полное имя
    void buildFullName();
public:
    Name(std::string pn = "", std::string sur = "", std::string pat = "");
    ~Name();
    Name(const Name& other);
    std::string Print();
    std::string getSurname() const { return surname; }
    std::string getPersonalName() const { return personal_name; }
    std::string getPatronymic() const { return patronymic; }
    void setSurname(const std::string& sur) { surname = sur; buildFullName(); }
    void setPatronymic(const std::string& pat) { patronymic = pat; buildFullName(); }
    void setPersonalName(const std::string& pn) { personal_name = pn; buildFullName(); }
};


void inputName_fromkeyboard(Name& name);
void inputName_fromfile(Name& name, const std::string& filename);
void inputName_random(Name& name);



class Cat {
private:
    std::string name;
public:
    Cat() : name("Безымянный кот") {}
    Cat(std::string n);
    Cat(const Cat& other) : name(other.name) {};
    ~Cat() {
        name.clear();
    }
    std::string Print();
    std::string meow(int n = 1) const;
    std::string getName() const { return name; }
    void setName(const std::string& n) { name = n; }
};

void inputCatName_fromkeyboard(Cat& cat);
void inputCatName_fromfile(Cat& cat, const std::string& filename);
void inputCatName_random(Cat& cat);



class city {
private:
    std::string name;
    std::vector<std::pair<city*, int>> where_go;
public:
    city(std::string n = "") : name(n) {}
    void print() const;
    ~city() = default;
    city(const city& other) : name(other.name), where_go(other.where_go) {}
    std::string getName() const { return name; }
    std::vector<std::pair<city*, int>> getWhereGo() { return where_go; }
    void setName(const std::string& n) { name = n; }
    void add(city* destination, int cost) {
        where_go.push_back({destination, cost});
    }

};

void addcity_fromkeyboard(std::vector<city*>& cities);
void addcity_fromfile(std::vector<city*>& cities, const std::string& filename);
void addcity_random(std::vector<city*>& cities);

class Person {
private:
    std::string name; // имя
    int height; // рост
public:
    Person(std::string n = "", int h = 0) {
        name = n;
        height = h;
    }
    ~Person() {
        name.clear();
        height = 0;
    }
    Person(const Person& p) {
        name = p.name;
    }
    std::string Print() {
        if (name.empty()) {
            return "Имя не задано";
        }
        return name + ", рост: " + std::to_string(height) + " см";
    }
    void setName(const std::string& n) { name = n; }
    void setHeight(int h) { height = h; }
    std::string getName() const { return name; }
    int getHeight() const { return height; }
};


void addPerson_fromkeyboard(Person& person);
void addPerson_fromfile(Person& person, const std::string& filename);
void addPerson_random(Person& person);
