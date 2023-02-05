#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()

using pii = pair<int, int>;
#define ff first
#define ss second
#define mp make_pair

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (len(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int N, Q;

vector<pii> queries;
vector<vi> arr;
vector<vi> scores;

// int dfs(int r, int c) {
//     int count = 0;

//     if (arr[r][c] == -1) {
//         count += dfs(r, c + 1);
//     }
//     else if (arr[r][c] == -2) {
//         count += dfs(r + 1, c);
//     }
//     else {
//         count += arr[r][c];
//     }
        
//     return count;
// }

int flood(int r, int c, int delta) {
    int count = 1;

    scores[r][c] += delta;

    // check up 
    if (r > 0 && arr[r - 1][c] == -2) {
        count += flood(r - 1, c, delta);
    }

    // check left
    if (c > 0 && arr[r][c - 1] == -1) {
        count += flood(r, c - 1, delta);
    }

    return count;
}

int main()
{
    setIO();
    cin >> N;

    for (int i = 0; i < N; i++) {
        vi row;
        string a; int p;
        cin >> a >> p;

        for (char c: a) {
            if (c == 'R') {
                row.pb(-1);
            }
            else
                row.pb(-2);
        }

        row.pb(p);
        arr.pb(row);
    }

    vi row;

    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        row.pb(p);
    }

    row.pb(0);
    arr.pb(row);

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int r, c; cin >> r >> c;
        r--; c--;
        queries.pb({r, c});
    }

    int ans = 0;

    // update initial score board

    scores.resize(N+1, vi(N+1));

    for (int r = 0; r < N; r++)
    {
        scores[r][N] = arr[r][N];
    }

    for (int c = 0; c < N; c++)
    {
        scores[N][c] = arr[N][c];
    }

    for (int r = 0; r < N; r++)
    {
        if (arr[r][N-1] == -1) {
            int n = flood(r, N-1, arr[r][N]);
            ans += n * arr[r][N];
        }
    }

    for (int c = 0; c < N; c++)
    {
        if (arr[N - 1][c] == -2)
        {
            int n = flood(N - 1, c, arr[N][c]);
            ans += n * arr[N][c];
        }
    }

    cout << ans << '\n';

    // Queries

    for (int i = 0; i < Q; i++) {
        int rr = queries[i].ff;
        int cc = queries[i].ss;

        int delta = 0;

        // -1 right
        // -2 down

        if (arr[rr][cc] == -1) {
            arr[rr][cc] = -2;
            delta = scores[rr + 1][cc] - scores[rr][cc];
        }

        else if (arr[rr][cc] == -2) {
            arr[rr][cc] = -1;
            delta = scores[rr][cc + 1] - scores[rr][cc];
        }

        int num_affected = flood(rr, cc, delta);
        ans += delta * num_affected;

        cout << ans << '\n';

        // cout << "================================================================" << endl;
        // for (auto row: scores) {
        //     for (int i: row) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "================================================================" << endl;
    }
}