//
// Created by Edward on 9/13/2020.
//

//
// Created by Edward on 9/12/2020.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
template<class T> using V = vector<T>;
template<class T, size_t SZ> using AR = array<T,SZ>;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define For(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define Rof(i,a) ROF(i,0,a);
#define trav(a,x) for (auto& a: x)

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) {
    // note: if (lo+hi)/2 is used instead of half(lo+hi) then this will loop infinitely when lo=hi
    hi ++; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true
        T mid = half(lo+hi);
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); // assuming f is decreasing
    while (lo < hi) { // find first index such that f is true
        T mid = half(lo+hi+1);
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}
template<class T> void remDup(vector<T>& v) {
    sort(all(v)); v.erase(unique(all(v)),end(v)); }

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
#ifdef LOCAL
    return b ? "true" : "false";
#else
    return ts((int)b);
#endif
}
template<class A> str ts(complex<A> c) {
    stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
    str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; F0R(i,SZ) res += char('0'+b[i]);
    return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
#ifdef LOCAL
    bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
#else
    bool fst = 1; str res = "";
    for (const auto& x: v) {
        if (!fst) res += " ";
        fst = 0; res += ts(x);
    }
    return res;

#endif
}
template<class A, class B> str ts(pair<A,B> p) {
#ifdef LOCAL
    return "("+ts(p.f)+", "+ts(p.s)+")";
#else
    return ts(p.f)+" "+ts(p.s);
#endif
}

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) {
    pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) {
    pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << ts(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
#define dbg(...) 0
#define chk(...) 0
#endif

int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "cbarn") {
    unsyncIO();
    // cin.exceptions(cin.failbit);
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

const int MOD = 1e9+7; // 998244353;
const int MX = 1e3+5;
const ll INF = 1e18;
//const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
//mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, k;
ll ret=INF,w[MX][MX], r[MX];

ll solve(int ind){//automatically have an entrance at ind
    ll arr[n];
    For(i,n)arr[i]=r[(ind+i)%n];
    For(i,n){
        w[i][i]=0;
        FOR(j,i+1,n){
            w[i][j]=w[i][(j-1+n)%n]+(j-i)*arr[j];
        }
    }
    pl dp[n+1][k+1];//(cnt, last entrance)
    For(i,n+1)For(j,k+1)dp[i][j]=mp(INF,-1);
    FOR(i,1,k+1)dp[0][i]=mp(0,0);
    FOR(i,1,n+1){
        FOR(j,1,min(i+1,k+1)){
            dp[i][j]=mp(dp[i-1][j].f+arr[i]*(i-dp[i-1][j].s),dp[i-1][j].s);
            if(j==1)continue;
            if(dp[i-1][j-1].f<=dp[i][j].f)dp[i][j]=mp(dp[i-1][j-1].f,i);//make a new entrance here?
            ll last=dp[i-1][j].s;
            while(dp[last][j-1].f+w[(last+1)%n][i]<=dp[i][j].f){//see if can move last up
                dp[i][j]=mp(dp[last][j-1].f+w[(last+1)%n][i],last+1);
                last++;
            }
        }
    }
    if(ind==270)ps(dp[n-1][k],dp[371][1],w[372][999]);
    return dp[n-1][k].f;
}//THE PROBLEM IS NOT MOVING THE POINTER FORWARD

int main() {
//	setIO();
    re(n,k);
    For(i,n)re(r[i]);
    For(i,n)For(j,n)w[i][j]=INF;

    ll track[n];
    For(i,n){
        track[i]=solve(i);
        ckmin(ret,track[i]);
    }
    For(i,n){//WEIRD
        if(track[i]==ret)ps(i);
    }
//    FOR(i,263,270)ps(track[i]);
//        For(i,n){
//        For(j,n)pr(w[i][j]," ");
//        ps();
//    }
    ps(ret);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/