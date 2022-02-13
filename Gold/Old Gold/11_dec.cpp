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

int n,b, dp[(1<<20)+5], c[21][21];
vpi a[21];

int main() {
	setIO("dec");
	cin >> n >> b;
	For(i,b){
		int b,c,d;cin>>b>>c>>d;
		a[b].pb(mp(c,d));//need p, d additional
	}
	For(i,n)For(j,n)cin>>c[i][j];

	FOR(i,1,(1<<n)){
		int cnt=__builtin_popcount(i)-1;
		For(j,n)if(i & (1<<j)){//jth cow, cnt even
			dp[i]=max(dp[i],dp[i^(1<<j)]+c[j][cnt]);
		}
		dbg(i,cnt);
		trav(x,a[cnt+1]){
			if(dp[i]>=x.f)dp[i]+=x.s;
		}
	}
	cout << dp[(1<<n)-1] <<nl;
}