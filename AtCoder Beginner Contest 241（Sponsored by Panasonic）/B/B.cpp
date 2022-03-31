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
    int N, M;

    cin >> N >> M;
    vector<int> A(N + 1);
    vector<int> B(M + 1);

    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }
    for (int i=1; i<=M; i++) {
        cin >> B[i];
    }

    bool ans = true;

    multiset<int> st;
    for (int i=1; i<=N; i++) {
        st.insert(A[i]);
    }
    for (int i=1; i<=M; i++) {
        auto it = st.find(B[i]);
        if (it == st.end()) {
            ans = false;
            break;
        } else {
            st.erase(it);
        }
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
