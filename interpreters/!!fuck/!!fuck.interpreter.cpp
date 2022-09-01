#include <string>
#include <iostream>
#include <vector>

void fuck_interpreter(std::string tape)
{
    std::vector<int> cells(10);
    int cellIndex = 0;
    int exclamationCount = 0;
    char inputChar;
    std::string output = "";
    while (cellIndex < tape.length())
    {
        char op = tape.at(cellIndex);
        switch (op)
        {
        case '!':
        {
            exclamationCount++;
            break;
        }
        case '#':
        {
            switch (exclamationCount)
            {
            case 5:
                if (cellIndex == cells.size())
                {
                    cells.resize(cells.size() * 2);
                }
                cellIndex++;
                exclamationCount = 0;
                break;
            case 6:
                if (cellIndex == 0)
                {
                    cellIndex = cells.size() - 1;
                }
                cellIndex--;
                exclamationCount = 0;
                break;
            case 7:
                cells[cellIndex]++;
                exclamationCount = 0;
                break;
            case 8:
                cells[cellIndex]--;
                exclamationCount = 0;
                break;
            case 9:
                output += ((char)cells[cellIndex]) - '0';
                exclamationCount = 0;
                break;
            case 10:
                std::cin >> inputChar;
                output += inputChar - '0';
                exclamationCount = 0;
                break;
            case 11:
                if (cells[cellIndex] == 0)
                {
                    exclamationCount = 0;
                    cellIndex++;
                    while (exclamationCount != 12)
                    {
                        char loopingOp = cells.at(cellIndex);
                        if (loopingOp == '#')
                        {
                            exclamationCount = 0;
                        }
                        exclamationCount++;
                        cellIndex++;
                    }
                    break;
                }
                exclamationCount = 0;
                break;
            case 12:
                if (cells[cellIndex] != 0)
                {
                    exclamationCount = 0;
                    cellIndex--;
                    while (exclamationCount != 11)
                    {
                        char loopingOp = cells.at(cellIndex);
                        if (loopingOp == '#')
                        {
                            exclamationCount = 0;
                        }
                        exclamationCount++;
                        cellIndex--;
                    }
                }
                break;
            }
        }
        }
        cellIndex++;
    }
    std::cout << output << std::endl;
}

int main(void)
{
    fuck_interpreter("")
}