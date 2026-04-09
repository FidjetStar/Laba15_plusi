#include <iostream>
#include "h.h"
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <list>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#ifdef _WIN64
#include <windows.h>
#endif
int getValidChoice(int min, int max) {
    using namespace std;
    int choice;
    while (!(cin >> choice) || choice < min || choice > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите число от " << min << " до " << max << ": ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

int main() {
    using namespace std;
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    srand(time(0));
    int mainChoice;
    Name name;
    Cat cat;
    Person person;
    vector<city*> cities;
    do {
        cout << "ГЛАВНОЕ МЕНЮ - РАБОТА С КЛАССАМИ\n";
        cout << "1. Name (Имя, Фамилия, Отчество)\n";
        cout << "2. Cat (Кот)\n";
        cout << "3. Person (Человек)\n";
        cout << "4. City (Город)\n";
        cout << "0. Выход\n";
        cout << "Выберите класс: ";
        mainChoice = getValidChoice(0, 4);
        switch (mainChoice) {
            case 1: {
                int choice;
                do {
                    cout << "\nКласс NAME\n";
                    cout << "1. Заполнить с клавиатуры\n";
                    cout << "2. Загрузить из файла\n";
                    cout << "3. Заполнить случайно\n";
                    cout << "4. Показать данные\n";
                    cout << "5.Примеры\n";
                    cout << "0. Назад\n";
                    cout << "Выберите действие: ";
                    choice = getValidChoice(0, 5);
                    switch (choice) {
                        case 1:
                            inputName_fromkeyboard(name);
                            cout << "\nДанные добавлены: " << name.Print() << "\n";
                            break;
                        case 2: {
                            string filename;
                            cout << "Введите имя файла: ";
                            getline(cin, filename);
                            inputName_fromfile(name, filename);
                            cout << "\nДанные: " << name.Print() << "\n";
                            break;
                        }
                        case 3:
                            inputName_random(name);
                            cout << "\nДанные созданы: " << name.Print() << "\n";
                            break;
                        case 4:
                            cout << "\nФИО\n";
                            cout << name.Print() << "\n";
                            break;
                        case 5: {
                            cout << "\nПримеры:\n";
                            Name example1("Клеопатра");
                            Name example2("Пушкин", "Александр", "Сергеевич");
                            Name example3("Маяковский", "Владимир");
                            cout << "Пример 1: " << example1.Print() << "\n";
                            cout << "Пример 2: " << example2.Print() << "\n";
                            cout << "Пример 3: " << example3.Print() << "\n";
                            break;
                        }
                        case 0:
                            break;
                    }
                } 
                while (choice != 0);
                break;
            }
            case 2: {
                int choice;
                do {
                    cout << "\nКласс CAT\n";
                    cout << "1. Заполнить с клавиатуры\n";
                    cout << "2. Загрузить из файла\n";
                    cout << "3. Заполнить случайно\n";
                    cout << "4. Показать данные\n";
                    cout << "5. Мяукнуть\n";
                    cout << "6. Кот мяукает\n";
                    cout << "7. Примеры\n";
                    cout << "0. Назад\n";
                    cout << "Выберите действие: ";
                    choice = getValidChoice(0, 7);
                    switch (choice) {
                        case 1:
                            inputCatName_fromkeyboard(cat);
                            cout << "\nДанные добавлены: " << cat.Print() << "\n";
                            break;
                        case 2: {
                            string filename;
                            cout << "Введите имя файла: ";
                            getline(cin, filename);
                            inputCatName_fromfile(cat, filename);
                            cout << "\nДанные: " << cat.Print() << "\n";
                            break;
                        }
                        case 3:
                            inputCatName_random(cat);
                            cout << "\nДанные созданы: " << cat.Print() << "\n";
                            break;
                        case 4:
                            cout << "\nИнформация\n";
                            cout << cat.Print() << "\n";
                            break;
                        case 5: {
                            cout << cat.meow() << "\n";
                            break;
                        }
                        case 6: {
                            int meowCount;
                            cout << "Сколько раз мяукать(1-100)? ";
                            meowCount = getValidChoice(1, 100);
                            cout << cat.meow(meowCount) << "\n";
                            break;
                        }
                        case 7: {
                            cout << "\nПримеры:\n";
                            Cat example("Барсик");
                            cout << example.Print() << "\n";
                            cout << example.meow() << "\n";
                            cout << example.meow(3) << "\n";
                            Cat example2(example);
                            cout << example2.Print();
                            break;
                        }
                        case 0:
                            break;
                    }
                } 
                while (choice != 0);
                break;
            }
            case 3: {
                int choice;
                do {
                    cout << "\nКласс PERSON\n";
                    cout << "1. Заполнить с клавиатуры\n";
                    cout << "2. Загрузить из файла\n";
                    cout << "3. Заполнить случайно\n";
                    cout << "4. Показать данные\n";
                    cout << "0. Назад\n";
                    cout << "Выберите действие: ";
                    choice = getValidChoice(0, 4);
                    switch (choice) {
                        case 1:
                            addPerson_fromkeyboard(person);
                            cout << "\n Данные добавлены: " << person.Print() << "\n";
                            break;
                        case 2: {
                            string filename;
                            cout << "Введите имя файла: ";
                            getline(cin, filename);
                            addPerson_fromfile(person, filename);
                            cout << "\n Данные: " << person.Print() << "\n";
                            break;
                        }
                        case 3:
                            addPerson_random(person);
                            cout << "\n Данные созданы: " << person.Print() << "\n";
                            break;
                        case 4:
                            cout << "\nИнформация\n";
                            cout << person.Print() << "\n";
                            break;
                        case 0:
                            break;
                    }
                } while (choice != 0);
                break;
            }
            case 4: {
                int choice;
                do {
                    cout << "\nКласс CITY\n";
                    cout << "1. Добавить город - с клавиатуры\n";
                    cout << "2. Добавить город - из файла\n";
                    cout << "3. Добавить город - случайно\n";
                    cout << "4. Показать все города\n";
                    cout << "5. Добавить маршрут между городами\n";
                    cout << "6. Примеры\n";
                    cout << "0. Назад\n";
                    cout << "Выберите действие: ";
                    choice = getValidChoice(0, 6);
                    switch (choice) {
                        case 1: {
                            int n = cities.size();
                            addcity_fromkeyboard(cities);
                            if (cities.size() > n) {
                                cout << "\nГород добавлен!\n";
                            }
                            break;
                        }
                        case 2: {
                            string filename;
                            cout << "Введите имя файла: ";
                            getline(cin, filename);
                            addcity_fromfile(cities, filename);
                            break;
                        }
                        case 3:
                            addcity_random(cities);
                            cout << "\nСлучайный город добавлен!\n";
                            break;
                        case 4: {
                            cout << "\nВсе города (" << cities.size() << ")\n";
                            if (cities.empty()) {
                                cout << "Городов нет!\n";
                            
                            } 
                            else {
                                for (size_t i = 0; i < cities.size(); i++) {
                                    cout << (i + 1) << ". " << cities[i]->getName() << "\n";
                                    auto routes = cities[i]->getWhereGo();
                                    if (!routes.empty()) {
                                        for (const auto& route : routes) {
                                            cout << "   -> " << route.first->getName() << " (стоимость: " << route.second << ")\n";
                                        }
                                    } 
                                    else {
                                        cout << "Нет маршрутов\n";
                                    }
                                }
                            }
                            break;
                        }
                        case 5: {
                            if (cities.size() < 2) {
                                cout << "Недостаточно городов для добавления маршрута!\n";
                                break; }
                            else {
                                cout << "\nДоступные города:\n";
                                for (size_t i = 0; i < cities.size(); i++) {
                                    cout << (i + 1) << ". " << cities[i]->getName() << "\n";
                                }
                                int from, to, cost;
                                cout << "\nВыберите город отправления (1-" << cities.size() << "): ";
                                from = getValidChoice(1, cities.size()) - 1;
                                do {
                                    cout << "Выберите город назначения (1-" << cities.size() << "): ";
                                    to = getValidChoice(1, cities.size()) - 1;
                                    if (from == to) {
                                        cout << "Ошибка! Город назначения совпадает с городом отправления. Выберите другой город.\n";
                                    }
                                } 
                                while (from == to);
                                cout << "Введите стоимость маршрута: ";
                                cost = getValidChoice(0, 10000);
                                cities[from]->add(cities[to], cost);
                                cout << "\nМаршрут добавлен: " << cities[from]->getName() << " -> " << cities[to]->getName() << " (стоимость: " << cost << ")\n";
                            }
                            break;
                        }
                        case 6: {
                            cout << "\nПримеры:\n";
                            vector<city*> New;
                            city* a = new city("A");
                            New.push_back(a);
                            city* b = new city("B");
                            New.push_back(b);
                            city* c = new city("C");
                            New.push_back(c);
                            city* d = new city("D");
                            New.push_back(d);
                            city* e = new city("E");
                            New.push_back(e);
                            city* f = new city("F");
                            New.push_back(f);
                            a->add(f, 1);
                            a->add(b, 5);
                            a->add(d, 6);
                            b->add(a,5);
                            b->add(c, 3);
                            cout << "Города и маршруты добавлены:\n";
                            for (auto c : New) {
                                c->print();
                                cout << "\n";
                            }
                            break;
                        }
                        case 0:
                            break;
                    }
                } 
                while (choice != 0);
                break;
            }
            case 0:
                cout << "\nПрограмма завершена\n";
                break;
        }
    } 
    while (mainChoice != 0);
    for (auto city_ptr : cities) {
        delete city_ptr;
    }
    cities.clear();
    return 0;
}
