//
// Created by Edward on 10/29/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <complex.h>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<pi, int> pii;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
template<class T> using V = vector<T>;
template<class T, size_t SZ> using AR = array<T,SZ>;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define For(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define Rof(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

template<class T> bool ckmin(T& a, const T& b) {
        return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
        return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) {
// note: if (lo+hi)/2 is used instead of half(lo+hi) then this will loop infinitely when lo=hi
        hi ++; assert(lo <= hi); // assuming f is increasing
        while (lo < hi) { // find first index such that f is true
                T mid = half(lo+hi);
                f(mid) ? hi = mid : lo = mid+1;
        }
        return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
        lo --; assert(lo <= hi); // assuming f is decreasing
        while (lo < hi) { // find first index such that f is true
                T mid = half(lo+hi+1);
                f(mid) ? lo = mid : hi = mid-1;
        }
        return lo;
}
template<class T> void remDup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)),end(v)); }

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) {
#ifdef LOCAL
        return b ? "true" : "false";
#else
        return ts((int)b);
#endif
}
template<class A> str ts(complex<A> c) {
        stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
        str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
        res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
        str res = ""; F0R(i,SZ) res += char('0'+b[i]);
        return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
#ifdef LOCAL
        bool fst = 1; str res = "{";
        for (const auto& x: v) {
                if (!fst) res += ", ";
                fst = 0; res += ts(x);
        }
        res += "}"; return res;
#else
        bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

#endif
}
template<class A, class B> str ts(pair<A,B> p) {
#ifdef LOCAL
        return "("+ts(p.f)+", "+ts(p.s)+")";
#else
        return ts(p.f)+" "+ts(p.s);
#endif
}

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) {
        pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) {
        pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
        cerr << ts(h); if (sizeof...(t)) cerr << ", ";
        DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
#define dbg(...) 0
	#define chk(...) 0
#endif

int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}
int max(int a,int b, int c){return max(a,max(b,c));}
int min(int a,int b, int c){return min(a,min(b,c));}
ll max(ll a,ll b, ll c){return max(a,max(b,c));}
ll min(ll a,ll b, ll c){return min(a,min(b,c));}
void dbga(int arr[]){int n=sizeof(arr);vi v;For(i,n)v.pb(arr[i]);dbg(v);}
void dbga(ll arr[]){int n=sizeof(arr);vi v;For(i,n)v.pb(arr[i]);dbg(v);}

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "pushabox") {
        unsyncIO();
// cin.exceptions(cin.failbit);
// throws exception when do smth illegal
// ex. try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
// 576743 29995400689069LL
const int MOD = 1e9+7; // 998244353;
const int MX = 1500+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

/**
 * Description: Biconnected components of edges. Removing any vertex in BCC
 	* doesn't disconnect it. To get block-cut tree, create a bipartite graph
 	* with the original vertices on the left and a vertex for each BCC on the right.
 	* Draw edge $u\leftrightarrow v$ if $u$ is contained within the BCC for $v$.
 	* Self-loops are not included in any BCC while BCCS of size 1 represent
 	* bridges.
 * Time: O(N+M)
 * Source: GeeksForGeeks (corrected)
 * Verification:
 	* USACO December 2017, Push a Box -> https://pastebin.com/yUWuzTH8
 	* https://cses.fi/problemset/task/1705/
 */

struct BCC {
    vector<vpi> adj; vpi ed;
    vector<vi> comps; // edges for each bcc
    int N, ti = 0; vi disc, st;
    void init(int _N) { N = _N; disc.rsz(N), adj.rsz(N); }
    void ae(int x, int y) {
            adj[x].eb(y,sz(ed)), adj[y].eb(x,sz(ed)), ed.eb(x,y); }
    int dfs(int x, int p = -1) { // return lowest disc
            int low = disc[x] = ++ti;
            trav(e,adj[x]) if (e.s != p) {
                            if (!disc[e.f]) {
                                    st.pb(e.s); // disc[x] < LOW -> bridge
                                    int LOW = dfs(e.f,e.s); ckmin(low,LOW);
                                    if (disc[x] <= LOW) { // get edges in bcc
                                            comps.eb(); vi& tmp = comps.bk; // new bcc
                                            for (int y = -1; y != e.s; )
                                                    tmp.pb(y = st.bk), st.pop_back();
                                    }
                            } else if (disc[e.f] < disc[x]) // back-edge
                                    ckmin(low,disc[e.f]), st.pb(e.s);
                    }
            return low;
    }
    void gen() { F0R(i,N) if (!disc[i]) dfs(i);  }
};

/*
 * first sol said i ran out of memory(i didnt and just out of bounds so wrote this trash one with 5/15
 * doesnt work and need to use 4*n*m states which i did in prev
 * p close idea
 * sample cases below
 */
BCC bcc;
int n,m,q2, gr[MX*MX*2],cnt,mbc[MX*MX*4];
bool v[MX][MX], grid[MX][MX], v2[MX][MX];
pi st, ed;
stack<pi> upd;

bool val(int a, int b){return a>=0 && b>=0 && a<n && b<m;}
int tr(int a, int b){return a*m+b;}
int tr(int a, int b, int c){return (a*m+b)*4+c;}

void dumbdfs(int a, int b){
        if(a==ed.f && b==ed.s)return;
        v2[a][b]=true;
        For(i,4){
                int nx=a+dx[i],ny=b+dy[i];
                if(!v2[nx][ny] && grid[nx][ny])dumbdfs(nx,ny);
        }
}

int main() {
        setIO();
        re(n,m,q2);
        bcc.init(n*m*4);
        For(i,n){
                string s;re(s);
                For(j,m){
                        grid[i][j] = (s[j]=='.' || s[j]=='A' || s[j]=='B');
                        if(s[j]=='A')st=mp(i,j);
                        if(s[j]=='B')ed=mp(i,j);
                }
        }
        For(i,n)For(j,m)if(grid[i][j]){
                if(grid[i+1][j]){
                        bcc.ae(tr(i,j),tr(i+1,j));
                        mbc[tr(i,j,0)]=cnt;
                        mbc[tr(i+1,j,2)]=cnt;cnt++;
                }
                if(grid[i][j+1]){
                        bcc.ae(tr(i,j),tr(i,j+1));
                        mbc[tr(i,j,1)]=cnt;
                        mbc[tr(i,j+1,3)]=cnt;cnt++;
                }
        }
        bcc.gen();
//        dbg(bcc.comps);
        For(i,sz(bcc.comps)){
                trav(x,bcc.comps[i])gr[x]=i+1;
        }

        dumbdfs(st.f,st.s);
        v[ed.f][ed.s]=true;
        queue<pi> q;
        For(i,4){
                int ox=ed.f-dx[i], oy=ed.s-dy[i];
                int tx=ed.f+dx[i], ty=ed.s+dy[i];
                if(val(ox,oy) && v2[ox][oy] && grid[tx][ty]){
                        v[tx][ty]=true;
                        q.push(mp(tx,ty));
                }
        }
        while(!q.empty()){
                pi x=q.front();q.pop();
                dbg(x.f,x.s);
                For(i,4){
                        int ox=x.f+dx[i], oy=x.s+dy[i];//fromx,fromy
                        if(!val(ox,oy) || !v[ox][oy] || !grid[ox][oy])continue;
                        //where i can stand
                        For(j,4){
                                int fx=x.f-dx[j], fy=x.s-dy[j];
                                int tx=x.f+dx[j], ty=x.s+dy[j];
                                if(!val(tx,ty)  || !val(fx,fy) || !grid[tx][ty] || v[tx][ty] || !grid[fx][fy])continue;
                                if(i==(j+2)%4 || gr[mbc[tr(x.f,x.s,(j+2)%4)]]==gr[mbc[tr(x.f,x.s,i)]]){//same dir or//CHANGED HERE, bcc wrong i stll think
                                        upd.push(mp(tx,ty));
                                        q.push(mp(tx,ty));
                                        dbg(tx,ty,ox,oy,x.f,x.s,i,j);
                                }
                        }
                }

                while(!upd.empty()){//BAD?
                        pi y=upd.top();upd.pop();v[y.f][y.s]=true;
                        For(k,4) {//bsaiicaly can i REUPDATE?
                                int ux = y.f + dx[k], uy = y.s + dy[k];
                                if (val(ux, uy) && grid[ux][uy] && v[ux][uy]) {
                                        For(i,4){
                                                if(i==(k+2)%4)continue;
                                                int fx=ux+dx[i], fy=uy+dy[i];
                                                if(!val(fx,fy) || !grid[fx][fy])continue;
                                                if(gr[mbc[tr(ux,uy,(k+2)%4)]]==gr[mbc[tr(ux,uy,i)]]){
                                                        dbg(ux,uy,y.f,y.s,"hi",k,i);
                                                        q.push(mp(ux,uy));
                                                        v[ux][uy]=true;
                                                }
                                        }
                                }
                        }
                }
        }

        For(i,n){
//                For(j,m)pr(v[i][j]);ps();
        }

        For(i,q2){
                int r,c;re(r,c);r--;c--;
                ps(v[r][c]?"YES":"NO");
        }
// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* think of simple solution first
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

/*
 *
5 5 4
##.##
##.##
A.B..
.#.##
...##
3 2
3 5
1 3
5 3

5 5 5
#...#
##..#
A.B#.
#..##
#####
3 2
3 5
1 3
5 3
1 2

5 5 5
##...
##.#.
A.B..
####.
####.
3 2
3 5
1 3
5 3
1 2

8 6 0
######
#...##
#.#.##
#A#B.#
.....#
..####
.....#
######

8 6 0
######
#...##
#.#.##
#A#B.#
#....#
.#####
.....#
######

8 6 0
######
#...##
#.#.##
#A#B.#
.....#
..##.#
.....#
##....

8 6 0
######
#...##
#.#.##
#A#B.#
.....#
..##.#
......
##....

6 6 0
......
......
A.....
..###.
..#.B.
......

6 6 0
......
......
A.....
..###.
....B.
..#...


6 6 0
......
......
A.....
......
......
.....B

6 6 0
......
......
A.....
......
......
..#.B.
 */