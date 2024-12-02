#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

std::string getExecutablePath(char *argv[]) {
  std::string execPath = std::string(argv[0]);

  size_t pos = execPath.find_last_of("/\\");
  if (pos != std::string::npos) {
    execPath = execPath.substr(0, pos);
  }

  return execPath;
}

void readAndPrintSections(const std::string &filename,
                          const std::string &section) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
    return;
  }

  std::string line;
  bool inSection = false;

  while (std::getline(file, line)) {

    if (line == "#" + section) {
      inSection = true;
      continue;
    }

    if (inSection && line.find("#") == 0) {
      std::cout << "Конец данного раздела." << std::endl;
      break;
    }

    if (inSection) {
      std::cout << line << std::endl;
    }
  }

  file.close();
}

unsigned long long factorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  return n * factorial(n - 1);
}

void clearConsole() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void printAppleGreen(int num) {
  int caseValue = 0;
  if (num % 3 == 0)
    caseValue |= 1;
  if (num % 5 == 0)
    caseValue |= 2;

  switch (caseValue) {
  case 3:
    std::cout << num << " apple green" << std::endl;
    break;
  case 1:
    std::cout << num << " apple" << std::endl;
    break;
  case 2:
    std::cout << num << " green" << std::endl;
    break;
  default:
    std::cout << "Not green or apple" << std::endl;
    break;
  }
}

int main(int argc, char *argv[]) {
  int choice;
  std::string exeDir = getExecutablePath(argv);
  std::cout << "Путь до исполняемого файла: " << exeDir << std::endl;

  while (true) {
    std::cout << "\nВыберите действие:\n"
              << "1. Объяснить основные типы данных\n"
              << "2. Объяснить ссылки и указатели\n"
              << "3. Вычислить факториал и apple/green\n"
              << "4. Выйти\n"
              << "Ваш выбор: ";
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Неверный ввод. Пожалуйста, введите число: ";
      std::cin >> choice;
    }

    clearConsole();

    switch (choice) {
    case 1:
      readAndPrintSections(exeDir + "/answers.txt", "DataTypes");
      break;
    case 2:
      readAndPrintSections(exeDir + "/answers.txt", "PointersAndReferences");
      break;
    case 3: {
      int num;
      std::cout << "Введите число: ";
      std::cin >> num;

      std::cout << "Факториал числа " << num << " = " << factorial(num)
                << std::endl;

      printAppleGreen(num);
      break;
    }
    case 4:
      std::cout << "Выход из программы. До свидания!\n";
      return 0;
    default:
      std::cout << "Неверный выбор, попробуйте снова.\n";
    }
  }

  return 0;
}
