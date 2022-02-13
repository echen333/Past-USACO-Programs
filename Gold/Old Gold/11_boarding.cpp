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
const int MX = 4e5+5;
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

// struct BIT{
// 	int n;
// 	vi v;
// 	void init(int N){
// 		n=N;
// 		v=vi(n+5,0);
// 	}
// 	void upd(int p, int val){
// 		assert(p>0);
// 		for(int i=p;i<=n;i+= i&-i){
// 			v[i]+=val;
// 		}
// 	}
// 	ll query(int x){
// 		ll ret=0;
// 		for(int i=x;i>0;i-= i&-i){
// 			ret+=v[i];
// 		}
// 		return ret;
// 	}
// };

/**
 * Description: range sum queries and point updates for $D$ dimensions
 * Source: https://codeforces.com/blog/entry/64914
 * Verification: SPOJ matsum
 * Usage: \texttt{BIT<int,10,10>} gives 2D BIT
 * Time: O((\log N)^D)
 */

template <class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
	template<typename... Args> T query(int r, Args... args) {
		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
		return res; }
	// template<typename... Args> T query(int l, int r, Args... 
	// 	args) { return sum(r,args...)-sum(l-1,args...); }
}; 

// BIT bit;
BIT<ll,MX> bit;
ll mx=0;
pi a[MX];
int main() {
	setIO("boarding");
	int n;cin>> n;
	FOR(i,1,n+1){
		cin>>a[i].f>>a[i].s;
	}
	ROF(i,1,n+1){
		int st=i-n;
		dbg(i-a[i].f,i-a[i].f+n);
		mx=max(mx,a[i].f-st+a[i].s + bit.query(a[i].f-i+n-1) );
		bit.upd(a[i].f-i+n,a[i].s);
	}
	cout << mx << nl;
}