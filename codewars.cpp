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
using namespace std::chrono;
using namespace std;

int countBits(unsigned long long);
long findMissing(vector<long>);
string stockSummary(vector<string>, vector<string>);

int main(void) {

    std::vector<std::string> art = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> cd = {"A", "B"};

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << stockSummary(art, cd) << std::endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count()*1.0 / 100 << " seconds" << std::endl;

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

string stockSummary(vector<string> listOfArt, vector<string> categories) {

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
    }
    string s;
    for (map<string,int>::iterator it = amounts.begin(); it != amounts.end(); ++it) {
        s += "(" + it->first + " : " + to_string(it->second) + ")";
    }
    return s;
}