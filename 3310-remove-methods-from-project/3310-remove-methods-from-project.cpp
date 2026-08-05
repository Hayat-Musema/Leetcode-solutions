class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);

        for (auto &e : invocations)
            g[e[0]].push_back(e[1]);

        vector<bool> suspicious(n, false);

        // Iterative DFS from k
        stack<int> st;
        st.push(k);
        suspicious[k] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : g[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    st.push(v);
                }
            }
        }

        // If any non-suspicious node points to a suspicious node,
        // we cannot remove anything.
        for (auto &e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!suspicious[i])
                ans.push_back(i);

        return ans;
    }
};