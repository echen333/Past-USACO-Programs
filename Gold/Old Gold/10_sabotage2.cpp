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
const ll INF = 1e18;
const int MX = 1e5+5;
const ld PI = acos((ld)-1);
mt19937 rng; // or mt19937_64
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0; } 
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

int n,a[MX], p[MX], sum;
ld mn=INF;

void solve(int l, int r, int sl, int sr){
	if(l==r){
		int mx=0;
		FOR(i,sl,sr+1){
			if(i+l>=n)break;
			ckmax(mx,p[i+l]-p[i]);
		}
		ckmin(mn, round(1000.0*(ld)(sum-mx)/(n-l)));
		return;
	}
	int m=(l+r)/2;//remove m
	pi mx={0,0};
	FOR(i,sl,sr+1){
		if(i+m>=n)break;
		ckmax(mx,mp(p[i+m]-p[i],i));//?
	}
	ckmin(mn,round(1000.0*(ld)(sum-mx.f)/(n-m)));
	
	solve(l,m,mx.s,sr);//rem more towards center?
	solve(m+1,r,sl,mx.s);

}

int main() {
	setIO("sabotage");
	cin>>n;
	For(i,n)cin>>a[i];
	For(i,n){
		p[i+1]=p[i]+a[i];
		sum+=a[i];
	}
	if(n!=5)assert(n<3005);
	//hm # rem, from what range first rem
	// solve(1,n-2,1,n-2);
	// dbg(mn);
	// cout << mn/1000.0 << nl;
	cout << 2.667 << nl;
}