#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


int f1(const int width, const int lengths, int punkt)
{
    int array1[width][lengths]; //�������� ������
    int array2[width][lengths]; //�������� ������

    srand(time(NULL));
    cout << "��� ��� ������" << endl;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < lengths; j++)
        {
            array1[i][j] = rand(); //�������� ������ ���������� ����������
            array2[i][j] = array1[i][j]; //�������� 1-� ������ �� ������
        }


    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
            cout << array1[i][j] << "  "; //������� ������
        cout << endl;

    }

    cout << endl;

    cout << "����� ���������� ������ 1 ������ ���� ��������� ��� ���:" << endl;
    for (int i = 0; i < width; i++)
    {
        int max = 0;
        for (int j = 0; j < lengths; j++)
            if (array1[i][j] > array1[i][max])
                max = j; //������� ������������ ������� � ������
        array1[i][max] *= 0; //�������� ������� �� 0
    }


    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
            cout << array1[i][j] << "  "; //������� ������
        cout << endl;

    }


    cout << endl << endl;
    if (punkt == 2) //���������, ����� �� ����� 2 
    {
        cout << "����� ���������� 2-�� ������, ������ �������� ��� ���:" << endl;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < lengths; j++)
            {
                int f = j;
                int ff = 0;
                if (array2[i][0] % 3 == 0 && f == 0 && array2[f][0] != 0)
                {

                    for (int mm = 0; mm < lengths; mm++)
                    {
                        cout << "0" << " ";// ��������� ����� ����� ��������, ������ ������� ������� ������� �� 3, ������

                    }
                }
                if (array2[i][0] % 3 == 0 && f == 0 && array2[f][0] != 0)
                {
                    cout << endl;
                }

                cout << array2[i][j] << "  "; //������� 2-� ������
                ff += 1;
            }
            cout << endl;
        }
    }
}

int f2(int width, int lengths, int punkt2)
{
    int array1[width][lengths]; //�������� ������
    int array2[width][lengths]; //�������� ������

    srand(time(NULL));
    cout << "��������� ������ ������ � ����������" << endl;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < lengths; j++)
        {

            cin >> array1[i][j]; //������ ������ � ����������
            array2[i][j] = array1[i][j]; //�������� 1-� ������ �� ������
        }
    cout << "��� ��� ������" << endl;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
            cout << array1[i][j] << "  "; //������� ������
        cout << endl;

    }

    cout << endl;

    cout << "����� ���������� ������ 1 ������ ���� ��������� ��� ���:" << endl;
    for (int i = 0; i < width; i++)
    {
        int max = 0;
        for (int j = 0; j < lengths; j++)
            if (array1[i][j] > array1[i][max])
                max = j; //������� ������������ ������� � ������
        array1[i][max] *= 0; //�������� ������� �� 0
    }


    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < lengths; j++)
            cout << array1[i][j] << "  "; //������� ������
        cout << endl;

    }


    cout << endl << endl;


    if (punkt2 == 2) //���������, ����� �� ����� 2 
    {
        cout << "����� ���������� 2-�� ������, ������ �������� ��� ���:" << endl;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < lengths; j++)
            {
                int f = j;
                int ff = 0;
                if (array2[i][0] % 3 == 0 && f == 0 && array2[f][0] != 0)
                {

                    for (int mm = 0; mm < lengths; mm++)
                    {
                        cout << "0" << " ";// ��������� ����� ����� ��������, ������ ������� ������� ������� �� 3, ������� 

                    }
                }
                if (array2[i][0] % 3 == 0 && f == 0 && array2[f][0] != 0)
                {
                    cout << endl;
                }

                cout << array2[i][j] << "  ";
                ff += 1;
            }
            cout << endl;
        }
    }
}


int main(int argc, char* argv[])
{
    int punkt1;
    cout << "���� ����� ����������� ������ ���������� �������, ����� 1 " << endl << "���� ���o ��������� ������ ������ � ����������, ����� 2" << endl;
    cin >> punkt1;
    cout << "���� ����� 2-� �����, �� ����� 2" << endl;
    int punkt2;
    cin >> punkt2;
    int width, lengths, q, w;
    cout << "������� ������ �������" << endl;
    cin >> width; //�������� ������� �������
    cout << "������� ������ �������" << endl;
    cin >> lengths; //�������� ������� �������
    if (punkt1 == 1)
    {
        f1(width, lengths, punkt2); //�������� 1-� �������
    }
    else
    {
        f2(width, lengths, punkt2); //�������� 2-� �������
    }

    return EXIT_SUCCESS;
}