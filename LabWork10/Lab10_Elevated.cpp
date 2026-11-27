#include <iostream> // Библиотека для ввода и вывода.
#include <stdexcept> #include <stdexcept> // Подключаем библиотеку для обработки стандартных исключений.

using namespace std; // Подключаем стандартное пространство имён.

// Функция обмена двух элементов.
// Оба параметра передаются по ссылке, поэтому изменяются исходные элементы массива.
void swapValues(int& a, int& b) {
	int temp = a; // Сохраняем первое значение.
	a = b; // Переносим второе значение в первое.
	b = temp; // Записываем сохраненное значение во второе.
}

// Функция сортировки массива пузырьком.
// Ссылка позволяет обменивать исходные элементы.
// const int& comparisons - ссылка только для чтения здесь не подходит, поэтому счетчик сравнений передаем по обычной ссылке.
void bubbleSort(int arr[], int size, int& comparisons, int& swaps) {

	comparisons = 0;
	swaps = 0;

	// Внешний цикл отвечает за количество проходов.
	for (int i = 0; i < size - 1; i++) {
        
        // Флаг показывает, были ли обмены.
        bool changed = false;

        // Сравниваем соседние элементы.
        for (int j = 0; j < size - i - 1; j++) {

            comparisons++;

            // Если элементы расположены неправильно, меняем их местами
            if (arr[j] > arr[j + 1]) {

                swapValues(arr[j], arr[j + 1]);

                swaps++;
                changed = true;
            }
        }

        // Если обменов не было, массив уже отсортирован.
        if (!changed) {
            break;
        }
	}
}

// Передача по значению.
// Функция получает копию числа.
// Изменение копии не влияет на оригинал.
void changeByValue(int x) {
    x = 100;
}

// Передача по указателю.
// Через указатель можно изменить исходную переменную.
void changeByPointer(int* x) {
    if (x != nullptr) {
        *x = 100;
    }
}

// Передача по ссылке.
// Изменяется исходная переменная.
void changeByReference(int& x) {
    x = 100;
}

// Функция возвращает константную ссылку.
// Она позволяет читать элемент без копирования и не позволяет изменить его через эту ссылку.
const int& getReadOnlyElement(const int& element) {
    return element;
}

// Функция возвращает ссылку на элемент массива.
// errorCode используется для сообщения об ошибке.
// Ссылка возвращается только на существующий элемент массива.
int& getElement(int arr[], int size, int index, int& errorCode) {

    if (index < 0 || index >= size) {
        errorCode = 1;
        throw out_of_range("The index goes beyond the boundaries of the array!");
    }

    errorCode = 0;
    return arr[index];
}

// Вывод массива.
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Главная функция программы.
int main() {

    int size;

    cout << "Enter the size of the array (from 1 to 100): ";
    cin >> size;

    // Проверяем корректность размера.
    if (!cin || size < 1 || size > 100) {
        cout << "Array size error!" << endl;
        return 1;
    }

    int arr[100];

    // Ввод элементов массива.
    cout << "Enter the array elements: " << endl;

    for (int i = 0; i < size; i++) {
        cin >> arr[i];

        if (!cin) {
            cout << "Element input error!" << endl;
            return 1;
        }
    }

    cout << "\nThe original array: ";
    printArray(arr, size);

    // Сортировка массива.
    int comparisons = 0;
    int swaps = 0;

    bubbleSort(arr, size, comparisons, swaps);

    cout << "\nSorted array: ";
    printArray(arr, size);

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of exchanges: " << swaps << endl;

    // Демонстрация трех способов передачи параметров.
    cout << "\n=== Methods of transmitting parameters ===" << endl;

    int a = 5;

    changeByValue(a);
    cout << "After passing by value: " << a << endl;

    changeByPointer(&a);
    cout << "After passing by pointer: " << a << endl;

    a = 5;

    changeByReference(a);
    cout << "After the transfer via the link: " << a << endl;

    // Демонстрация const-ссылки.
    const int& readOnly = getReadOnlyElement(arr[0]);

    cout << "\nThe first element is via a const-link: "
        << readOnly << endl;

    // Демонстрация возврата ссылки на элемент массива.
    int errorCode = 0;

    try {
        getElement(arr, size, 0, errorCode) = 50;

        cout << "After changing the first element: ";
        printArray(arr, size);
    }
    catch (const out_of_range& error) {
        cout << "Error: " << error.what() << endl;
    }

    // Выводим результаты.
    cout << "Error code: " << errorCode << endl;

    return 0; // Успешное завершение программы.
}