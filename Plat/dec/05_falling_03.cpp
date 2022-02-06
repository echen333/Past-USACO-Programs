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

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int n,a[MX], q[MX];
vi idx, rev, p[MX];
pi ans[MX];

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

void solve1(){//concave up
	vector<int> v;//stk, front of v is last line, vector of slopes, decr by slopes
	FOR(i,1,n+1){
		while(sz(v) && idx[i]<v.bk)
			v.pop_back();
		while(sz(v)>=2 && cmp(cross(v[sz(v)-1],v[sz(v)-2]),cross(idx[i],v[sz(v)-2])))//check here
			v.pop_back();
		v.pb(idx[i]);
		trav(x,p[i]){
			int tmp=lower_bound(all(v),q[x])-v.begin();
			dbg(tmp,i,x,idx[i]);
			trav(x,v)dbg(x);
			int l=0, r=tmp-1;
			if(r>=0){
				while(l!=r){
					dbg(i,l,r);
					int m=(l+r)/2;
					if(cmp(cross(q[x],v[m]),cross(q[x],v[m+1])))r=m;
					else l=m+1;
				}
			}
			ans[x]=cross(v[l],q[x]);
		}
	}
}

void solve2(){//concave down, speed up
	vector<int> v;
	ROF(i,1,n+1){
		while(sz(v) && idx[i]>v.bk)
			v.pop_back();
		while(sz(v)>=2 && cmp(cross(v[sz(v)-1],v[sz(v)-2]),cross(idx[i],v[sz(v)-1])))//check here
			v.pop_back();
		v.pb(idx[i]);
		trav(x,p[i]){
			int tmp=lower_bound(all(v),q[x],greater<int>())-v.begin();
			int l=0, r=tmp-1;
			trav(x,v)dbg("hi",x);
			if(r>=0){
				while(l!=r){
					dbg(i,l,r);
					int m=(l+r)/2;
					if(cmp(cross(q[x],v[m]),cross(q[x],v[m+1])))r=m;
					else l=m+1;
				}
			}
			ans[x]=cross(v[l],q[x]);
		}
	}
}
int main() {
	setIO("falling");
	cin >> n;
	FOR(i,1,n+1)cin >> a[i];
	FOR(i,1,n+1)cin >> q[i];
	idx.resize(n+1);
	rev.resize(n+1);
	iota(all(idx),0);//0?
	trav(x,idx)dbg(x);
	sort(all(idx),[](int b, int c){
		return a[b]<a[c];
	});
	FOR(i,1,n+1)rev[idx[i]]=i;
	FOR(i,1,n+1){
		if(a[i]<a[q[i]])//slow down
			p[rev[i]].pb(i);
	}
	solve1();
	FOR(i,1,n+1)p[i].clear();
	FOR(i,1,n+1)
		if(a[i]>a[q[i]])
			p[rev[i]].pb(i);
	solve2();
	FOR(i,1,n+1){
		if(ans[i].s==0){
			cout << -1 << nl;
			continue;
		}
		int g=__gcd(ans[i].f,ans[i].s);
		cout << ans[i].f/g<<'/'<<ans[i].s/g<<nl;
	}
}