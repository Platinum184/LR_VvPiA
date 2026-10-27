#include <iostream> // Подключение библиотеки ввода-вывода.
#include <limits> // Для очистки буфера ввода.

int main() // Объявляем главную функцию.
{
	int  figure; // Переменная для хранения выбранной фигуре.

	while (true) {
		// Основное меню программы.
		std::cout << "Geometric calculator" << std::endl;
		std::cout << "1. Circle" << std::endl;
		std::cout << "2. Square" << std::endl;
		std::cout << "3. Rectangle" << std::endl;
		std::cout << "4. Triangle" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << " " << std::endl;

		std::cout << "Choose a figure: ";
		std::cin >> figure;

		// Обработка ошибок ввода фигуры.
		while (std::cin.fail()) {
			std::cin.clear(); // Сброс флага ошибки.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера.

			std::cout << "ERROR: Wrong input!" << std::endl;
			std::cout << "Choose a figure: ";
			std::cin >> figure;
		}

		std::cout << " " << std::endl;

		switch (figure) {

		case 1: { // Обработка круга.
			int action;
			double radius;
			double Csquare;
			double Clength;
			const double PI = 3.14;

			std::cout << "CIRCLE" << std::endl;
			std::cout << "1. Square" << std::endl;
			std::cout << "2. Perimeter (circumference length)" << std::endl;
			std::cout << "0. Back" << std::endl;
			std::cout << " " << std::endl;

			std::cout << "Choose an action: ";
			std::cin >> action;
			std::cout << " " << std::endl;

			// Обработка ошибок ввода действия.
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Choose an action: ";
				std::cin >> action;
			}

			// Возврат в главное меню.
			if (action == 0) {
				break;
			}

			if (action != 1 && action != 2) {
				std::cout << "ERROR: Wrong action!" << std::endl;
				break;
			}

			// Ввод радиуса.
			std::cout << "Enter the radius: ";
			std::cin >> radius;
			std::cout << " " << std::endl;

			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Enter the radius: ";
				std::cin >> radius;
			}

			// Вычисления.
			Csquare = PI * radius * radius;
			Clength = 2 * PI * radius;

			switch (action) {
			case 1:
				std::cout << "Square = " << Csquare << std::endl;
				break;

			case 2:
				std::cout << "Circumference length = " << Clength << std::endl;
				break;

			default:
				std::cout << "ERROR : Wrong action!" << std::endl;
				break;
			}
			break;
		}

		case 2: { // Обработка квадрата.
			int action;
			double side;
			double Ssquare;
			double Sperimeter;

			std::cout << "SQUARE" << std::endl;
			std::cout << "1. Square" << std::endl;
			std::cout << "2. Perimeter" << std::endl;
			std::cout << "0. Back" << std::endl;
			std::cout << " " << std::endl;

			std::cout << "Choose an action: ";
			std::cin >> action;
			std::cout << " " << std::endl;

			// Обработка ошибок ввода действия.
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Choose an action: ";
				std::cin >> action;
			}

			// Возврат в главное меню.
			if (action == 0) {
				break;
			}

			if (action != 1 && action != 2) {
				std::cout << "ERROR: Wrong action!" << std::endl;
				break;
			}

			// Ввод стороны.
			std::cout << "Enter the side: ";
			std::cin >> side;
			std::cout << " " << std::endl;

			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Enter the side: ";
				std::cin >> side;
			}

			// Вычисления.
			Ssquare = side * side;
			Sperimeter = 4 * side;

			switch (action) {
			case 1:
				std::cout << "Square = " << Ssquare << std::endl;
				break;

			case 2:
				std::cout << "Perimeter = " << Sperimeter << std::endl;
				break;

			default:
				std::cout << "ERROR : Wrong action!" << std::endl;
				break;
			}
			break;
		}

		case 3: { // Обработка прямоугольника.
			int action;
			double length;
			double width;
			double Rsquare;
			double Rperimeter;

			std::cout << "RECTANGLE" << std::endl;
			std::cout << "1. Square" << std::endl;
			std::cout << "2. Perimeter" << std::endl;
			std::cout << "0. Back" << std::endl;
			std::cout << " " << std::endl;

			std::cout << "Choose an action: ";
			std::cin >> action;
			std::cout << " " << std::endl;

			// Обработка ошибок ввода действия.
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Choose an action: ";
				std::cin >> action;
			}

			// Возврат в главное меню.
			if (action == 0) {
				break;
			}

			if (action != 1 && action != 2) {
				std::cout << "ERROR: Wrong action!" << std::endl;
				break;
			}

			// Ввод длины.
			std::cout << "Enter the length: ";
			std::cin >> length;

			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Enter the length: ";
				std::cin >> length;
			}

			// Ввод ширины.
			std::cout << "Enter the width: ";
			std::cin >> width;
			std::cout << " " << std::endl;

			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Enter the width: ";
				std::cin >> width;
			}

			// Вычисления.
			Rsquare = length * width;
			Rperimeter = 2 * (length + width);

			switch (action) {
			case 1:
				std::cout << "Square = " << Rsquare << std::endl;
				break;

			case 2:
				std::cout << "Perimeter = " << Rperimeter << std::endl;
				break;

			default:
				std::cout << "ERROR : Wrong action!" << std::endl;
				break;
			}
			break;
		}

		case 4: { // Обработка треугольника.
			int action;

			std::cout << "TRIANGLE" << std::endl;
			std::cout << "1. Square" << std::endl;
			std::cout << "2. Perimeter" << std::endl;
			std::cout << "0. Back" << std::endl;
			std::cout << " " << std::endl;

			std::cout << "Choose an action: ";
			std::cin >> action;
			std::cout << " " << std::endl;

			// Обработка ошибок ввода действия.
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "ERROR: Wrong input!" << std::endl;
				std::cout << "Choose an action: ";
				std::cin >> action;
			}

			// Возврат в главное меню.
			if (action == 0) {
				break;
			}

			// Разные действия.
			switch (action) {
			case 1: { // Обработка площади треугольника.
				double base;
				double height;
				double Tsquare;

				// Ввод основания.
				std::cout << "Enter the base: ";
				std::cin >> base;

				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, '\n');

					std::cout << "ERROR: Wrong input!" << std::endl;
					std::cout << "Enter the base: ";
					std::cin >> base;
				}

				// Ввод высоты.
				std::cout << "Enter the height: ";
				std::cin >> height;
				std::cout << " " << std::endl;

				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, '\n');

					std::cout << "ERROR: Wrong input!" << std::endl;
					std::cout << "Enter the height: ";
					std::cin >> height;
				}

				// Вычисления.
				Tsquare = (base * height) / 2;

				std::cout << "Square = " << Tsquare << std::endl;

				break;
			}

			case 2: { // Обработка периметра треугольника.
				double sideA;
				double sideB;
				double sideC;
				double Tperimeter;

				// Ввод первой стороны.
				std::cout << "Enter the side A: ";
				std::cin >> sideA;

				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, '\n');

					std::cout << "ERROR: Wrong input!" << std::endl;
					std::cout << "Enter the side A: ";
					std::cin >> sideA;
				}

				// Ввод второй стороны.
				std::cout << "Enter the side B: ";
				std::cin >> sideB;

				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, '\n');

					std::cout << "ERROR: Wrong input!" << std::endl;
					std::cout << "Enter the side B: ";
					std::cin >> sideB;
				}

				// Ввод третьей стороны.
				std::cout << "Enter the side C: ";
				std::cin >> sideC;
				std::cout << " " << std::endl;

				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, '\n');

					std::cout << "ERROR: Wrong input!" << std::endl;
					std::cout << "Enter the side C: ";
					std::cin >> sideC;
				}

				// Вычисления.
				Tperimeter = sideA + sideB + sideC;

				std::cout << "Perimeter = " << Tperimeter << std::endl;

				break;
			}

			default:
				std::cout << "ERROR : Wrong action!" << std::endl;
				break;
			}

			break;
		}

		case 0: // Выход из программы.
			std::cout << "Program finished." << std::endl;
			return 0;

		default:
			std::cout << "ERROR: There is no such figure!" << std::endl;
			break;
		}

		std::cout << "-----------------------------------------" << std::endl;

	}
	
	return 0; // Завершаем программу успешно.
}