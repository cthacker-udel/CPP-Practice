#include <string>
#include <bitset>
#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <set>
#include <list>
#include <map>
#include <sstream>
#include <array>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <forward_list>
#include <initializer_list>
#include <stack>
using namespace std::chrono;
using namespace std;

int countBits(unsigned long long);
long findMissing(vector<long>);
string stockSummary(vector<string> &a, vector<string> &b);
void func7(string, int[], int, int, int,bool);

vector<int> sortArray(vector<int> array) {

    bool loopVar = false;
    while (!loopVar) {

        for (int i = 0; i < array.size() - 1; i++) {
            int value = array[i];
            int forwardValue = array[i + 1];
        }

    }
    return array;

}

int countBits(unsigned long long n) {
    unsigned int count = 0;
    while (n >= 1) {
        int remainder = n % 2;
        count += remainder;
        n = n / 2;
    }
    return count;
}

long findMissing(vector<long> theList) {
    
    for (int i = 0; i < (int)theList.size(); i++) {
        cout << theList[i];
    }
    cout << endl;
    set<long> diff;
    set<long> theListSet;
    map<long, long> diffCount;

    for(int i = 0; i < theList.size(); i++) {
        theListSet.insert(theList[i]);
    }

    int commonDiff = abs(theList[theList.size() - 2] - theList[theList.size() - 1]);

    int count = 0;
    for (set<long>::iterator i = theListSet.begin(); i != theListSet.end(); i++) {
        long num = *i;
        if (count == theListSet.size() - 1) {
            break;
        } else {
            if (theListSet.count(num + commonDiff) == 0) {
                return num + commonDiff;
            }
        }
    }
    return -1;

};

string stockSummary(vector<string> &listOfArt, vector<string> &categories) {

    for (int i = 0; i < categories.size(); i++) {
        cout << "Value : " << categories[i] << endl;
    }

    map<string, int> amounts;
    for (int i = 0; i < categories.size(); i++) {
        for (int j = 0; j < listOfArt.size(); j++) {
            string artPiece = listOfArt[j];
            if (artPiece.substr(0, 1) == categories[i]) {
                int amt;
                std::stringstream string_amt(artPiece.substr(artPiece.find(" ") + 1, string::npos));
                string_amt >> amt;
                if (amounts.count(categories[i]) > 0) {
                    // in map
                    amounts[categories[i]] += amt;
                } else {
                    amounts[categories[i]] = amt;
                }
            }
        }
        if (amounts.count(categories[i]) == 0) {
            amounts[categories[i]] = 0;
        }
    }
    
    string s;
    for (int i = 0, count = 0; i < categories.size(); i++, count++) {
        if (count == (categories.size() - 1)) {
            // do not add - on end
            s += "(" + categories[i] + " : " + to_string(amounts[categories[i]]) + ")";
        } else {
            s += "(" + categories[i] + " : " + to_string(amounts[categories[i]]) + ") - ";
        }
    }
    return s;
    
}

void func7(string s, int arr[], int len, int i1, int i2,bool do_pr) {

    //{25,45,48,12,10,16,50,9,32,17,19,36,27,33,30,24,20,28,7,6,18,14,37,39,38,42,44};
    // 25 45 48 12 10 16 50 9 32 17 19 36 42 27 33 30 24 20 28 7 6 18 14 37 39 38 44 
	cout << "passing " << s << " and " << i1 << " and " << i2 << endl;

    if (i1 > i2) {
        int tmp = i1;
        i1 = i2;
        i2 = tmp;
    }

    while (i1 < i2) {
        int tmp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = tmp;
        i1++;
    }

	if(do_pr) {
		for(int i = 0; i < len; i++) {
			cout << s[arr[i]];
		}

	}
}

int compareChars(const void *char1, const void *char2) {
    char letter1 = *((char *)char1);
    char letter2 = *((char *)char2);
    if (letter1 > letter2) {
        return -1;
    } else if (letter2 > letter1) {
        return 1;
    } else {
        return 0;
    }
}


