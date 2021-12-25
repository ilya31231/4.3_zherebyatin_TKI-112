#include <iostream>
#include <random>
using namespace std;
/**
   Функция меняет значения местами
   min_Value Первое значение
   max_Value Второе значение
 */
void ChangePos(int& min_Value, int& max_Value);
/**
   Функция позволяет ввести число предверяя его сообщением msg
   msg Передаваемое сообщение

 */
int IntInput(const string& msg);
/**
   Функция заполняет массив случайными числами в заданном промежутке. Возможны перебои при работе с большими массивами
   arr Передаваемый массив
   of_strings Количество строк
   of_columns Количество столбцов
 */
void random_fill(int** arr, const size_t of_strings, const size_t of_columns, const int min_Value, const int max_Value);
/**
   Функция позволяет пользователю вручную заполнить массив
   arr Передаваемый массив
   of_strings Количество строк
   of_columns Количество столбцов
 */
void Enter_with_keyboard(int** arr, const size_t of_strings, const size_t of_columns);
/**
   Функция выводит на экран данный ей массив
   arr Передаваемый массив
   of_strings Количество строк
   of_columns Количество столбцов
 */
void ShowArr(int** arr, const size_t of_strings, const size_t of_columns);
/**
   Функция меняет наибольший(наибольшие) по модулю элементы на ноль
   arr Передаваемый массив
   of_strings Количество строк
   of_columns Количество столбцов
 */
void  replacement_to_0(int** arr, const size_t of_strings, const size_t of_columns);
/**
   Функция добавляет ряд нулей перед рядам с первым числом кратным 3. На данный момент плохо работает при множественном вызове
   arr Передаваемый массив
   of_strings Количество строк
   of_columns Количество столбцов
  arr
 */
int** New_Row_of_Zeros(int** arr, const size_t of_strings, const size_t of_columns);
/**
   Функция инициализирует двумерный массив
   arr Инициализируемый массив
   of_strings Количество строк
   of_columns Количество столбцов
  arr в случае успеха
 */
int** InitArr(int** arr, const size_t of_strings, const size_t of_columns);
/**
   Функция освобождает динамическую память массива
   arr Массив для "зачистки"
   of_strings Количество строк массива
 */
void DeleteArr(int** arr, const size_t of_strings);
enum class InputWay {
    random,
    keyboard
};
/**
   Главная функция программы
  0 в случае успеха
 */
int main()
{
    size_t of_strings, of_columns;
    cout << "Enter number of strings in array: ";
    cin >> of_strings;
    cout << "Enter number of columns in array: ";
    cin >> of_columns;
    int** arr = InitArr(arr, of_strings, of_columns);
    cout << "Do you want fill array by yourself? \n"
        << static_cast<int>(InputWay::random) << " - NO \n"
        << static_cast<int>(InputWay::keyboard) << " - YES \n"
        ">> ";
    int choise = IntInput("");
    try
    {
        auto chose = static_cast<InputWay>(choise);
        switch (chose)
        {
        case InputWay::random:
        {
            int min_Value = IntInput("Input min value of array >> ");
            int max_Value = IntInput("Input max value of array >> ");
            if (min_Value > max_Value) {
                ChangePos(min_Value, max_Value);
            }
            random_fill(arr, of_strings, of_columns, min_Value, max_Value);
            break;
        }
        case InputWay::keyboard:
        {
            Enter_with_keyboard(arr, of_strings, of_columns);
            break;
        }
        default:
            cout << "You entered wrong choice!\n";
            return 1;
        }
        ShowArr(arr, of_strings, of_columns);

    }
    catch (out_of_range&)
    {
        cout << "You entered wrong choice!\n";
        return 1;
    }
    bool exitCode = false;
    do
    {
        cout << "Choose an option:\n"
            "1: Replace max value with 0 On each line\n"
            "2: print a string of zeros before the first digit of each row, divisible by 3\n"
            "3: Show array\n"
            "0: Exit program\n"
            "> ";
        cin >> choise;
        int numberStr;
        switch (choise)
        {
        case 0:
            exitCode = true;
            break;
        case 1:
            replacement_to_0(arr, of_strings, of_columns);
            break;
        case 2:
            arr = New_Row_of_Zeros(arr, of_strings, of_columns);
            numberStr = 0;
            for (int i = 1; i < of_strings; i += 2)
            {
                numberStr += 1;
            }
            of_strings = of_strings + numberStr;
            break;
        case 3:
            ShowArr(arr, of_strings, of_columns);
            break;
        default:
            cout << "Not supposed input!\n";
        }
    } while (exitCode == 0);
    return 0;
}

