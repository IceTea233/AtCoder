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

int A[maxn] = {};
bool cht[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N, M;

    cin >> N >> M;
    for (i=1; i<=N; i++)
        scanf("%lld", &A[i]);
    set<int> st;
    for (int i=1; i<=N; i++) {
        for (int j=2; j*j <= A[i]; j++) {
            if (A[i] % j == 0) {
                st.insert(j);
                while (A[i] % j == 0)
                    A[i] /= j;
            }
        }
        if (A[i] > 1)
            st.insert(A[i]);
    }

    for (auto it : st) {
        // printf("A[i] = %lld\n", it);
        for (int j=it; j<=M; j += it)
            cht[j] = true;
    }

    vector<int> ans;
    for (int i=1; i<=M; i++) {
        if  (!cht[i])
            ans.PB(i);
    }

    printf("%d\n", ans.size());
    for (auto &it : ans) {
        printf("%lld\n", it);
    }


    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//