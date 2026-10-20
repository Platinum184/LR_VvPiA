#include <iostream> // Подключаем библиотеки для ввода/вывода.
 
int main() // Объявляем главную функцию.
{ 
	int YearOfBirth; // Создаём переменную для хранения значения года рождения.
	int CurrentYear; // Создаём переменную для хранения значения текущего года.
	int age; // Создаём переменную для хранения значения возраста.
	// Используем int, так как месяц не может быть дробным числом.

	std::cout << "Enter the year of birth: "; // Запрашиваем у пользователя значение года рождения.
	std::cin >> YearOfBirth; // Считываем введённое значение в переменную YearOfBirth.

	std::cout << "Enter the current year: "; // Запрашиваем у пользователя значение текущего года.
	std::cin >> CurrentYear; // Считываем введённое значение в переменную CurrentYear.

	// Проверяем, удалось ли корректно считать целые числа из ввода.
	if (std::cin.fail()) {
		std::cout << "Error: Enter an integer!" << std::endl;
		return 1;
	}

	// Проверяем, что год рождения — положительное число.
	if (YearOfBirth <= 0) {
		std::cout << "Error: The year must be positive!" << std::endl;
		return 1;
	}

	// Проверяем, что текущий год — положительное число.
	if (CurrentYear <= 0) {
		std::cout << "Error: The year must be positive!" << std::endl;
		return 1;
	}

	// Проверяем логическую корректность: год рождения не может быть больше текущего года.
	if (YearOfBirth > CurrentYear) {
		std::cout << "Error: The year of birth cannot be in the future!" << std::endl;
		return 1;
	}

	// Рассчитываем возраст как разницу между текущим годом и годом рождения.
	age = CurrentYear - YearOfBirth;

	// Дополнительная проверка, чтобы возраст был разумным.
	if (age > 122) {
		std::cout << "Error: Age should be reasonable!" << std::endl;
		return 1;
	}

	// Выводим рассчитанный возраст.
	std::cout << "Age: " << age << std::endl;

	// Определяем и выводим возрастную категорию.
	if (age <= 12) {
		std::cout << "Category: Child" << std::endl;
	} 
	else if (age <= 17) {
		std::cout << "Category: Teenager" << std::endl;
	} 
	else if (age <= 64) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Category: Elderly" << std::endl;
	}

	return 0; // Успешное завершение программы.
}