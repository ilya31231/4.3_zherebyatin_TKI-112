#include <iostream>
#include <random>
#include <string>

using namespace std;
/**
 * \brief Способ заполнения массива.
 */
enum class input_way
{
    /**
     * \brief Заполнение массива при помощи ГПСЧ.
     */
    random,

    /**
     * \brief Заполнение массива при помощи пользовательского ввода.
     */
     keyboard
};

/**
 * \brief
 */
enum class menu_item
{
    /**
    * \brief
    */
    Show,
    /**
    * \brief
    */
    task_1,
    /**
    * \brief
    */
    task_2,
    /**
    * \brief
    */
    exit
};

/**
 * \brief Функция позволяет ввести число предверяя его сообщением \a message.
 * \param  message Передаваемое сообщение.
 * \return Введёное пользователем число.
 */
int read_integer(const string& message = "") noexcept;

/**
 * \brief Считывает способ запонения массива.
 * \param Мотивирующее сообщение.
 * \return Способ заполнения массива.
 */
input_way read_input_way(const string& message = "");

/**
 * \brief Считывает пункт меню.
 * \param Мотивирующее сообщение.
 * \return Пункт меню.
 */
menu_item read_menu_item(const string& message = "");

/**
 * \brief Считывает оазмер по одному из измерений массива.
 * \param Мотивирующее сообщение.
 * \return Способ заполнения массива.
 * \exception out_of_range В случае если введён размер меньше или раен нулю.
 */
size_t read_size(const string& message = "");

/**
 * \brief Создаёт двумерный массив.
 * \param rows Количество строк.
 * \param columns Количество столбцов.
 * \return Созданный массив.
 */
int** create_array(const size_t rows, const size_t columns);

/**
 * \brief Функция заполняет массив случайными числами в заданном промежутке. Возможны перебои при работе с большими массивами.
 * \param array Заполняемый массив.
 * \param rows Количество строк.
 * \param columns Количество столбцов.
 * \param min_value Левая граница распределения.
 * \param max_value Правая граница распределения.
 */
void random_fill(int** array, const size_t rows, const size_t columns, const int min_value, const int max_value);

/**
 * \brief Функция позволяет пользователю вручную заполнить массив.
 * \param rows Количество строк.
 * \param columns Количество столбцов.
 */
void read_from_keyboard(int** array, const size_t rows, const size_t columns);

/**
 * \brief  Функция выводит на экран данный ей массив.
 * \param  array Отображаемый массив.
 * \param  rows Количество строк.
 * \param  columns Количество столбцов.
 */
void Show(const int** const array, const size_t rows, const size_t columns);

/**
 * \brief  Функция меняет наибольший(наибольшие) по модулю элементы на ноль.
 * \param  array Исходный массив.
 * \param  rows Количество строк.
 * \param  columns Количество столбцов.
 * \return Изменённый массив
 */
int** replace_max_element_with_zero(const int** const array, const size_t rows, const size_t columns);

/**
 * \brief Получает значение максимального элемента \a array.
 * \param Массив элементов.
 * \param Размер массива.
 * \return Максимальный элемент.
 */
int get_max_value(const int* const array, const size_t size);

/**
 * \brief Функция добавляет ряд нулей перед рядам с первым числом кратным 3. На данный момент плохо работает при множественном вызове.
 * \param array Исходный массив.
 * \param rows Количество строк.
 * \param columns Количество столбцов.
 * \param new_array_rows out параметр, хранящий число строк изменённого массива.
 * \return Изменённый элемент.
 */
int** add_rows_of_zeros(const int** const array, const size_t rows, const size_t columns, size_t& new_array_rows);

/**
   Функция освобождает динамическую память массива
   array Массив для "зачистки"
   rows Количество строк массива
 */
void Delete_array(int** array, const size_t rows);

/**
   Главная функция программы
  0 в случае успеха
 */
