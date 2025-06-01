#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

namespace StringLib {
    vector<string> SplitString(string Word, string delim);
    string ReadString(string Message);
    void FibonacciSeriesOfNumber(short Number, int fibo[]);
    void PrintArr(int arr[3], short length);
    void FibonacciSeriesOfNumberRecursive(short Number, short prev1, short prev2);
    void PrintFirstLiterInString(string Word);
    string UpperFirstLetterOfEachWord(string Word);
    string LowerFirstLetterOfEachWord(string Word);
    string UpperAllString(string Word);
    string LowerAllString(string Word);
    char ReadChar(string message);
    char InvertLetterCase(char C);
    string InvertAllStringLettersCase(string Word);
    short CountSmallLetters(string Word);
    short CountCapitalLetters(string Word);
    short CountLetter(string Word, char C, bool MatchCase = true);
    bool IsVowelChar(char C, bool Slow); // Overloaded version
    bool IsVowelChar(char C);            // Overloaded version
    short CountVowels(string Word);
    void PrintAllVowelsInString(string Word);
    void PrintEachWordInString(string Word);
    short CountWords(string Word);
    void PrintVector(vector<string> vString);
    string TrimLeft(string Word);
    string TrimRight(string Word);
    string Trim(string Word);
    string JoinString(vector<string> vString, string delim);
    string JoinString(string arrString[], short length, string delim);
    string RevereseString(string Word);
    string ReplaceWordInString(string Str, string StringToReplace, string ReplaceTo, bool MatchCase = true);
    string ReplaceWordInStringUsingBuiltInFunction(string Str, string StringToReplace, string ReplaceTo);
    string RemoveAllOunctuationsFromString(string Str);

    extern const char VowelChars[10];
}

#endif // STRINGLIB_H
