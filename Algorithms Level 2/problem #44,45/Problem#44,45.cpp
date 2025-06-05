#include <iostream>
using namespace std;

void ReadNumber(string message, int& number)
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
    int random;
    do
    {
        random = rand() % (to - from + 1) + from;

    } while (random == 0);
    return random;
}

void FillArray(int length, int arr[])
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = GenerateRandomNumber(-100, 100);
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

void CountPositiveNumbers(int arr[], int length)
{
    int count = 0;
    int positiveIndex = 0;
    int positives[100];
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
        {
            count++;
            positives[positiveIndex++] = arr[i];
            sum += arr[i];
        }
    }

    cout << "Positive Numbers: ";
    PrintArray(positives, positiveIndex);
    cout << endl;
    cout << "Count of Positive Numbers: " << count << endl;
    cout << "Sum of Positive Numbers: " << sum << endl;
}

void CountNegativeNumbers(int arr[], int length)
{
    int count = 0;
    int negativeIndex = 0;
    int negatives[100];
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
        {
            count++;
            negatives[negativeIndex++] = arr[i];
            sum += arr[i];
        }
    }

    cout << "Negative Numbers: ";
    PrintArray(negatives, negativeIndex);
    cout << endl;
    cout << "Count of Negative Numbers: " << count << endl;
    cout << "Sum of Negative Numbers: " << sum << endl;
}

int main()
{
    int length;
    int arr[100];

    ReadNumber("Enter desired array length:", length);
    FillArray(length, arr);
    PrintArray(arr, length);
    CountPositiveNumbers(arr, length);
    CountNegativeNumbers(arr, length);
}
