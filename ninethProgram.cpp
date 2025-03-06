#include <iostream>
using namespace std;

const int m = 5, n = 3;
void printMatrix(int[][3]);

int main()
{
    int matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter pos " << i + 1 << "," << j + 1 << " value" << endl;
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    printMatrix(matrix);
}

void printMatrix(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Value in pos" << i + 1 << "," << j + 2 << " is " << matrix[i][j] << '\n';
        }
        cout << endl;
    }
}