char * sortTheInnerContent(const char* words, int length) {

    vector<string> splitString;
    string emptyString;
    for (int i = 0; i < length + 1; i++) {

        char theLetter = words[i];
        if (theLetter == ' ') {
            // found word
            splitString.push_back(emptyString);
            emptyString = "";
        } else {
            emptyString += theLetter;
        }
    }
    splitString.push_back(emptyString);
    for (int i = 0; i < (int)splitString.size(); i++) {
        string vec_string = splitString.at(i);
        int strLength = 0;
        for (int y = 0; vec_string[y] != '\0'; y++) {
            strLength++;
        }
        char theString[strLength - 1];
        for (int j = 0, x = 1; x < (strLength - 1); x++, j++) {
            theString[j] = splitString[i][x];
        }
        qsort(theString, strLength - 2, sizeof(char), compareChars);
        string sortedString = "";
        sortedString += splitString[i][0];
        for (int j = 0; j < strLength - 2; j++) {
            sortedString += theString[j];
        }
        sortedString += splitString[i][strLength - 1];
        cout << "The string = " << sortedString << endl;
        splitString[i] = sortedString;
    }
    string returnString = "";
    for (int i = 0; i < splitString.size(); i++) {
        if (i == splitString.size() - 1) {
            returnString += splitString[i];
        } else {
            returnString += splitString[i] + " ";
        }
    }
    char *the_string = (char *)malloc(sizeof(char) * returnString.length());
    strcpy(the_string, returnString.c_str());
    return the_string;


}

vector<string> dup(vector<string> strArray) {

    for (int i = 0; i < strArray.size(); i++) {
        string theString = strArray[i];
        string newString = "";
        for (int j = 0; j < theString.length() - 1; j += 2) {
            char letter1 = theString[j];
            char letter2 = theString[j + 1];
            if (letter1 == letter2 && newString[newString.length() - 1] != letter1) {
                newString += letter1;
                continue;
            } if (letter1 != letter2 && newString[newString.length() - 1] != letter1) {
                newString += letter1;
            } if (letter2 != letter1 && newString[newString.length() - 1] != letter2) {
                newString += letter2;
            }
        }
        if (newString != "" && theString[theString.length() - 1] != newString[newString.length() - 1]) {
            newString += theString[theString.length() - 1];
        }
        strArray[i] = newString;
    }
    return strArray;


}

