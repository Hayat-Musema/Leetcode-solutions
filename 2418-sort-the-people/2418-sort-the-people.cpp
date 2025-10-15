class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    for (int i = 0; i < heights.size() - 1; i++) {
        for (int j = i + 1; j < heights.size(); j++) {
            if (heights[i] < heights[j]) { 
             
                int temp = heights[i];
                heights[i] = heights[j];
                heights[j] = temp;

            
                string temp2 = names[i];
                names[i] = names[j];
                names[j] = temp2;
            }
        }
    }
    return names;
}
};
