#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int n;
    int memo[1 << 20][20];
    const int INF = 1e9;

public:
    int solve(int mask, int u, vector<vector<int>>& cost) {
        if (mask == (1 << n) - 1) {
            return cost[u][0];
        }

        if (memo[mask][u] != -1) {
            return memo[mask][u];
        }

        int res = INF;

        for (int v = 0; v < n; v++) {
            if (!(mask & (1 << v))) {
                int current_cost = cost[u][v] + solve(mask | (1 << v), v, cost);
                res = min(res, current_cost);
            }
        }

        return memo[mask][u] = res;
    }

    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        if (n == 0) return 0;
        
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }

        return solve(1, 0, cost);
    }
};