//
// Created on 10/24/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <complex.h>
#include <random>
#include <chrono>

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
const int MOD = 1e9+7; // 998244353;
const int MX = 3e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int n=6;

int cnt[5];

void dbga(int arr[]){int n=*(&arr + 1) - arr;dbg(n);vi v;For(i,n)v.pb(arr[i]);dbg(v);}
void dbga(ll arr[]){int n=sizeof(arr);vi v;For(i,n)v.pb(arr[i]);dbg(v);}

bool check(int a, int b, int c, int d){
        int arr[]={a,b,c,d};
        vi arr2(n,0);
        For(i,4)For(j,arr[i])arr2[(i+j)%n]++;

        bool w=true;
        For(i,n)if(arr[i]!=arr2[i])w=false;
        return w;
        cnt[0]++;
}

bool check(int a, int b, int c, int d, int e){
        int n=5;
        int arr[]={a,b,c,d,e};
        vi arr2(n,0);
        For(i,n)For(j,arr[i])arr2[(i+j)%n]++;

        bool w=true;
        For(i,n)if(arr[i]!=arr2[i])w=false;
        cnt[1]++;
        return w;

}

bool check(int a, int b, int c, int d, int e, int f){
        int arr[]={a,b,c,d,e,f};
        vi arr2(n,0);
        For(i,n)For(j,arr[i])arr2[(i+j)%n]++;

        bool w=true;
        For(i,n)if(arr[i]!=arr2[i])w=false;
        cnt[2]++;
        return w;
}


bool check(int a, int b, int c, int d, int e, int f,int g, int h){
        int arr[]={a,b,c,d,e,f,g,h};
        vi arr2(n,0);
        For(i,n)For(j,arr[i])arr2[(i+j)%n]++;

        bool w=true;
        For(i,n)if(arr[i]!=arr2[i])w=false;
        cnt[3]++;
        return w;
}
bool check(int a, int b, int c, int d, int e, int f,int g, int h, int i){
        int arr[]={a,b,c,d,e,f,g,h,i};
        vi arr2(n,0);
        For(i,n)For(j,arr[i])arr2[(i+j)%n]++;

        bool w=true;
        For(i,n)if(arr[i]!=arr2[i])w=false;
        cnt[3]++;
        return w;
}

bool check(int a, int b, int c, int d, int e, int f,int g, int h, int i, int j){
        int arr[]={a,b,c,d,e,f,g,h,i,j};
        vi arr2(n,0);
        For(i,n)For(j,arr[i])arr2[(i+j)%n]++;

        bool w=true;
        For(i,n)if(arr[i]!=arr2[i])w=false;
        cnt[3]++;
        return w;
}

