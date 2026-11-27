#include <iostream> // Библиотека для ввода и вывода.

using namespace std; // Подключаем стандартное пространство имён.

// Функция вычисляет среднее арифметическое массива.
double arrayAverage(const int arr[], int size) {
	// Проверяем, что массив не пустой.
	if (size <= 0) {
		return 0;
	}

	// Суммируем все элементы массива.
	int summ = 0;
	for (int i = 0; i < size; i++) {
		summ += arr[i];
	}

	// Делим сумму на количество элементов.
	return static_cast<double>(summ) / size;
}

int main() // Объявляем главную функцию.
{
	int size;

	// Ввод данных.
	cout << "Enter the number of array elements: ";
	cin >> size;

	// Проверка размера массива.
	if (size <= 0 || size > 100) {
		cout << "Error! The size of the array should be from 1 to 100.";
		return 1;
	}

	int arr[100];

	// Заполнение массива.
	for (int i = 0; i < size; i++) {
		cout << "Enter the element " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Вывод массива.
	cout << "\nArray: ";
	for (int i = 0; i < size;i++) {
		cout << arr[i] << " ";
	}

	// Вызов функции вычисления среднего.
	double result = arrayAverage(arr, size);

	// Вывод результата.
	cout << "\nArithmetic mean: " << result << endl;

	return 0; //Успешное завершение программы.
}