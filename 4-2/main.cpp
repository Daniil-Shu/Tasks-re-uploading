#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <sstream>

using namespace std;

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
/**
*\brief Нахождение элемента, значение которого минимально по модулю
*\param array Массив
*\param size Размер массива
**/
int FindAbsMin(int* array, const size_t size);
/**
*\brief Замена минимального по модулю элемента последним элементом массива
*\param array Массив
*\param size Размер массива
**/
void ReplaceMinToLast(int* array, const size_t size);
/**
*\brief Проверка элемента массива на выполнение условия
*\param number Элемент массива
**/
bool check(const int number);
/**
*\brief Вычисление размера нового массива
*\param array Массив
*\param size Размер массива
**/
size_t getNewSize(int* array, const size_t size);
/**
*\brief Массив с удаленными элементами
*\param oldArray Старый массив
*\param size Размер старого массива
*\param newSize Размер нового массива
**/
int* deleteElements(int* oldArray, const size_t size, const size_t newSize);
/**
*\brief Определение четности индекса элемента
*\param number индекс элемента
**/
bool isEven(const int number);
/**
*\brief Создание нового массива
*\param array Массив
*\param size Размер массива
**/
int* NewArray(int* array, const size_t size);

/**
* \brief Выбор способа заполнеия массива
**/
enum class FillType
{
    randomize = 1,
    manual = 2
};

int main() {
    setlocale(LC_ALL, "Russian");

    const int min = -20, max = 40;

    cout << "Введите количество элементов в массиве: ";
    size_t size;
    cin >> size;

    int* array = new int[size];
    int* newarray = new int[size];

    cout << "Выберите способ заполнения массива:\n" << "1) Случайные числа\n" << "2) Ручной ввод\n";
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
    FindAbsMin(array, size);
    ReplaceMinToLast(array, size);
    cout << arrayToString(array, size, "Массив с замененным элементом = ") << "\n";

    size_t newSize = getNewSize(array, size);
    int* array2 = deleteElements(array, size, newSize);
    cout << arrayToString(array2, newSize, "Измененный массив = ") << "\n";
    int* array3 = NewArray(array, size);
    cout << arrayToString(array3, size, "Сформированный массив = ") << "\n";
}

void randomizeArray(int* array, const size_t size, const int min, const int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    const uniform_int_distribution<> uniformIntDistribution(min, max);

    for (size_t i = 0; i < size; ++i)
        array[i] = uniformIntDistribution(gen);

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


int FindAbsMin(int* array, const size_t size) {
    int minIndex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (abs(array[minIndex]) > abs(array[i]))
            minIndex = i;
    }
    return minIndex;
}

void ReplaceMinToLast(int* array, const size_t size) {
    array[FindAbsMin(array, size)] = array[size - 1];
}

bool check(int number)
{
    return number % 2 != 0 && number % 3 == 0;
}

size_t getNewSize(int* array, size_t size)
{
    size_t newSize = size;

    for (size_t i = 0; i < size; i++)
        if (check(array[i]))
            newSize--;

    return newSize;
}

int* deleteElements(int* oldArray, size_t size, size_t newSize)
{
    size_t offset = 0;
    int* newArray = new int[newSize];

    for (size_t i = 0; i < size; i++)
    {
        if (check(oldArray[i]))
            offset++;
        else
            newArray[i - offset] = oldArray[i];
    }

    return newArray;
}

bool isEven(const int number)
{
    return number % 2 == 0;
}

int* NewArray(int* array, const size_t size)
{
    int* newArray = new int[size];

    for (size_t i = 0; i < size; i++)
        if (isEven(i))
            newArray[i] = array[i] + i;
        else
            newArray[i] = array[i] - i;

    return newArray;
}