bool pairCompare(pair<int, int>&a, pair<int, int>&b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solve(const vector<int> &vec) {

    map<int, int> frequencies;
    for (int i = 0; i < (int)vec.size(); i++) {
        int elem = vec[i];
        if (frequencies.count(elem) > 0) {
            // contains key
            frequencies[elem] = frequencies[elem] + 1;
        } else {
            frequencies[elem] = 1;
        }
    }
    vector<pair<int, int>> pairs;
    for (pair<int, int> eachpair: frequencies) {
        pairs.push_back(eachpair);
    }
    sort(pairs.begin(), pairs.end(), pairCompare);
    vector<int> sortedPairs;
    for (pair<int, int> eachpair: pairs) {
        int amount = eachpair.second;
        for (int i = 0; i < amount; i++) {
            sortedPairs.push_back(eachpair.first);
        }
    }
    return sortedPairs;;

}

bool isPrime(long long number) {

    if (number <= 3) {
        return true;
    } else if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0) {
        return false;
    } else {
        for (long long i = 4; i < sqrt(number) + 1; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

}

long long sumProperDivisor(long long n) {

    long long origN = n;
    long long total = 1;
    long long start = 2;
    map<int, int> factors;
    while (n > 1) {
        if (n % start == 0) {
            while (n % start == 0) {
                factors[start] += 1;
                n /= start;
            }
            start = 2;
            continue;
        }
        start++;
    }
    long subtotal = 1;
    long power = 1;
    for (pair<int,int> eachpair: factors) {
        for (int i = 0; i < eachpair.second; i++) {
            subtotal += pow(eachpair.first, power++);
        }
        total *= subtotal;
        subtotal = 1;
        power = 1;
    }
    total -= origN;

    return total;

}

string buddy(long long start, long long limit) {

    for (long long i = start; i < limit; i++) {
        long long sum_i = sumProperDivisor(i);
        long long sum_i_result = sumProperDivisor(sum_i - 1);
        if ((sum_i_result - 1) == i) {
            return "(" + to_string(i) + " " + to_string(sum_i - 1) + ")";
        }
    }
    return "Nothing";

}

int isThreeFive(int num) {
    return num % 3 == 0 && num % 5 == 0;
}

int solution(int number) {
    cout << "testing " << number << endl;
    if (number < 0) {
        return 0;
    }
        // 3 6 9 12 15 18
    // 5 10
    set<int> additions;
    int threeNum = 3;
    int fiveNum = 5;
    int total = 0;
    while (threeNum < number || fiveNum < number) {
        if (threeNum < number) {
            additions.insert(threeNum);
            threeNum += 3;
        }
        if (fiveNum < number) {
            additions.insert(fiveNum);
            fiveNum += 5;
        }
    }
    for (set<int>::iterator it = additions.begin(); it != additions.end(); ++it) {
        total += *it;
    }
    return total;

}

void printRandValues() {

    int min = 1;
    int max = 20;

    for (int i = 0; i < 1000000; i++) {
        int randNumber = (rand() % (max - 1)) + 1;
        if (randNumber == 0 || randNumber == 20) {
            cout << "found rand with " << randNumber << endl;
        }
    }
}

vector<vector<int>> create_spiral(int n) {

    int arr[n][n];
    const char directions[] = {'r', 'd', 'l', 'u'};
    int currDirection = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = -1;
        }
    }
    int row = 0;
    int col = 0;
    int currNumber = 1;
    int neg1Count = n * n;
    while (neg1Count > 0) {

        char theCurrDirection = directions[currDirection];
        if (theCurrDirection == 'r') {
            if (col == (n - 1)) {
                arr[row++][col] = currNumber++;
                currDirection++;
                neg1Count--;
                continue;
            } else {
                if (arr[row][col + 1] != -1) {
                    arr[row++][col] = currNumber++;
                    currDirection++;
                    neg1Count--;
                    continue;
                } else {
                    arr[row][col++] = currNumber++;
                    neg1Count--;
                }
            }
        } else if (theCurrDirection == 'd') {
            if (row == n - 1) {
                arr[row][col--] = currNumber++;
                currDirection++;
                neg1Count--;
                continue;
            } else {
                if (arr[row + 1][col] != -1) {
                    arr[row][col--] = currNumber++;
                    currDirection++;
                    neg1Count--;
                    continue;
                } else {
                    arr[row++][col] = currNumber++;
                    neg1Count--;
                }
            }
        } else if (theCurrDirection == 'l') {
            if (col == 0) {
                arr[row--][col] = currNumber++;
                currDirection++;
                neg1Count--;
                continue;
            } else {
                if (arr[row][col - 1] != -1) {
                    arr[row--][col] = currNumber++;
                    currDirection++;
                    neg1Count--;
                    continue;
                } else {
                    arr[row][col--] = currNumber++;
                    neg1Count--;
                }
            }
        } else {
            if (row == 0) {
                arr[row][col++] = currNumber++;
                currDirection = 0;
                neg1Count--;
                continue;
            } else {
                if (arr[row - 1][col] != -1) {
                    arr[row][col++] = currNumber++;
                    currDirection = 0;
                    neg1Count--;
                    continue;
                } else {
                    arr[row--][col] = currNumber++;
                    neg1Count--;
                }
            }
        }
    }
    
    vector<vector<int>> nested_spiral;
    vector<int> subsprial;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            subsprial.push_back(arr[i][j]);
        }
        nested_spiral.push_back(subsprial);
        subsprial.clear();
    }
    return nested_spiral;

}

string grid2(int n) {

    string result = "";
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int index = 0;
    int baseIndex = 0;
    for (int i = 0; i < n; i++) {
        index = baseIndex;
        for (int times = 0; times < n; times++) {
            result += alpha[index++];
            if (times < (n - 1)) {
                result += " ";
            }
            if (index == 26) {
                index = 0;
            }
        }
        if (i < n - 1) {
            result += "\n";
        }
        baseIndex++;
        if (baseIndex == 26) {
            baseIndex = 0;
        }
    }
    cout << result << endl;
    return result;


}

