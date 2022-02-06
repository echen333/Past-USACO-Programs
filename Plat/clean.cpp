#pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
#define f first
#define s second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define For(i,b) FOR(i,0,b)
#define trav(a,b) for(auto& a:b)
#define vi vector<int>
#define vpi vector<pi>
#define vs vector<string>
#define pb push_back
#define bk back()
#define ins insert
#define pi pair<int,int>
#define ll long long
#define sz(x) (int) x.size()
#define all(x) x.begin(),x.end()
#define nl '\n'
#define AR array<int,3>
 
const int MX=15e2+5;
const int MX2=23e5+5;
const int MOD=1e9+7;

void dbg(){
	cerr<<endl;
}
template<class A,class... B> void dbg(A a, B... b){
	cerr<<a;
	if(sizeof...(b))cerr<<", ";
	dbg(b...);
}

template<class T> bool ckmin(T& a,const T& b){
	if(b<a){
		a=b; return true;
	}
	return false;
}
template<class T> bool ckmax(T& a, T& b){
	if(b>a){
		a=b; return true;
	}
	return false;
}

int n,m,q;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
bool conn[MX][MX][4][4];
vs g;

struct BCC{
	vi adj[MX2];
	vector<vi> comps;
	int low[MX2];
	int dep[MX2];
	int N;
	vi stk;
	void ae(int a, int b){
		adj[a].pb(b);
		adj[b].pb(a);
	}
	void init(int _N){
		N=_N;
		memset(low,MOD,sizeof low);
		memset(dep,-1,sizeof dep);
	}
	void dfs(int n, int p){
		// dbg(n,p);
		stk.pb(n);
		assert(n<MX2);
		low[n]=dep[n];
		trav(x,adj[n])if(x!=p){
			assert(x<MX2);
			if(dep[x]==-1){
				dep[x]=dep[n]+1;
				dbg(x,n);
				dfs(x,n);
				ckmin(low[n],low[x]);
				if(low[x]==dep[n]){
					comps.pb({});
					while(sz(stk) && stk.bk!=n){
						comps.bk.pb(stk.bk);
						stk.pop_back();
					}
					assert(sz(stk));
					comps.bk.pb(n);
				}
			} else if(dep[x]<dep[n]){
				ckmin(low[n],dep[x]);
			}
		}
		if(low[n]==dep[n]){
			assert(sz(stk));
			stk.pop_back();
		}
	}
	void gen(){
		For(i,N)if(dep[i]==-1 && sz(adj[i]))stk.clear(),dep[i]=0,dfs(i,i);
	}
} bcc;

bool leg(int a, int b){
	return a>=0 && b>=0 && a<n && b<m;
}
int opp(int a){
	return (a+2)%4;
}
bool vis[MX][MX][4];//where person is relative to box
bool vis2[MX][MX];
vi TMP[MX][MX];

int main(){
	cin.tie(0)->sync_with_stdio(0);//HI
	freopen("pushabox.in","r",stdin); 
	freopen("pushabox.out","w",stdout); 
	cin>>n>>m>>q;
	dbg(n,m,q);
	For(i,n){
		string S;cin>>S;
		g.pb(S);
	}
	bcc.init(n*m);
	pi st,bx;
	For(i,n)For(j,m)if(g[i][j]!='#'){
		if(g[i][j]=='A')st={i,j};
		if(g[i][j]=='B')bx={i,j};
		For(k,4){
			int nx=i+dx[k],ny=j+dy[k];
			if(leg(nx,ny) && g[nx][ny]!='#'){
				bcc.ae(i*m+j,nx*m+ny);
			}
		}
	}
	dbg("HI");
	bcc.gen();
	dbg("HI");
	trav(x,bcc.comps){
		vpi tmp2;
		trav(y,x){
			int i=y/m,j=y%m;
			For(k,4){
				int nx=i+dx[k],ny=j+dy[k];
				if(leg(nx,ny) && g[nx][ny]!='#'){
					tmp2.pb({nx,ny});
					TMP[nx][ny].pb(opp(k));
				}
			}
		}
		trav(y,tmp2)if(sz(TMP[y.f][y.s])){
			vi& tmp=TMP[y.f][y.s];
			For(i,sz(tmp)){
				For(j,sz(tmp)){
					conn[y.f][y.s][tmp[i]][tmp[j]]=true;
				}
			}
			TMP[y.f][y.s].clear();
		}
	}
	dbg("HI");
	queue<pi> q1;
	q1.push({st.f,st.s});
	vis2[st.f][st.s]=true;
	while(sz(q1)){
		pi x=q1.front();q1.pop();
		For(k,4){
			int nx=x.f+dx[k],ny=x.s+dy[k];
			if(leg(nx,ny) && g[nx][ny]=='.' && !vis2[nx][ny]){
				vis2[nx][ny]=true;
				q1.push({nx,ny});
			}
		}
	}
	queue<AR> q2;
	For(k,4){
		int nx=bx.f+dx[k],ny=bx.s+dy[k];
		if(leg(nx,ny) && vis2[nx][ny]){
			vis[bx.f][bx.s][k]=true;
			q2.push({bx.f,bx.s,k});
		}
	}
	dbg("HI");
	while(sz(q2)){
		AR x=q2.front();q2.pop();
		//switch dir
		For(i,4){
			if(conn[x[0]][x[1]][x[2]][i] && !vis[x[0]][x[1]][i]){
				vis[x[0]][x[1]][i]=true;
				q2.push({x[0],x[1],i});
			}
		}
		//push forward?
		int dir=opp(x[2]);
		int nx=x[0]+dx[dir],ny=x[1]+dy[dir];
		if(leg(nx,ny) && g[nx][ny]!='#' && !vis[nx][ny][x[2]]){
			vis[nx][ny][x[2]]=true;
			q2.push({nx,ny,x[2]});
		}
	}
	dbg("HI");

	bool good[n][m];
	For(i,n){
		For(j,m){
			good[i][j]=(vis[i][j][0]||vis[i][j][1]||vis[i][j][2]||vis[i][j][3]);
			// cout<<(good[i][j]?"X":".");
		}
		// cout<<endl;
	}
	good[bx.f][bx.s]=true;
	For(i,q){
		int x,y;cin>>x>>y;x--;y--;
		if(!i)dbg(x,y);
		cout<<(good[x][y]?"YES":"NO")<<'\n';//endl
	}
}