#include "stringlib.h"

namespace StringLib
{
    vector<string> SplitString(string Word, string delim=" ")
    {
        vector<string> vString;
        short pos = 0;
        string sWord;
        while ((pos = Word.find(delim)) != std::string::npos)
        {
            sWord = Word.substr(0, pos);
            if (sWord != "")
                vString.push_back(sWord);
            Word.erase(0, pos + delim.length());
        }
        if (Word != "")
            vString.push_back(Word);
        return vString;
    }

    string ReadString(string Message)
    {
        string Str;
        cout << Message << endl;
        getline(cin, Str);
        return Str;
    }
    void FibonacciSeriesOfNumber(short Number, int fibo[])
    {
        short sum = 1;
        fibo[0] = fibo[1] = 1;
        for (int i = 2; i < Number; i++)
        {
            fibo[i] = fibo[i - 2] + fibo[i - 1];
        }
    }
    void PrintArr(int arr[3], short length)
    {
        for (int i = 0; i < length; i++)
        {
            printf(" %*d  ", 6, arr[i]);
        }
        cout << endl;
    }
    void FibonacciSeriesOfNumberRecursive(short Number, short prev1, short prev2)
    {
        int fibNumber = 0;
        if (Number > 0)
        {
            fibNumber = prev1 + prev2;
            prev2 = prev1;
            prev1 = fibNumber;
            cout << fibNumber << "    ";
            FibonacciSeriesOfNumberRecursive(Number - 1, prev1, prev2);
        }
    }

    void PrintFirstLiterInString(string Word)
    {
        cout << "First Leter Of this string : " << endl;
        bool IsFirstLetter = true;
        for (int i = 0; i < Word.length(); i++)
        {
            if (Word[i] != ' ' && IsFirstLetter)
                cout << Word[i] << endl;
            IsFirstLetter = (Word[i] == ' ' ? true : false);
        }
    }

    string UpperFirstLetterOfEachWord(string Word)
    {
        bool IsFirstLetter = true;
        for (int i = 0; i < Word.length(); i++)
        {
            if (Word[i] != ' ' && IsFirstLetter)
                Word[i] = toupper(Word[i]);
            IsFirstLetter = (Word[i] == ' ' ? true : false);
        }
        return Word;
    }
    string LowerFirstLetterOfEachWord(string Word)
    {
        bool IsFirstLetter = true;
        for (int i = 0; i < Word.length(); i++)
        {
            if (Word[i] != ' ' && IsFirstLetter)
                Word[i] = tolower(Word[i]);
            IsFirstLetter = (Word[i] == ' ' ? true : false);
        }
        return Word;
    }
    string UpperAllString(string Word)
    {
        for (int i = 0; i < Word.length(); i++)
        {
            Word[i] = toupper(Word[i]);
        }
        return Word;
    }
    string LowerAllString(string Word)
    {
        for (int i = 0; i < Word.length(); i++)
        {
            Word[i] = tolower(Word[i]);
        }
        return Word;
    }
    char ReadChar(string message)
    {
        char C;
        cout << message << endl;
        cin >> C;
        return C;
    }
    char InvertLetterCase(char C)
    {
        return islower(C) ? toupper(C) : tolower(C);
    }
    string InvertAllStringLettersCase(string Word)
    {
        for (int i = 0; i < Word.length(); i++)
        {
            Word[i] = InvertLetterCase(Word[i]);
        }
        return Word;
    }

    short CountSmallLetters(string Word)
    {
        short Counter = 0;
        for (int i = 0; i < Word.length(); i++)
        {
            if (islower(Word[i]))
                Counter++;
        }
        return Counter;
    }

