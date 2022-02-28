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


int main(void) {

    auto start = std::chrono::high_resolution_clock::now();

    cout << solution(20) << endl;
    // 3 6 9 12 15 18
    // 5 10
    // 78

    auto stop = high_resolution_clock::now();
    std::cout << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count()*1.0 / 100 << " seconds" << std::endl;

}
