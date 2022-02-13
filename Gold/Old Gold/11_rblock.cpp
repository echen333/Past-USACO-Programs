#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,int> pl;
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
//OVERFLOW?

int n,m;
vpi adj[MX], imp;
pl d[MX];
ll mx=0;

ll go(){
	vector<ll> dist(n,INF);
	dist[0]=0;
	priority_queue<int,vi,greater<int>> pq;
	pq.push(0);
	while(sz(pq)){
		int x=pq.top();pq.pop();
		trav(y,adj[x]){
			if(ckmin(dist[y.f],dist[x]+y.s)){
				pq.push(y.f);
			}
		}
	}
	assert(dist[n-1]!=INF);
	dbg(dist[n-1]);
	return dist[n-1];
}

int main() {
	setIO("rblock");
	cin >> n>> m;
	For(i,n)d[i]=mp(INF,0);
	d[0]=mp(0,-1);

	For(i,m){
		int a, b, c;cin>>a>>b>>c;
		a--;b--;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	priority_queue<int,vi,greater<int>> pq;
	pq.push(0);
	while(sz(pq)){
		int x=pq.top();pq.pop();
		trav(y,adj[x]){
			if(d[y.f].f>d[x].f+y.s){
				d[y.f]=mp(d[x].f+y.s,x);
				pq.push(y.f);
			}
		}
	}
	int cur=n-1,prev=-1;
	while(cur!=-1){
		prev=cur;
		cur=d[cur].s;
		if(cur!=-1)
			imp.pb(mp(prev,cur));
	}

	trav(x,imp){
		trav(y,adj[x.f])
			if(y.f==x.s)y.s*=2;
		trav(y,adj[x.s])
			if(y.f==x.f)y.s*=2;
		mx=max(mx,go());
		dbg(mx);
		trav(y,adj[x.f])
			if(y.f==x.s)y.s/=2;
		trav(y,adj[x.s])
			if(y.f==x.f)y.s/=2;
	}
	dbg(d[n-1].f);
	cout<<mx-d[n-1].f<<nl;
}