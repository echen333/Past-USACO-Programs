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

#define nl '\n' 

const int MOD = 1e9+7;
const int MX = 1e5+7;
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
 * Description: 1D range increment and sum query.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */
/**
 * Description: Multiply two 64-bit integers mod another if 128-bit is not available.
	* modMul is equivalent to \texttt{(ul)(\_\_int128(a)*b\%mod)}. 
	* Works for $0\le a,b<mod<2^{63}.$
 * Source: KACTL
 * Verification: see "Faster Factoring"
 */
/**
 * Description: pre-compute factorial mod inverses,
 	* assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

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

ll comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}

void ad(ll &a, ll b){
	a+=b;
	if(a>=MOD)a-=MOD;
}

template<class T, int SZ> struct LazySeg { 
	const T ID = 0; T comb(T a, T b) { return (a+b>=MOD?a+b-MOD:a+b); }
	T seg[2*SZ], lazy[2*SZ], lazy2[2*SZ]; 
	LazySeg() { F0R(i,2*SZ){
			seg[i] = lazy[i] = ID;
			lazy2[i]=1LL;
		} 
	}
	void push(int ind, int L, int R) { /// modify values for current node
		ad(seg[ind],(R-L+1)*lazy[ind]);
		seg[ind]%=MOD;
		if (L != R)
		 	F0R(i,2){
		 		ad(lazy[2*ind+i],lazy[ind]);
		 	}  /// prop to children
		lazy[ind] = 0LL; 
	} // recalc values for current node
	void push2(int ind, int L, int R) { /// modify values for current node
		seg[ind] *= lazy2[ind]; // dependent on operation
		seg[ind]%=MOD;
		if (L != R){
			F0R(i,2){
				lazy2[2*ind+i] *= lazy2[ind];
				lazy2[2*ind+i]%=MOD;
			} /// prop to children
		}
		lazy2[ind] = 1LL; 
	} // recalc values for current node
	void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
	void build() { ROF(i,1,SZ) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	void upd2(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		assert(inc==2);
		push2(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy2[ind] = inc; push2(ind,L,R); return; }
		int M = (L+R)/2; upd2(lo,hi,inc,2*ind,L,M); 
		upd2(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R);
		push2(ind,L,R);
		 if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; 
		return comb(query(lo,hi,2*ind,L,M),query(lo,hi,2*ind+1,M+1,R));
	}
};

int n,k;
const int MX2=(1<<18)-1;
LazySeg<ll, MX2+1> seg[11];
vector<pi> p;
int main() {
	setIO("help");
	cin >> n >> k;
	genFac(11);
	seg[0].upd(0,0,1LL);
	For(i,n){
		int l,r;cin>> l>>r;
		p.pb(mp(l,r));
	}
	sort(all(p));
	trav(x,p){//n*k^2
		For(i,k+1){
			seg[i].upd2(x.s+1,MX2,2);
			ll tmp=0;
			vector<ll> tmp2(k+1,0);
			For(i,k+1)tmp2[i]=seg[i].query(0,x.f);
			For(j,i+1)
				ad(tmp,comb(i,j)*tmp2[j]);
			ad(tmp,seg[i].query(x.f,x.s-1));
			seg[i].upd(x.s,x.s,tmp);
		}
	}
	ll ans=seg[k].query(0,MX2);
	dbg(ans);
	cout << ans << nl;
}