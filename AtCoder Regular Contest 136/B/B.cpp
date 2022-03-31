#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 5e3 + 7;

int A[maxn] = {};
int B[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }
    for (int i=1; i<=N; i++) {
        cin >> B[i];
    }

    vector<int> cnt1(maxn);
    vector<int> cnt2(maxn);
    for (int i=1; i<=N; i++) {
        cnt1[A[i]] ++;
        cnt2[B[i]] ++;
    }

    bool ans = true;
    for (int i=1; i<maxn; i++) {
        if (cnt1[i] != cnt2[i])
            ans = false;
    }

    if (ans)
        printf("Yes\n");
    else
        printf("No\n");


    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
