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

#define For(i, a) for (int i=0; i<(a); i++)
#define Ford(i,a) for (int i = (a); i >= 0; i--)
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
const int MX = 100001;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    cin.tie(0)->sync_with_stdio(0); // see Fast Input & Output
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
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

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return a^b; }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {	// sum on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

int n,q, timer, e[MX], timeIn[MX], timeOut[MX], tracker[2*MX+3];
vi adj[MX];
Seg<int> S;

void dfs(int n, int p){
    timer++;
    timeIn[n]=timer;
    tracker[timer]=n;
    for(int x:adj[n]){
        if(x!=p)
            dfs(x,n);
    }
    timer++;
    timeOut[n]=timer;
    tracker[timer]=n;
}
int main() {
    setIO();
    cin >> n >> q;
    S.init(2*n);
    For(i,n)cin >> e[i];
    For(i,n-1){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(0,0);
    For(i,2*n)S.upd(i,e[tracker[i]]);
    For(i,q){
        int a, j, k; cin >> a >> j >> k;j--;k--;
        if(a==1){
            int tmp=S.query(timeIn[j],timeIn[j]);
            S.upd(timeIn[j],k^tmp);
            S.upd(timeOut[j],k^tmp);
        }
        else{
            int t1=timeIn[j], t2=timeOut[j], t3=timeIn[k], t4=timeOut[k];
            if((t1<t3 && t2>t4) || (t1>t3 && t4>t2)){
                cout << S.query()
            }
        }
    }
}