int main()
{
    try
    {
        const auto rows = read_size("Enter number of strings in arrayay: ");
        const auto columns = read_size("Enter number of columns in arrayay: ");

        auto array = create_array(rows, columns);

        auto message = "Do you want fill arrayay by yourself? \n"
            + to_string(static_cast<int>(input_way::random)) + " - NO \n"
            + to_string(static_cast<int>(input_way::keyboard)) + " - YES \n"
            + ">> ";

        const auto choise = read_input_way(message);
        switch (choise)
        {
        case input_way::random:
        {
            const auto min_value = read_integer("Input min value of arrayay >> ");
            const auto max_value = read_integer("Input max value of arrayay >> ");
            if (min_value > max_value)
            {
                throw logic_error("max_value have to be greater then min_value");
            }

            random_fill(array, rows, columns, min_value, max_value);
            break;
        }
        case input_way::keyboard:
        {
            read_from_keyboard(array, rows, columns);
            break;
        }
        default:
        {
            throw out_of_range("You entered wrong choice!");
        }
        }

        Show(const_cast<const int** const>(array), rows, columns);

        bool chould_exit = false;
        do
        {
            auto message = "Choose an option:\n"
                + to_string(static_cast<int>(menu_item::task_1)) + ": Replace max value with 0 On each line\n"
                + "2: print a string of zeros before the first digit of each row, divisible by 3\n"
                + "3: Show arrayay\n"
                + to_string(static_cast<int>(menu_item::exit)) + "Exit program\n"
                + "> ";

            const auto choise = read_menu_item(message);
            switch (choise)
            {
            case menu_item::exit:
            {
                chould_exit = true;
                break;
            }
            case menu_item::task_1:
            {
                const auto new_array = replace_max_element_with_zero(const_cast<const int** const>(array), rows, columns);
                Show(const_cast<const int** const>(new_array), rows, columns);
                Delete_array(new_array, rows);
                break;
            }
            case menu_item::task_2:
            {
                size_t modifed_array_rows = 0;
                auto modifed_array = add_rows_of_zeros(const_cast<const int** const>(array), rows, columns, modifed_array_rows);
                Show(const_cast<const int** const>(modifed_array), modifed_array_rows, columns);
                Delete_array(modifed_array, rows);
                break;
            }
            case menu_item::Show:
            {
                Show(const_cast<const int** const>(array), rows, columns);
                break;
            }
            default:
            {
                throw out_of_range("Not supposed input!");
            }
            }
        } while (!chould_exit);

        Delete_array(array, rows);
    }
    catch (out_of_range& error)
    {
        cerr << error.what() << endl;
        return 1;
    }
    catch (logic_error& logic_error)
    {
        cerr << logic_error.what() << endl;
        return 2;
    }

    return 0;
}

int read_integer(const string& message) noexcept
{
    cout << message;
    int x = 0;
    cin >> x;
    return x;
}

input_way read_input_way(const string& message)
{
    const auto choise = read_integer(message);
    return static_cast<input_way>(choise);
}

menu_item read_menu_item(const string& message)
{
    const auto choise = read_integer(message);
    return static_cast<menu_item>(choise);
}

size_t read_size(const string& message)
{
    const auto size = read_integer(message);
    if (size < 0)
    {
        throw out_of_range("size have to be greater than zero");
    }
    return static_cast<size_t>(size);
}

int** create_array(const size_t rows, const size_t columns)
{
    auto array = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
    }

    return array;
}

void random_fill(int** array, const size_t rows, const size_t columns, const int min_value, const int max_value)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(min_value, max_value);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array[i][j] = uniformIntDistribution(gen);
        }
    }
}

void read_from_keyboard(int** array, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cin >> array[i][j];
        }
    }
}

void Show(const int** const array, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        cout << '[' << i << "] - ";
        size_t j = 0;

        for (; j < columns; j++)
        {
            cout << '[' << array[i][j] << "], ";
        }
        cout << endl;

    }
}

int** replace_max_element_with_zero(const int** const array, const size_t rows, const size_t columns)
{
    int** new_array = create_array(rows, columns);

    for (size_t i = 0; i < rows; i++)
    {
        const auto max_value = get_max_value(array[i], columns);
        for (size_t j = 0; j < columns; j++)
        {
            new_array[i][j] = array[i][j] == max_value
                ? 0
                : array[i][j];
        }
    }

    return new_array;
}

int get_max_value(const int* const array, const size_t size)
{
    int max_value = array[0];
    for (size_t i = 0; i < size; i++)
    {
        if (max_value < array[i])
        {
            max_value = array[i];
        }
    }

    return max_value;
}

int** add_rows_of_zeros(const int** const array, const size_t rows, const size_t columns, size_t& new_array_rows)
{
    int added_rows_count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (array[i][0] % 3 == 0)
        {
            added_rows_count++;
        }
    }

    new_array_rows = rows + added_rows_count;
    auto new_array = create_array(new_array_rows, columns);

    size_t k = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (array[i][0] % 3 == 0)
        {
            for (size_t j = 0; j < columns; j++)
            {
                new_array[k][j] = 0;
            }
            k++;
        }

        for (size_t j = 0; j < columns; j++)
        {
            new_array[k][j] = array[i][j];
        }
        k++;
    }

    return new_array;
}

void Delete_array(int** array, const size_t rows)
{
    if (array != nullptr)
    {
        for (size_t i = 0; i < rows; i++)
        {
            if (array[i] != nullptr)
            {
                delete[] array[i];
                array[i] = nullptr;
            }
        }

        delete[] array;
        array = nullptr;
    }
}

