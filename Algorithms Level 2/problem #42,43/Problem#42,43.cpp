#include <iostream>
using namespace std;

void EnterNumber(string message, int& number)
{
    cout << message << endl;
    do
    {
        cin >> number;
        if (number > 100 || number < 0)
            cout << "Enter a number between 0 and 100" << endl;

    } while (number > 100 || number < 0);
}

int GenerateRandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillArray(int length, int arr[])
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = GenerateRandomNumber(1, 100);
    }
}

void PrintArray(int arr[], int length)
{
    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

void CountOddNumbers(int arr[], int length)
{
    int count = 0;
    int sum = 0;
    int oddNumbers[100];
    int oddIndex = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 != 0)
        {
            count++;
            sum += arr[i];
            oddNumbers[oddIndex++] = arr[i];
        }
    }

    cout << "Odd Numbers Array: ";
    PrintArray(oddNumbers, count);
    cout << "Count of Odd Numbers: " << count << endl;
    cout << "Sum of Odd Numbers: " << sum << endl;
}

void CountEvenNumbers(int arr[], int length)
{
    int count = 0;
    int sum = 0;
    int evenNumbers[100];
    int evenIndex = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
            sum += arr[i];
            evenNumbers[evenIndex++] = arr[i];
        }
    }

    cout << "Even Numbers Array: ";
    PrintArray(evenNumbers, count);
    cout << "Count of Even Numbers: " << count << endl;
    cout << "Sum of Even Numbers: " << sum << endl;
}

int main()
{
    int number, arr[100];
    EnterNumber("Enter the number of elements for the array:", number);
    FillArray(number, arr);
    PrintArray(arr, number);
    CountOddNumbers(arr, number);
    cout << endl << endl;
    CountEvenNumbers(arr, number);
}
