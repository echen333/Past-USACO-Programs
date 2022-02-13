//
// Created by Edward on 10/30/2020.
//

#include "grader.h"
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

const int MX = 1e5+5;

/**
 * Description: Calculates least common ancestor in tree with verts
 	* $0\ldots N-1$ and root $R$ using binary jumping.
 * Time: O(N\log N) build, O(\log N) query
 * Memory: O(N\log N)
 * Source: USACO Camp, KACTL
 * Verification: *
 */

struct LCA {
    int N; vector<vi> par, adj; vi depth;
    void init(int _N) {  N = _N;//CALL THIS
            int d = 1; while ((1<<d) < N) d ++;
            par.assign(d,vi(N)); adj.rsz(N); depth.rsz(N);
    }
    void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
    void gen(int R = 0) { par[0][R] = R; dfs(R); }//IM HERE LOOK AT ME
    void dfs(int x = 0) {
            FOR(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
            trav(y,adj[x]) if (y != par[0][x])
                            depth[y] = depth[par[0][y]=x]+1, dfs(y);
    }
    int jmp(int x, int d) {
            F0R(i,sz(par)) if ((d>>i)&1) x = par[i][x];
            return x; }
    int lca(int x, int y) {
            if (depth[x] < depth[y]) swap(x,y);
            x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
            R0F(i,sz(par)) {
                    int X = par[i][x], Y = par[i][y];
                    if (X != Y) x = X, y = Y;
            }
            return par[0][x];
    }
    int dist(int x, int y) { // # edges on path
            return depth[x]+depth[y]-2*depth[lca(x,y)]; }
};

//void addBox(int a, int b, int c, int d){
//        cout << a<<b<<c<<d<<'\n';
//}

int cntx, cnty, N,q;
vi adj[MX];
pi l[MX];
LCA lca;

void addRoad(int a, int b){
        adj[a].pb(b);
        adj[b].pb(a);
}

void dfs(int n, int p){
        l[n].s=cnty--;
        trav(x,adj[n]){
                if(x==p)continue;
                dfs(x,n);
        }
        l[n].f=cntx--;
        setFarmLocation(n,l[n].f,l[n].s);
}
void buildFarms(){
        N=getN();
//        N=7;
        lca.init(N);
        For(i,N)trav(x,adj[i])if(x>i)lca.ae(i,x);
        lca.gen();
        cntx=N, cnty=N;
        dfs(0,0);
}

void notifyFJ(int a, int b){
        int c=lca.lca(a,b);
        if(b==c){
                addBox(l[c].f,l[a].s,l[a].f,l[c].s);
        }
        else if(a==c){
                addBox(l[c].f,l[b].s,l[b].f,l[c].s);
        }
        else{
                addBox(l[c].f,l[a].s,l[a].f,l[c].s);
                int bel=lca.jmp(b,lca.depth[b]-lca.depth[c]-1);
                addBox(l[bel].f,l[b].s,l[b].f,l[bel].s);
        }
}

//int main(){
//        addRoad(0,1);
//        addRoad(2,1);
//        addRoad(5,4);
//        addRoad(6,4);
//        addRoad(0,4);
//        addRoad(3,1);
//        buildFarms();
//        For(i,N)cout << l[i].f << " " << l[i].s << '\n';
//        notifyFJ(0,6);
//        notifyFJ(1,3);
//        notifyFJ(6,5);
//}