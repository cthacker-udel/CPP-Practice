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


int main(void) {

    char *letters = "sort content";
    int len = 12;    

    auto start = std::chrono::high_resolution_clock::now();

    cout << sortTheInnerContent(letters, len) << endl;

    auto stop = high_resolution_clock::now();
    std::cout << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count()*1.0 / 100 << " seconds" << std::endl;

}
