#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Входные данные
    double h = 10.0;          // мм
    double delta_h = 0.2;     // Погрешность h
    double s = 20.00;         // м
    double delta_s = 0.01;    // Погрешность s
    double n = 10.0;          // Делений
    double delta_n = 0.1;     // Погрешность n

    // Коэффициент из формулы
    const double k = 206.0;

    // Вычисляем значение t
    double t = (k * h) / (n * s);

    // Вычисляем относительные погрешности
    double rel_h = delta_h / h;
    double rel_s = delta_s / s;
    double rel_n = delta_n / n;

    // Общая относительная погрешность
    double rel_error_t = sqrt(pow(rel_h, 2) + pow(rel_n, 2) + pow(rel_s, 2));

    // Абсолютная погрешность t
    double delta_t = t * rel_error_t;

    // Вывод результатов
    cout << "t = " << t << " ± " << delta_t << endl;
    cout << "Относительная погрешность t: " << rel_error_t * 100 << "%" << endl;

    return 0;
}
