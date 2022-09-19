#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
    setlocale(0, "");
    srand(time(NULL));

    int n=1000, m = n;

    int** A = new int* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[m];
    }

    int** B = new int* [n];
    for (int i = 0; i < n; i++)
    {
        B[i] = new int[m];
    }

    int** C = new int* [n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[m];
    }

    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            A[i][j]=10+rand()%90;

    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            B[i][j] = 10 + rand() % 90;

    double time1 = clock();
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n; j++) {
            C[i][j] = 0;
            for (auto k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    double time2 = clock();

    cout << "Время умножения: " << (time2 - time1) / 1000.0 << endl;
    cout << endl << "Время выполнение програмы: " << clock() / 1000.0;
    cin.get();

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < n; i++)
        delete[] C[i];
    delete[] C;

    return 0;
}
