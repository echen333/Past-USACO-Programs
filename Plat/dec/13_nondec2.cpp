#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi; 
typedef vector<pi> vpi;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define bk back()
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define For(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define Rof(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define nl '\n' 

const int MOD = 1e9+7;
const int MX = 3e5+5;
const ld PI = acos((ld)-1);
mt19937 rng; // or mt19937_64
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << h; if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

#pragma once

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend string ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

typedef array<mi,20> T;
typedef array<T,20> TT;

int n,k,a[MX];
mi ans[MX], tmp[MX];

void divi(vector<array<int,3>> q, int L, int R){
	if(!sz(q))return;
	if(L==R){
		trav(x,q)ans[x[2]]=2;
		return;
	}

	vector<array<int,3>> l,m,r;
	int M=(L+R)/2;
	trav(x,q){
		if(x[1]<=M)l.pb(x);
		else if(x[0]>M)r.pb(x);
		else m.pb(x);
	}
	divi(l,L,M);divi(r,M+1,R);
	if(!sz(m))return;

	swap(q,m); if (!sz(q)) return;
    F0R(v,K) {
        {
            T lef = T();
            for (int i = M ; i >= L; --i) {
                if (A[i] <= v) {
                    mi sum = (A[i] == v); 
                    FOR(j,A[i],v+1) sum += lef[j];
                    lef[A[i]] += sum;
                }
                tmp[i] = (v == 0); F0R(j,v+1) tmp[i] += lef[j];
            }
        }
        {
            T rig = T();
            for (int i = M+1; i <= R; ++i) {
                if (A[i] >= v) {
                    mi sum = 1;
                    FOR(j,v,A[i]+1) sum += rig[j];
                    rig[A[i]] += sum;
                }
                tmp[i] = 1; FOR(j,v,K) tmp[i] += rig[j];
            }
        }
        trav(t,q) ans[t[2]] += tmp[t[0]]*tmp[t[1]];
    }
}

int main() {
	setIO("nondec");
	cin>>n>>k;
	For(i,n){
		cin>>a[i];
		a[i]--;
	}

	int Q;cin>>Q;
	vector<array<int,3>> q;
	For(i,Q){
		int l,r;cin>>l>>r;
		l--;r--;
		q.pb({l,r,i});
	}
	divi(q,0,n-1);
	For(i,Q){
		cout<<ans[i].v<<nl;
	}
}