void random_fill(int** arr, const size_t of_strings, const size_t of_columns, const int min_Value, const int max_Value)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniformIntDistribution(min_Value, max_Value);
    for (int i = 0; i < of_strings; i++)
    {
        for (int j = 0; j < of_columns; j++)
        {
            arr[i][j] = uniformIntDistribution(gen);
        }
    }
}

void Enter_with_keyboard(int** arr, const size_t of_strings, const size_t of_columns)
{
    for (size_t i = 0; i < of_strings; i++)
    {
        for (size_t j = 0; j < of_columns; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void ShowArr(int** arr, const size_t of_strings, const size_t of_columns)
{
    for (size_t i = 0; i < of_strings; i++)
    {
        cout << '[' << i << "] - ";
        for (size_t j = 0; j < of_columns; j++)
        {
            if (j == of_columns - 1) {
                cout << '[' << arr[i][j] << "]" << endl;
                break;
            }
            cout << '[' << arr[i][j] << "], ";
        }
    }
}

void  replacement_to_0(int** arr, const size_t of_strings, const size_t of_columns)
{
    int max = 0;
    int** testArr = InitArr(testArr, of_strings, of_columns);
    for (size_t i = 0; i < of_strings; i++)
    {
        for (size_t j = 0; j < of_columns; j++)
        {
            testArr[i][j] = arr[i][j];
            if (abs(max) < abs(testArr[i][j])) {
                max = arr[i][j];
            }
        }
        for (size_t j = 0; j < of_columns; j++)
        {
            if (arr[i][j] == (0) * max || arr[i][j] == max)
            {
                arr[i][j] = (0);
            }
        }
        max = 0;
    }
    DeleteArr(testArr, of_strings);
}

int** New_Row_of_Zeros(int** arr, const size_t of_strings, const size_t of_columns)
{
    int strCount = -1; //number of added strings in new array
    for (size_t i = 0; i < of_strings; i++)
    {
        for (size_t j = 0; j < of_columns; j++)
        {
            if (arr[i][0] % 3 == 0)
            {
                strCount = strCount + 1;
            }
        }
    }

    int** testArr = InitArr(testArr, of_strings, of_columns);
    int** testArr1 = InitArr(testArr1, of_strings, of_columns);
    int** testArr2 = InitArr(testArr2, of_strings, of_columns); //нетрогать!!!!!!!!! спасает от ошибки 
    int** testArr3 = InitArr(testArr3, of_strings, of_columns);
    for (size_t i = 0; i < of_strings; i++)
    {
        for (size_t j = 0; j < of_columns; j++)
        {
            testArr[i][j] = arr[i][j]; //saving data
            testArr1[i][j] = arr[i][j]; //нетрогать!!!!!!!!! спасает от ошибки 
            testArr2[i][j] = arr[i][j];
            testArr3[i][j] = arr[i][j];
        }
    }

    DeleteArr(arr, of_strings);
    arr = InitArr(arr, of_strings + strCount, of_columns);

    for (size_t i = 0; i < of_strings; i++)
    {
        for (size_t j = 0; j < of_columns; j++)
        {
            if (testArr[i][0] % 3 == 0 && testArr[i][0] != 0)
            {
                if (testArr1[i - 1][0] % 3 == 0 && testArr1[i - 1][0] != 0 && (i - 1) != (-1))
                {
                    for (size_t j = 0; j < of_columns; j++)
                    {
                        arr[i + 1][j] = 0;
                        arr[i + 2][j] = testArr1[i][j];
                    }
                }
                else
                {
                    for (size_t j = 0; j < of_columns; j++)
                    {
                        arr[i][j] = 0;
                        arr[i + 1][j] = testArr1[i][j];
                    }

                }

            }
            else
            {
                if (i > 0)
                {
                    if (testArr3[i - 1][0] % 3 == 0)
                    {
                        arr[i + 1][j] = testArr3[i][j];

                    }
                    else
                    {
                        arr[i][j] = testArr3[i][j];

                    }

                }
                else
                {
                    arr[i][j] = testArr3[i][j];
                }
            }
        }
    }


    DeleteArr(testArr, of_strings);
    return arr;
}

int** InitArr(int** testArr, const size_t of_strings, const size_t of_columns)
{
    testArr = new int* [of_strings];
    for (size_t i = 0; i < of_strings; i++)
    {
        testArr[i] = new int[of_columns];
    }
    return testArr;
}

void DeleteArr(int** arr, const size_t of_strings)
{
    for (size_t i = 0; i < of_strings; i++)
    {
        if (arr[i] != nullptr)
        {
            delete[] arr[i];
        }
    }
}

int IntInput(const string& msg)
{
    cout << msg;
    int x;
    cin >> x;
    return x;
}

void ChangePos(int& min_Value, int& max_Value)
{
    auto temp = min_Value;
    min_Value = max_Value;
    max_Value = temp;
}