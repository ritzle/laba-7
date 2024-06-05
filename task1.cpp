// тестовое число 3852
#include <iostream>
#include <vector>

using namespace std;

// Рекурсивная функция, которая пытается найти последовательность операций, чтобы получить s
bool recurs(int a, vector<int> &chisla, const int &s)
{
    // Если вектор чисел пуст, проверяем, равно ли текущее значение s
    if (chisla.empty())
    {
        return a == s;
    }
    // Для каждого числа в векторе
    for (size_t i = 0; i < chisla.size(); i++)
    {
        // Создаем новый вектор, копируя текущий, но без текущего элемента
        vector<int> newChisla(chisla);
        int currentNumber = newChisla[i];
        newChisla.erase(newChisla.begin() + i);

        // Пробуем добавить текущее число к текущему результату и рекурсивно проверяем
        if (recurs(a + currentNumber, newChisla, s))
        {
            cout << currentNumber << " + ";
            return true;
        }
        // Пробуем умножить текущее число на текущий результат и рекурсивно проверяем
        if (recurs(a * currentNumber, newChisla, s))
        {
            cout << currentNumber << " * ";
            return true;
        }
    }
    // Если не удалось найти последовательность операций, возвращаем false
    return false;
}

// Функция, которая запускает процесс с каждым числом из вектора
bool start(vector<int> chisla, const int &s)
{
    // Для каждого числа в векторе
    for (size_t i = 0; i < chisla.size(); i++)
    {
        // Создаем новый вектор, копируя текущий, но без текущего элемента
        vector<int> newChisla(chisla);
        int currentNumber = newChisla[i];
        newChisla.erase(newChisla.begin() + i);

        // Запускаем рекурсивную функцию с текущим числом
        if (recurs(currentNumber, newChisla, s))
        {
            cout << currentNumber;
            cout << endl;
            return true;
        }
    }
    // Если не удалось найти последовательность операций, возвращаем false
    return false;
}

int main()
{
    int s;
    int n = 4;

    vector<int> chisla = {89, 65, 86, 43};

    cin >> s;

    cout << endl
         << start(chisla, s);
}