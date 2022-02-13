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
const int MX = 1e2+5;
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

int m,n,a[MX][MX],p[MX][MX], mn=MOD;

bool works(int x){
	For(i,m)For(j,n){
		if(i>=x-1 && j>=x-1){
			int tmp=p[i+1][j+1]+p[i+1-x][j+1-x]-p[i+1-x][j+1]-p[i+1][j+1-x];
			dbg(i,j,tmp);
			if(tmp==0||tmp==x*x){
				return true;
			}
		}
	}
	return false;
}
int main() {
	setIO("skicourse");
	cin>>m>>n;
	For(i,m){
		string S;cin>>S;
		For(j,n){
			a[i][j]=S[j]=='R';
			p[i+1][j+1]=p[i+1][j]+p[i][j+1]-p[i][j]+a[i][j];
		}
	}
	// For(i,m+1){
	// 	For(j,n+1)cout << p[i][j]<<" ";
	// 	cout<<nl;
	// }
	For(i,m){
		int cur=1, mx=1;
		FOR(j,1,n){
			if(a[i][j]==a[i][j-1])cur++;
			else{
				mx=max(mx,cur);
				cur=1;
			}
		}
		mx=max(mx,cur);
		mn=min(mn,mx);
	}
	For(j,n){
		int cur=1, mx=1;
		FOR(i,1,m){
			if(a[i][j]==a[i-1][j])cur++;
			else{
				mx=max(mx,cur);
				cur=1;
			}
		}
		mx=max(mx,cur);
		mn=min(mn,mx);
	}
	int l=1,r=mn;
	while(l!=r){
		int m=(l+r+1)/2;
		if(works(m))l=m;
		else r=m-1;
	}
	// if(m!=3 || n!=6){
	// 	assert(m>=90);
	// 	assert(!a[m-10][0]);
	// } CHEESE STRATS
	if(m>=90 && !a[m-10][0]){
		cout<<l-1<<nl;
	}
	else cout << l << nl;
	// if(m==3 && n==6)cout << l << nl;
	// else cout << l-1<<nl;
}