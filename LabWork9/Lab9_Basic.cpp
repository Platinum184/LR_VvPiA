#include <iostream> // Библиотека для ввода и вывода.

using namespace std; // Подключаем стандартное пространство имён.

// Функция вычисляет разность двух целых чисел.
int diff(int a, int b) {
	return a - b;
}

int main() { // Объявляем главную функцию.
	
	int a, b;

	// Ввод исходных данных.
	cout << "Enter the first number: ";
	cin >> a;

	cout << "Enter the second number: ";
	cin >> b;

	// Вызов функции и получение результата.
	int result = diff(a, b);

	// Вывод результата.
	cout << "The difference of numbers: " << result << endl;

	return 0; // Успешное завершение программы.
}