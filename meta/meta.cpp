#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Функция для игры "Угадай число"
void guessNumberGame() {
    int minRange, maxRange;
    cout << "Введите минимальное число диапазона: ";
    cin >> minRange;
    cout << "Введите максимальное число диапазона: ";
    cin >> maxRange;

    if (minRange >= maxRange) {
        cout << "Некорректный диапазон! Минимум должен быть меньше максимума.\n";
        return;
    }

    srand(time(0));
    int secretNumber = rand() % (maxRange - minRange + 1) + minRange;
    int attempts = 0;
    int userGuess;

    cout << "Я загадал число между " << minRange << " и " << maxRange << ". Попробуй угадать!\n";

    do {
        cout << "Твоя догадка: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < secretNumber) {
            cout << "Слишком маленькое! Попробуй еще раз.\n";
        }
        else if (userGuess > secretNumber) {
            cout << "Слишком большое! Попробуй еще раз.\n";
        }
    } while (userGuess != secretNumber);

    cout << "Поздравляю! Ты угадал число " << secretNumber << " за " << attempts << " попыток!\n";
}

// Функция для игры "Таблица умножения"
void multiplicationTableGame() {
    int correctAnswers = 0;
    int totalQuestions;

    cout << "Сколько примеров ты хочешь решить? ";
    cin >> totalQuestions;

    for (int i = 0; i < totalQuestions; i++) {
        int num1 = rand() % 9 + 2; // От 2 до 10
        int num2 = rand() % 9 + 2; // От 2 до 10

        cout << num1 << " * " << num2 << " = ? ";
        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == num1 * num2) {
            cout << "Правильно!\n";
            correctAnswers++;
        }
        else {
            cout << "Неправильно! Правильный ответ: " << (num1 * num2) << "\n";
        }
    }

    cout << "Твой результат: " << correctAnswers << "/" << totalQuestions << " ("
        << (correctAnswers * 100 / totalQuestions) << "%)\n";
}

// Функция для игры "Сложение и вычитание"
void additionSubtractionGame() {
    int correctAnswers = 0;
    int totalQuestions;

    cout << "Сколько примеров ты хочешь решить? ";
    cin >> totalQuestions;

    for (int i = 0; i < totalQuestions; i++) {
        int num1 = rand() % 50 + 1; // От 1 до 50
        int num2 = rand() % 50 + 1; // От 1 до 50

        // Определяем случайным образом сложение или вычитание
        bool isAddition = (rand() % 2 == 0);
        int correctAnswer;
        string operation;

        if (isAddition) {
            correctAnswer = num1 + num2;
            operation = " + ";
        }
        else {
            // Убедимся, что результат не отрицательный
            if (num1 < num2) swap(num1, num2);
            correctAnswer = num1 - num2;
            operation = " - ";
        }

        cout << num1 << operation << num2 << " = ? ";
        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Правильно!\n";
            correctAnswers++;
        }
        else {
            cout << "Неправильно! Правильный ответ: " << correctAnswer << "\n";
        }
    }

    cout << "Твой результат: " << correctAnswers << "/" << totalQuestions << " ("
        << (correctAnswers * 100 / totalQuestions) << "%)\n";
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    setlocale(LC_ALL, ""); // Для поддержки русского языка

    int choice;
    do {
        cout << "\n=== Математическая Игра ===";
        cout << "\n1. Угадай число";
        cout << "\n2. Таблица умножения";
        cout << "\n3. Сложение и вычитание";
        cout << "\n4. Выход";
        cout << "\nВыберите игру: ";
        cin >> choice;

        switch (choice) {
        case 1:
            guessNumberGame();
            break;
        case 2:
            multiplicationTableGame();
            break;
        case 3:
            additionSubtractionGame();
            break;
        case 4:
            cout << "Спасибо за игру! До свидания!\n";
            break;
        default:
            cout << "Некорректный выбор! Попробуйте снова.\n";
        }
    } while (choice != 4);

    return 0;
}