string grid(int n) {

    
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    if (n <= 0) {
        return "";
    } else if (n == 1) {
        return string(1,alpha[0]);
    }

    char grid[n][n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[j][i] = alpha[index++];
            if (index == 26) {
                index = 0;
            }
        }
    }

    int col = 0;
    for (int i = 0; i < n; i++) {
        char starter = grid[i][col];
        int n_index = alpha.find(starter);
        if (n_index == 25) {
            n_index = 0;
        } else {
            n_index++;
        }
        for (int j = 1; j < n; j++) {
            grid[i][j] = alpha[n_index];
            n_index += 1;
            if (n_index == 26) {
                n_index = 0;
            }
        }
    }

    string result = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //cout << grid[i][j] << " ";
            if (j == (n - 1)) {
                result += grid[i][j];
                if (i != (n - 1)) {
                    result += "\n";
                }
            } else {
                result += grid[i][j];
                result +=  " ";
            }
        }
        //cout << endl;

    }
    return result;

}

vector<int> remove_values(vector<int> integers, vector<int> values) {

    vector<int> newArray;
    string numbers = "";
    for (int i = 0; i < values.size(); i++) {
        numbers += to_string(values[i]);
    }
    for (int i = 0; i < integers.size(); i++) {
        string theDigit = to_string(integers[i]);
        if (numbers.find(theDigit) == string::npos) {
            newArray.push_back(integers[i]);
        }
    }
    return newArray;

}

string phone(const string& orgdr, string num) {

    string token = "";
    string dirCopy = orgdr.substr(0);
    while (dirCopy.find('\n') != string::npos) {
        int index = dirCopy.find('\n');
        string theSub = dirCopy.substr(0, dirCopy.find('\n'));
        cout << "the sub = " << theSub << endl;
        bool foundPhone = false;
        bool foundName = false;
        bool foundAddress = false;
        string validCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string theName = "";
        string theAddress = "";
        string thePhone = "";
        for (int i = 0; i < theSub.length(); i++) {
            char theLetter = theSub[i];
            if (foundPhone && theLetter != ' ') {
                thePhone += theLetter;
            } else if (foundName && theLetter != '>') {
                theName += theLetter;
            } else if (foundName && theLetter == '>') {
                foundName = false;
            } else if (foundPhone && theLetter == ' ') {
                foundPhone = false;
            } else if (!foundPhone && !foundName && foundAddress) {
                theAddress += theLetter;
            } else if (theLetter == '+') {
                foundPhone = true;
            } else if (theLetter == '<') {
                foundName = true;
            } else if (validCharacters.find(theLetter) != string::npos) {
                foundAddress = true;
            } else {
                continue;
            }
        }
        cout << "the name = " << theName << " and the address = " << theAddress << " and the phone == " << thePhone << endl;
    }
    return "";
}

bool isNumber(string theCommand) {

    try {
        int result = stoi(theCommand);
        return true;
    } catch (...) {
        return false;
    }
    return true;

}

void print_map_keys(unordered_map<string, int> theMap) {

    cout << "themap contains = " << endl;
    for (auto it = theMap.begin(); it != theMap.end(); ++it) {
        cout << " " << it->first << " : " << it->second << endl; 
    }

}


