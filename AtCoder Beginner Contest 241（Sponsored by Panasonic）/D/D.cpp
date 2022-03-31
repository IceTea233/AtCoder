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

    cin >> Q;

    multiset<int> A;
    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            A.insert(x);
        } else if (cmd == 2) {
            int x, k;
            cin >> x >> k;
            auto it = A.upper_bound(x);
            if (it == A.begin()) {
                printf("-1\n");
            } else {
                it = prev(it);
                bool flag = false;
                for (int i=1; i<k; i++) {
                    if (it == A.begin()) {
                        flag = true;
                        break;
                    }
                    it = prev(it);
                }

                if (flag) {
                    printf("-1\n");
                } else {
                    printf("%lld\n", *it);
                }
            }
        } else if (cmd == 3) {
            int x, k;
            cin >> x >> k;
            auto it = A.lower_bound(x);
            // printf(">>> %lld\n", *it);
            if (it == A.end()) {
                printf("-1\n");
            } else {
                bool flag = false;
                for (int i=1; i<k; i++) {
                    it = next(it);
                    if (it == A.end()) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    printf("-1\n");
                } else {
                    printf("%lld\n", *it);
                }
            }
        }
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
