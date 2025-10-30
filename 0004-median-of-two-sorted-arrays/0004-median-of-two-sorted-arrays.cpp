class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        if (A.size() > B.size()) swap(A, B);
        int m = (int)A.size();
        int n = (int)B.size();

        int low = 0, high = m;
        while (low <= high) {
            int i = (low + high) / 2;            
            int j = (m + n + 1) / 2 - i;        

            int Aleft  = (i == 0) ? INT_MIN : A[i-1];
            int Aright = (i == m) ? INT_MAX : A[i];
            int Bleft  = (j == 0) ? INT_MIN : B[j-1];
            int Bright = (j == n) ? INT_MAX : B[j];

            
            if (Aleft <= Bright && Bleft <= Aright) {
                
                if ((m + n) % 2 == 1) {
                    return (double)max(Aleft, Bleft);
                } else {
                    long long leftMax = max(Aleft, Bleft);
                    long long rightMin = min(Aright, Bright);
                    return (leftMax + rightMin) / 2.0;
                }
            } else if (Aleft > Bright) {
                
                high = i - 1;
            } else {
                
                low = i + 1;
            }
        }

        
        throw runtime_error("Logic error: unable to find median partitions");
    }
};
