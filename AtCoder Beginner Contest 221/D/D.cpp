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
    int type;
    int day;

    bool operator<(event b) {
        if (day == b.day)
            return type < b.type;
        return day < b.day;
    }
};

int A[maxn] = {};
int B[maxn] = {};
int ans[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<event> keep;
    for (int i=1; i<=N; i++) {
        keep.PB({1, A[i]});
        keep.PB({2, A[i] + B[i]});
    }

    sort(all(keep));
    int last = 0;
    int cnt = 0;
    for (int i=0; i<keep.size(); ) {
        int cur = keep[i].day;
        // printf("cur = %lld\n", cur);
        ans[cnt] += cur - last;
        while (i < keep.size() && keep[i].day == cur) {
            if (keep[i].type == 1) {
                cnt++;
            } else if (keep[i].type == 2) {
                cnt--;
            }
            i++;
        }
        last = cur;
    }

    for (int i=1; i<=N; i++)
        printf("%lld ", ans[i]);
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
