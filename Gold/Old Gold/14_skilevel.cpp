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
const int MX =5e2+5;
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

int dx[]={0,1}, dy[]={1,0};
int m,n,t, a[MX][MX];
ll ret;

int tr(int a, int b){
	return a*n+b;//WAS BUG HERE, REPLACED N with M
}
struct DSU{
	int n;
	vi pts, e;
	void init(int N){
		n=N;
		pts=vi(n,0);
		e=vi(n,-1);
		dbg(e[0],e[1],e[2]);
	}
	int get(int x){
		return (e[x]<0)?x:e[x]=get(e[x]);
	}
	bool unite(int x, int y, int len){
		x=get(x), y=get(y);
		if(x==y)return false;
		if(e[y]<e[x])swap(x,y);

		e[x]+=e[y];e[y]=x;
		pts[x]+=pts[y];
		if(-e[x]>=t){
			dbg("HI",pts[x],x,len);
			ret+=(ll)pts[x]*len;
			pts[x]=0;
		}
		return true;
	}
};

DSU dsu;
vector<pair<int,pi>> ev;
int main() {
	setIO("skilevel");
	cin>>m>>n>>t;
	dsu.init(m*n+5);
	For(i,m)For(j,n)cin>>a[i][j];
	For(i,m)For(j,n)cin>>dsu.pts[tr(i,j)];
	For(i,m)For(j,n)For(t,2){
		if(i+dx[t]<m && j+dy[t]<n){
			dbg(i+dx[t],j+dy[t]);
			ev.pb(mp(abs(a[i][j]-a[i+dx[t]][j+dy[t]]),mp(tr(i,j),t)));
		}
	}
	sort(all(ev));
	trav(x,ev){
		pi tmp=mp(x.s.f/n,x.s.f%n);
		pi tmp2=mp(tmp.f+dx[x.s.s],tmp.s+dy[x.s.s]);
		dbg(tmp.f,tmp.s,tmp2.f,tmp2.s,x.s.s,x.f,x.s.f);
		dsu.unite(tr(tmp.f,tmp.s),tr(tmp2.f,tmp2.s),x.f);
	}
	cout << ret<< nl;
}