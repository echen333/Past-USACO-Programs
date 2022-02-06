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
#define rsz resize
#define bk back()
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define For(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define Rof(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const int MX = 1e3+7;
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
 * Description: 1D point update, range query where \texttt{comb} is
 	* any associative operation. If $N=2^p$ then \texttt{seg[1]==query(0,N-1)}.
 * Time: O(\log N)
 * Source: 
	* http://codeforces.com/blog/entry/18051
	* KACTL
 * Verification: SPOJ Fenwick
 */
/**
 * Description: 1D range increment and sum query.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */

template<class T, int SZ> struct LazySeg { 
	const T ID = 0; T comb(T a, T b) { return a+b; }
	T seg[2*SZ], lazy[2*SZ], lazy2[2*SZ]; 
	LazySeg() { F0R(i,2*SZ){
		seg[i] = lazy[i] = ID;
		lazy2[i]=1;
	}  }
	void push(int ind, int L, int R) { /// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) F0R(i,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc;push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	void upd2(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy2[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; 
		return comb(query(lo,hi,2*ind,L,M),query(lo,hi,2*ind+1,M+1,R));
	}
};

ll ad(ll x, ll y){
	return (x+y>=MOD?x+y-MOD:x+y);
}

/**
 * Description: Multiply two 64-bit integers mod another if 128-bit is not available.
	* modMul is equivalent to \texttt{(ul)(\_\_int128(a)*b\%mod)}. 
	* Works for $0\le a,b<mod<2^{63}.$
 * Source: KACTL
 * Verification: see "Faster Factoring"
 */

typedef unsigned long long ul;
ul modMul(ul a, ul b, const ul mod) {
	ll ret = a*b-mod*(ul)((ld)a*b/mod);
	return ret+((ret<0)-(ret>=(ll)mod))*mod; }
ul modPow(ul a, ul b, const ul mod = MOD) {
	if (b == 0) return 1;
	ul res = modPow(a,b/2,mod); res = modMul(res,res,mod);
	return b&1 ? modMul(res,a,mod) : res;
}


int n, k, cur[MX];
ll cnt[MX], ret;
LazySeg<int,(1<<10)> seg[MX];
vpi ev;

int main() {
	setIO("help");
	cin >> n >> k;
	seg[0].upd(0,0,1);
	For(i,n){
		int l,r;
		cin >> l >> r;
		ev.pb(mp(l,r));
	}
	sort(all(ev));
	FOR(j,1,n){
		For(i,sz(ev)){
			pi x=ev[i];
			cur[i]=seg[j-1].query(0,x.f)+seg[j].query(x.f,x.s);
			seg[j].upd(x.s,cur[i]);
			cnt[j]=ad(cnt[j],cur[i]);
		}
		ll tmp=modPow(j,k)*(ll)cnt[j]%MOD;
		dbg(j,cnt[j]);
		ret=ad(ret,tmp);
	}
	cout << ret << '\n';
	dbg(ret);
 }