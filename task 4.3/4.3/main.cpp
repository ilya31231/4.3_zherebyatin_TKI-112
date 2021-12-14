#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <random> 

using namespace std;

void zapolnrandom(int* array3, int* array4, const int width, const int lengths);
void zapolnvod(int* array3, int* array4, const int width, const int lengths);
void zamena(int* array3, const int width, const int lengths);
void punkt(int* array4, const int width, const int lengths);

int main()
{
    int punkt1;
    cout << "Если нужно заполненить массив случайными числами, введи 1 " << endl << "Если надo заполнить массив вводом с клавиатуры, введи 2" << endl;
    cin >> punkt1;
    cout << "Елси нужен 2-й пункт, то введи 2" << endl;
    int punkt2;
    cin >> punkt2;
    size_t width, lengths;
    cout << "Введите ширину массива" << endl;
    cin >> width; //Вводится размеры массива m
    cout << "Введите длинну массива" << endl;
    cin >> lengths; //Вводится размеры массива n

    int* array3 = new int[width * lengths];
    int* array4 = new int[width * lengths];


    if (punkt1 == 1)
    {
        zapolnrandom(array3, array4, width, lengths); //вызываем 1-ю функцию
    }
    else
    {
        cout << "Заполните массив вводом с клавиатуры" << endl;
        zapolnvod(array3, array4, width, lengths); //вызываем 2-ю функцию
    }

    cout << "Вот ваш массив" << endl;
    int f = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
        {
            cout << array3[f] << "  ";
            f++;
        }
        cout << endl;

    }

    cout << "После выполнения пункта 1 массив стал выглядить вот так:" << endl;
    zamena(array3, width, lengths);

    f = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
        {
            cout << array3[f] << "  ";
            f++;
        }
        cout << endl;

    }

    if (punkt2 == 2)
    {
        punkt(array4, width, lengths);
    }


    return EXIT_SUCCESS;
}

void zapolnrandom(int* array3, int* array4, const int width, const int lengths)
{
    mt19937 gen;
    gen.seed(time(0));
    size_t f = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
        {
            array3[f] = gen(); //заполяем массив рандомными элементами
            array4[f] = array3[f]; //копируем 1-й массив во второй
            f++;
        }

    }

}

void zapolnvod(int* array3, int* array4, const int width, const int lengths)
{
    size_t f = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
        {
            cin >> array3[f]; //заполяем массив рандомными элементами
            array4[f] = array3[f]; //копируем 1-й массив во второй
            f++;
        }
    }

}

void zamena(int* array3, const int width, const int lengths)
{
    size_t i = 0;
    size_t r = 1;
    size_t max = 0;
    size_t f = 0;
    while (i <= width * lengths)
    {
        if (i <= lengths * r)
        {
            if (array3[i] >= array3[max])
            {
                max = i;
            }
            if (i == lengths * r)
            {
                array3[max] = 0;
            }

        }
        else
        {
            array3[max] = 0;
            r = r + 1;
            max = 0;
            if (i < lengths * r)
            {
                if (array3[i] >= array3[max])
                {
                    max = i;
                }

            }
        }
        i++;
    }
}

void punkt(int* array4, const int width, const int lengths)
{
    cout << endl << "После выполнения пункта 2, массив выглядит так" << endl;
    size_t i = 0;
    size_t r = 1;
    size_t z = 1;

    while (i < lengths * width)
    {

        if (i > r * lengths)
        {
            r = r + 1;
        }

        if (i == 0 || (i - r * lengths) == 0)
        {
            cout << endl;
            if (array4[i] % 3 == 0 && array4[i] != 0)
            {
                for (int j = 0; j < lengths; j++)
                {
                    cout << "0" << " ";// Вставляем перед всеми строками, первый элемент которых делится на 3, строку
                }
                cout << endl;
            }

        }
        if (i == z * lengths)
        {
            z = z + 1;
        }

        cout << array4[i] << " ";
        i++;

    }
}
