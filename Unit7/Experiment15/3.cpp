#include <bits/stdc++.h>
using namespace std;

bool dfs(const vector<vector<int>> &adj, int vi, int vj, int k, vector<bool> &visited, int pathLength)
{
    if (pathLength == k && vi == vj)
    {
        return true;
    }

    visited[vi] = true;
    for (auto i : adj[vi])
    {
        if (!visited[i])
        {
            if (dfs(adj, i, vj, k, visited, pathLength + 1))
            {
                return true;
            }
        }
    }
    visited[vi] = false;
    return false;
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    /*
        0->1
        1->0, 2
        2->1, 3
        3->2, 4
        4->3
    */

    int vi = 0, vj = 4, k = 3;
    vector<bool> visited(n, false);
    if (dfs(adj, vi, vj, k, visited, 0))
    {
        cout << "存在长度为 " << k << " 的简单路径从 " << vi << " 到 " << vj << endl;
    }
    else
    {
        cout << "不存在长度为 " << k << " 的简单路径从 " << vi << " 到 " << vj << endl;
    }

    return 0;
}
