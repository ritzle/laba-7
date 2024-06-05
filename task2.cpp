#include <iostream>
#include <vector>

using namespace std;

// Рекурсивная функция, которая пытается найти k-ю комбинацию чисел
bool recurs(int &check, vector<int> &nomer, const int &k, string &result)
{
    // Если все числа использованы, увеличиваем счетчик найденных комбинаций
    if (nomer.empty())
    {
        check++;
        // Если найдено k комбинаций, возвращаем true
        if (check == k)
        {
            return true;
        }
        // Иначе возвращаем false, так как комбинация не является k-й
        return false;
    }
    // Для каждого числа в векторе
    for (size_t i = 0; i < nomer.size(); i++)
    {
        // Создаем новый вектор, копируя текущий, но без текущего элемента
        vector<int> newNomer(nomer);
        int currentNumber = newNomer[i];
        newNomer.erase(newNomer.begin() + i);

        // Рекурсивно ищем k-ю комбинацию
        if (recurs(check, newNomer, k, result))
        {
            // Если нашли, добавляем текущее число к результату
            char k = currentNumber + '0';
            result.push_back(k);
            return true;
        }
    }
    // Если не удалось найти k-ю комбинацию, возвращаем false
    return false;
}

int main()
{
    int n;         // Количество чисел для комбинаций
    int k;         // Номер комбинации, которую нужно найти
    int check = 0; // Счетчик найденных комбинаций

    string result; // Строка для хранения результата

    cin >> n; // Ввод количества чисел
    cin >> k; // Ввод номера комбинации

    vector<int> nomer; // Вектор для хранения чисел
    for (int i = 1; i <= n; i++)
    {
        nomer.push_back(i); // Заполнение вектора числами от 1 до n
    }

    // Запуск рекурсивной функции для поиска k-й комбинации
    recurs(check, nomer, k, result);

    // Вывод результата в обратном порядке
    for (int i = n - 1; i >= 0; i--)
    {
        cout << result[i];
    }
}
