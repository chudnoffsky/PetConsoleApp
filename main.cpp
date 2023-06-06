#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cctype>
#include "nlohmann/json.hpp"

/**
 * @mainpage Консольный Пет проект
 *
 * @section intro_sec Введение
 *
 * Эта программа представляет собой систему управления клиникой для домашних животных.
 * Она позволяет пользователям добавлять и управлять информацией о своих питомцах, включая их тип,
 * породу, имя, возраст, вес, рост, прививки и болезни. Программа также позволяет пользователям добавлять
 * информацию о лекарствах для своих питомцев.

 *
 * @section author_sec Автор
 *
 * Чудновский Владимир
 *
 * @section version_sec Версия
 *
 * Версия 1.0.0
 */



using json = nlohmann::json;
using namespace std::string_literals;


/**
 * @brief Структура, представляющая лекарство
 */
struct Medication {
    std::string name; ///< Название лекарства
    tm startTime{}; ///< Время начала приема лекарства
    int durationInDays{}; ///< Продолжительность приема лекарства в днях
};


/**
 * @class Pet
 * @brief Класс для хранения информации о питомце
 *
 * Этот класс содержит информацию о питомце, такую как тип, порода, имя, возраст, вес и рост.
 * Также в классе хранится информация о лекарствах, прививках и заболеваниях питомца.
 */
class Pet {
public:

    /**
    * @brief Метод для добавления лекарства питомцу
    * @param medication_ Лекарство, которое нужно добавить
    */
    void addMedication(const Medication &medication_) {
        medication = medication_;
    }

    /**
    * @brief Метод для установки типа питомца
    * @param type_ Тип питомца (например, собака или кошка)
    */
    void setType(const std::string &type_) {
        type = type_;
    }

    /**
    * @brief Метод для установки породы питомца
    * @param breed_ Порода питомца
    */
    void setBreed(const std::string &breed_) {
        breed = breed_;
    }

    /**
    * @brief Метод для установки имени питомца
    * @param name_ Имя питомца
    */
    void setName(const std::string &name_) {
        name = name_;
    }

    /**
    * @brief Метод для установки возраста питомца
    * @param age_ Возраст питомца в годах
    */
    void setAge(int age_) {
        age = age_;
    }

    /**
    * @brief Метод для установки веса питомца
    * @param weight_ Вес питомца в килограммах
    */
    void setWeight(double weight_) {
        weight = weight_;
    }

    /**
    * @brief Метод для установки роста питомца
    * @param height_ Рост питомца в сантиметрах
    */
    void setHeight(double height_) {
        height = height_;
    }

    /**
    * @brief Метод для добавления прививки питомцу
    * @param vaccination Прививка, которую нужно добавить
    */
    void addVaccination(std::string &vaccination) {
        vaccinations.push_back(vaccination);
    }

    /**
    * @brief Метод для добавления заболевания питомцу
    * @param illness Заболевание, которое нужно добавить
    */
    void addIllness(std::string &illness) {
        illnesses.push_back(illness);
    }

public:
    /**
    * @brief Метод для получения лекарства, которое принимает питомец
    * @return Лекарство, которое принимает питомец
    */
    [[nodiscard]] const Medication &getMedication() const {
        return medication;
    }

    /**
    * @brief Метод для получения типа питомца
    * @return Тип питомца (например, собака или кошка)
    */
    [[nodiscard]] const std::string &getType() const {
        return type;
    }

    /**
    * @brief Метод для получения породы питомца
    * @return Порода питомца
    */
    [[nodiscard]] const std::string &getBreed() const {
        return breed;
    }

    /**
    * @brief Метод для получения имени питомца
    * @return Имя питомца
    */
    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    /**
    * @brief Метод для получения возраста питомца
    * @return Возраст питомца в годах
    */
    [[nodiscard]] int getAge() const {
        return age;
    }

    /**
    * @brief Метод для получения веса питомца
    * @return Вес питомца в килограммах
    */
    [[nodiscard]] double getWeight() const {
        return weight;
    }

    /**
   * @brief Метод для получения роста питомца
   * @return Рост питомца в сантиметрах
   */
    double getHeight() const {
        return height;
    }

    /**
    * @brief Метод для получения списка прививок, которые были сделаны питомцу
    * @return Список прививок, которые были сделаны питомцу
    */
    [[nodiscard]] const std::vector<std::string> &getVaccinations() const {
        return vaccinations;
    }

