#include <string>
#include <stdlib.h>
using namespace std;

string balancedNum(unsigned long long int number)
{
  if (number < 100)
  {
    return "Balanced";
  }
  string convertedNumber = to_string(number);
  const int middle = convertedNumber.length() / 2;
  if (convertedNumber.length() % 2 == 0)
  {
    int secondMiddle = middle - 1;
    string leftPart = convertedNumber.substr(0, convertedNumber.length() - (middle + 1));
    string rightPart = convertedNumber.substr(middle + 1);
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < leftPart.length(); i++)
    {
      leftSum += leftPart.at(i) - '0';
      if (i < rightPart.length())
      {
        rightSum += rightPart.at(i) - '0';
      }
    }
    return leftSum == rightSum ? "Balanced" : "Not Balanced";
  }
  else
  {
    string leftPart = convertedNumber.substr(0, convertedNumber.length() - (middle + 1));
    string rightPart = convertedNumber.substr(middle + 1);
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < leftPart.length(); i++)
    {
      leftSum += leftPart[i] - '0';
      if (i < rightPart.length())
      {
        rightSum += rightPart[i] - '0';
      }
    }
    return leftSum == rightSum ? "Balanced" : "Not Balanced";
  }
}

int main(void)
{

  balancedNum(432);
}