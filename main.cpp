#include <iostream>
#include <cmath>      // виклик матиматичної бібліотеки
using namespace std;

// If19. Дано чотири цілих числа, одне з яких відмінне від трьох інших,
// рівних між собою. Визначити порядковий номер числа, відмінного від інших.
void task_if19();

// If36. Для заданого дійсного x знайти значення функції t(x).
void task_if36();

// Геометрія, варіант 11: чи потрапляє точка (x, y) у світло-зелену область.
void task_geom11();

int main() {
    int menu;
    cout << "Task number" << endl;
    cout << "1 - If19" << endl;
    cout << "2 - If36" << endl;
    cout << "3 - geom 11" << endl;
    cout << "Task number: ";
    cin >> menu;

    if (!cin) {                     // перевірка: введено не число
        cout << "Wrong task" << endl;
        return 1;
    }

    // вибір завдання за допомогою інструкції switch
    switch (menu) {
        case 1: task_if19();   break;
        case 2: task_if36();   break;
        case 3: task_geom11(); break;
        default: cout << "Wrong task! (Only 1, 2, 3)" << endl;
    }
    return 0;
}

// ---------- If19 ----------
void task_if19() {
    int a, b, c, d;
    cout << "************* If 19 *****************" << endl;
    cout << "Enter 4 numbers: ";
    cin >> a >> b >> c >> d;

    // Кожна умова перевіряє, що три числа рівні, а одне - відмінне.
    // Якщо всі числа рівні то виводиться відповідний текст.
    if (a == b && b == c && c != d)
        cout << "Number 4" << endl;
    else if (a == b && b == d && d != c)
        cout << "Number 3" << endl;
    else if (a == c && c == d && d != b)
        cout << "Number 2" << endl;
    else if (b == c && c == d && d != a)
        cout << "Number 1" << endl;
    else
        cout << "All numbers a simillar" << endl;
}

// ---------- If36 ----------
void task_if36() {
    double x;
    int t;
    cout << "************* If 36 *****************" << endl;
    cout << "Enter x: ";
    cin >> x;

    if (x <= -1)                    // гілка якщо x <= −1
        t = x - 2;
    else if (x < 2)                 // гілка якщо − 1 < x < 2;
        t = x * x + x;
    else                            // гілка якщо x >= 2
        t = 6;

    cout << "t(" << x << ") = " << t << endl;
}

// ---------- Geometry 11 ----------
void task_geom11() {
    double r, x, y;
    cout << "************* Figure 11 *****************" << endl;
    cout << "Enter radius r: ";
    cin >> r;
    if (!cin || r <= 0) {           // радіус має бути додатним числом
        cout << "Incorect r" << endl;
        return;
    }

    cout << "Enter x, y: ";
    cin >> x >> y;

    // Верхнє коло: центр (r, r), радіус r
    double d1 = pow(x - r, 2) + pow(y - r, 2);
    // Нижнє коло: центр (-r, -r), радіус r
    double d2 = pow(x + r, 2) + pow(y + r, 2);

    // Верхнє коло: сектор 45 між напрямами "вгору" і "вгору-вліво":
    // зліва від вертикального діаметра (x <= r) і вище діагонального (x + y >= 2r)
    bool inUpper = d1 <= r * r && x <= r && x + y >= 2 * r;

    // Нижнє коло: півкруг по один бік від діагонального діаметра (x + y >= -2r)
    bool inLower = d2 <= r * r && x + y >= -2 * r;

    if (inUpper || inLower)
        cout << "Belongs to the region" << endl;
    else
        cout << "Does not belong" << endl;
}
