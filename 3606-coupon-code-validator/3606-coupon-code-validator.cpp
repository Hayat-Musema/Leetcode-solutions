#3606

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<int> valid;
        vector<string> allowed = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        auto isAllowed = [&](const string& b) {
            for (auto &x : allowed)
                if (x == b) return true;
            return false;
        };

        auto isValidCode = [&](const string& s) {
            if (s.empty()) return false;
            for (char c : s)
                if (!isalnum(c) && c != '_') return false;
            return true;
        };

        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (isActive[i] && isAllowed(businessLine[i]) && isValidCode(code[i])) {
                valid.push_back(i);
            }
        }

        sort(valid.begin(), valid.end(), [&](int a, int b) {
            if (businessLine[a] != businessLine[b])
                return businessLine[a] < businessLine[b];
            return code[a] < code[b];
        });

        vector<string> result;
        for (int i : valid) result.push_back(code[i]);
        return result;
    }
};
