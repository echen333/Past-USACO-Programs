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
#define bk back()
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define For(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define Rof(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define nl '\n' 

const int MOD = 1e9+7;
const int MX = 3e5+7;
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

vpi ret;

int main() {
	setIO("fcount");
	int n;cin>>n;
	n++;
	int a[n], sum=0;
	vpi ev;
	For(i,n){
		cin>>a[i];
		sum+=a[i];
		ev.pb(mp(a[i],i));
	}
	sum%=2;
	sort(all(ev));
	For(i,sz(ev))if(ev[i].f%2==sum){
		if(i && ev[i].f==ev[i-1].f){
			if(sz(ret) && ret.bk.f==ev[i].f)ret.pb(ev[i]);
			continue;
		}
		vi v;
		For(j,n)if(j!=ev[i].s)v.pb(a[j]);
		trav(x,v)dbg(i,x);
		while(1){
			sort(all(v));
			reverse(all(v));
			if(v[0]==0){
				ret.pb(ev[i]);
				break;
			}
			int x=v[0];
			FOR(k,1,n){
				if(!v[k])
					goto done;
				v[k]--;
				x--;
				if(x==0){
					v[0]=0;
					break;
				}
				if(k==n)
					goto done;
			}
		}
		done:;
	}
	dbg(sz(ret));
	vi ret2;
	trav(x,ret)ret2.pb(x.s);
	sort(all(ret2));
	cout << sz(ret2) << nl;
	trav(x,ret2){
		dbg(x);
		cout<< x+1 << nl;
	}

}