#3433

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int allCount = 0;

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta == tb) return a[0] == "OFFLINE";
            return ta < tb;
        });

        for (auto &e : events) {
            int t = stoi(e[1]);

            while (!pq.empty() && pq.top().first <= t) {
                online[pq.top().second] = true;
                pq.pop();
            }

            if (e[0] == "OFFLINE") {
                int id = stoi(e[2]);
                online[id] = false;
                pq.push({t + 60, id});
            } 
            else {
                string msg = e[2];

                if (msg == "ALL") {
                    allCount++;
                } 
                else if (msg == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++)
                        if (online[i]) ans[i]++;
                } 
                else {
                    stringstream ss(msg);
                    string token;
                    while (ss >> token) {
                        int id = stoi(token.substr(2));
                        ans[id]++;
                    }
                }
            }
        }

        for (int i = 0; i < numberOfUsers; i++)
            ans[i] += allCount;

        return ans;
    }
};
