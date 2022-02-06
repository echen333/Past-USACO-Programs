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
#define ft front()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define For(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define Rof(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)


const int MOD = 1e9+7;
const int MX = 2e5+7;
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

int n, a[MX], q[MX];
pi ans[MX];
deque<pair<pi,pi>> hul;//time, height, slope
vpi ev;

bool cmp(pi a, pi b, pi c){
	ld t=c.f/c.s;
	return a.f+a.s*t-b.f-b.s*t;
}

void ad(pi x){//height, slope
	while(sz(hul) && x.s>hul.ft.s.s)
		hul.pop_front();
	while(sz(hul)>2){
		if(cmp(x,hul.ft.s,hul[2].f)){
			hul.pop_front();
		}
		else break;
	}
	hul.pb(mp(mp(0,1),x));//wrong need pb more
}

pi query(int he, int sl){
	// assert(sl<hul.bk.s.s);

}

void solve1(){
	For(i,n){
		ev.pb(mp(a[i],i));
	}
	sort(all(ev));
	trav(x,ev){
		ad({x.f,q[x.s]});
		if(a[q[x.s]]>a[x.s] && q[x.s]<hul.bk.s.s);
			ans[x.s]=query(a[q[x.s]], q[x.s]);
	}
}

int main() { cin.tie(0)->sync_with_stdio(0);
	freopen("falling.in","r",stdin);
	freopen("falling.out","w",stdin);
	cin>> n;
	For(i,n)cin>> a[i];
	For(i,n){
		cin>> q[i];
		q[i]=--q[i];
	}
	For(i,n)ans[i]=mp(-1,1);
	solve1();
	For(i,n){
		if(ans[i].f==-1)cout << -1 << '\n';
		else cout << ans[i].f << "/" << ans[i].s<<'\n';
	}
 }