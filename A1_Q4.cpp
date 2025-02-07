#include <iostream>
using namespace std;

void printSpiral(int n)
{
    int matrix[n][n];
    int num = 1;

    for (int layer = 0; layer < (n + 1) / 2; layer++)
    {

        for (int i = layer; i < n - layer; i++)
        {
            matrix[layer][i] = num++;
        }

        for (int i = layer + 1; i < n - layer; i++)
        {
            matrix[i][n - layer - 1] = num++;
        }

        for (int i = n - layer - 2; i >= layer; i--)
        {
            matrix[n - layer - 1][i] = num++;
        }

        for (int i = n - layer - 2; i > layer; i--)
        {
            matrix[i][layer] = num++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    printSpiral(n);
    return 0;
}