int main() {
        setIO();
        int a,b,c,d;
//        re(a,b,c,d);
//        ps(check(a,b,c,d));
        For(i1,n){
                For(i2,n){
                        For(i3,n){
                                For(i4,n){
                                        For(i5,n){
//                                                if(check(i1+1,i2+1,i3+1,i4+1,i5+1))ps(i1+1,i2+1,i3+1,i4+1,i5+1);
                                                For(i6,n){
                                                        if(check(i1+1,i2+1,i3+1,i4+1,i5+1,i6+1))ps(i1+1,i2+1,i3+1,i4+1,i5+1,i6+1);
                                                }
                                        }
                                }
                        }
                }
        }
        cout.flush();
        n=10;
//        ps(check(4,5,4,5,4,5,4,5));
//        ps(check(2,3,2,3,2,3,2,3));
        For(i1,n){
                For(i2,n){
                        For(i3,n){
                                For(i4,n){
                                        For(i5,n){
                                                For(i6,n){
                                                        For(i7,n)For(i8,n)For(i9,n)For(i10,n){
//                                                                if(check(i1+1,i2+1,i3+1,i4+1,i5+1,i6+1,i7+1,i8+1))ps(i1+1,i2+1,i3+1,i4+1,i5+1,i6+1,i7+1,i8+1);
                                                                if(check(i1+1,i2+1,i3+1,i4+1,i5+1,i6+1,i7+1,i8+1,i9+1,i10+1))ps(i1+1,i2+1,i3+1,i4+1,i5+1,i6+1,i7+1,i8+1,i9+1,i10+1);
                                                        }
                                                }
                                        }
                                }
                        }
                }
                cout.flush();
        }

        dbga(cnt);
// you should actually read the stuff at the bottom
}
/*
 *
n
1 1 1 1 1 1
2 2 2 2 2 2
3 3 3 3 3 3
4 4 4 4 4 4
5 5 5 5 5 5
6 6 6 6 6 6

~2*n-4
2 3 2 3 2 3
3 2 3 2 3 2
3 4 3 3 4 3
4 3 4 4 3 4
4 5 4 5 4 5
5 4 5 4 5 4

3 3 4 3 3 4
3 4 4 3 4 4
4 3 3 4 3 3
4 4 3 4 4 3

 ////////////////////////////////

 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3
5 5 5 5 5 5 5 5
6 6 6 6 6 6 6 6
7 7 7 7 7 7 7 7
8 8 8 8 8 8 8 8


2 3 2 3 2 3 2 3
3 2 3 2 3 2 3 2

12

4 4 4 4 4 4 4 4
4 4 4 5 4 4 4 5
4 4 5 4 4 4 5 4
4 5 4 4 4 5 4 4
4 4 5 5 4 4 5 5
4 5 5 4 4 5 5 4
4 5 5 5 4 5 5 5
5 4 4 4 5 4 4 4
5 4 4 5 5 4 4 5
5 4 5 5 5 4 5 5
5 5 4 4 5 5 4 4
5 5 4 5 5 5 4 5
5 5 5 4 5 5 5 4

6 7 6 7 6 7 6 7
7 6 7 6 7 6 7 6
6 7 6 7 6 7 6 7
7 6 7 6 7 6 7 6

///////////////////////////////////////////
 n=8

1 1 1 1 1 1 1 1

2 2 2 2 2 2 2 2
2 3 2 3 2 3 2 3

3 2 3 2 3 2 3 2
3 3 3 3 3 3 3 3

4 4 4 4 4 4 4 4
4 4 4 5 4 4 4 5
4 4 5 4 4 4 5 4
4 4 5 5 4 4 5 5
4 5 4 4 4 5 4 4
4 5 4 5 4 5 4 5
4 5 5 4 4 5 5 4
4 5 5 5 4 5 5 5

5 4 4 4 5 4 4 4
5 4 4 5 5 4 4 5
5 4 5 4 5 4 5 4
5 4 5 5 5 4 5 5
5 5 4 4 5 5 4 4
5 5 4 5 5 5 4 5
5 5 5 4 5 5 5 4
5 5 5 5 5 5 5 5

6 6 6 6 6 6 6 6
6 7 6 7 6 7 6 7

7 6 7 6 7 6 7 6
7 7 7 7 7 7 7 7

8 8 8 8 8 8 8 8

 1 2  4
 8 6  12 =26
  3*2  1*(2^4-4)

 1
 2
 2
 8
 8
 2
 2
 1


 ////////////////////////////////////
 n=6
1 1 1 1 1 1

2 2 2 2 2 2
2 3 2 3 2 3

3 2 3 2 3 2
3 3 3 3 3 3

3 3 4 3 3 4
3 4 3 3 4 3
3 4 4 3 4 4

4 3 3 4 3 3
4 3 4 4 3 4
4 4 3 4 4 3

4 4 4 4 4 4

4 5 4 5 4 5

5 4 5 4 5 4
5 5 5 5 5 5

6 6 6 6 6 6

 1
 2
 5
 5
 2
 1

 1,2,3,6?
 6 4 6
     1*(2^3-2)
   2*2

////////////////////////////////
 n=9

 1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3 3
3 3 4 3 3 4 3 3 4
3 4 3 3 4 3 3 4 3
3 4 4 3 4 4 3 4 4
4 3 3 4 3 3 4 3 3
4 3 4 4 3 4 4 3 4
4 4 3 4 4 3 4 4 3
4 4 4 4 4 4 4 4 4
5 5 5 5 5 5 5 5 5
6 6 6 6 6 6 6 6 6
6 6 7 6 6 7 6 6 7
6 7 6 6 7 6 6 7 6
6 7 7 6 7 7 6 7 7
7 6 6 7 6 6 7 6 6
7 6 7 7 6 7 7 6 7
7 7 6 7 7 6 7 7 6
7 7 7 7 7 7 7 7 7
8 8 8 8 8 8 8 8 8
9 9 9 9 9 9 9 9 9

 1 2 3 4 5 6 7 8 9
 1 1 4 4 1 4 4 1 1

 1, 3
 9  6*2

 ///////////////////////////////////////////////////////
 n=10
 1 1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2 2
2 3 2 3 2 3 2 3 2 3
3 2 3 2 3 2 3 2 3 2
3 3 3 3 3 3 3 3 3 3
4 4 4 4 4 4 4 4 4 4
4 5 4 5 4 5 4 5 4 5
5 4 5 4 5 4 5 4 5 4
5 5 5 5 5 5 5 5 5 5
5 5 5 5 6 5 5 5 5 6
5 5 5 6 5 5 5 5 6 5
5 5 5 6 6 5 5 5 6 6
5 5 6 5 5 5 5 6 5 5
5 5 6 5 6 5 5 6 5 6
5 5 6 6 5 5 5 6 6 5
5 5 6 6 6 5 5 6 6 6
5 6 5 5 5 5 6 5 5 5
5 6 5 5 6 5 6 5 5 6
5 6 5 6 5 5 6 5 6 5
5 6 5 6 6 5 6 5 6 6
5 6 6 5 5 5 6 6 5 5
5 6 6 5 6 5 6 6 5 6
5 6 6 6 5 5 6 6 6 5
5 6 6 6 6 5 6 6 6 6

 6 5 5 5 5 6 5 5 5 5
6 5 5 5 6 6 5 5 5 6
6 5 5 6 5 6 5 5 6 5
6 5 5 6 6 6 5 5 6 6
6 5 6 5 5 6 5 6 5 5
6 5 6 5 6 6 5 6 5 6
6 5 6 6 5 6 5 6 6 5
6 5 6 6 6 6 5 6 6 6
6 6 5 5 5 6 6 5 5 5
6 6 5 5 6 6 6 5 5 6
6 6 5 6 5 6 6 5 6 5
6 6 5 6 6 6 6 5 6 6
6 6 6 5 5 6 6 6 5 5
6 6 6 5 6 6 6 6 5 6
6 6 6 6 5 6 6 6 6 5
6 6 6 6 6 6 6 6 6 6
6 7 6 7 6 7 6 7 6 7

 1   2          5
 10  4*(2^2-2) 1*(2^5-2)
 10  4*2       1*30
 10  8         30

 48


 */

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* think of simple solution first
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH

