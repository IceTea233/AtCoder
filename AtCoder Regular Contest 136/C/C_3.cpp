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

int PreMin[maxn] = {};
int SufMin[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    PreMin[0] = A[0];
    for (int i=1; i<N; i++) {
        PreMin[i] = min(PreMin[i-1], A[i]);
    }
    SufMin[N] = INF;
    for (int i=N-1; i>=0; i--) {
        SufMin[i] = min(SufMin[i+1], A[i]);
    }

    // for (int i=0 ; i < N; i++) {
    //     printf("%lld ", PreMin[i]);
    // }
    // printf("\n");
    //
    // for (int i=0 ; i < N; i++) {
    //     printf("%lld ", SufMin[i]);
    // }
    // printf("\n");

    vector<int> keep = A;

    int ans = A[0];
    keep[0] = 0;
    for (int i=1; i<N; i++) {
        int cut = min({A[0], (i == 0 ? INF : PreMin[i - 1]) + (i == N - 1 ? INF : SufMin[i + 1]), A[i]});
        keep[i] = A[i] - cut;
    }

    printf(">>> ");
    for (auto it : keep)
        printf("%lld ", it);
    printf("\n");

    int hand = 0;
    for (int i=1; i<N; i++) {
        ans += max(0LL, keep[i] - hand);
        hand = min(hand, keep[i]);
    }

    printf("%lld\n", ans);

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
