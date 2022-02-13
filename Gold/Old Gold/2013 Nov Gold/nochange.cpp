#include "bits/stdc++.h"
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

#define lb lower_bound
#define ub upper_bound

int dp[(1<<16)+5];

int main() {
	setIO("nochange");
	int n,k;cin>>k>>n;
	vi pre(n+1,0), a(n), b(n);
	ll tot=0;
	For(i,k)cin>>b[i],tot+=b[i];
	For(i,n)cin>>a[i],pre[i+1]=pre[i]+a[i];
	ll ans=-1;
	For(i,1<<k)dp[i]=0;
	FOR(i,1,1<<k){
		ll tmp2=0;
		For(j,k)if(i&(1<<j)){
			int tmp=dp[i-(1<<j)];
			int val=pre[tmp];
			//fst one i cant purchase
			auto it=ub(all(pre),val+b[j]);
			int dist=it-pre.begin();
			dp[i]=max(dp[i],dist-1);
			tmp2+=b[j];
		}
		dbg(i,tot,tmp2,dp[i]);
		if(dp[i]==n){
			ans=max(ans,tot-tmp2);
		}
	}
	// assert(ans!=-1);
	cout<<ans<<endl;
}