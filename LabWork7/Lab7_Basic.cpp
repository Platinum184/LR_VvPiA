#include <iostream>   // Подключаем библиотеку для ввода/вывода.
#include <iomanip>   // Подключаем библиотеку для управления форматированием ввода/вывода.

using namespace std;    // Подключаем стандартное пространство имён.

int main()   // Объявляем главную функцию.
{
	const int N = 3;   // Размер квадратной матрицы (N×N).
	int matrix[N][N];   // Объявление матрицы.

	// Заполнение матрицы с клавиатуры.
	cout << "Enter the matrix elements " << N << "x" << N << ":" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
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

	// Сумма главной диагонали.
	int sumMain = 0;
	for (int i = 0; i < N; i++) {
		sumMain += matrix[i][i];
	}
	
	// Вывод суммы главной диагонали.
	cout << "The sum of the main diagonal: " << sumMain << endl;

	return 0;   // Завершаем программу успешно.
}