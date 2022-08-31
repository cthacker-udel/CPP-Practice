#include <map>
#include <iostream>
using namespace std;

void sum_two() {

    int x;
    int y;
    cin >> x;
    cin >> y;
    /**
     * first element is the number
     * second pair is the first index and second index
     */
    map<int, pair<int, int>>themap;
    for (int i = 0; i < x; i++) {
        int z;
        cin >> z;
        //printf("themap.count(%d) = %d\n", z, themap.count(z));
        if (themap.count(z) > 0) {
            //printf("in if");
            pair<int, int> thepair = themap[z];
            thepair.second = i;
            themap[z] = thepair;
            //printf("creating the pair %d and %d", thepair.first, thepair.second);
        } else if (themap.count(z) == 0) {
            //printf("in else\n");
            pair<int, int> addendum;
            addendum.first = i;
            addendum.second = -1;
            themap[z] = addendum;
        }
    }

    bool found = false;
    for (auto i : themap) {
        int value = y - i.first;
        if (value == i.first) {
            if (i.second.second != -1) {
                found = true;
                printf("%d %d\n", i.second.first + 1, i.second.second + 1);
                break;
            } else {
                break;
            }
        } else if (themap.find(value) != themap.end()) {
            // if the value second is not null and the value is the same as the number we are subbing the 
            printf("%d %d\n", themap[value].first + 1, i.second.first + 1);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("IMPOSSIBLE\n");
    }

}


int main() {
    sum_two();
}