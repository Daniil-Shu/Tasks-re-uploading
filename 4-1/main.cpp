#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <sstream>


using namespace std;

/**
*\brief Нахождение минимального по значению элемента
*\param array Массив
*\param size Размер массива
**/
size_t FindMin(const int* array, const size_t size);

/**
*\brief Нахождение среднего арифметического среди элементов массива
*\param array Массив
*\param size Размер массива
**/
int FindAverage(const int* array, const size_t size);

/**
*\brief Замена минимального элемента массива на среднее арифметическое
*\param array Массив
*\param size Размер массива
**/
void  ReplaceMinToAverage(int* array, const size_t size);

/**
*\brief Вывод индексов элементов, значение которых больше предыдущих
*\param array Массив
*\param size Размер массива
**/
void ShowIndexes(int* array, const size_t size);
/**
*\brief Проверка на существование двух пар элементов с одинаковыми знаками
*\param array Массив
*\param size Размер массива
**/
bool ElementExist(int* array, const size_t size);

/**
* \brief Выбор заполнеия массива
**/
enum class FillType
{
    randomize = 1,
    manual = 2
};

/**
* \brief Заполнение массива случайными числами
* \array Массив
* \size Размер массива
* \param min Минимально возможное число
* \param max Максимально возможное число
**/
void randomizeArray(int* array, const size_t size, const int min, const int max);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void manualInput(int* array, const size_t size);

/**
* \brief Конвертация массива строку вида {element_1, element_2, ... ,element_n}
* \param array Массив
* \param size Размер массива
* \param message Сообщение, которое будет выведено перед массивом
**/
string arrayToString(int* array, const size_t size, const string& message);

int main() {



    const int min = -20, max = 40;

    cout << "Введите размер массива\n";
    size_t size;
    cin >> size;
    int* array = new int[size];

    cout << "Выберите способ заполнения массива:\n" << "Случайные элементы - 1\n" << "Ручной ввод - 2\n";

    int choice;
    cin >> choice;

    const auto fillType = static_cast<FillType>(choice);

    switch (fillType)
    {
    case FillType::randomize:
    {
        randomizeArray(array, size, min, max);
        cout << arrayToString(array, size, "Ваш массив = ") << "\n";
        break;
    }
    case FillType::manual:
    {
        manualInput(array, size);
        cout << arrayToString(array, size, "Ваш массив = ") << "\n";
        break;
    }
    default:
        break;
    }

    cout << "Индексы элементов, значения которых больше предыдущих\n";

    ShowIndexes(array, size);

    if (ElementExist(array, size))
        cout << "Существует ";
    else
        cout << "Не существует ";
    cout << "две пары соседних элементов с одинаковыми знаками\n";

    ReplaceMinToAverage(array, size);
    cout << arrayToString(array, size, "Измененный массив = ") << '\n';

    delete[] array;
}

void randomizeArray(int* array, const size_t size, const int min, const int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    const uniform_int_distribution<> uniformIntDistribution(min, max);

    for (size_t i = 0; i < size; ++i)
    array[i] = uniformintdistribution(gen);

}

void manualInput(int* array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }
}

string arrayToString(int* array, const size_t size, const string& message = "")
{
    std::stringstream buffer;
    buffer << message << "{" << array[0];

    for (size_t i = 1; i < size; ++i)
    {
        buffer << ", " << array[i];
    }

    buffer << "}";

    return buffer.str();
}

size_t FindMin(int* array, size_t size) {
    size_t minIndex = 0;

    for (size_t i = 1; i < size; i++)
    {
        if (array[minIndex] > array[i])
            minIndex = i;
    }

    return minIndex;
}

int FindAverage(int* array, size_t size) {
    int average = 0;
    for (size_t i = 1; i < size; i++) {
        average += array[i];
    }
    return average / size;
}

void  ReplaceMinToAverage(int* array, size_t size)
{
    array[FindMin(array, size)] = FindAverage(array, size);
}

void ShowIndexes(int* array, size_t size) {
    if (size <= 2)
        return;

    for (size_t i = 1; i < size - 1; i++)
        if (array[i] < array[i + 1])
            cout << "index = " << i + 1 << '\n';

}

bool ElementExist(int* array, size_t size) {
    int k = 0;

    for (size_t i = 0; i < size; i++)
        if (array[i] * array[i + 1] > 0)
            k++;
    return k >= 2;
}
