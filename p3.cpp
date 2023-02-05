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

int N;
vi A;

int main()
{
    setIO();
    
    cin >> N;
    string ans = "";

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        A.pb(num);
    }

    int mini = INT_MAX;

    for (int i: A) {
        mini = min(mini, i);
    }

    mini--;

    for (int i = 0; i < N; i++)
    {
        A[i] -= mini;
    }

    bool turn_right = true;

    while (mini > 0) {
        for (int i = 0; i < N; i++)
        {
            if (turn_right)
                ans += 'R';
            else
                ans += 'L';
        }
        turn_right = !turn_right;
        mini--;
    }
    
    int pos = N;

    while (true) {
        bool done = true;
        for (int i: A) {
            if (i != 0) {
                done = false;
                break;
            }
        }

        if (done) {
            break;
        }

        pos--;

        A[pos]--;
        pos--;
        ans += 'L';

        // move left to find 1 (or all the way left)
        while (pos >= 0 && A[pos] != 1) {
            A[pos]--;
            pos--;
            ans += 'L';
        }

        pos++;

        // move right to find 0 (or all the way right)
        while (pos < N && A[pos] != 0) {
            A[pos]--;
            pos++;
            ans += 'R';
        }
    }

    cout << ans << '\n';
}