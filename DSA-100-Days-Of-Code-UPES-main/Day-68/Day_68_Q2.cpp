#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for (const string& w : words) {
            for (char c : w) {
                if (inDegree.find(c) == inDegree.end()) {
                    inDegree[c] = 0;
                }
            }
        }

        for (int i = 0; i < (int)words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min((int)w1.length(), (int)w2.length());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    char u = w1[j];
                    char v = w2[j];
                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                        inDegree[v]++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found && w1.length() > w2.length()) return "";
        }

        queue<char> q;
        for (auto const& [ch, degree] : inDegree) {
            if (degree == 0) q.push(ch);
        }

        string result = "";
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            result += u;

            if (adj.count(u)) {
                for (char v : adj[u]) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) q.push(v);
                }
            }
        }

        return result.length() == inDegree.size() ? result : "";
    }
};