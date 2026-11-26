#include <iostream>   // Подключаем библиотеку для ввода/вывода.
#include <iomanip>   // Подключаем библиотеку для управления форматированием ввода/вывода.
#include <cstdlib>
#include <ctime>

using namespace std;    // Подключаем стандартное пространство имён.

int main()   // Объявляем главную функцию.
{
	const int N = 5;   // Размер квадратной матрицы (N×N).
	int matrix[N][N];   // Объявление матрицы.

	// Инициализация генератора случайных чисел.
	srand(static_cast<unsigned>(time(nullptr)));
	// Заполнение матрицы случайными числами от 1 до 100.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = 1 + rand() % 100 + 1;
		}
	}

	// Поиск минимального и максимального элементов.
	int MinVal = matrix[0][0];
	int MaxVal = matrix[0][0];
	int MinRow = 0, MinCol = 0;
	int MaxRow = 0, MaxCol = 0;

	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] < MinVal) {
				MinVal = matrix[i][j];
				MinRow = i;
				MinCol = j;
			}
			if (matrix[i][j] > MaxVal) {
				MaxVal = matrix[i][j];
				MaxRow = i;
				MaxCol = j;
			}
		}
	}

	// Вывод матрицы в виде таблицы.
	cout << "\nThe entered matrix: " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;   //  Переход на новую строку после каждой строки матрицы.
	}

	// Вывод результатов.
	cout << "\nMinimum element: " << MinVal << " (line " << MinRow << ", column " << MinCol << ")\n";
	cout << "\nMaximum element: " << MaxVal << " (line " << MaxRow << ", column " << MaxCol << ")\n";

	return 0;   // Завершаем программу успешно.
}
