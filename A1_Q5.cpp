#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int matrix[n][n];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter element for matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int rotated[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }

    cout << "The rotated matrix (90 degrees clockwise) is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
