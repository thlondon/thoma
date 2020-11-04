/* Дана целочисленная квадратная матрица. Определить:
1)	произведение элементов в тех строках, которые не содержат отрицательных элементов;
2)	максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы. */

#include <iostream>
#include <Windows.h>

#define N 3

using namespace std;

int main(int argc, const char* argv[])
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251); // установка кодировки для корректного отображения слов на русском языке

    int array[N][N] = {
        {-2, 22, 8},
        {-3, 1, 1},
        {2, 2, 2},
    };

    int A[N] = { NULL };

    int s = 0, c = 1; // s - строка, c = произведение
    int attention = 1; //проверяет, были ли в строке отрицательные элементы
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (array[s][j] > 0) { 
                c = array[s][j] * c;
            }
            if (array[s][j] < 0) {
                c = 1;
                attention = 2;
                break;
            }
        }
        if (attention == 1) { A[i] = c; c = 1; }
        attention = 1;
        s++;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            cout << A[i] << endl;
        }
    }

    /// 
    /// 
    
    int maxSum = 1, underDiagonal = 0, aboveDiagonal = 0;

    for (unsigned int i = 1; i < N; i++) {

        underDiagonal = 0;

        for (unsigned int j = 0, k = j; j < N - i; j++, k++) {

            underDiagonal += array[j + i][k];

        }

        maxSum = (maxSum < underDiagonal) ? underDiagonal : maxSum;

    }

    for (unsigned int i = 1; i < N; i++) {

        aboveDiagonal = 0;

        for (unsigned int j = 0, k = j; j < N - i; j++, k++) {

            aboveDiagonal += array[j][k + i];

        }

        maxSum = (maxSum < aboveDiagonal) ? aboveDiagonal : maxSum;

    }

    cout << "\n" << maxSum << endl;

    cin.get();
    return 0;
}
