#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>

void brainfeed_interpreter(std::string tape)
{

    std::string punctuation = "!? .,><()/+-:;÷*\'\"";
    std::string lower = "abcdefghijklmnopqrstuvwxyz";
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = 0;
    int cells[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int cellsSize = 18;
    int cellsPointer = 0;
    int memoryVariable = 0;
    std::string output = "";
    int selectedCell = -1;
    while (index < tape.length())
    {
        char op = tape.at(index);
        switch (op)
        {
        case '>':
        {
            cellsPointer++;
            continue;
        }
        case '<':
        {
            cellsPointer--;
            continue;
        }
        case '+':
        {
            if (cells[cellsPointer] != 30)
            {
                cells[cellsPointer]++;
            }
            break;
        }
        case '-':
        {
            if (cells[cellsPointer] != 0)
            {
                cells[cellsPointer]--;
            }
            break;
        }
        case ',':
        {
            output += lower.at(cells[cellsPointer]);
            break;
        }
        case '?':
        {
            output += upper.at(cells[cellsPointer]);
            break;
        }
        case '!':
        {
            output += punctuation.at(cells[cellsPointer] % 18);
            break;
        }
        case '#':
        {
            cells[cellsPointer] = 0;
            break;
        }
        case '@':
        {
            int count = 0;
            for (int i = 0; i < cellsSize; i++)
            {
                if (cells[i] == 0)
                {
                    count++;
                }
            }
            output += std::to_string(count);
            break;
        }
        case '^':
        {
            int inputtedValue;
            std::cin >> inputtedValue;
            cells[cellsPointer] = inputtedValue;
            break;
        }
        case '/':
        {
            memoryVariable = cells[cellsPointer];
            break;
        }
        case '~':
        {
            memoryVariable = cells[cellsPointer];
            break;
        }
        case ':':
        {
            selectedCell = 0;
            break;
        }
        case ';':
        {
            selectedCell = cellsSize - 1;
            break;
        }
        case '$':
        {
            memoryVariable = selectedCell != -1 ? selectedCell + 1 : -1;
            break;
        }
        case '%':
        {
            if (selectedCell != -1)
            {
                output += selectedCell == (cellsSize - 1) ? std::to_string(cellsSize) : "1";
            }
            break;
        }
        case '&':
        {
            int randomIndex = rand() % cellsSize;
            selectedCell = randomIndex;
            break;
        }
        }
        index++;
    }
    std::cout << output << std::endl;
}

int main(void)
{
    brainfeed_interpreter("+++++++?---,+++++++,,+++,#++++!--!++++++++++++++++++++?--------,+++,------,#+++,#!");
}