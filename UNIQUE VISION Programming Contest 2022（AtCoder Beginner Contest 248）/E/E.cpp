#pragma GCC optimize("O2")

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
#define x F
#define y S
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int,int> pos;
typedef pos vec;
typedef pair<pos, vec> line;
const int INF = 1e18;
const int maxn = 3e2 + 7;

int N, K;
pos P[maxn];

// struct cmp {
//     bool operator()(const line &a, const line &b) {
//         if (a.F == b.F) {
//             if (a.S.x == b.S.x)
//                 return a.S.y < b.S.y;
//             return a.S.x < b.S.x;
//         }
//         if (a.F.x == b.F.x)
//             return a.F.y < b.F.y;
//         return a.F.x < b.F.x;
//     }
// };

vec normalize(vec v) {
    if (v.x == 0) {
        v = {0, 1};
    } else if (v.y == 0) {
        v = {1, 0};
    } else {
        if (v.x < 0) {
            v.x *= -1;
            v.y *= -1;
        }
        int gcd = __gcd(abs(v.x), abs(v.y));

        v.x /= gcd;
        v.y /= gcd;
    }
    return v;
}

line make_line(pos A, pos B) {
    pos p = A;
    vec v = normalize({B.x - A.x, B.y - A.y});

    if (v.x == 0) {
        p = {A.x, 0};
    } else if (v.y == 0) {
        p = {0, A.y};
    } else {
        p.y -= v.y * (p.x / v.x);
        p.x -= v.x * (p.x / v.x);
        if (p.x < 0) {
            p.y += v.y;
            p.x += v.x;
        }
    }

    return {p, v};
}

bool parr(vec u, vec b) {
    if (u.x == 0 || b.x == 0) {
        return u.x == 0 && b.x == 0;
    } else if (u.y == 0 || b.y == 0) {
        return u.y == 0 && b.y == 0;
    } else {
        return ( (b.x % u.x == 0 && b.y % u.y == 0)
                && (b.x / u.x == b.y / u.y));
    }
}

bool onLine(line L, pos X) {
    if (L.F == X) {
        return true;
    } else {
        return parr(L.S, {L.F.x - X.x, L.F.y - X.y});
    }
}

bool chk(line L) {
    int cnt = 0;
    for (int i=1; i<=N; i++) {
        if (onLine(L, P[i]))
            cnt++;
    }
    return cnt >= K;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        int _x, _y;
        scanf("%lld %lld", &_x, &_y);
        P[i] = {_x, _y};
    }

    if (K == 1) {
        printf("Infinity\n");
        return 0;
    }

    vector<line> st;
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            line L = make_line(P[i], P[j]);
            st.PB(L);
        }
    }
    sort(all(st));
    st.resize(unique(all(st)) - st.begin());

    int ans = 0;
    for (auto it : st) {
        // printf("(%lld, %lld), (%lld, %lld)\n", it.F.x, it.F.y, it.S.x, it.S.y);
        if (chk(it)) {
            // printf("OK\n");
            ans ++;
        }
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
