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
const int maxn = 2e5 + 7;

int cnt[maxn] = {};
int nxt[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;
    vector<int> A(N + 1);
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    for (int i=1; i<=N; i++) {
        cnt[A[i]] ++;
        if (!nxt[i] && A[i + 1] != A[i]) {
            nxt[A[i]] = (i == N ? 0 : A[i+1]);
        }
    }

    int x = 0;
    int maxi = 0;

    for (int i=1; i<=N; i++) {
        maxi = max(maxi, cnt[i]);
    }

    for (int i=1; i<=N; i++) {
        if (cnt[A[i]] == maxi && nxt[A[i]] < A[i]) {
            printf("x = %lld, nxt = %lld", A[i], );
            x = A[i];
            break;
        }
    }

    // printf("x = %lld\n", x);
    for (int i=1; i<=N; i++) {
        if (A[i] != x) {
            printf("%lld ", A[i]);
        }
        // printf("\n")
    }
    printf("\n");


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
