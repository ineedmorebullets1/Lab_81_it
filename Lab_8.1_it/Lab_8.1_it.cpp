#include <iostream>
#include <cstring>
using namespace std;

// Перевірка: чи є пара символів "SQ" або "QS"
bool IsPair(char a, char b)
{
    return (a == 'S' && b == 'Q') || (a == 'Q' && b == 'S');
}

int Count(char* str)
{
    if (strlen(str) < 2)
        return 0;

    int k = 0; // лічильник знайдених пар "SQ" або "QS"

    for (int i = 0; str[i] != 0 && str[i + 1] != 0; i++)
        if (IsPair(str[i], str[i + 1]))
        {
            k++;  // пара знайдена - збільшуємо лічильник
            i++;  // пропускаємо другий символ пари (пари не перекриваються)
        }
    return k;
}

// Заміна кожної пари "SQ" або "QS" на "***".
char* Change(char* str)
{
    size_t len = strlen(str);

    char* tmp = new char[len * 3 / 2 + 1];
    char* t = tmp;

    size_t i = 0;

    while (i + 1 < len)
    {
        if (IsPair(str[i], str[i + 1]))
        {
            *t++ = '*';
            *t++ = '*';
            *t++ = '*';
            i += 2;
        }
        else
            *t++ = str[i++];
    }

    while (i < len)
        *t++ = str[i++];
    *t = '\0';

    size_t j = 0;
    while (tmp[j] != '\0')
    {
        str[j] = tmp[j];
        j++;
    }
    str[j] = '\0';

    return tmp;
}

int main()
{
    char str[151]; // запас, бо після заміни рядок може стати довшим

    cout << "Enter string:" << endl;
    cin.getline(str, 101);
    cout << "String contained " << Count(str) << " pairs of 'SQ' or 'QS'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // звільняємо пам'ять

    return 0;
}