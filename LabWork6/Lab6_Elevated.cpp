#include <iostream> // Подключаем библиотеку для ввода/вывода.
#include <iomanip> // Подключаем библиотеку для форматирования.
#include <random> // Генератор случайных чисел.
#include <limits> // Для очистки некорректного ввода.

using namespace std;

// Функция вывода массива.
void printArray(const int arr[], int SIZE, const char title[]) {
    cout << title << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << setw(5) << arr[i];

        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }

    cout << endl;
}

// Функция безопасного ввода числа K.
int readShift() {
    int k;

    while (true) {
        cout << "Enter the number of shift positions K: ";
        cin >> k;

        // Проверяем корректность ввода.
        if (cin.fail()) {
            cout << "ERROR! You must enter an integer!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Проверяем, что число неотрицательное.
        if (k < 0) {
            cout << "ERROR! K must be non-negative!" << endl;
            continue;
        }

        return k;
    }
}

int main() {
    // Объявление массива.
    const int SIZE = 20;

    // Границы случайных чисел.
    const int MIN_RANDOM = 1;
    const int MAX_RANDOM = 100;

    // Создаём статический массив.
    int arr[SIZE];

    // Создаём генератор случайных чисел.
    random_device rd;
    mt19937 gen(rd());

    // Задаём диапазон случайных чисел от 1 до 100.
    uniform_int_distribution<int> distribution(MIN_RANDOM, MAX_RANDOM);

    // Заполнение массива.
    cout << "Generation of an array from " << SIZE << " elements." << endl;

    for (int i = 0; i < SIZE; i++) {
        arr[i] = distribution(gen);
    }

    // Вывод исходного массива с помощью функции.
    printArray(arr, SIZE, "\nInitial array:");

    // Ввод количества позиций сдвига.
    int k = readShift();

    // Нормализация количества сдвигов.
    k = k % SIZE;

    cout << "\nNumber of actual shifts: " << k << endl;

    // Циклический сдвиг вправо.
    for (int step = 0; step < k; step++) {

        // Сохраняем последний элемент массива.
        int lastElement = arr[SIZE - 1];

        // Сдвигаем элементы вправо.
        for (int i = SIZE - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        // Переносим последний элемент в начало.
        arr[0] = lastElement;
    }

    // Вывод массива после сдвига.
    printArray(arr, SIZE, "\nThe array is cyclically shifted to the right:");

    cout << "The shift has been completed successfully!" << endl;

    return 0;
}
