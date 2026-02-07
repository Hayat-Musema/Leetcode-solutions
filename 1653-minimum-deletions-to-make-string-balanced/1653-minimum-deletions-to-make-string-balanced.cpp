#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int deleteA = 0;  // min deletions so far
        int countB = 0;   // number of 'b's seen so far

        for (char c : s) {
            if (c == 'a') {
                // Either delete this 'a' (deleteA+1),
                // or delete all previous 'b's (countB)
                deleteA = min(deleteA + 1, countB);
            } else {
                // c == 'b': just count it
                countB++;
            }
        }
        return deleteA;
    }
};