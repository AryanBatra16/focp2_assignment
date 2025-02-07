#include <iostream>
#include <string>
using namespace std;

int main()
{
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);
    cout << "You entered: " << inputString << endl;

    bool isPalindrome = true;
    int start = 0, end = inputString.length() - 1;

    while (start < end)
    {
        if (inputString[start] != inputString[end])
        {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome)
    {
        cout << "The entered string is a palindrome." << endl;
    }
    else
    {
        cout << "The entered string is not a palindrome." << endl;
    }

    int charCount[256] = {0};
    for (char character : inputString)
    {
        charCount[character]++;
    }

    cout << "Character frequencies in the string are as follows:" << endl;
    for (int i = 0; i < 256; i++)
    {
        if (charCount[i] > 0)
        {
            cout << "Character '" << char(i) << "' appears " << charCount[i] << " time(s)." << endl;
        }
    }

    cout << "Replacing vowels in the string with '*':" << endl;
    for (char &character : inputString)
    {
        if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' ||
            character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U')
        {
            character = '*';
        }
    }
    cout << "Modified string: " << inputString << endl;

    return 0;
}