unordered_map<string, int> assembler(const vector<string>& program) {

    unordered_map<string, int> the_registers;

    stringstream ss;
    string eachcommand;
    string _register;
    int i = 0;
    while (i < (int)program.size()) {
        int index = 0;
        string command = program[i];
        cout << "the command = [" << command << "]" << endl;
        if (command.find("mov") != string::npos) {
            // found mov
            ss = stringstream(command);
            while (ss >> eachcommand) {
                if (eachcommand == "mov") {
                    index++;
                    continue; 
                } else {
                    if (index == 1) {
                        // register
                        if (the_registers.count(eachcommand) == 0) {
                            the_registers[eachcommand] = 0;
                        }
                        _register = eachcommand;
                        index++;
                    } else {
                        // value to move into it
                        the_registers[_register] = isNumber(eachcommand) ? stoi(eachcommand) : the_registers[eachcommand];
                    }
                }
            }
            i++;
        } else if (command.find("inc") != string::npos) {
            // found inc
            ss = stringstream(command);
            while (ss >> eachcommand) {
                if (eachcommand == "inc") {
                    index++;
                    continue;
                } else {
                    if (the_registers.count(eachcommand) == 0) {
                        the_registers[eachcommand] = 1;
                    } else {
                        the_registers[eachcommand] = the_registers[eachcommand] + 1;
                    }
                }
            }
            i++;
        } else if (command.find("dec") != string::npos) {
            // found dec
            ss = stringstream(command);
            while (ss >> eachcommand) {
                if (eachcommand == "dec") {
                    index++;
                    continue;
                } else {
                    if (the_registers.count(eachcommand) == 0) {
                        the_registers[eachcommand] = 0;
                    } else {
                        the_registers[eachcommand] = the_registers[eachcommand] - 1;
                    }
                }
            }
            i++;
        } else if (command.find("jnz") != string::npos) {
            // found jnz
            ss = stringstream(command);
            string the_jnz_reg;
            int amt_jump;
            bool is_number = false;
            int is_number_reg = 0;
            while (ss >> eachcommand) {
                if (eachcommand == "jnz") {
                    index++;
                    continue;
                } else {
                    if (index == 1) {
                        if (isNumber(eachcommand)) {
                            // is a number
                            is_number = true;
                            is_number_reg = stoi(eachcommand);
                        } else {
                            the_jnz_reg = eachcommand;
                        }
                        index++;
                    } else {
                        amt_jump = stoi(eachcommand);
                    }
                }
            }
            if (!is_number && the_registers[the_jnz_reg] != 0) {
                i += amt_jump;
            } else if (is_number && is_number_reg == 0) {
                i += amt_jump;
            } else {
                i++;
            }
        }
    }

    return the_registers;

}

int maxTotal = 0;
mutex maxTotalMutex;

void printIntVector(vector<int> values) {
    for (int i = 0; i < values.size(); i++) {
        cout << "values[" << i << "] = " << values[i] << ", ";
    }
    cout << endl;
}

void calcMax(vector<int> values, int startingIndex) {
    int total = 0;
    vector<int> valuesCopy(values);
    vector<int> adder;
    for (int i = startingIndex; i < valuesCopy.size() - 3;) {
        int value1 = valuesCopy[i];
        int value2 = valuesCopy[i + 1];
        int value3 = valuesCopy[i + 2];
        maxTotalMutex.lock();
        cout << "value1 = " << value1 << " and value2 = " << value2 << " and value3 = " << value3 << " and total = " << total << endl;
        maxTotalMutex.unlock();
        if (value1 + value2 + value3 <= 0) {
            i += 3;
        } else if (max(max(value1, value2), value3) == value1) {

            total += value1;
            adder.push_back(value1);
            i += 2;
        } else if (max(max(value1, value2), value3) == value2) {

            total += value2;
            adder.push_back(value2);
            i++;
        } else {

            total += value3;
            adder.push_back(value3);
            i += 2;
        }
        valuesCopy[i + 1] = 0;
        valuesCopy[i] = 0;
    }
    maxTotalMutex.lock();
    printIntVector(adder);
    cout << "total = " << total << endl;
    maxTotal = max(total, maxTotal);
    maxTotalMutex.unlock();
}


int targetGame(vector<int> values) {
    vector<thread> theThreads;
    for (int i = 0; i < values.size(); i++) {
        thread the_thread(calcMax, values, i);
        theThreads.push_back(move(the_thread));
    }
    for (int i = 0; i < theThreads.size(); i++) {
        theThreads[i].join();
    }
    return maxTotal;

}

string multiply(string a, string b) {

    int len1 = a.size();
    int len2 = a.size();
    if (len1 == 0 || len2 == 0) {
        return "0";
    }

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = a[i] - '0';
        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--) {

            int n2 = a[j] - '0';

            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0) {
            result[i_n1 + i_n2] += carry;
        }

        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1) {
        return "0";
    }

    string s = "";
    while (i >= 0) {
        s += to_string(result[i--]);
    }
    return s;


}
class Node {
    Node *next;
    public:
        Node * getNext() {
            return next;
        }
        void setNext(Node *newNext) {
            this->next = newNext;
        }
};

