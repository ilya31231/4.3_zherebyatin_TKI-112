#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <random> 

using namespace std;
// переменные r, i, j, f, z введены для перебора последовательностей

void manual(int* array1, const int sum, const int dlin, const int hir, int* array2);
void rando(int* array1, const int sum, const int dlin, const int hir, int* array2);

int main()
{
    int dlin, hir, sum, random, punkt2;
    cout << "Введи длинну массива ";
    cin >> dlin;
    cout << "Введи ширину массива ";
    cin >> hir;
    cout << "Если хочешь заполнить массив случайными числами введи 1 ";
    cin >> random;
    cout << "Если нужен пункт 2 введи 2 ";
    cin >> punkt2;

    sum = dlin * hir;

    int* array1 = new int[sum];
    int* array2 = new int[sum];

    for (int i = 0; i < sum; i++)
    {
        array1[i] = 0;

    }
    if (random == 1)
    {
        rando(array1, sum, dlin, hir, array2);
    }
    else
    {
        manual(array1, sum, dlin, hir, array2);
    }

    int i = 0;
    int f = 1;
    cout << "После выполнения пункта 1, массив выглядит так " << endl;
    while (i < sum)
    {

        cout << array1[i] << " ";
        if (f % dlin == 0)
        {
            cout << endl;
        }
        i++;
        f++;

    }

    if (punkt2 == 2)
    {
        cout << endl << "После выполнения пункта 2, массив выглядит так" << endl;
        int i = 0;
        int r = 1;
        int z = 1;

        while (i <= sum)
        {

            if (i < r * dlin)
            {
                r = r + 1;
            }

            if (i == 0 || (i - r * dlin) == 0)
            {
                if (array2[i] % 3 == 0 && array2[i] != 0)
                {
                    for (int j = 0; j < dlin; j++)
                    {
                        cout << "0" << " ";// Вставляем перед всеми строками, первый элемент которых делится на 3, строку
                    }
                    cout << endl;
                }

            }
            if (i > z * dlin)
            {
                cout << endl;
                z = z + 1;
            }
            cout << array2[i] << " ";

            i++;

        }
    }

    return 0;
}



void rando(int* array1, const int sum, const int dlin, const int hir, int* array2)
{

    mt19937 gen;
    gen.seed(time(0));

    for (int i = 0; i < sum; i++)
    {
        array1[i] = gen();
        array2[i] = array1[i];
    }


    int i = 0;
    int r = 1;
    int max = 0;
    int f = 0;

    while (i <= sum)
    {
        if (i <= dlin * r)
        {
            if (array1[i] >= array1[max])
            {
                max = i;
            }
            if (i == dlin * r)
            {
                array1[max] = 0;
            }

        }
        else
        {
            array1[max] = 0;
            r = r + 1;
            max = 0;
            if (i < dlin * r)
            {
                if (array1[i] >= array1[max])
                {
                    max = i;
                }

            }
        }
        i++;
    }
}

void manual(int* array1, const int sum, const int dlin, const int hir, int* array2)
{

    for (int i = 0; i < sum; i++)
    {
        cin >> array1[i];
        array2[i] = array1[i];
    }
    int i = 0;
    int r = 1;
    int max = 0;
    int f = 0;

    while (i <= sum)
    {
        if (i <= dlin * r)
        {
            if (array1[i] >= array1[max])
            {
                max = i;
            }
            if (i == dlin * r)
            {
                array1[max] = 0;
            }

        }
        else
        {
            array1[max] = 0;
            r = r + 1;
            max = 0;
            if (i < dlin * r)
            {
                if (array1[i] >= array1[max])
                {
                    max = i;
                }

            }
        }
        i++;
    }
}
