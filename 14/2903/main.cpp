#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
  int rev, from, to;
  int cap, icap;
  Edge(int r, int f, int t, int c): rev(r), from(f), to(t), cap(c), icap(c) {}
  friend ostream& operator << (ostream& s, const Edge& E) {
    if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
    else return s;
  }
};


const int INF = 1<<30;
struct Graph {
  vector<vector<Edge > > list;
  Graph(int n = 0) : list(n) { }
  void init(int n = 0) { list.clear(); list.resize(n); }
  void reset() { for (int i = 0; i < (int)list.size(); ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
  inline vector<Edge >& operator [] (int i) { return list[i]; }
  inline const size_t size() const { return list.size(); }
  Edge &redge(Edge e) {
    if (e.from != e.to) return list[e.to][e.rev];
    else return list[e.to][e.rev + 1];
  }
  void addedge(int from, int to, int cap) {
    list[from].push_back(Edge((int)list[to].size(), from, to, cap));
    list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0));
  }
};

struct FF {

  FF() {}
  vector<int> seen;
  int fodfs(Graph &g, int v, int t, int f) {
    if ( v == t ) return f;
    seen[v] = true;
    for( auto &e :g[v] ) {
      if ( seen[e.to] ) continue;
      if ( e.cap == 0 ) continue;

      int flow = fodfs(g, e.to, t, min(f, e.cap));
      if ( flow == 0 ) continue;
      e.cap -= flow;
      g.redge(e).cap += flow;
      return flow;
    }
    return 0;
  }

  int solve(Graph &g, int s, int t) {
    int res;

    while(true) {
      seen.assign((int)g.size(), 0);
      int flow = fodfs(g, s, t, INF);
      if ( flow == 0 ) return res;
      res += flow;
    }
    return 0;
  }


};

struct Dinic {
    vector<int> level, iter;
 
    Dinic() { }
    void dibfs(Graph &G, int s) {
        level.assign((int)G.size(), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); ++i) {
                Edge &e = G[v][i];
                if (level[e.to] < 0 && e.cap > 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        } }
     
    int didfs(Graph &G, int v, int t, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); ++i) {
            Edge &e = G[v][i], &re = G.redge(e);
            if (level[v] < level[e.to] && e.cap > 0) {
                int d = didfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    re.cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
     
    int solve(Graph &G, int s, int t) {
        level.assign((int)G.size(), -1); 
        iter.assign((int)G.size(), 0);
        int res = 0;
        while (true) {
            dibfs(G, s);
            if (level[t] < 0) return res;
            for (int i = 0; i < (int)iter.size(); ++i) iter[i] = 0;
            int flow = 0;
            while ((flow = didfs(G, s, t, INF)) > 0) {
                res += flow;
            }
        } }
};
 
int n, m;
inline int conv(int i, int j) {
    return i*m + j;
}
 
int main() {
    cin >> n >> m;
    vector<string> fi(n);
    for (int i = 0; i < n; ++i) cin >> fi[i];
    int num_black = 0;
    int num_adj = 0;
    Graph G(n*m*3+2);
    int s = n*m*3, t = n*m*3+1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (fi[i][j] == '.') continue;
            ++num_black;
 
            if (i+1<n && fi[i+1][j] == '#') {
                ++num_adj;
                int newv = conv(i,j) + n*m;
                G.addedge(newv, t, 1);
                G.addedge(conv(i,j), newv, INF);
                G.addedge(conv(i+1,j), newv, INF);
            }
 
            if (j+1<m && fi[i][j+1] == '#') {
                ++num_adj;
                int newv = conv(i,j) + n*m*2;
                G.addedge(s, newv, 1);
                G.addedge(newv, conv(i,j), INF);
                G.addedge(newv, conv(i,j+1), INF);
            }
        }
    }
    FF ff;
    int flow = ff.solve(G, s, t);
 
    cout << num_black - (num_adj - flow) << endl;
}
