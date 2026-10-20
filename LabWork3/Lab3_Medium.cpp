#include <iostream> // Подключаем библиотеку для ввода/вывода.

int main() // Объявляем главную функцию.
{
	int month; // Создаём переменную для хранения значения числа месяца.
	// Используем int, так как месяц не может быть дробным числом.

	std::cout << "Enter the month number (1-12): "; // Запрашиваем значение числа месяца.
	std::cin >> month; // Считываем введённое значение в переменную month.

	// Проверяем значение переменной month и выводим название месяца и количество дней.
	if (month == 1) {
		std::cout << "January, 31 days" << std::endl;
	} 
	else if (month == 2) {
		std::cout << "February, 28 days" << std::endl;
	} 
	else if (month == 3) {
		std::cout << "March, 31 days" << std::endl;
	} 
	else if (month == 4) {
		std::cout << "April, 30 days" << std::endl;
	} 
	else if (month == 5) {
		std::cout << "May, 31 days" << std::endl;
	} 
	else if (month == 6) {
		std::cout << "June, 30 days" << std::endl;
	} 
	else if (month == 7) {
		std::cout << "July, 31 days" << std::endl;
	} 
	else if (month == 8) {
		std::cout << "August, 31 days" << std::endl;
	} 
	else if (month == 9) {
		std::cout << "September, 30 days" << std::endl;
	} 
	else if (month == 10) {
		std::cout << "October, 31 days" << std::endl;
	} 
	else if (month == 11) {
		std::cout << "November, 30 days" << std::endl;
	} 
	else if (month == 12) {
		std::cout << "December, 31 days" << std::endl;
	} 
	else {
		// Если введённое число не соответствует заданному диапазону (1-12), выводим сообщение об ошибке.
		std::cout << "Error: The number must be between 1 and 12" << std::endl;
	}
	
	return 0; // Успешное завершение программы.
}