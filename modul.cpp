#include "h.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <limits>
#include <deque>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>

bool cityExists(const std::vector<city*>& cities, const std::string& name) {
    for (const auto& c : cities) {
        if (c->getName() == name) {
            return true;
        }
    }
    return false;
}

Name::Name(std::string pn, std::string sur, std::string pat) {
        personal_name = pn;
        surname = sur;
        patronymic = pat;
        buildFullName();
}

Name::~Name() {
        personal_name.clear();
        surname.clear();
        patronymic.clear();
        full_name.clear();
}

Name::Name(const Name& other) {
    personal_name = other.personal_name;
    surname = other.surname;
    patronymic = other.patronymic;
    buildFullName();
}

std::string Name::Print() {
        if (full_name.empty()) {
            return "Имя не задано";
        }
        return full_name;
}

void Name::buildFullName() {
    full_name.clear();
    if (!surname.empty())
        full_name += surname;
    if (!personal_name.empty()) {
        if (!full_name.empty()) full_name += " ";
        full_name += personal_name;
    }
    if (!patronymic.empty()) {
        if (!full_name.empty()) full_name += " ";
        full_name += patronymic;
    }
}

bool isgivename(const std::string& str) {
    for (char c : str) {
        if (isdigit(c)) {
            return false;
        }
    }
    return true;
}


void inputName_fromkeyboard(Name& name) {
    std::string personal_name, surname, patronymic;
    std::cout << "Введите имя: ";
    while (true) {
        std::getline(std::cin, personal_name);
        if (isgivename(personal_name)) {
            break;
        }
        std::cout << "Ошибка! Введите имя без цифр: ";
    }
    std::cout << "Введите фамилию: ";
    while (true) {
        std::getline(std::cin, surname);
        if (isgivename(surname)) {
            break;
        }
        std::cout << "Ошибка! Введите фамилию без цифр: ";
    }
    std::cout << "Введите отчество: ";
    while (true) {
        std::getline(std::cin, patronymic);
        if (isgivename(patronymic)) {
            break;
        }
        std::cout << "Ошибка! Введите отчество без цифр: ";
    }
    name.setPersonalName(personal_name);
    name.setSurname(surname);
    name.setPatronymic(patronymic);
}

void inputName_fromfile(Name& name, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
        return;
    }
    if (file.is_open()) {
        std::string personal_name, surname, patronymic;
        std::getline(file, personal_name);
        std::getline(file, surname);
        std::getline(file, patronymic);
        name.setPersonalName(personal_name);
        name.setSurname(surname);
        name.setPatronymic(patronymic);
        file.close();
    }
}

void inputName_random(Name& name) {
    const std::vector<std::string> personal_names = {
        "Александр", "Мария", "Дмитрий", "Елена", "Сергей",
        "Анна", "Иван", "Ольга", "Павел", "Наталья"
    };
    const std::vector<std::string> surnames = {
        "Иванов", "Петров", "Сидоров", "Кузнецов", "Попов",
        "Смирнов", "Волков", "Морозов", "Лебедев", "Козлов"
    };
    const std::vector<std::string> patronymics = {
        "Александрович", "Мариевна", "Дмитриевич", "Еленовна", "Сергеевич",
        "Анновна", "Иванович", "Ольговна", "Павлович", "Натальевна"
    };
    std::string personal_name = personal_names[rand() % personal_names.size()];
    std::string surname = surnames[rand() % surnames.size()];
    std::string patronymic = patronymics[rand() % patronymics.size()];
    name.setPersonalName(personal_name);
    name.setSurname(surname);
    name.setPatronymic(patronymic);
}





Cat::Cat(std::string n) {
        if (n.empty()) {
            name = "Безымянный кот";
        }
        else {
            name = n;
        }
}

std::string Cat::Print() {
    if (name.empty()) {
        return "Кот: Безымянный кот";
    }
    return "Кот: " + name;
}

std::string Cat::meow(int n) const {
        std::string res = name + ": ";
        for (int i = 0; i < n; ++i) {
            res += "мяу";
            if (i < n - 1) res += "-";
        }
        res += "!";
        return res;
}

void inputCatName_fromkeyboard(Cat& cat) {
    std::string cat_name;
    std::cout << "Введите имя кота: ";
    while (true) {
        std::getline(std::cin, cat_name);
        if (isgivename(cat_name)) {
            break;
        }
        std::cout << "Ошибка! Введите имя без цифр: ";
    }
    cat.setName(cat_name);
}

void inputCatName_fromfile(Cat& cat, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
        return;
    }
    if (file.is_open()) {
        std::string cat_name;
        std::getline(file, cat_name);
        cat.setName(cat_name);
        file.close();
    }
}

void inputCatName_random(Cat& cat) {
    const std::vector<std::string> cat_names = {
        "Барсик", "Мурка", "Васька", "Пушок", "Снежок",
        "Том", "Люся", "Гриша", "Рыжик", "Мурзик"
    };
    std::string cat_name = cat_names[rand() % cat_names.size()];
    cat.setName(cat_name);
}


void city::print() const {
        std::cout << "Город: " << name << "\nНаправления:\n";
        for (const auto& dest : where_go) {
            std::cout << " - " << dest.first->name
                      << ": " << dest.second << " руб.\n";
        }
    }

void addcity_fromkeyboard(std::vector<city*>& cities) {
    std::string city_name;
    std::cout << "Введите название города: ";
    while (true) {
        std::getline(std::cin, city_name);
        if (!isgivename(city_name)) {
            std::cout << "Ошибка! Введите название города без цифр: ";
            continue;
        }
        if (cityExists(cities, city_name)) {
            std::cout << "Ошибка! Такой город уже существует. Введите другое название: ";
            continue;
        }
        break;
    }
    cities.push_back(new city(city_name));
}

void addcity_fromfile(std::vector<city*>& cities, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
        return;
    }
    std::string city_name;
    while (file >> city_name) {
        if (!city_name.empty()) {
            cities.push_back(new city(city_name));
        }
    }
    std::cout << "\nГорода из файла добавлены!\n";
}


void addcity_random(std::vector<city*>& cities) {
    const std::vector<std::string> city_names = {
        "Москва", "Санкт-Петербург", "Новосибирск", "Екатеринбург", "Казань",
        "Нижний Новгород", "Челябинск", "Самара", "Омск", "Ростов-на-Дону"
    };
    std::string city_name = city_names[rand() % city_names.size()];
    cities.push_back(new city(city_name));
}



void addPerson_fromkeyboard(Person& person) {
    std::string name;
    int height;
    std::cout << "Введите имя человека: ";
    std::getline(std::cin, name);
    std::cout << "Введите рост человека (в см): ";
    while (!(std::cin >> height) || height <= 0) {
        std::cout << "Пожалуйста, введите корректный рост (положительное число): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    person.setName(name);
    person.setHeight(height);
}

void addPerson_fromfile(Person& person, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
        return;
    }
    if (file.is_open()) {
        std::string name;
        int height;
        std::getline(file, name);
        file >> height;
        person.setName(name);
        person.setHeight(height);
        file.close();
    }
}

void addPerson_random(Person& person) {
    const std::vector<std::string> names = {
        "Александр", "Мария", "Дмитрий", "Елена", "Сергей",
        "Анна", "Иван", "Ольга", "Павел", "Наталья"
    };
    std::string name = names[rand() % names.size()];
    int height = 150 + rand() % 51; // Рост от 150 до 200 см
    person.setName(name);
    person.setHeight(height);
}





