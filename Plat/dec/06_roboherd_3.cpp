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

int n,k, cur;
ll ret=0, mn=0;
vector<vi> a;

void cnt(){
	priority_queue<pair<pair<ll,int>,int>> pq;//room, ind, p
	pq.push(mp(mp(-mn-a[0][0],0),0));
	while(sz(pq)){
		auto x=pq.top();pq.pop();
		x.f.f=-x.f.f;
		// if(x.f.f>mx)continue;
		ret+=x.f.f;cur++;
		if(cur>=k)break;
		if(x.s+1<sz(a[x.f.s]))
			pq.push(mp(mp(-(x.f.f+a[x.f.s][x.s+1]-a[x.f.s][x.s]),x.f.s),x.s+1));
		if(x.f.s+1<sz(a)){
			if(x.s==0)pq.push(mp(mp(-(x.f.f-a[x.f.s][0]+a[x.f.s+1][0]),x.f.s+1),0));
			pq.push(mp(mp(-(x.f.f+a[x.f.s+1][0]),x.f.s+1),0));
		}
	}
}
int main() {
	setIO("roboherd");
	// cin >> n >> k;
	scanf("%d%d", &n, &k);
	For(i,n){
		int m, b;
		vi v,v2;
		// cin>> m;
		scanf("%d",&m);
		For(i,m){
			int x;
			// cin >> x;
			scanf("%d",&x);
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

	// ll l=mn, r=(ll)MOD*n;
	// while(l!=r){
	// 	ll m=(l+r)/2;
	// 	cur=1; ret=0;
	// 	cnt(m);
	// 	if(cur>=k)r=m;
	// 	else l=m+1;
	// }
	cur=1,ret=mn;
	cnt();
	// ret-=(cur-k)*l;
	cout << ret << nl;
}