// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <time.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <complex.h>
// #include <random>
// #include <chrono>
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
const int MOD = 1e9+7; // 998244353;
const int MX = 3e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

/**
 * Description: Big Integer
 * Source: https://github.com/indy256/codelibrary/blob/master/cpp/numeric/bigint.cpp
    * oops that one uses FFT instead of Karatsuba now ....
 * Verification: https://oj.uz/problem/view/IOI11_parrots
 */

// base and base_digits must be consistent
const int base = 1e9, base_digits = 9;
struct bigint { // value == 0 is represented by empty z
    vi z; // digits
    int sign; // sign == 1 <==> value >= 0
    bigint() : sign(1) {} // sign == -1 <==> value < 0
    bigint(ll v) { *this = v; }
    bigint &operator=(ll v) {
        sign = v < 0 ? -1 : 1; v *= sign; // make v positive
        z.clear(); for (;v;v/=base) z.pb(v%base);
        return *this;
    }
    bigint(const str &s) { read(s); } // add char by char

    bigint &operator+=(const bigint &other) {
        //dbg("ADDING",*this,other,sign,other.sign);
        if (sign == other.sign) {
            for (int i = 0, carry = 0; i < sz(other.z) || carry; ++i) {
                if (i == sz(z)) z.pb(0);
                z[i] += carry+(i<sz(other.z)?other.z[i]:0);
                carry = z[i] >= base; if (carry) z[i] -= base;
            }
        } else if (other != 0 /* prevent infinite loop */) *this -= -other;
        return *this;
    }
    friend bigint operator+(bigint a, const bigint &b) { return a += b; }
    bigint &operator-=(const bigint &other) {
        if (sign == other.sign) {
            if ((sign == 1 && *this >= other) || (sign == -1 && *this <= other)) {
                for (int i = 0, carry = 0; i < sz(other.z) || carry; ++i) {
                    z[i] -= carry+(i<sz(other.z)?other.z[i]:0);
                    carry = z[i]<0; if (carry) z[i] += base;
                }
                trim();
            } else { // result will change sign
                *this = other-*this;
                this->sign = -this->sign;
            }
        } else *this += -other;
        return *this;
    }
    friend bigint operator-(bigint a, const bigint &b) { return a -= b; }

