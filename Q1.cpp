#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int nextPrime(int n)
{
    do
    {
        n++;
    } while (!isPrime(n));
    return n;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n))
    {
        cout << "Prime\n"
             << "Next Prime number: " << nextPrime(n) << endl;
    }
    else
    {
        cout << "Not Prime\n"
             << "The factors are: ";
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
