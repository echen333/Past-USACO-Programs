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
#define trav(a,x) for (auto& a: x)

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

int n, G[MX][MX], GG[MX][MX];
ll ans;

void rot(){
	For(i,n)For(j,n)GG[n-1-j][i]=G[i][j];
	For(i,n)For(j,n)G[i][j]=GG[i][j];
}

void solve(){
	For(a,2*n-1){//diagonal a
		for(int b = a+2; b < 2*n-1; b+=2){//diagonal b
			int dif=(b-a)/2, st=max(0,a-(n-1)), en=min(a,n-1);
			int cur=0;
			FOR(i,st,en+1){//i,a-i
				if(i==st)
					FOR(j,max(i,b-(n-1)),min(i+dif,n-dif))
						cur += G[j][b-j] && G[j+dif][b-j-dif];
				if(G[i][a-i]) ans+=cur;
				if(i+2*dif < n && b-(i+dif)<n)
					cur += G[i+dif][b-i-dif] && G[i+2*dif][b-i-2*dif];
				if(i+dif<n && b-i<n)
					cur -= G[i][b-i] && G[i+dif][b-i-dif];
 			}
		}
	}
}

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main() {
	setIO("triangles");
	cin >> n;
	For(i,n){
		string s;cin>>s;
		For(j,n)G[i][j]=(s[j]=='*');
	}
	For(i,4){
		solve();
		rot();
	}
	cout << ans << '\n';

}