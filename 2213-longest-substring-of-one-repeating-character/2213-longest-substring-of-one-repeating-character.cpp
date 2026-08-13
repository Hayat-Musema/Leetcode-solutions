class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen, best, len;

        Node() {
            leftChar = rightChar = '#';
            leftLen = rightLen = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            leftLen = rightLen = best = len = 1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Calculate left consecutive length
        res.leftLen = a.leftLen;
        if (a.leftLen == a.len && a.rightChar == b.leftChar) {
            res.leftLen += b.leftLen;
        }

        // Calculate right consecutive length
        res.rightLen = b.rightLen;
        if (b.rightLen == b.len && a.rightChar == b.leftChar) {
            res.rightLen += a.rightLen;
        }

        // Best consecutive length inside either half
        res.best = max(a.best, b.best);

        // Sequence crossing the middle
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.rightLen + b.leftLen);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(node * 2, l, mid, pos, c);
        } else {
            update(node * 2 + 1, mid + 1, r, pos, c);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};