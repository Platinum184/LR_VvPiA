#include <iostream> // Библиотека для ввода и вывода.

using namespace std; // Подключаем стандартное пространство имён.
 
// Функция вычисляет сумму элементов массива и количество элементов.
// const int arr[] - массив передается для чтения, его элементы нельзя изменять.
// int& sum - ссылка для возврата суммы.
// int& count - ссылка для возврата количества элементов.
void sumAndCount(const int arr[], int size, int& sum, int& count) {

	// Проверяем корректность размера массива.
	if (size <= 0) {
		sum = 0;
		count = 0;
		return;
	}

	// Начальные значения.
	sum = 0;
	count = 0;

	// Перебираем все элементы массива.
	for (int i = 0; i < size; i++) {
		// Добавляем текущий элемент к сумме.
		sum += arr[i];
		// Увеличиваем количество элементов.
		count++;
	}
}

// Главная функция программы.
int main() 
{
	int size;

	// Ввод размера массива.
	cout << "Enter the number of array elements: ";
	cin >> size;

	// Проверяем размер массива.
	if (size <= 0 || size > 100) {
		cout << "Error! The size of the array should be from 1 to 100.";
		return 1;
	}

	int arr[100];

	// Заполнение массива.
	cout << "Enter the array elements: " << endl;

	for (int i = 0;i < size;i++) {
		cin >> arr[i];
	}

	// Переменные для получения результатов.
	int sum = 0;
	int count = 0;

	// Передаем массив и переменные в функцию.
	sumAndCount(arr, size, sum, count);

	// Выводим результаты.
	cout << "The sum of the elements: " << sum << endl;
	cout << "Number of elements: " << count << endl;

	return 0; // Успешное завершение программы.
}