    bigint &operator*=(int v) { // oops make sure not to multiply by ll ...
        if (v < 0) sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < sz(z) || carry; ++i) {
            if (i == sz(z)) z.pb(0);
            ll cur = (ll)z[i]*v+carry;
            carry = cur/base; z[i] = cur%base;
        }
        trim(); return *this;
    }
    bigint operator*(int v) const { return bigint(*this) *= v; }
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base/(b1.z.bk+1);
        bigint a = a1.abs()*norm, b = b1.abs()*norm, q, r; // make last element of b big
        q.z.rsz(sz(a.z));
        R0F(i,sz(a.z)) {
            r *= base; r += a.z[i];
            int s1 = sz(b.z) < sz(r.z) ? r.z[sz(b.z)] : 0;
            int s2 = sz(b.z)-1 < sz(r.z) ? r.z[sz(b.z)-1] : 0;
            int d = ((ll)s1*base+s2)/b.z.bk; // best approximation
            r -= b*d; while (r < 0) r += b, --d;
            q.z[i] = d;
        }
        q.sign = a1.sign*b1.sign; r.sign = a1.sign;
        q.trim(); r.trim(); return {q,r/norm};
    }
    friend bigint sqrt(const bigint &a1) {
        bigint a = a1; while (!sz(a.z) || sz(a.z)&1) a.z.pb(0);
        int n = sz(a.z), firstDigit = ::sqrt((db)a.z[n-1]*base+a.z[n-2]);
        int norm = base/(firstDigit+1); a *= norm; a *= norm;
        while (!sz(a.z) || sz(a.z)&1) a.z.pb(0);
        bigint r = (ll)a.z[n-1]*base+a.z[n-2];
        firstDigit = (int)::sqrt((db)a.z[n-1]*base+a.z[n-2]);
        int q = firstDigit; bigint res;
        R0F(j,n/2) {
            for (;; --q) {
                bigint r1 = (r-(res*2*base+q)*q)*base*base +
                            (j>0?(ll)a.z[2*j-1]*base+a.z[2*j-2]:0);
                if (r1 >= 0) { r = r1; break; }
            }
            res *= base; res += q; // add a bit to sqrt
            if (j > 0) {
                int d1 = sz(res.z)+2 < sz(r.z) ? r.z[sz(res.z)+2] : 0; // always 0/1?
                int d2 = sz(res.z)+1 < sz(r.z) ? r.z[sz(res.z)+1] : 0;
                int d3 = sz(res.z) < sz(r.z) ? r.z[sz(res.z)] : 0;
                q = ((ll) d1*base*base+(ll)d2*base+d3)/(firstDigit*2);
            }
        }
        res.trim(); return res/norm;
    }
    bigint operator/(const bigint &v) const { return divmod(*this, v).f; }
    bigint operator%(const bigint &v) const { return divmod(*this, v).s; }
    bigint &operator/=(int v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = sz(z)-1, rem = 0; i >= 0; --i) {
            ll cur = z[i]+rem*(ll)base;
            z[i] = cur/v; rem = cur%v;
        }
        trim(); return *this;
    }
    bigint operator/(int v) const { return bigint(*this) /= v; }
    int operator%(int v) const {
        if (v < 0) v = -v;
        int m = 0; R0F(i,sz(z)) m = (z[i]+m*(ll)base)%v;
        return m*sign; }
    bigint &operator*=(const bigint &v) { return *this = *this*v; }
    bigint &operator/=(const bigint &v) { return *this = *this/v; }

    bool operator<(const bigint &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (sz(z) != sz(v.z)) return sz(z)*sign < sz(v.z) * v.sign;
        R0F(i,sz(z)) if (z[i] != v.z[i]) return z[i]*sign < v.z[i]*sign;
        return 0; // equal
    }
    bool operator>(const bigint &v) const { return v < *this; }
    bool operator<=(const bigint &v) const { return !(v < *this); }
    bool operator>=(const bigint &v) const { return !(*this < v); }
    bool operator==(const bigint &v) const { return !(*this < v) && !(v < *this); }
    bool operator!=(const bigint &v) const { return *this < v || v < *this; }
    void trim() {
        while (sz(z) && z.bk == 0) z.pop_back();
        if (!sz(z)) sign = 1; // don't output -0
    }
    bool isZero() const { return !sz(z); }
    friend bigint operator-(bigint v) {
        if (sz(v.z)) v.sign = -v.sign;
        return v; }
    bigint abs() const { return sign == 1 ? *this : -*this; }
    ll longValue() const {
        ll res = 0; R0F(i,sz(z)) res = res*base+z[i];
        return res*sign; }
    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b); } // euclidean algo
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a/gcd(a, b) * b; }

    void read(const str &s) {
        sign = 1; z.clear(); int pos = 0;
        while (pos < sz(s) && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos; } // account for sign
        for (int i = sz(s)-1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i-base_digits+1); j <= i; j++)
                x = x*10+s[j]-'0';
            z.pb(x);
        }
        trim();
    }
    friend istream &operator>>(istream &is, bigint &v) {
        str s; is >> s; v.read(s); return is; }
    friend ostream &operator<<(ostream &os, const bigint &v) {
        if (v.sign == -1) os << '-';
        os << (!sz(v.z) ? 0 : v.z.bk);
        R0F(i,sz(v.z)-1) os << setw(base_digits) << setfill('0') << v.z[i];
        return os; // pad with zeroes
    }
    static vi convert_base(const vi &a, int old_digits, int new_digits) {
        vl p(max(old_digits, new_digits) + 1); // blocks of 10^{old} -> 10^{new}
        p[0] = 1; FOR(i,1,sz(p)) p[i] = p[i-1]*10;
        vi res; ll cur = 0; int cur_digits = 0;
        for (int v:a) {
            cur += v*p[cur_digits]; cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.pb(cur%p[new_digits]);
                cur /= p[new_digits]; cur_digits -= new_digits;
            }
        }
        res.pb(cur); while (sz(res) && res.bk == 0) res.pop_back();
        return res;
    }
    static vl karatMul(const vl &a, const vl &b) { // karatsuba
        int n = sz(a); vl res(2*n);
        if (n <= 32) { // naive multiply
            F0R(i,n) F0R(j,n) res[i+j] += a[i]*b[j];
            return res; }
        int k = n/2;
        vl a1(begin(a),begin(a)+k), a2(k+all(a));
        vl b1(begin(b),begin(b)+k), b2(k+all(b));
        vl a1b1 = karatMul(a1, b1), a2b2 = karatMul(a2, b2);
        F0R(i,k) a2[i] += a1[i], b2[i] += b1[i];
        vl r = karatMul(a2, b2); // three instead of four products
        F0R(i,sz(a1b1)) r[i] -= a1b1[i];
        F0R(i,sz(a2b2)) r[i] -= a2b2[i];
        F0R(i,sz(r)) res[i+k] += r[i];
        F0R(i,sz(a1b1)) res[i] += a1b1[i];
        F0R(i,sz(a2b2)) res[i+n] += a2b2[i];
        return res;
    }
    bigint operator*(const bigint &v) const {
        if (min(sz(z),sz(v.z)) < 150) return mul_simple(v);
        bigint res; res.sign = sign*v.sign; // should work as long as # of digits isn't too large (> LLONG_MAX/10^{12})
        vi a6 = convert_base(this->z, base_digits, 6); // blocks of 10^6 instead of 10^9
        vi b6 = convert_base(v.z, base_digits, 6);
        vl a(all(a6)), b(all(b6));
        while (sz(a) < sz(b)) a.pb(0);
        while (sz(b) < sz(a)) b.pb(0);
        while (sz(a)&(sz(a)-1)) a.pb(0), b.pb(0); // make size power of 2
        vl c = karatMul(a, b);
        ll cur = 0; F0R(i,sz(c)) { // process carries
            cur += c[i]; res.z.pb(cur%1000000); cur /= 1000000; } 
        res.z = convert_base(res.z,6,base_digits); 
        res.trim(); return res;
    }
    bigint mul_simple(const bigint &v) const {
        bigint res; res.sign = sign*v.sign;
        res.z.rsz(sz(z)+sz(v.z));
        F0R(i,sz(z)) if (z[i]) {
            ll cur = 0; for (int j = 0; j < sz(v.z) || cur; ++j) {
                cur += res.z[i+j]+(ll)z[i]*(j<sz(v.z)?v.z[j]:0);
                res.z[i+j] = cur%base; cur /= base;
            }
        }
        res.trim(); return res;
    }
    friend str ts(const bigint& v) {
        stringstream ss; ss << v;
        str s; ss >> s; return s; }
};

