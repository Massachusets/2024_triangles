// Треугольники1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath> // Для использования функции sqrt
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double Ax, Bx, Cx, Ay, By, Cy, AB, BC, AC, S, per;
    cout << "Введите координату вершины A по X" << endl;
    cin >> Ax;
    cout << "Введите координату вершины A по Y" << endl;
    cin >> Ay;
    cout << "Введите координату вершины B по X" << endl;
    cin >> Bx;
    cout << "Введите координату вершины B по Y" << endl;
    cin >> By;
    cout << "Введите координату вершины C по X" << endl;
    cin >> Cx;
    cout << "Введите координату вершины C по Y" << endl;
    cin >> Cy;

    if (((Ax == Bx) && (Ay == By)) || ((Bx == Cx) && (By == Cy)) || ((Ax == Cx) && (Ay == Cy)))
    {
        cout << "Невозможно построить треугольник" << endl;
        return 0; // Завершение программы
    }

    if (((Ax == Bx) && (Ax == Cx)) || ((By == Cy) && (By == Ay)))
    {
        cout << "Невозможно построить треугольник" << endl;
        return 0; // Завершение программы
    }
    
    // необходимо добавить доп условие на совпадение 
    // координат на одной плоскости (напримео, (1,2),(1,4),(1,5) или по игрику

    AB = sqrt((Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay));
    BC = sqrt((Cx - Bx) * (Cx - Bx) + (Cy - By) * (Cy - By));
    AC = sqrt((Cx - Ax) * (Cx - Ax) + (Cy - Ay) * (Cy - Ay));

    if ((AB == AC) || (AB == BC) || (AC == BC)) // Используем логическое ИЛИ
    {
        cout << "Треугольник Равнобедренный" << endl;
        cout << "Большая сторона: ";

        if (AB == AC)
        {
            if (AB > BC)
            {
                cout << "BC: " << BC << " AC: " << AC << " AB: " << AB << endl;
            }
            else
            {
                cout << "AC: " << AC << " AB: " << AB << " BC: " << BC << endl;
            }
        }
        if (AB == BC)
        {
            if (AB > AC)
            {
                cout << "AC: " << AC << " BC: " << BC << " AB: " << AB << endl;
            }
            else
            {
                cout << "BC: " << BC << " AB: " << AB << " AC: " << AC << endl;
            }
        }
        if (AC == BC)
        {
            if (AC > AB)
            {
                cout << "AB: " << AB << " BC: " << BC << " AC: " << AC << endl;
            }
            else
            {
                cout << "BC: " << BC << " AC: " << AC << " AB: " << AB << endl;
            }
        }

        per = (AB + BC + AC) / 2.0;
        // Приведение к double не обязательно
        S = sqrt(per * (per - AB) * (per - BC) * (per - AC));
        cout << "S = " << S << endl;
    }
    else
    {
        cout << "Треугольник не равнобедренный" << endl;

    }

    // Определение типа треугольника
    double AB2 = AB * AB;
    double BC2 = BC * BC;
    double AC2 = AC * AC;

    if (AB2 + BC2 == AC2 || AB2 + AC2 == BC2 || AC2 + BC2 == AB2)
    {
        cout << "Треугольник прямоугольный" << endl;
    }
    else if (AB2 + BC2 < AC2 || AB2 + AC2 < BC2 || AC2 + BC2 < AB2)
    {
        cout << "Треугольник тупоугольный" << endl;
    }
    else
    {
        cout << "Треугольник остроугольный" << endl;
    }
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
