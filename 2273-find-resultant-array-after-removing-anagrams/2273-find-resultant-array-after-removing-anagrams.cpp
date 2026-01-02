class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        for (string w : words) {
            string sortedW = w;
            sort(sortedW.begin(), sortedW.end());

            if (result.empty()) {
                result.push_back(w);
            } else {
                string last = result.back();
                sort(last.begin(), last.end());

                if (sortedW != last) {
                    result.push_back(w);
                }
            }
        }
        return result;
    }
};