bigint random_bigint(int n) {
    str s; F0R(i,n) s += rand() % 10 + '0';
    return bigint(s); }

// random tests
void bigintTest() {
    bigint x = bigint("120");
    bigint y = bigint("5");
    cout << x / y << endl;
    F0R(i,1000) {
        int n = rand() % 100 + 1;
        bigint a = random_bigint(n), res = sqrt(a);
        bigint xx = res * res, yy = (res + 1) * (res + 1);
        if (xx > a || yy <= a) {
            dbg("SQRT FAILED",i);
            dbg(a,res);
            break;
        }
        int m = rand() % n + 1;
        bigint b = random_bigint(m)+1;
        res = a/b; xx = res*b, yy = b*(res+1);
        if (xx > a || yy <= a) {
            dbg("DIVISION FAILED",i);
            dbg(a,b,res);
            break;
        }
    }
    {
        bigint a = random_bigint(10000);
        bigint b = random_bigint(2000);
        auto t1 = chrono::high_resolution_clock::now();
        bigint c = a / b;
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = t2 - t1;
        dbg(duration.count(),"ms");
    }
    bigint a = random_bigint(500000);
    bigint b = random_bigint(500000);
    bigint c1, c2;
    {
        auto t1 = chrono::high_resolution_clock::now();
        c1 = a * b;
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = t2 - t1;
        dbg(duration.count(),"ms");
    }
    {
        auto t1 = chrono::high_resolution_clock::now();
        c2 = a.mul_simple(b);
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = t2 - t1;
        dbg(duration.count(),"ms");
    }
    dbg(c1 == c2);
    {

        auto t1 = chrono::high_resolution_clock::now();
        F0R(i,1000000) {
            a = random_bigint(30);
            b = random_bigint(30);
            c2 = a.mul_simple(b);
        }
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = t2 - t1;
        dbg(duration.count(),"ms");
    }
}

map<bigint,pair<str,str>> m;
bigint one=1;
bigint tw=2;

bool have(bigint ind, bigint se){//se includes me
    se-=one;
    if(se)

        /*
        if even have(m[ind].s,se/2);
        if odd have(m[ind].f,se/2+1);
         */
}

bigint go(bigint ind){//find sz including me
    ps(ind);
    str a,b;re(a,b);
    m[ind]=mp(a,b);

    bigint x=1;
    if(b[0]!='0'){
        x=go(b);
        if(have(a,x+1))return tw*x+tw;
        else return tw*x+one;
    }
    else{
        return 1+(a[0]=='1');
    }
}

void solve(){
    ps("Answer"+ts(go(1)));
}

int main() {
        setIO();
        int t=1;
        // re(t);
        while(t--)solve();
        // you should actually read the stuff at the bottom
}

//psums, bsearch, two pointers
/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * think of simple solution first
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
*/