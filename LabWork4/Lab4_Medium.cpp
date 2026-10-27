#include <iostream> // Подключение библиотеки ввода-вывода.

int main() // Объявляем главную функцию.
{
	int month; // Переменная для хранения номера месяца.

	std::cout << "Enter the number month: "; // Запрашиваем ввод у пользователя.
	std::cin >> month; // Считываем введённое значение в переменную month.

	// Проверяем, успешно ли прошёл ввод.
	if (std::cin.fail()) {
		std::cin.clear(); // Сбрасываем флаг ошибки.
		std::cin.ignore(10000, '\n'); // Очищаем буфер от некорректных данных.
		// Если ввод некорректен выводим сообщение об ошибке.
		std::cout << "ERROR: Enter a number!" << std::endl;
		return 1;
	}

	// Определяем время года по номеру месяца.
	switch (month) {
		// Зимние месяцы.
		case 12: // Декабрь.
		case 1: // Январь.
		case 2: // Февраль. 
			std::cout << "Winter" << std::endl; // Вывод "Зима".
			break; // Выход из switch.

		case 3: // Март.
		case 4: // Апрель.
		case 5: // Май.
			std::cout << "Spring" << std::endl; // Вывод "Весна".
			break; 

		case 6: // Июнь.
		case 7: // Июль.
		case 8: // Август.
			std::cout << "Summer" << std::endl; // Вывод "Лето".
			break; 

		case 9: // Сентябрь.
		case 10: // Октябрь.
		case 11: // Ноябрь.
			std::cout << "Autumn" << std::endl; // Вывод "Осень".
			break; 

		default: // Этот блок выполняется, если значение month не совпадает ни с одним из case.
			std::cout << "ERROR: The month should be from 1 to 12!" << std::endl;
			break;
	}

	return 0; // Завершаем программу успешно.
}


