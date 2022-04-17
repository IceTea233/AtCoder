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

struct event {
    int id;
    int type;
    int pos;
    int val;

    bool operator< (event b) {
        if (pos == b.pos)
            return type < b.type;
        return pos < b.pos;
    }
};

int A[maxn] = {};
int cnt[maxn] = {};
int ans[maxn] = {};
int pre[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;
    for (int i=1; i<=N; i++) {
        scanf("%lld", &A[i]);
    }

    int Q;
    cin >> Q;

    vector<event> keep;
    for (int i=1; i <= Q; i++) {
        int l, r, x;
        scanf("%lld %lld %lld", &l, &r, &x);
        keep.PB({i, 1, l, x});
        keep.PB({i, 2, r, x});
    }
    sort(all(keep));
    for (int i=1, j = 0; i<=N; i++) {
        while (j < keep.size() && keep[j].pos == i && keep[j].type == 1) {
            pre[keep[j].id] = cnt[keep[j].val];
            j++;
        }
        cnt[A[i]]++;
        while (j < keep.size() && keep[j].pos == i && keep[j].type == 2) {
            ans[keep[j].id] = cnt[keep[j].val] - pre[keep[j].id];
            j++;
        }
    }

    for (int i=1; i<=Q; i++) {
        printf("%lld\n", ans[i]);
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
