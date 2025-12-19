#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            parent[find(a)] = find(b);
        };

        // Initially, person 0 and firstPerson know the secret
        unite(0, firstPerson);

        // Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;

            // Process all meetings at the same time
            while (i < meetings.size() && meetings[i][2] == time) {
                unite(meetings[i][0], meetings[i][1]);
                people.push_back(meetings[i][0]);
                people.push_back(meetings[i][1]);
                i++;
            }

            // If a person is not connected to person 0, reset them
            for (int p : people) {
                if (find(p) != find(0)) {
                    parent[p] = p;
                }
            }
        }

        // Collect all people who know the secret
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                result.push_back(i);
        }

        return result;
    }
};
