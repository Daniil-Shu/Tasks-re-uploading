#include <iostream>

using namespace std;

/**
* \brief Пользовательский выбор вывода или месяца (0),
* или дня недели (1)
*/
enum class mainChoice { month, day };

/**
* \brief Пользовательский выбор вывода названия месяца (значения от 1 до 12)
*/
enum class months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

/**
* \brief Пользовательский выбор вывода названия дня недели (значения от 1 до 7)
*/
enum class days { Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun };

/**
* \brief Точка входа в программу.
* \return Код ошибки (0 - успех).
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Что вы хотите узнать: месяц (0) или день недели (1)" << "\n";
    int type;
    cin >> type;

    const auto choice = static_cast<mainChoice>(type);
    switch (choice)
    {
    case mainChoice::month:
    {
        cout << "Введите номер месяца" << "\n";
        int month;
        cin >> month;

        const auto monthChoice = static_cast<months>(month);

        switch (monthChoice)
        {
        case months::Jan:
        {
            cout << "Январь";
            break;
        }
        case months::Feb:
        {
            cout << "Февраль";
            break;
        }
        case months::Mar:
        {
            cout << "Март";
            break;
        }
        case months::Apr:
        {
            cout << "Апрель";
            break;
        }
        case months::May:
        {
            cout << "Май";
            break;
        }
        case months::Jun:
        {
            cout << "Июнь";
            break;
        }
        case months::Jul:
        {
            cout << "Июль";
            break;
        }
        case months::Aug:
        {
            cout << "Август";
            break;
        }
        case months::Sep:
        {
            cout << "Сентябрь";
        }
        case months::Oct:
        {
            cout << "Октябрь";
            break;
        }
        case months::Nov:
        {
            cout << "Ноябрь";
            break;
        }
        case months::Dec:
        {
            cout << "Декабрь";
            break;
        }
        }
        break;
    }
    case mainChoice::day:
    {
        cout << "Введите номер дня" << "\n";
        int day;
        cin >> day;

        const auto dayChoice = static_cast<days>(day);

        switch (dayChoice)
        {
        case days::Mon:
        {
            cout << "Понедельник";
            break;
        }
        case days::Tue:
        {
            cout << "Вторник";
            break;
        }
        case days::Wed:
        {
            cout << "Среда";
            break;
        }
        case days::Thu:
        {
            cout << "Четверг";
            break;
        }
        case days::Fri:
        {
            cout << "Пятница";
            break;
        }
        case days::Sat:
        {
            cout << "Суббота";
            break;
        }
        case days::Sun:
        {
            cout << "Воскресенье";
            break;
        }
        }
        break;
    }
    }
    cout << endl;
    return 0;
}
