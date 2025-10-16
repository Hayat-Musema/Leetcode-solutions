class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;  
        for (int size = arr.size(); size > 1; size--) {

         int maxIndex = max_element(arr.begin(), arr.begin() + size) - arr.begin();

           
            if (maxIndex == size - 1)
                continue;

            
            if (maxIndex != 0) {
                reverse(arr.begin(), arr.begin() + maxIndex + 1); 
                res.push_back(maxIndex + 1);
            }

            
            reverse(arr.begin(), arr.begin() + size);
            res.push_back(size);
        }

        return res; 
    }
};