Node * duplicateNodes(vector<Node*> nodes, Node *theNode) {

    int ct = 0;
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == theNode) {
            ct++;
        } else if (ct > 1) {
            return theNode;
        }
    }
    return ct > 1 ? theNode : NULL;
}

int findLengthOfLoop(vector<Node*> nodes, const Node *theDuplicate) {

    int l = 0, r = 0;
    bool foundFirst = false;
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == theDuplicate && !foundFirst) {
            foundFirst = true;
            l = i;
        } else if (nodes[i] == theDuplicate && foundFirst) {
            r = i;
            break;
        }
    }
    return r - l;
}

/**
 * @brief Get the size of the loop within the linked list
 * 
 * @param startNode The node to start the loop from
 * @return int The size of the loop in the linked list, "loop" being a node that eventually traces back to itself, or -1 if not found or some system error occurs
 */
int getLoopSize(Node* startNode)
{   
    /**
     * @brief the count of all the nodes, the key represents the pointer
     * The first int in the outer pair represents the count, and the inner pair represents the <left, right> index
     * if the count is 1, then initialize the left to len, and if it is > 1 then initialize right to len, and then take the diff, rather then iterate through the enitre list n times
     */
    unordered_map<Node *, pair<int, pair<int, int>>> nodeCounts;
    /**
     * @brief The node to start from, which is passed in through the parameter
     */
    Node *currentNode = startNode;
    /**
     * @brief The length of the loop
     */
    int len = 0;
    do {
      if (nodeCounts.count(currentNode) > 0) {
        return len - nodeCounts[currentNode].second.first;
      } else {
          pair<int, pair<int,int>> thePair;
          thePair.first = 1;
          thePair.second.first = len;
          thePair.second.second = 0;
          nodeCounts[currentNode] = thePair;
      }
      currentNode = currentNode->getNext();
      len++;
    } while (true);
  return -1;
}

bool compare(forward_list<int> list1, forward_list<int> list2) {
    return list1 == list2;
};

double areaOfPolygonInsideCircle (double circleRadius, int numberOfSides) {

    double theta = 360 / numberOfSides;
    double theta_radians = theta * 3.14 / 180;
    double sideLength = 2 * circleRadius * sin(theta_radians / 2);
    cout << "The sidelength = " << sideLength << endl;
    return 1.0;
    
}   

int solve(const string& eq) {

    cout << "testing = " << eq << endl;
    string eqCpy = eq;
    vector<string> splitString;
    int index = 0;
    int total = 0;
    int eqIndex = 0;
    int xIndex = 0;
    while (eqCpy.find(" ") != string::npos) {
        string firstPart = eqCpy.substr(index, eqCpy.find(" "));
        if (firstPart == "=") {
            eqIndex = splitString.size();
        } else if (firstPart == "x") {
            xIndex = splitString.size();
        }
        splitString.push_back(firstPart);
        eqCpy = eqCpy.substr(eqCpy.find(" ") + 1);
    }
    if (eqCpy == "x") {
        xIndex = splitString.size();
    }
    splitString.push_back(eqCpy);
    bool isLeft = xIndex < eqIndex;
    bool isPlus = true;
    for (int i = 0; i < splitString.size(); i++) {
        if (splitString[i] == "x") {
            continue;
        } else if (splitString[i] == "+") {
            isPlus = true;
        } else if (splitString[i] == "-") {
            isPlus = false;
        } else {
            cout << "stoiing = " << splitString[i] << endl;
            // is a number
            if (isLeft && !isPlus && i < eqIndex) {
                total += stoi(splitString[i]);
            } else if (isLeft && isPlus && i < eqIndex) {
                total -= stoi(splitString[i]);
            } else if (!isLeft && isPlus && i < eqIndex) {
                total += stoi(splitString[i]);
            } else if (!isLeft && !isPlus && i < eqIndex) {
                total -= stoi(splitString[i]);
            } else if (isLeft && !isPlus && i > eqIndex) {
                total -= stoi(splitString[i]);
            } else if (isLeft && isPlus && i > eqIndex) {
                total += stoi(splitString[i]);
            } else if (!isLeft && !isPlus && i > eqIndex) {
                total += stoi(splitString[i]);
            } else if (!isLeft && isPlus && i > eqIndex) {
                total -= stoi(splitString[i]);
            }
            isPlus = true;
        }
    }
    if (eq.find("- x") != string::npos) {
        return -1 * total;
    }
    return total;

}

