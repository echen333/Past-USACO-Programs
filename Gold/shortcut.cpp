#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 50001;

void setIO(string name = "shortcut") { // name is nonempty for USACO file I/O
    cin.tie(0)->sync_with_stdio(0); // see Fast Input & Output
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n, m, t,c[MX], visited[MX];
vpi adj[MX];
vi adj2[MX];

void dfs(int n, int p){
    for(int x:adj2[n]){
        if(x!=p){
            dfs(x,n);
            c[n]+=c[x];
        }
    }
}

int main() {
    setIO();
    cin >> n >> m >> t;
    F0R(i,n)cin >> c[i];
    F0R(i,m){
        int u,v,w; cin >> u >> v>>w; u--; v--;
        adj[u].push_back(mp(v,w)); adj[v].push_back(mp(u,w));
    }
    F0R(i,n)visited[i]=1e9;
    priority_queue<pair<pi,int>> pq;
    pq.push(mp(mp(0,0),0));//-dist, -field from, field to
    while(!pq.empty()){
        pair<pi,int> x=pq.top();pq.pop();
        int a=-x.first.first,b=-x.first.second, d=x.second;
        if(visited[d]!=1e9)continue;
        visited[d]=a;
        adj2[b].push_back(d); adj2[d].push_back(b);
        for(pi y:adj[d])
            if(visited[y.first]==1e9)
                pq.push(mp(mp(-(a+y.second),-d), y.first));
    }
    dfs(0,0);
    ll ret=0;
    F0R(i, n){
        ret=max(ret, (visited[i]-t)*1LL*c[i]);
    }
    cout << ret;
}