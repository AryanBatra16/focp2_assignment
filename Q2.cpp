#include <iostream>
using namespace std;

void inputArray(int arr[], int n)
{
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void reverseArray(int arr[], int n)
{
    cout << "Reversed array: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findSecondElements(int arr[], int n)
{
    int min = arr[0], second_min = arr[0];
    int max = arr[0], second_max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            second_min = min;
            min = arr[i];
        }
        else if (arr[i] < second_min || second_min == min)
        {
            second_min = arr[i];
        }

        if (arr[i] > max)
        {
            second_max = max;
            max = arr[i];
        }
        else if (arr[i] > second_max || second_max == max)
        {
            second_max = arr[i];
        }
    }

    cout << "Second minimum and second maximum: " << second_min << " " << second_max << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n];

    inputArray(arr, n);
    reverseArray(arr, n);
    findSecondElements(arr, n);

    return 0;
}
