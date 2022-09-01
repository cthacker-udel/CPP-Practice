#include <string>
#include <stack>
#include <vector>
#include <iostream>

std::string random_symbol_interpreter(std::string tape)
{
    int index = 0;
    int top = 0;
    std::stack<int> theStack;
    std::string output = "";
    while (index < tape.length())
    {
        char op = tape.at(index);
        switch (op)
        {
        case '!':
        {
            theStack.push(theStack.top());
            break;
        }
        case '@':
        {
            top = theStack.top();
            theStack.pop();
            output += ((char)top);
            break;
        }
        case '#':
        {
            top = theStack.top();
            theStack.pop();
            output += (top - '0');
            break;
        }
        case '$':
        {
            const int top = theStack.top();
            theStack.pop();
            int belowTop;
            if (theStack.size() == 0)
            {
                belowTop = theStack.top();
                theStack.pop();
            }
            else
            {
                belowTop = 0;
            }
            theStack.push(top);
            theStack.push(belowTop);
            break;
        }
        case '%':
        {
            std::vector<int> stackList;
            for (int i = 0; i < theStack.size(); i++)
            {
                stackList.push_back(theStack.top());
                theStack.pop();
            }
            for (int i = 0; i < stackList.size(); i++)
            {
                theStack.push(stackList[i]);
            }
            break;
        }
        case '^':
        {
            const int top = theStack.top();
            theStack.pop();
            theStack.push(top + 1);
            break;
        }
        case '&':
        {
            const int a = theStack.top();
            int athElement;
            theStack.pop();
            std::vector<int> stackList;
            for (int i = 0; i < theStack.size(); i++)
            {
                const int stackTop = theStack.top();
                stackList.push_back(stackTop);
            }
            for (int i = 0, j = stackList.size() - 1; j >= 0; j--, i++)
            {
                if (i == a)
                {
                    athElement = stackList[i];
                    break;
                }
            }
            for (int i = stackList.size() - 1; i >= 0; i--)
            {
                theStack.push(stackList[i]);
            }
            theStack.push(athElement);
            break;
        }
        case '*':
        {
            char input;
            std::cin >> input;
            theStack.push((int)input);
            break;
        }
        case '(':
        {
            if (theStack.top() == 0)
            {
                for (int i = index;; i++)
                {
                    char lParenOp = tape.at(i);
                    if (lParenOp == ')')
                    {
                        index = i;
                        break;
                    }
                }
            }
            break;
        }
        case ')':
        {
            if (theStack.top() != 0)
            {
                for (int i = index;; i--)
                {
                    char lParenOp = tape.at(i);
                    if (lParenOp == '(')
                    {
                        index = i;
                        break;
                    }
                }
            }
            break;
        }
        case '_':
        {
            const int top = theStack.top();
            theStack.pop();
            theStack.push(top - 1);
            break;
        }
        case '+':
        {
            const int top = theStack.top();
            theStack.pop();
            theStack.push(top + 1);
            break;
        }
        }
        index++;
    }
    return output;
}

int main(void)
{
    std::cout << random_symbol_interpreter(" ^dlroW ,olleH(@)") << std::endl;
}