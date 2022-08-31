#include <algorithm>
#include <string>
#include <ctype.h>
#include <iostream>

using namespace std;

string alphabet_position(const string &text)
{

    const std::string lowerAlpha = "abcdefghijklmnopqrstuvwxyz";
    const std::string upperAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string replacedText = "";

    for (int i = 0; i < text.length(); i++)
    {
        char letter = text.at(i);
        if (islower(letter) && lowerAlpha.find(letter) != string::npos)
        {
            if (i != text.length() - 1)
            {
                replacedText += to_string(((int)lowerAlpha.find(letter)) + 1) + " ";
            }
            else
            {
                replacedText += to_string(((int)lowerAlpha.find(letter)) + 1);
            }
        }
        else if (isupper(letter) && upperAlpha.find(letter) != string::npos)
        {
            if (i != text.length() - 1)
            {
                replacedText += to_string(((int)upperAlpha.find(letter)) + 1) + " ";
            }
            else
            {
                replacedText += to_string(((int)upperAlpha.find(letter)) + 1);
            }
        }
    }
    replacedText = replacedText.at(replacedText.length() - 1) == ' ' ? replacedText.substr(0, replacedText.length() - 1) : replacedText;
    return replacedText;
}

int main()
{
    cout << "IN MAIN" << endl;
    cout << alphabet_position("The narwhal bacons at midnight.") << endl;
}