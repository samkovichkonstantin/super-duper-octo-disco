#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

int main() {
    // Данные
    double S1 = 141.714;         // м
    double delta_S1 = 0.018;     // м
    double D2 = 195.615;         // м
    double delta_D2 = 0.028;     // м
    double v_deg = 4 + 42.0 / 60 + 18.0 / 3600;  // угол в градусах
    double delta_v_sec = 20;     // секунд
    double delta_v_deg = delta_v_sec / 3600; // угол в градусах

    // Перевод угла в радианы
    double v_rad = v_deg * PI / 180.0;
    double delta_v_rad = delta_v_deg * PI / 180.0;

    // Вычисление горизонтальной проекции S2
    double S2 = D2 * cos(v_rad);

    // Общая длина L
    double L = S1 + S2;

    // Частные производные
    double dS2_dD2 = cos(v_rad);
    double dS2_dv = -D2 * sin(v_rad);

    // Средняя квадратическая погрешность L
    double delta_L = sqrt(pow(delta_S1, 2) + pow(dS2_dD2 * delta_D2, 2) + pow(dS2_dv * delta_v_rad, 2));

    // Вывод результатов
    cout << "Общая длина линии L = " << L << " м" << endl;
    cout << "Средняя квадратическая погрешность delta_L = " << delta_L << " м" << endl;

    return 0;
}
