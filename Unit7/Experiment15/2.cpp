#include <bits/stdc++.h>
using namespace std;

bool dfs(const vector<vector<int>> &adj, int vi, int vj, vector<bool> &visited)
{
    if (vi == vj)
    {
        return true;
    }

    visited[vi] = true;
    for (int i = 0; i < adj.size(); ++i)
    {
        if (adj[vi][i] == 1 && !visited[i])
        {
            if (dfs(adj, i, vj, visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    adj[0][1] = 1; // 0 -> 1
    adj[1][2] = 1; // 1 -> 2
    adj[2][3] = 1; // 2 -> 3
    adj[3][4] = 1; // 3 -> 4

    int vi = 0, vj = 3;
    vector<bool> visited(n, false);
    if (dfs(adj, vi, vj, visited))
    {
        cout << "存在路径从 " << vi << " 到 " << vj << endl;
    }
    else
    {
        cout << "不存在路径从 " << vi << " 到 " << vj << endl;
    }

    return 0;
}
