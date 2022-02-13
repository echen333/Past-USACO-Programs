#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pi;
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

int n;

//WRONG WHEN THREE POINTS ON SAME LINE
//BASICALLY IDEA IS JUST FIND NUMBER OF POINTS INSIDE CHULL
//i did outside and subtract from n
int cross(pi a, pi b){
	return a.f*b.s-a.s*b.f;
}
int cross(pi a, pi b, pi c){
	return cross(mp(b.f-a.f,b.s-a.s),mp(c.f-a.f,c.s-a.s));
}
int find(vpi a, vpi b){
	vpi lo,up;//from a
	trav(x,a){
		while(sz(lo)>=2 && cross(lo[sz(lo)-2],lo.back(),x)>=0)
			lo.pop_back();
		lo.pb(x);
	}
	trav(x,a){
		while(sz(up)>=2 && cross(up[sz(up)-2],up.back(),x)<=0)
			up.pop_back();
		up.pb(x);
	}
	trav(x,lo)dbg(x.f,x.s);

	int cnt=0, l=0,l2=0;
	trav(y,b){
		while(l<sz(lo)-1 && y.f>lo[l+1].f)l++;
		while(l2<sz(up)-1 && y.f>up[l+1].f)l2++;
		if(y.f<lo[0].f){
			cnt++;continue;
		}
		else if(y.f>lo.back().f){
			cnt++;continue;
		}
		else if(cross(lo[l],lo[l+1],y)>0){
			cnt++;continue;
		}
		else if(cross(up[l2],up[l2+1],y)<0){
			cnt++;continue;
		}
	}
	return n-cnt;
}

int main() {
	setIO("curling");
	cin>>n;
	vpi a, b;
	For(i,n){
		int x,y;cin>>x>>y;
		a.pb(mp(x,y));
	}
	For(i,n){
		int x,y;cin>>x>>y;
		b.pb(mp(x,y));
	}
	sort(all(a));
	sort(all(b));
	cout<<find(a,b)<<" "<<find(b,a)<<nl;
}