    /**
    * @brief Метод для получения списка заболеваний, которые были у питомца
    * @return Список заболеваний, которые были у питомца
    */
    [[nodiscard]] const std::vector<std::string> &getIllnesses() const {
        return illnesses;
    }

    /**
    * @brief Метод для вывода информации о питомце
    */
    void printPetInfo() {
        std::cout << "Тип: " << type << "\n";
        std::cout << "Порода: " << breed << "\n";
        std::cout << "Имя: " << name << "\n";
        std::cout << "Возраст: " << age << "\n";
        std::cout << "Вес: " << weight << "\n";
        std::cout << "Рост: " << height << "\n";
    }

private:
    Medication medication; ///< Лекарство, которое принимает питомец
    std::string type; ///< Тип питомца (например, собака или кошка)
    std::string breed; ///< Порода питомца
    std::string name; ///< Имя питомца
    int age{}; ///< Возраст питомца в годах
    double weight{}; ///< Вес питомца в килограммах
    double height{}; ///< Рост питомца в сантиметрах
    std::vector<std::string> vaccinations; ///< Список прививок, которые были сделаны питомцу
    std::vector<std::string> illnesses; ///< Список заболеваний, которые были у питомца
};


/**
 * @brief Класс, представляющий пользователя
 */
class User {
public:
    std::vector<Pet> pets; ///< Список питомцев пользователя

    std::string fullName; ///< Полное имя пользователя
    std::string phone; ///< Номер телефона пользователя

    /**
     * @brief Конструктор по умолчанию
     */
    User() = default;

    /**
     * @brief Метод для добавления нового питомца в список питомцев пользователя
     * @param pet Новый питомец
     */
    void addPet(Pet pet) {
        pets.push_back(pet);
    }

    /**
     * @brief Метод для вывода информации о всех питомцах пользователя
     */
    void printPet() {
        for (auto &pet: pets) {
            pet.printPetInfo();
            std::cout << "\n";
        }
    }
};


/**
 * @brief Функции для работы с интерфейсом и классами
 */
namespace interface {

    /**
 * @brief Проверяет, является ли номер телефона действительным российским номером телефона.
 *
 * @param phoneNumber Строка, содержащая номер телефона для проверки.
 * @return true Если номер телефона является действительным российским номером телефона.
 * @return false Если номер телефона не является действительным российским номером телефона.
 */
    bool isValidRussianPhoneNumber(const std::string &phoneNumber) {
        if (phoneNumber.length() != 12 &&
            phoneNumber.length() != 11)  ///< Проверяет, действительно ли это русский номер телефона

        {
            return false;
        }

        if (phoneNumber.length() == 12 && phoneNumber.substr(0, 2) != "+7") {
            return false;
        }

        if (phoneNumber.length() == 11 && phoneNumber[0] != '8') {
            return false;
        }

        for (size_t i = phoneNumber.length() == 12 ? 2 : 1; i < phoneNumber.length(); i++) {
            if (!isdigit(phoneNumber[i])) {
                return false;
            }
        }

        return true;
    }


