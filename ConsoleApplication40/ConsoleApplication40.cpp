#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string convertToBase(int number, int base) {
    string result;

    if (number == 0) {
        return "0";
    }

    while (number != 0) {
        result += digits[number % base];
        number /= base;
    }

    reverse(result.begin(), result.end());
    return result;
}

const int NUM_ROLLS = 5;

struct Player {
    string name;
    int totalScore;
};

Player playDice(Player& player) {
    srand(time(nullptr));
    for (int i = 0; i < NUM_ROLLS; ++i) {
        int roll = rand() % 6 + 1;
        cout << player.name << " бросил кубик и получил " << roll <<endl;
        player.totalScore += roll;
    }

    return player;
}

void printAverage(const Player& p1, const Player& p2) {
    float avgP1 = static_cast<float>(p1.totalScore) / NUM_ROLLS;
    float avgP2 = static_cast<float>(p2.totalScore) / NUM_ROLLS;
    cout << "Средняя сумма по броскам для " << p1.name << ": " << avgP1 << endl;
    cout << "Средняя сумма по броскам для " << p2.name << ": " << avgP2 << endl;
}

bool whoGoesFirst() {
    srand(time(nullptr));
    return rand() % 2;
}

void drawRectangle(int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << "* ";
        }
        cout << "\n";
    }
}

unsigned long factorial(unsigned int n) {
    unsigned long result = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void findMinMax(int* arr, int size) {
    if (size == 0) {
        cout << "Массив пуст\n";
        return;
    }

    int minValue = arr[0], maxValue = arr[0];
    int minIndex = 0, maxIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }

    cout << "Минимум: " << minValue << " (индекс " << minIndex << ")\n";
    cout << "Максимум: " << maxValue << " (индекс " << maxIndex << ")\n";
}

void reverseArray(int* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    setlocale(LC_ALL,"Rus");
    int number = 27;
    int base = 16;
    cout << "Перевод числа " << number << " в систему счисления " << base << ": " << convertToBase(number, base) << endl;

    // Игра "Кубики"
    Player human{ "Человек", 0 };
    Player computer{ "Компьютер", 0 };

    bool humanFirst = whoGoesFirst();
    if (humanFirst) {
        cout << "Первый ход за человеком.\n";
        human = playDice(human);
        computer = playDice(computer);
    }
    else {
        cout << "Первый ход за компьютером.\n";
        computer = playDice(computer);
        human = playDice(human);
    }

    if (human.totalScore > computer.totalScore) {
        cout << "Победил человек!\n";
    }
    else if (computer.totalScore > human.totalScore) {
        cout << "Победил компьютер!\n";
    }
    else {
        cout << "Ничья!\n";
    }

    printAverage(human, computer);

    int height = 5;
    int width = 10;
    drawRectangle(height, width);

    unsigned int num = 5;
    cout << "Факториал числа " << num << " равен " << factorial(num) << std::endl;

    int primeNumber = 17;
    if (isPrime(primeNumber)) {
       cout << primeNumber << " - простое число\n";
    }
    else {
        cout << primeNumber << " - не простое число\n";
    }


    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    int size = sizeof(array) / sizeof(array[0]);
    findMinMax(array, size);

    // Обратный порядок массива
    int reversedArray[] = {1, 2, 3, 4, 5};
    int reversedSize = sizeof(reversedArray) / sizeof(reversedArray[0]);
    reverseArray(reversedArray, reversedSize);
    for (int i = 0; i < reversedSize; ++i) {
        cout << reversedArray[i] << " ";
    }
    cout << "\n";

    return 0;
    }