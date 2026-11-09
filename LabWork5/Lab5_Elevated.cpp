#include <iostream> // Ввод/вывод: cin, cout.
#include <iomanip>  // Форматирование: setw, fixed, setprecision.
#include <cmath>    // Библиотечная функция cos() и fabs().
#include <limits>   // limits - для очистки буфера ввода (numeric_limits).

using namespace std; // Стандартное пространство имён.

// --- Функция вычисления cos(x) через ряд Тейлора ---
// cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
// РЕКУРРЕНТНАЯ ФОРМУЛА: каждый следующий член получаем
// из предыдущего умножением, без вычисления степеней и факториалов.
// Суммируем, пока |очередной член| > eps: как только член стал меньше
// точности, дальнейшие слагаемые уже не влияют на нужные нам разряды.
double cosTaylor(double x, double eps)
{
	double sum = 1.0; // Нулевой член ряда (n = 0): cos(0)-часть равна 1.
	double term = 1.0; // Текущий член ряда; T(0) = 1.
	int    n = 0;   // Номер текущего члена.

	while (fabs(term) > eps) { // Проверка ДО добавления: член уже мал - не добавляем.
		// Рекуррентная формула: T(n+1) = -T(n) * x^2 / ((2n+1)(2n+2)).
		// Знак "минус" обеспечивает чередование членов ряда (+, -, +, - ...).
		// Все константы записаны как double (2.0), чтобы избежать целочисленного деления.
		term = -term * x * x / ((2.0 * n + 1.0) * (2.0 * n + 2.0));
		sum += term; // Накапливаем сумму (аккумулятор).
		n++;
	}
	return sum;
}

int main() // Главная функция — точка входа в программу.
{
	const int WIDTH = 12; // Константа - ширина столбца таблицы.
	const double EPS = 1e-9; // Константа - допуск на погрешность типа double.
	const double TAYLOR_EPS = 1e-6; // Точность суммы ряда Тейлора (по заданию).

	double a; // Переменная для хранения a - начало интервала.
	double b; // Переменная для хранения b - конца интервала.
	double h; // Переменная для хранения h - шаг.

	cout << "Tabulating the function y = cos(x)" << endl;

	// Каждый ввод оформлен циклом do-while: тело выполняется минимум один раз
	// (пользователь должен увидеть приглашение в любом случае), а повтор
	// происходит, пока данные не будут введены корректно.
	// Это канонический сценарий для do-while: «ввод с проверкой после».
	do {
		cout << "Enter the beginning of the interval a: ";
		cin >> a;
		if (cin.fail()) { // Проверяем, что введено число, а не буквы.
			cin.clear(); // Сбрасываем флаг ошибки потока, иначе все последующие чтения провалятся.
			// Очищаем буфер.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR: incorrect input! Try again." << endl;
			continue; // Начинаем do-while заново - повторный запрос ввода.
		}
		break; // Число прочитано успешно - выходим из цикла ввода.
	} while (true);

	do {
		cout << "Enter the end of interval b: ";
		cin >> b;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR: incorrect input! Try again." << endl;
			continue;
		}
		break;
	} while (true);

	do {
		cout << "Enter step h: ";
		cin >> h;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR: incorrect input! Try again." << endl;
			continue;
		}
		break;
	} while (true);

	// Проверка корректности ввода.
	if (a > b) // Начало не должно быть больше конца, иначе цикл не выполнится ни разу.
	{
		cout << "ERROR: the beginning of the interval cannot be greater than the end!" << endl;
		return 1;
	}
	if (h <= 0) // Шаг должен быть положительным.
	{
		cout << "ERROR: the step must be positive!" << endl;
		return 1;
	}

	// Шапка таблицы: четыре столбца - аргумент, библиотечная функция, ряд, погрешность.	
	cout << "\n+------------+------------+------------+------------+" << endl;
	cout << "|     x      |   cos(x)   |  Taylor    |   error    |" << endl;
	cout << "+------------+------------+------------+------------+" << endl;

	// Форматирование вывода: 6 знаков после запятой.
	cout << fixed << setprecision(6);

	// Цикл табуляции.
	// Цикл for выбран, потому что число итераций известно заранее.
	// Условие x <= b + EPS, а не x <= b: при накоплении x += h значения
	// double могут «дрожать» у границы, и последняя точка выпадала бы из таблицы.
	// Внутри цикла НЕТ лишних вычислений: всё, что не зависит от x
	// (константы точности), вынесено за его пределы.

	for (double x = a; x <= b + EPS; x += h) {
		double yLib = cos(x); // Эталон - библиотечная функция.
		double yTaylor = cosTaylor(x, TAYLOR_EPS); // Сумма ряда Тейлора.
		double error = fabs(yLib - yTaylor); // Абсолютная погрешность.

		// Вывод строки таблицы: setw(WIDTH) выравнивает все четыре столбца.
		cout << "|" << setw(WIDTH) << x
			<< "|" << setw(WIDTH) << yLib
			<< "|" << setw(WIDTH) << yTaylor
			<< "|" << setw(WIDTH) << error << "|" << endl;
	}

	// Нижняя граница таблицы.
	cout << "+------------+------------+------------+------------+" << endl;

	// Итоговое пояснение о точности суммы ряда.
	cout << "\nNote: Taylor series summed with eps = " << TAYLOR_EPS
		<< " (recurrent formula, no pow/factorial used)." << endl;

	return 0; // Успешное завершение программы.
}