    /**
 * @brief Находит слово в тексте, игнорируя регистр и пробелы.
 *
 * Эта функция принимает текст и слово в качестве входных данных и возвращает true, если слово найдено в тексте.
 * Функция не чувствительна к регистру и игнорирует пробелы. Она также устанавливает локаль на русский.
 *
 * @param text Текст для поиска.
 * @param word Слово для поиска.
 * @return true, если слово найдено в тексте, false в противном случае.
 */
    bool isEqual(std::string first, std::string second) {
        first.erase(std::remove(first.begin(), first.end(), ' '), first.end());
        second.erase(std::remove(second.begin(), second.end(), ' '), second.end());

        std::transform(first.begin(), first.end(), first.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        std::transform(second.begin(), second.end(), second.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        return first == second;
    }


    /**
 * @brief Выводит таблицу с информацией о пользователях
 * @param users Вектор пользователей для вывода
 */
    void printUserList(std::vector<User> &users) {


        // Print table header
        std::cout << "+-----+--------------------+--------------------+--------------------+" << std::endl;
        std::cout << "| " << std::left << std::setw(3) << "No." << " | " << std::setw(18) << "Full Name" << " | "
                  << std::setw(18) << "Phone" << " | " << std::setw(18) << "Number of Pets" << " |" << std::endl;

        // Print table rows
        for (auto i = 0u; i < users.size(); i++) {
            User user = users[i];
            std::cout << "+-----+--------------------+--------------------+--------------------+" << std::endl;
            std::cout << "| " << std::left << std::setw(3) << i + 1 << " | " << std::setw(18) << user.fullName << " | "
                      << std::setw(18) << user.phone << " | " << std::setw(18) << user.pets.size() << " |" << std::endl;
        }

        // Print table footer
        std::cout << "+-----+--------------------+--------------------+--------------------+" << std::endl;


    }


/**
* @brief Запрашивает у пользователя информацию о новом пользователе и его питомцах и возвращает объект класса User с этой информацией
* @return Объект класса User с информацией о новом пользователе и его питомцах
*/
    User addNew() {

        User user;

        std::cout << "Имя: ";
        std::string fname, lname;
        std::cin >> fname;
        std::cout << "Фамилия: ";
        std::cin >> lname;
        user.fullName = std::string(fname + " " + lname);
        std::string number;

        std::string phoneNumber;
        std::cout << "Введите свой русский номер телефона: ";
        std::cin >> phoneNumber;

        while (!isValidRussianPhoneNumber(phoneNumber)) {
            std::cout << "Неверный русский номер. Попробуйте снова: ";
            std::cin >> phoneNumber;
        }
        user.phone = phoneNumber;
        int numPets;
        std::cout << "Введите число питомцев: ";
        std::cin >> numPets;

        for (int i = 0; i < numPets; i++) {
            Pet pet;

            std::string type;
            std::cout << "Введите тип питомца (кошка, собака и т.д.): ";
            std::cin >> type;
            pet.setType(type);

            std::string breed;
            std::cout << "Введите породу питомца: ";
            std::cin >> breed;
            pet.setBreed(breed);

            std::string name;
            std::cout << "Введите имя питомца: ";
            std::cin >> name;
            pet.setName(name);

            int age;
            std::cout << "Введите возраст питомца: ";
            std::cin >> age;
            pet.setAge(age);

            double weight;
            std::cout << "Введите вес питомца: ";
            std::cin >> weight;
            pet.setWeight(weight);

            double height;
            std::cout << "Введите рост питомца: ";
            std::cin >> height;
            pet.setHeight(height);

            int numVaccinations;
            std::cout << "Введите число вакцинаций: ";
            std::cin >> numVaccinations;

            for (int j = 0; j < numVaccinations; j++) {
                std::string vaccination;
                std::cout << "Введите тип вакцинации: ";
                std::cin >> vaccination;
                pet.addVaccination(vaccination);
            }

            int numIllnesses;
            std::cout << "Введите число болезней: ";
            std::cin >> numIllnesses;

            for (int j = 0; j < numIllnesses; j++) {
                std::string illness;
                std::cout << "Введите тип болезни: ";
                std::cin >> illness;
                pet.addIllness(illness);
            }

            user.addPet(pet);
        }


        return user;


    }

/**
 * @brief Записывает данные о пользователях и их питомцах в файл в формате JSON
 * @param fileName Имя файла для записи данных
 * @param users Вектор пользователей для записи в файл
 */
    void writeJson(const std::string &fileName, const std::vector<User> &users) {
        json data;
        for (const auto &user: users) {
            json item;
            item["fullName"] = user.fullName;
            item["phone"] = user.phone;
            for (const auto &pet: user.pets) {
                json itPet;
                itPet["type"] = pet.getType();
                itPet["breed"] = pet.getBreed();
                itPet["name"] = pet.getName();
                itPet["age"] = pet.getAge();
                itPet["weight"] = pet.getWeight();
                itPet["height"] = pet.getHeight();
                for (const auto &vac: pet.getVaccinations()) {
                    itPet["vaccinations"].push_back(vac);
                }
                for (const auto &ill: pet.getIllnesses()) {
                    itPet["illnesses"].push_back(ill);
                }
                item["pets"].push_back(itPet);
            }
            data.push_back(item);
        }
        std::ofstream file(fileName);
        file << data.dump(4);
        file.close();
    }

    /**
 * @brief Функция для чтения информации о пользователях из JSON-файла
 * @param fileName Имя файла с информацией о пользователях в формате JSON
 * @param users Ссылка на вектор, в который будут добавлены прочитанные пользователи
 *
 * Эта функция считывает информацию о пользователях из файла в формате JSON и добавляет их в вектор users.
 * Каждый пользователь имеет поля fullName и phone, а также список питомцев.
 * Каждый питомец имеет поля type, breed, name, age, weight и height, а также списки прививок и заболеваний.
 */
    void readJson(const std::string &fileName, std::vector<User> &users) {
        json data;
        std::ifstream file(fileName);
        if (file.fail()) {
            std::cout << "File " << fileName << " not found!" << std::endl;
        }
        file >> data;
        file.close();
        for (const auto &item: data) {
            User user;
            user.fullName = item["fullName"];
            user.phone = item["phone"];
            for (const auto &itPet: item["pets"]) {
                Pet pet;
                pet.setType(itPet["type"]);
                pet.setBreed(itPet["breed"]);
                pet.setName(itPet["name"]);
                pet.setAge(itPet["age"]);
                pet.setWeight(itPet["weight"]);
                pet.setHeight(itPet["height"]);
                for (const auto &vac: itPet["vaccinations"]) {
                    std::string str = vac;
                    pet.addVaccination(str);
                }
                for (const auto &ill: itPet["illnesses"]) {
                    std::string str = ill;
                    pet.addIllness(str);
                }
                user.addPet(std::move(pet));
            }
            users.push_back(user);
        }
    }
}


int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Pet clinic Data" << std::endl;
    std::vector<User> users;
    std::string fileName = "../data.json";
    std::cout << "Для загрузки базы данных нажмите любую букву >";
    getchar();
    interface::readJson(fileName, users);
    char number = '0';
    while (number != '5') {
        std::cout << "|=== Выберите ===|\n";
        std::cout << "1. Вывести имя клиентов\n";
        std::cout << "2. Показать питомцев\n";
        std::cout << "3. Добавить нового питомца\n";
        std::cout << "4. Удалить Клиента или его питомца\n";
        std::cout << "5. Сохранить и выйти\n";
        std::cout << " > ";
        std::cin >> number;
        while (number < '1' || number > '5') {
            std::cout << "Попробуйте снова > ";
            std::cin >> number;
        }
//        system("clear");
        switch (number) {
            case '1':
                interface::printUserList(users);
                break;
            case '2':
                for (auto &user: users) {
                    user.printPet();
                }
                break;
            case '3': {
                std::cout << "Выберите:\n";
                std::cout << "1. Новый пользователь\n";
                std::cout << "2. Существующий\n";
                std::cout << "> ";
                char login;
                std::cin >> login;
                while (login < '1' || login > '2') {
                    std::cout << "Try again >";
                    std::cin >> login;
                }
                if (login == '1') {
                    User user = interface::addNew();
                    users.push_back(user);
                } else if (login == '2') {
                    std::cout << "Введите полное имя пользователя!\n";
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    auto res = std::find_if(users.begin(), users.end(), [&](User &u) {
                        return interface::isEqual(u.fullName, name);
                    });
                    if (res != users.end()) {
                        Pet pet;
                        res->addPet(pet);
                    }
                }
                break;
            }
            case '4': {
                std::cout << "=== Выберите ===\n";
                std::cout << "1. Удалить пользователя\n";
                std::cout << "2. Удалить питомца пользователя\n";
                std::cout << " > ";
                char choice;
                std::cin >> choice;
                if (choice != '1' && choice != '2') std::cout << "Wrong command!" << std::endl;
                if (choice == '1') {
                    std::cout << "Введите полное имя пользователя" << std::endl;
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    auto res = std::find_if(users.begin(), users.end(), [&](auto u) {
                        return interface::isEqual(u.fullName, name);
                    });
//
                    if (res != users.end()) {
                        users.erase(res);
                        std::cout << "Пользователь удален!\n";
                    } else {
                        std::cout << "Пользователь не найден!\n";
                    }
                } else if (choice == '2') {
                    std::cout << "Введите полное имя пользователя!\n";
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    auto res = std::find_if(users.begin(), users.end(), [&](const User &u) {
                        return interface::isEqual(u.fullName, name);
                    });
                    if (res != users.end()) {
                        std::cout << "Введите имя питомца!\n";
                        std::string petName;
                        std::getline(std::cin, petName);
                        auto petRes = std::find_if(res->pets.begin(), res->pets.end(), [&](Pet &p) {
                            return interface::isEqual(p.getName(), petName);
                        });
                        if (petRes != res->pets.end()) {
                            res->pets.erase(petRes);
                            std::cout << "Питомец удален!\n\n" << std::endl;
                        } else {
                            std::cout << "Питомец не найден!\n\n" << std::endl;
                        }
                    } else {
                        std::cout << "Пользователь не найден!\n\n" << std::endl;
                    }
                }
                break;
            }

            case '5': {
                break;
            }
        }
    }
    interface::writeJson("../data.json", users);
    std::cout << "До встречи!\n";
    return 0;
}