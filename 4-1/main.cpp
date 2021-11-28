#include <iostream>
#include <random>
using namespace std;

/*
* \brief - заполнение массива пользователем
* \param arr массив
* \param size размер массива
*/
void userInput(int* arr, const size_t size);

/*
* \brief заполнение массива случайными числами
* \param arr массив
* \param size размер массива
*/
void randomDigits(int* arr, const size_t size);

/*
* \brief вывод массива
* \param arr массив
* \param size размер массива
*/
void output(const int* arr, const size_t size, const string& message);
/*
* \brief нахождение минимального элемента массива
* \param arr массив
* \param size размер массива
* \return минимальный элемент массива
*/
int findMin(int* arr, const size_t size);

/*
* \brief - замена среднего элемента массива на минимальный
* \param arr массив
* \param size размер массива
* \param min минимальный элемент массива
*/
void replacingTheMinimumElementWithTheMiddleOne(int* arr, const size_t size, const int min);

/*
* \brief вывод на экран индексов элементов больших чем предыдущий элемент
* \param arr массив
* \param size размер массива
*/
void showIndexes(int* array, const size_t size);

/*
* \brief Проверка на существование двух пар элементов с одинаковыми знаками
* \param array Массив
* \param size Размер массива
* \return true если пара существует
*/
bool elementExist(int* array, const size_t size);

/*
* \brief Выбор заполнеия массива
*/
enum class path
{
	Manuall,
	Random
};

/*
* \brief Точка входа в программу
* \return Код ошибки(0 - успех)
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество элементов массива - ";
	size_t size;
	cin >> size;
	int* arr = new int[size];

	cout << "Как хотите заполнить массив?\n"
		<< static_cast<int>(path::Manuall) << " - заполнение массива с клавиатуры,\n"
		<< static_cast<int>(path::Random) << " - заполнение массива случайными числами.\n"
		<< "Ваш выбор: ";
	int choice;
	cin >> choice;
	const auto chosen = static_cast<path>(choice);
	switch (chosen) 
	{
	  case path::Random:
	  {
		randomDigits(arr, size);
		break;
	  }
	  case path::Manuall:
	  {
		userInput(arr, size);
		break;
	  }
	  default:
	  {
		cout << "Некоректный ввод.";
		return 0;
	  }
	}

	output(arr, size, "Ваш массив: ");

	int min = findMin(arr, size);
	cout << "\nМинимальный элемент массива = " << min << "\n";

	if (size % 2 != 0)
	{
		replacingTheMinimumElementWithTheMiddleOne(arr, size, min);
		output(arr, size, "Массив после замены среднего элемента на минимальный:");
	}
	else
	{
		cout << "Массив содержит четное число элементов.\n";
		output(arr, size, "Ваш массив: ");
	}

	cout << "\nИндексы элементов, значение которых больше предыдущего: \n";
	showIndexes(arr, size);

	if (elementExist(arr, size))
		cout << "Существуют пары с одинаковыми знаками";
	else
		cout << "Не существуют пары с одинаковыми знаками";

	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
	return (0);
}

void randomDigits(int* arr, const size_t size)
{
	const int UP_BOUND = 40;
	const int LOW_BOUND = -20;
	std::random_device rd;
	std::mt19937 gen(rd());

	const std::uniform_int_distribution<> uniformIntDistribution(LOW_BOUND, UP_BOUND);

	for (size_t index = 0; index < size; index++)
		arr[index] = uniformIntDistribution(gen);
}

void userInput(int* arr, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> arr[i];
	}
}

void output(const int* arr, const size_t size, const string& message)
{
	cout << message;
	size_t counter = 0;
	cout << "[ ";
	while (counter < size)
		cout << arr[counter++] << " ";
	cout << "]";
}

int findMin(int* arr, const size_t size)
{
	int min = 2147483647;
	for (size_t i = 0; i < size; i++)
		if (arr[i] < min)
			min = arr[i];
	return (min);
}

void replacingTheMinimumElementWithTheMiddleOne(int* arr, const size_t size, const int min)
{
	arr[size / 2] = min;
}

void showIndexes(int* array, const size_t size)
{
	if (size <= 2)
		return;

	for (size_t i = 1; i < size - 1; i++)
		if (array[i] < array[i + 1])
			cout << "индекс = " << i + 1 << '\n';

}

bool elementExist(int* array, size_t size)
{
	int k = 0;

	for (size_t i = 0; i < size; i++)
		if (array[i] * array[i + 1] > 0)
			k++;
	return k >= 2;
}