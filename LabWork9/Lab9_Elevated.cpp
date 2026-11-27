#include <iostream> // Библиотека для ввода и вывода.
#include <limits> // limits - для очистки буфера ввода (numeric_limits).

using namespace std; // Подключаем стандартное пространство имён.

// Прототипы функций.
void clearInput();
int readInt(string message);
bool isPrime(int n);
void printPrimesInRange(int start, int end);
void runProgram();

// Очистка некорректного ввода.
void clearInput() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция безопасного ввода целого числа.
// message — текст приглашения к вводу.
// return — введённое целое число.
int readInt(string message) {
	int value;

	cout << message;

	while (!(cin >> value)) {
		cout << "Error! Enter an integer:";
		clearInput();
	}

	return value;
}

// Проверка числа на простоту.
// n — проверяемое число.
// return — true, если число простое, иначе false.
bool isPrime(int n) {
	// Числа меньше 2 не являются простыми.
	if (n < 2) {
		return false;
	}

	// Проверяем делители от 2 до квадратного корня из n.
	for (int i = 2; i <= n / i;i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

// Вывод простых чисел в заданном диапазоне.
// start — начало диапазона.
// end — конец диапазона.
// return — функция ничего не возвращает.
void printPrimesInRange(int start, int end) {
	bool found = false;

	cout << "Prime numbers in the range: ";

	for (int i = start; i <= end; i++) {
		if (isPrime(i)) {
			cout << i << " ";
			found = true;
		}
	}

	if (!found) {
		cout << "There are no prime numbers";
	}

	cout << endl;
}

// Главная функция обработки программы.
void runProgram() {
	int start = readInt("Enter the beginning of the range: ");
	int end = readInt("Enter the end of the range: ");

	// Проверка правильности диапазона.
	if (start > end) {
		cout << "Error! The beginning of the range is greater than the end." << endl;
		return;
	}

	// Запуск поиска простых чисел.
	printPrimesInRange(start, end);
}

// Главная функция программы.
int main() {
	runProgram();

	return 0; // Успешное завершение программы.
}