string sum_strings(string a, string b) {

    int carry = 0;
    string newNumber = "";
    int start = a.size() > b.size() ? b.size() - 1 : b.size() > a.size() ? a.size() - 1 : b.size() - 1;
    for (int i = start; i >= 0; i--) {

        char digit_a = a[i];
        char digit_b = b[i];
        int p_a = stoi(string(1, digit_a));
        int p_b = stoi(string(1, digit_b));
        int combin = p_a + p_b;
        if (carry > 0) {
            combin += carry;
            if (combin > 9) {
                carry = 1;
                newNumber = newNumber + to_string(combin - 10);
            } else {
                carry = 0;
                newNumber = newNumber + to_string(combin);
            }
        } else if (combin > 9) {
            carry = 1;
                           newNumber = newNumber + to_string(combin - 10);
        } else {
            carry = 0;
                newNumber = newNumber + to_string(combin);
        }
    }
    return newNumber;

}

string DNAtoRNA(string dna) {

    string result = "";
    transform(dna.begin(), dna.end(), back_inserter(result), [](char eachletter) {
        cout << "eachletter = " << eachletter << endl;
        if (eachletter == 'T') {
            return 'U';
        } else {
            return eachletter;
        }
    });

    return result;

};

string drawCube(int n) {

    if (n < 1) {
        return "";
    } else {
        int timesBeforeBase = n - 1;
        int startingLength = n;
        string theCube = "";
        string eachSection = "";
        int totalLength = (n * 2) - 1;
        int leftStart = n - 1;

        // for spaces on the right when the face of the cube is being drawn
        int rightSpaces = 0;

        int rightAmount = 0;
        int leftAmount = n - 1;
        int middlePivot = totalLength - 1;

        for (int i = 0; i < timesBeforeBase; i++, rightAmount++, leftStart--, middlePivot--) {
            int leftPivot = leftStart + 1;
            int rightPivot = totalLength - 2;
            for (int j = 0; j < totalLength; j++) {
                if (j < leftStart) {
                    eachSection += " ";
                } else if (i == 0) {
                    eachSection += "#";
                } else {
                    if (j == leftPivot - 1) {
                        eachSection += "#";
                    } else if (j < middlePivot && rightAmount < leftAmount) {
                        eachSection += "*";
                    } else if (j < middlePivot && rightAmount >= leftAmount) {
                        eachSection += "#";
                    } else if (j == middlePivot) {
                        eachSection += "#";
                    } else if (j > middlePivot && rightAmount == 0) {
                        eachSection += "#";
                    } else if (j > middlePivot && rightAmount <= leftPivot) {
                        eachSection += "#";
                    }
                }
            }
            eachSection += "\n";
            startingLength++;
            
        }
    }

}

bool accept_string(string str) {

	stack<char> theStack;
	for (int i = 0; i < (int)str.length(); i++) {
		char theChar = str.at(i);
		if (theChar == ']') {
			if (theStack.top() == '[') {
				// valid match, remove
				theStack.pop();
			} else {
				return false;
			}
		} else if (theChar == '}') {
			if (theStack.top() == '{') {
				theStack.pop();
			} else {
				return false;
			}
		} else  if (theChar == '[') {
			theStack.push(theChar);
		} else if (theChar == '{') {
			theStack.push(theChar);
		} else {
			return false;
		}
	}
	return theStack.size() == 0;

}

int main(void) {
    
     srand(time(NULL));
     auto start = std::chrono::high_resolution_clock::now();
    
    bool result = accept_string("[[[]]]");
	string res = result ? "Passed" : "Failed";
	cout << res << endl;

     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);
     std::cout << ((duration.count()*1.0) / 1000000) << " seconds" << std::endl;

}
