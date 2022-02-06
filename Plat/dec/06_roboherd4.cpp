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
const int MX = 300+7;
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

ll n,k;
ll  cur;
ll ret=0, mn=0, mx;
vector<vi> a;
//idk why robo3 works but this doesnt
//robo 3 just tls on 11-15 
//ROBO 3 works
void dfs(ll room, int ind, int p){
	if(room>mx)return;
	if(cur>=k)return;

	ret+=room;cur++;
	if(p+1<sz(a[ind]))
		dfs(room+a[ind][p+1]-a[ind][p],ind,p+1);
	if(cur>=k)return;
	if(ind+1<sz(a)){
		if(p==0)dfs(room-a[ind][0]+a[ind+1][0],ind+1,0);
		if(cur>=k)return;
		dfs(room+a[ind+1][0],ind+1,0);
	}
}

int main() {
	setIO("roboherd");
	cin >> n >> k;
	For(i,n){
		int m;
		vi v,v2;
		cin>> m;
		For(i,m){
			int x;cin >> x;
			v.pb(x);
		}
		sort(all(v));
		FOR(i,1,sz(v)){
			v2.pb(v[i]-v[0]);
		}
		mn+=v[0];
		if(sz(v2))a.pb(v2);
	}
	sort(all(a));

	ll l=mn, r=(ll)MOD*n;
	while(l!=r){
		ll m=(l+r)/2;
		cur=1; ret=0;mx=m;
		dfs(mn+a[0][0],0,0);
		if(cur>=k)r=m;
		else l=m+1;
	}
	cur=1,ret=mn;mx=l;
	dfs(mn+a[0][0],0,0);
	ret-=(cur-k)*l;
	cout << ret << nl;
}