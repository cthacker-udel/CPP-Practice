#include <string>
#include <bitset>
#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <set>
#include <list>
#include <map>
using namespace std::chrono;
using namespace std;

int countBits(unsigned long long);
long findMissing(vector<long>);

int main(void) {

    vector<long> testList;
    testList.push_back(1);
    testList.push_back(3);
    testList.push_back(7);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << findMissing(testList) << std::endl;

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

static long findMissing(vector<long> theList) {
    
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