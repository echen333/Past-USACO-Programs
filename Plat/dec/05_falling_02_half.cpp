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
const int MX = 2e3+7;
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

int n,a[MX], q[MX];
pi mn[MX];

bool cmp(pi a, pi b){
	return (ll)a.f*b.s<(ll)b.f*a.s;
}

pi cross(int b, int c){
	pi tmp=mp(a[b]-a[c],b-c);
	if(tmp.s<0){
		tmp.f*=-1;
		tmp.s*=-1;
	}
	if(tmp.f<0)return mp(1,0);
	return tmp;
}

int main() {
	setIO("falling");
	cin >> n;
	FOR(i,1,n+1)cin>> a[i];
	FOR(i,1,n+1)cin>> q[i];
	FOR(i,1,n+1){
		mn[i]=cross(i,q[i]);
		dbg(mn[i].f,mn[i].s);
		FOR(j,1,n+1){
			if(i!=j && cross(i,j).s!=0 && cross(j,q[i]).s!=0 && cmp(cross(i,j),cross(j,q[i]))){
				if(cmp(cross(j,q[i]),mn[i])){
					mn[i]=cross(j,q[i]);
					dbg(i,j);
				}
			}
		}
	}
	FOR(i,1,n+1){
		if(mn[i].s==0){
			cout << -1 << nl;
			continue;
		}
		int g=__gcd(mn[i].f,mn[i].s);
		cout << mn[i].f/g<<'/'<<mn[i].s/g<<nl;
	}
}