#include <iostream> // Библиотека для ввода и вывода.

using namespace std; // Подключаем стандартное пространство имён.

// Функция уменьшает исходное число на delta.
// int& value означает передачу переменной по ссылке.
// Поэтому изменяется именно исходная переменная из main().
void decrement(int& value, int delta) {
	value = value - delta;
}

// Главная функция программы.
int main() {
	int number, delta;

	// Ввод исходного числа.
	cout << "Enter the number: ";
	cin >> number;

	// Ввод значения, на которое нужно уменьшить число.
	cout << "How much to reduce the number: ";
	cin >> delta;

	// Вывод значения до изменения.
	cout << "Before reduction: " << number << endl;

	// Вызов функции.
	decrement(number, delta);

	// Вывод изменённого значения.
	cout << "After reduction: " << number << endl;

	return 0; // Успешное завершение программы.
}
