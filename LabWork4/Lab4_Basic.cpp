#include <iostream> // Подключаем библиотеку для ввода/вывода.

int main() // Объявляем главную функцию.
{
	int month; // Переменная для хранения номера месяца.

	// Запрашиваем ввод у пользователя.
	std::cout << "Enter the number month: ";
	std::cin >> month; // Считываем введённое значение в переменную month.

	// Проверяем, успешно ли прошёл ввод.
	if (std::cin.fail()) {
		// Если ввод некорректен выводим сообщение об ошибке.
		std::cout << "ERROR: Enter a number!" << std::endl;
		return 1;
	}

	// Используем switch для выбора месяца по его номеру.
	switch (month) {
		case 1:
			// Если месяц равен 1, выводим название января.
			std::cout << "January" << std::endl;
			break; // Выход из switch после выполнения.
		case 2:
			// Если месяц равен 2, выводим название февраль.
			std::cout << "February" << std::endl;
			break;
		case 3:
			// Если месяц равен 3, выводим название март.
			std::cout << "March" << std::endl;
			break;
		case 4:
			// Если месяц равен 4, выводим название апрель.
			std::cout << "April" << std::endl;
			break;
		case 5:
			// Если месяц равен 5, выводим название май.
			std::cout << "May" << std::endl;
			break;
		case 6:
			// Если месяц равен 6, выводим название июнь.
			std::cout << "June" << std::endl;
			break;
		case 7:
			// Если месяц равен 7, выводим название июль.
			std::cout << "July" << std::endl;
			break;
		case 8:
			// Если месяц равен 8, выводим название август.
			std::cout << "August" << std::endl;
			break;
		case 9:
			// Если месяц равен 9, выводим название сентябрь.
			std::cout << "September" << std::endl;
			break;
		case 10:
			// Если месяц равен 10, выводим название октябрь.
			std::cout << "October" << std::endl;
			break;
		case 11:
			// Если месяц равен 11, выводим название ноябрь.
			std::cout << "November" << std::endl;
			break;
		case 12:
			// Если месяц равен 12, выводим название декабрь.
			std::cout << "December" << std::endl;
			break;
		default: // Этот блок выполняется, если значение month не совпадает ни с одним из case. 
			std::cout << "ERROR: The month should be from 1 to 12!" << std::endl;
			break;
	}

	return 0; // Завершаем программу успешно.
}