4 5 4 5 4 5 4 5
5 4 5 4 5 4 5 4
6 7 6 7 6 7 6 7
7 6 7 6 7 6 7 6
 */

/*
 n=10
 * 1 1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2 2
2 3 2 3 2 3 2 3 2 3
3 2 3 2 3 2 3 2 3 2
3 3 3 3 3 3 3 3 3 3
4 4 4 4 4 4 4 4 4 4
4 5 4 5 4 5 4 5 4 5
5 4 5 4 5 4 5 4 5 4
5 5 5 5 5 5 5 5 5 5
5 5 5 5 6 5 5 5 5 6
5 5 5 6 5 5 5 5 6 5
5 5 5 6 6 5 5 5 6 6
5 5 6 5 5 5 5 6 5 5
5 5 6 5 6 5 5 6 5 6
5 5 6 6 5 5 5 6 6 5
5 5 6 6 6 5 5 6 6 6
5 6 5 5 5 5 6 5 5 5
5 6 5 5 6 5 6 5 5 6
5 6 5 6 5 5 6 5 6 5
5 6 5 6 6 5 6 5 6 6
5 6 6 5 5 5 6 6 5 5
5 6 6 5 6 5 6 6 5 6
5 6 6 6 5 5 6 6 6 5
5 6 6 6 6 5 6 6 6 6
6 5 5 5 5 6 5 5 5 5
6 5 5 5 6 6 5 5 5 6
6 5 5 6 5 6 5 5 6 5
6 5 5 6 6 6 5 5 6 6
6 5 6 5 5 6 5 6 5 5
6 5 6 5 6 6 5 6 5 6
6 5 6 6 5 6 5 6 6 5
6 5 6 6 6 6 5 6 6 6
6 6 5 5 5 6 6 5 5 5
6 6 5 5 6 6 6 5 5 6
6 6 5 6 5 6 6 5 6 5
6 6 5 6 6 6 6 5 6 6
6 6 6 5 5 6 6 6 5 5
6 6 6 5 6 6 6 6 5 6
6 6 6 6 5 6 6 6 6 5
6 6 6 6 6 6 6 6 6 6
6 7 6 7 6 7 6 7 6 7
7 6 7 6 7 6 7 6 7 6
7 7 7 7 7 7 7 7 7 7
8 8 8 8 8 8 8 8 8 8
8 9 8 9 8 9 8 9 8 9

 */