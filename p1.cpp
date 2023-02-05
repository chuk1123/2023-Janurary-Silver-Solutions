#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (len(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vi visited(100);
vi start_nodes;
unordered_map<int, int> adj;
unordered_map<int, int> letter_log;

void dfs(int u)
{
    if (visited[u] == 2)
    {
        return;
    }

    if (visited[u] == 1)
    {
        start_nodes.pb(u);
        return;
    }

    visited[u] = 1;

    if (adj[u])
        dfs(adj[u]);

    visited[u] = 2;
}

void solve()
{
    visited.clear();
    visited.resize(100);
    adj.clear();
    letter_log.clear();
    start_nodes.clear();
    string original;
    string target;

    cin >> original >> target;

    int N = original.length();

    int count = 0;
    int tot_letters = 0;

    for (int i = 0; i < N; i++)
    {
        int a = original[i] - 'A' + 1;
        int b = target[i] - 'A' + 1;

        if (!letter_log[a])
        {
            tot_letters++;
            letter_log[a] = b;
        }
        else
        {
            if (letter_log[a] != b)
            {
                cout << -1 << '\n';
                return;
            }
        }

        if (adj[a] && adj[a] != b)
        {
            cout << -1 << '\n';
            return;
        }

        if (a != b)
        {
            if (!adj[a])
            {
                count++;
                adj[a] = b;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (!visited[i] && adj[i])
        {
            dfs(i);
        }
    }

    vi cycle_nodes(100);
    unordered_map<int, int> colors_log;

    int color = 1;

    for (int u : start_nodes)
    {
        int v = adj[u];

        cycle_nodes[u] = color;

        while (v != u)
        {
            cycle_nodes[v] = color;
            v = adj[v];
        }
        color++;
    }

    int nodes_with_in = 0;

    for (int i = 0; i < 100; i++)
    {
        if (cycle_nodes[i] == 0 && adj[i])
        {
            int v = adj[i];
            if (cycle_nodes[v] && !colors_log[cycle_nodes[v]])
            {
                colors_log[cycle_nodes[v]] = 1;
                nodes_with_in++;
            }
        }
    }

    if (len(start_nodes) >= 1 && tot_letters >= 52 && !nodes_with_in)
    {
        cout << -1 << '\n';
        return;
    }

    cout << count + len(start_nodes) - nodes_with_in << '\n';
}

int main()
{
    setIO();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
}