    short CountCapitalLetters(string Word)
    {
        short Counter = 0;
        for (int i = 0; i < Word.length(); i++)
        {
            if (isupper(Word[i]))
                Counter++;
        }
        return Counter;
    }
    short CountLetter(string Word, char C, bool MatchCase = true)
    {
        short Counter = 0;
        if (!MatchCase)
            islower(C) ? Word = LowerAllString(Word) : Word = UpperAllString(Word);
        for (int i = 0; i < Word.length(); i++)
        {
            if (Word[i] == C)
                Counter++;
        }
        return Counter;
    }
    const char VowelChars[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    bool IsVowelChar(char C, bool Slow)
    {
        for (int i = 0; i < 10; i++)
        {
            if (VowelChars[i] == C)
                return true;
        }
        return false;
    }
    bool IsVowelChar(char C)
    {
        C = tolower(C);
        return (C == 'a' || C == 'e' || C == 'u' || C == 'i' || C == 'O');
    }
    short CountVowels(string Word)
    {
        short Counter = 0;
        for (int i = 0; i < Word.length(); i++)
        {
            if (IsVowelChar(Word[i]))
                Counter++;
        }
        return Counter;
    }
    void PrintAllVowelsInString(string Word)
    {
        string VowelsChares = " ";
        for (int i = 0; i < Word.length(); i++)
        {
            if (IsVowelChar(Word[i]))
            {
                cout << Word[i] << "    ";
            }
        }
        cout << endl;
    }

    void PrintEachWordInString(string Word)
    {
        string delim = " ";
        cout << "Your String Words are : " << endl;
        short pos = 0;
        string sWord;
        while ((pos = Word.find(delim)) != std::string::npos)
        {
            sWord = Word.substr(0, pos);
            if (sWord != "")
                cout << sWord << endl;
            Word.erase(0, pos + delim.length());
        }
        if (Word != "")
            cout << Word << endl;
    }
    short CountWords(string Word)
    {
        short Counter = 0;
        string delim = " ";
        short pos = 0;
        string sWord;
        while ((pos = Word.find(delim)) != std::string::npos)
        {
            sWord = Word.substr(0, pos);
            if (sWord != "")
                Counter++;
            Word.erase(0, pos + delim.length());
        }
        if (Word != "")
            Counter++;
        return Counter;
    }
    void PrintVector(vector<string> vString)
    {
        for (string &S : vString)
            cout << S << endl;
    }
    string TrimLeft(string Word)
    {
        for (int i = 0; i < Word.length(); i++)
        {
            if (Word[i] != ' ')
                return Word.substr(i);
        }
        return "";
    }
    string TrimRight(string Word)
    {
        for (int i = Word.length() - 1; i >= 0; i--)
        {
            if (Word[i] != ' ')
                return Word.substr(0, i + 1);
        }
        return "";
    }
    string Trim(string Word)
    {
        return TrimRight(TrimLeft(Word));
    }
    string JoinString(vector<string> vString, string delim = " ")
    {
        if (vString.empty())
            return "";
        string Word;
        for (string &S : vString)
        {
            Word += (S + delim);
        }
        return Word.substr(0, Word.length() - delim.length());
    }

    string JoinString(string arrString[], short length, string delim = " ")
    {
        string Word;
        for (int i = 0; i < length; i++)
            Word += (arrString[i] + delim);
        return Word.substr(0, Word.length() - delim.length());
    }
    string RevereseString(string Word)
    {
        vector<string> vString;
        string RevereseWord;
        vString = SplitString(Word);

        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin())
        {
            --iter;
            RevereseWord += (*iter + " ");
        }

        return RevereseWord;
    }
    string ReplaceWordInString(string Str, string StringToReplace, string ReplaceTo, bool MatchCase = true)
    {
        vector<string> vString;
        vString = SplitString(Str);
        string target = MatchCase ? StringToReplace : LowerAllString(StringToReplace);
        for (string &s : vString)
        {
            string current = MatchCase ? s : LowerAllString(s);
            if (current == target)
            {
                s = ReplaceTo;
            }
        }
        return JoinString(vString);
    }
    string ReplaceWordInStringUsingBuiltInFunction(string Str, string StringToReplace, string ReplaceTo)
    {
        short Pos = Str.find(StringToReplace);
        while (Pos != std::string::npos)
        {
            Str = Str.replace(Pos, StringToReplace.length(), ReplaceTo);
            Pos = Str.find(StringToReplace);
        }
        return Str;
    }

    string RemoveAllOunctuationsFromString(string Str)
    {
        string S2 = "";
        for (int i = 0; i < Str.length(); i++)
        {
            if (!ispunct(Str[i]))
            {
                S2 += Str[i];
            }
        }
        return S2;
    }
    bool AreStringsEqual(string S1, string S2) {
        S1 = LowerAllString(S1);
        S2 = LowerAllString(S2);
        return S1 == S2;
    }
}