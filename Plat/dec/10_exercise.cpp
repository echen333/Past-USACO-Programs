#include "bits/stdc++.h"

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str; 

typedef pair<int,int> pi;
typedef pair<pi, int> pii;
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
#define Rof(i,a) ROF(i,0,a)
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
int max(int a,int b, int c){return max(a,max(b,c));}
int min(int a,int b, int c){return min(a,min(b,c));}
ll max(ll a,ll b, ll c){return max(a,max(b,c));}
ll min(ll a,ll b, ll c){return min(a,min(b,c));}
void dbga(int arr[], int n){vi v;For(i,n)v.pb(arr[i]);dbg(v);}
void dbga(ll arr[], int n){vi v;For(i,n)v.pb(arr[i]);dbg(v);}

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
        unsyncIO();
        // cin.exceptions(cin.failbit); 
        // throws exception when do smth illegal
        // ex. try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
// 576743 29995400689069LL
int MOD = 1e9+7; // 998244353;
const int MX = 75e2+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

template<int SZ> struct Sieve { 
    bitset<SZ> pri; vi pr;
    Sieve() { // cum[i] = # of primes up to i
        pri.set(); pri[0] = pri[1] = 0;
        for (int i = 4; i < SZ; i += 2) pri[i] = 0;
        for (int i = 3; i*i < SZ; i += 2) if (pri[i])
            for (int j = i*i; j < SZ; j += i*2) pri[j] = 0;
        F0R(i,SZ) if (pri[i]) pr.pb(i);
    }
    /*int sp[SZ]; // smallest prime that divides
    Sieve() { // above is faster
        memset(sp,0,sizeof sp);
        FOR(i,2,SZ) { 
            if (sp[i] == 0) sp[i] = i, pr.pb(i); 
            trav(p,pr) {
                if (p > sp[i] || i*p >= SZ) break;
                sp[i*p] = p;
            }
        }
    }*/
};
Sieve<320000> S;

vi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
    invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FOR(i,2,SZ) invs[i] = MOD-(ll)MOD/i*invs[MOD%i]%MOD;
    FOR(i,1,SZ) {
        fac[i] = (ll)fac[i-1]*i%MOD;
        ifac[i] = (ll)ifac[i-1]*invs[i]%MOD;
    }
}

typedef unsigned long long ul;
ul modMul(ul a, ul b, const ul mod) {
    ll ret = a*b-mod*(ul)((ld)a*b/mod);
    return ret+((ret<0)-(ret>=(ll)mod))*mod; }
ul modPow(ul a, ul b, const ul mod = MOD) {
    if (b == 0) return 1;
    ul res = modPow(a,b/2,mod); res = modMul(res,res,mod);
    return b&1 ? modMul(res,a,mod) : res;
}


ll ad(ll a,ll b){
    return (a+b>=MOD)?a+b-MOD:a+b;
}
ll sub(ll a, ll b){
    return (a-b<0)?a-b+MOD:a-b;
}

int n;
ll c[MX][MX], cnt[MX];
ll dp1[MX], dp2[MX], ret=1;

void go(int x){

    //all divis by x
    // dp1[x]=fac[x];
    dp1[0]=1;
    for(int i=1;i<=n/x;i++){
        for(int j=1;j<=i;j++){
            dp1[i]=ad(dp1[i],dp1[i-j]*c[i*x-1][j*x-1]%MOD*fac[j*x-1]%MOD);
        }
        dbg(x,i,dp1[i]);
    }


    for(int i=n/x;i>=0;i--){
        dp2[i]=fac[n-i*x];
        for(int j=i+1;j<=n/x;j++){
            dbg(n-i*x,n-j*x,c[n-i*x][n-j*x]);
            dp2[i]=sub(dp2[i],dp2[j]*dp1[j-i]*c[n-i*x][n-j*x]);
        }
        dbg(x,i,dp2[i]);
    }

    // for(int i=x;i<=n;i+=x){
    //     cnt[x]=ad(cnt[x],c[n][x]*dp1[i]%MOD*dp2[n-i]%MOD);
    // }

    // ll prev=1;
    // for(int i=1;i<=n/x;i++){
    //     prev=prev*c[i*x-1][x-1]%MOD*fac[x]%MOD;
    //     cnt[x]=ad(cnt[x],c[n][i*x]*dp2[n-i*x]%MOD*prev%MOD);
    // }
    dbg(x,dp2[0]);
    ret=(ret*modPow(x,sub(fac[n],dp2[0]),MOD+1))%(MOD+1);
}

void solve(){
    re(n,MOD);MOD--;
    genFac(MX);
    c[0][0]=1, c[1][0]=1, c[1][1]=1;
    FOR(i,1,n+1){
        c[i][0] = c[i][i] = 1;
        FOR(j,1,i){
            c[i][j]=ad(c[i-1][j],c[i-1][j-1]);
        }
    }
    FOR(i,2,n+1){
        if(S.pri[i]){
            int tmp=i;
            while(tmp<=n){
                go(tmp);
                tmp*=i;
            }
        }
    }

    dbg(ret);
    ps(ret);

}

int main() {
        setIO("exercise");
        int t=1;
        // re(t);
        while(t--)solve();
        // you should actually read the stuff at the bottom
}

/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
*/