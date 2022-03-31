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
const int maxn = 1e5 + 7;

int32_t main() {
    cin.tie(0);
    int i,j;
    int Q;
    string S;

    cin >> S;
    cin >> Q;

    int maxIdx = 0;
    int cur = S.size();
    for (maxIdx=0; cur * 2 > cur; maxIdx++) {
        // printf("cur = %lld\n", cur);
        cur = cur * 2;
    }
    printf(">> maxi = %lld\n", maxIdx);

    while (Q--) {
        int t, k;
        cin >> t >> k;

        int idx = -1;
        if (t > maxIdx) {
            idx = 0;
        } else {
            idx = (k - 1) / (1LL << t);
        }

        printf("Select %lld to start\n", idx);
        vector<int> keep({idx});
        for (int i=t; i>0; i--) {
            if ((idx + 1) * (1LL << (i - 1)) > (k - 1)) {
                keep.PB(0);
                idx = idx * 2;
            } else {
                keep.PB(1);
                idx = idx * 2 + 1;
            }
        }

        printf(">>> ");
        for (auto it : keep) {
            printf("%lld ", it);
        }
        printf("\n");
        printf("idx = %lld(+1)\n", idx);
    }


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
