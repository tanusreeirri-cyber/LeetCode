#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Segment Tree Node structure
struct Node {
    char lc, rc;
    int pref, suff, mx, len;
};

class Solution {
private:
    vector<Node> tree;

    // Helper function to merge results from left and right child nodes
    Node merge(const Node& L, const Node& R) {
        Node res;
        res.lc = L.lc;
        res.rc = R.rc;
        res.len = L.len + R.len;
        res.mx = max(L.mx, R.mx);
        res.pref = L.pref;
        res.suff = R.suff;

        // Check if adjacent characters at the split boundary are identical
        if (L.rc == R.lc) {
            // Check if the combined boundary substring is larger
            res.mx = max(res.mx, L.suff + R.pref);

            // Extend prefix if left segment is completely uniform
            if (L.pref == L.len) {
                res.pref = L.len + R.pref;
            }

            // Extend suffix if right segment is completely uniform
            if (R.suff == R.len) {
                res.suff = R.len + L.suff;
            }
        }
        return res;
    }

    // Build the initial Segment Tree
    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Point update at index `idx` with new character `ch`
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        
        // Segment tree size is 4 * N
        tree.resize(4 * n);

        // Build the initial tree
        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            // Update single position
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            
            // Root node (index 1) always represents the entire string [0, n-1]
            ans[i] = tree[1].mx;
        }

        return ans;
    }
};