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
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define nl '\n' 

const int MOD = 1e9+7;
const int MX = 7e4+5;
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

/**
 * Description: The centroid of a tree of size $N$ is a vertex such that 
 	* after removing it, all resulting subtrees have size at most $\frac{N}{2}.$ 
 	* Supports updates in the form ``add 1 to all verts $v$ such that $dist(x,v)\le y$."
 * Time: O(N\log N) build, O(\log N) update and query
 * Memory: O(N\log N)
 * Source: own
 * Verification: 
	* solves https://dmoj.ca/problem/dmopc19c7p6
	* https://codeforces.com/contest/342/problem/E
	* Triway Cup 2019 G
 */

int n;

void ad(vi& a, int b) { ckmin(b,sz(a)-1); if (b>=0) a[b]++; }
template<int SZ> struct Centroid {
	vi adj[SZ]; void ae(int a,int b){adj[a].pb(b),adj[b].pb(a);}
	bool done[SZ]; // processed as centroid yet
	int N,sub[SZ],cen[SZ],lev[SZ]; // subtree size, centroid anc
	int dist[32-__builtin_clz(SZ)][SZ]; // dists to all ancs
	vi stor[SZ], STOR[SZ];
	
	int leafDist[SZ],par[SZ], cnt;//make sure not using dist
	vi leaves, cur;

	void dfs(int x, int p) { sub[x] = 1; 
		trav(y,adj[x]) if (!done[y] && y != p) 
			dfs(y,x), sub[x] += sub[y]; 
	}
	int centroid(int x) {
		dfs(x,-1); 
		for (int sz = sub[x];;) {
			pi mx = {0,0};
			trav(y,adj[x]) if (!done[y] && sub[y] < sub[x]) 
				ckmax(mx,{sub[y],y});
			if (mx.f*2 <= sz) return x; 
			x = mx.s;
		}
	}

	void genDist(int x, int p, int lev) {
		dist[lev][x] = dist[lev][p]+1;
		trav(y,adj[x]) if (!done[y] && y != p) genDist(y,x,lev); }
	void dfs2(int x, int p){//CONSTANT
		par[x]=p;
		if(sz(adj[x])==1)leaves.pb(x);
		trav(y,adj[x])if(y!=p){
			dfs2(y,x);
		}
	}
	void dfs3(int x, int p, int depth){
		if(depth && leafDist[x]>=depth){
			cur.pb(x);
			cnt++;
			return;
		}
		trav(y,adj[x])if(y!=p){
			dfs3(y,x,depth+1);
		}
	}
	void gen(int CEN, int _x) { // CEN = centroid above x
		int x = centroid(_x); done[x] = 1; cen[x] = CEN; 
		sub[x] = sub[_x]; lev[x] = (CEN == -1 ? 0 : lev[CEN]+1);
		//HUH
		dist[lev[x]][x] = 0; 
		stor[x].resize(sub[x]),STOR[x].resize(sub[x]+1); 

		cur.clear();leaves.clear();cnt=0;
		
		dfs2(x,x);
		//gen leaf dist from leaves
		queue<int> q;
		trav(x,leaves){
			q.push(x);
			leafDist[x]=0;
		}//leafDist is just constant right?
		while(sz(q)){
			int x=q.front();q.pop();
			trav(y,adj[x])
				if(leafDist[y]>leafDist[x]+1){
					leafDist[y]=leafDist[x]+1;
					q.push(y);
				}
		}
		trav(y,adj[x]){
			dfs3(y,x,1);//gets cnt
		}
		
		stor[x][0]=cnt;
		FOR(i,1,sub[x]){
			vi tmp;
			trav(y,cur)tmp.pb(par[y]);
			// tmp.erase(unique(all(tmp),tmp.end()));
			cur=tmp;
			stor[x][i]=sz(tmp);
		}
		//need STOR for subtract same subtree


		trav(y,adj[x]) if (!done[y]) genDist(y,x,lev[x]);
		trav(y,adj[x]) if (!done[y]) gen(x,y);
	}
	void init(int _N) { N = _N; 
		FOR(i,1,N+1){
			done[i] = 0;
			leafDist[i]=MOD;
		} 
		gen(-1,1);
		  } // start at vert 1
	// void upd(int x, int y) { 
	// 	int cur = x, pre = -1;
	// 	R0F(i,lev[x]+1) {
	// 		ad(stor[cur],y-dist[i][x]); 
	// 		if (pre != -1) ad(STOR[pre],y-dist[i][x]);
	// 		if (i > 0) pre = cur, cur = cen[cur];
	// 	}
	// } // call propAll() after all updates
	// void propAll() { FOR(i,1,N+1) prop(stor[i]), prop(STOR[i]); }
	int query(int x) { // get value at vertex x
		//GOING UP CENTROID TREE
		int cur = x, pre = -1, ans = 0;
		R0F(i,lev[x]+1) { // if pre != -1, subtract those from
			ans += stor[cur][dist[i][x]]; // same subtree
			
			
			if (pre != -1) ans -= STOR[pre][dist[i][x]];
			if (i > 0) pre = cur, cur = cen[cur];
		}
		return ans;
	}
};

Centroid<MX> C;
int main() {
	setIO("atlarge");
	cin>>n;
	For(i,n-1){
		int a,b;cin>>a>>b;
		C.ae(a,b);
	}
	C.init(n+1);
	FOR(i,1,n+1){
		cout << C.query(i) << nl;
	}
}