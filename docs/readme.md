
# Пространство имен Interface

Пространство имен `interface` содержит функции для работы с интерфейсами и классами.

## Функции

### isValidRussianPhoneNumber

Эта функция проверяет, является ли номер телефона действительным российским номером телефона. Действительный российский номер телефона начинается с кода страны +7 или 8, за которым следуют 10 цифр.

```cpp
bool isValidRussianPhoneNumber(const std::string &phoneNumber);
```

### isEqual

Эта функция сравнивает две строки на равенство, игнорируя регистр и пробелы. Она принимает две строки в качестве входных данных и возвращает true, если они равны при игнорировании регистра и пробелов, и false в противном случае.

```cpp
bool isEqual(std::string first, std::string second);
```

### printUserList

Эта функция выводит таблицу с информацией о пользователях.

```cpp
void printUserList(std::vector<User> &users);
```

### addNew

Эта функция запрашивает у пользователя информацию о новом пользователе и его питомцах и возвращает объект класса `User` с этой информацией.

```cpp
User addNew();
```

### writeToJsonFile

Эта функция записывает данные о пользователях и их питомцах в файл в формате JSON.

```cpp
void writeToJsonFile(const std::string &fileName, const std::vector<User> &users);
```

### readJson

Эта функция читает информацию о пользователях из файла JSON.

```cpp
void readJson(const std::string &fileName, std::vector<User> &users);
```