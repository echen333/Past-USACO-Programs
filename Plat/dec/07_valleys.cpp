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
const int MX = 750+7;
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
	// ios_base::sync_with_stdio(0); cin.tie(0); 
	cin.tie(0)->sync_with_stdio(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int dx[]={1,1,1,0,0,-1,-1,-1}, dy[]={0,-1,1,1,-1,0,-1,1};
int dx2[]={1,0,-1,0}, dy2[]={0,1,0,-1};
int n, g[MX][MX];
bool c[MX][MX];
vector<pair<int, pi>> ev;
map<pi,int> m;
ll ret=0;

bool side(int x, int y){
	return (x==0 || y==0 || x==n-1 || y==n-1);
}
bool leg(int x, int y){
	return (x>=0 && x<=n-1 && y>=0 && y<=n-1);
}

int tr(int x, int y){
	return x*n+y;
}
pi r(int x){
	return mp(x/n,x%n);
}
struct DSU{
	int n;
	vi p, mx;
	void init(int N){
		n=N;
		p=vi(n,-1);
		mx=vi(n,0);
	}
	int get(int x){
		return (p[x]<0)?x:p[x]=get(p[x]);
	}
	bool same(int x, int y){
		return get(x)==get(y);
	}
	bool unite(int x, int y){
		x=get(x), y=get(y);
		if(x==y)return false;
		if(y==0 || (x!=0 && p[y]<p[x]))swap(x,y);
		p[x]+=p[y];
		p[y]=x;
		mx[x]=max(mx[x],mx[y]);
		return true;
	}
};

DSU dsu;
int main() {
	setIO("valleys");
	cin >> n;
	dsu.init(MX*MX);
	For(i,n){
		For(j,n){
			cin>> g[i][j];
			ev.pb(mp(g[i][j],mp(i,j)));
		}
	}
	sort(all(ev));
	reverse(all(ev));
	// trav(x,ev)dbg(x.f,x.s.f,x.s.s);
	trav(x,ev){
		queue<pi> q;
		if(side(x.s.f,x.s.s)){
			q.push(x.s);
		}
		else{//PROBLEM WAS HERE 201 FOR UPDATE IF NEW
			For(k,8){//HERE BUG 149 6/21
				int nx=x.s.f+dx[k], ny=x.s.s+dy[k];//DECR, which ones need me
				if(leg(nx,ny) && c[nx][ny]){
					q.push(x.s);
					break;
				}
			}
		}
		while(sz(q)){//prob wrong here IS SOL EVEN RIGHT?
			pi y=q.front(); q.pop();
			int tx=y.f, ty=y.s;
			if(!c[tx][ty]){
				// dbg(x.f,x.s.f,x.s.s,y.f,y.s,c[tx][ty]);
				m[mp(x.s.f,x.s.s)]=max(m[mp(x.s.f,x.s.s)],g[tx][ty]);
				c[tx][ty]=true;
				For(k,8){
					int nx=tx+dx[k], ny=ty+dy[k];//DECR, which ones need me
					if(leg(nx,ny) && g[nx][ny]>g[x.s.f][x.s.s] && !c[nx][ny]){
						q.push(mp(nx,ny));
					}
				}
			}
		}
	}
	trav(x,m)dbg(x.f.f,x.f.s,x.s);
	reverse(all(ev));
	trav(x,ev){
		int cx=x.s.f,cy=x.s.s;
		For(k,4){
			int tx=cx+dx2[k], ty=cy+dy2[k];
			if(leg(tx,ty) && g[tx][ty]<g[cx][cy])//already processed
				dsu.unite(tr(tx,ty),tr(cx,cy));
		}
		dsu.mx[dsu.get(tr(cx,cy))]=max(dsu.mx[dsu.get(tr(cx,cy))],m[mp(cx,cy)]);

		if(g[cx][cy]>=dsu.mx[dsu.get(tr(cx,cy))])//no hole to worry abt
			dsu.mx[dsu.get(tr(cx,cy))]=-1;

		// dbg(cx,cy,dsu.mx[dsu.get(tr(cx,cy))]);
		if(dsu.mx[dsu.get(tr(cx,cy))]<=0){
			// dbg(-dsu.p[dsu.get(tr(cx,cy))],cx,cy);
			ret+=-dsu.p[dsu.get(tr(cx,cy))];
		}
		// else dbg("HI",dsu.mx[dsu.get(tr(cx,cy))],cx,cy);
	}
	cout << ret << nl;
	dbg(ret);
}
			// c[x.s.f][x.s.s]=true;
			// For(k,8){
			// 	int tx=x.s.f+dx[k], ty=x.s.s+dy[k];
			// 	if(leg(tx, ty) && g[tx][ty]>g[x.s.f][x.s.s] && !c[tx][ty])
			// 		q.push(mp(tx,ty));
			// }