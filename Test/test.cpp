#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

const int MAX = 1e5+1, LG = ceil(log2(1e5+1));
int n, p1, p2, p3;

vector<int> adj[MAX], queries[MAX], parent(MAX), ancestor, lvl(MAX), degree(MAX), arr(MAX), leftsmall(MAX), leftlarge(MAX), rightsmall(MAX), rightlarge(MAX), vis(MAX);
vector<vector<int>> up(MAX, vector<int>(LG+1));
vector<bool> visited;
map<pair<int, int>, int> lca;
vector<pair<pair<int, int>, int>> lcas;

int find_set(int v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

void dfs(int v)
{
    visited[v] = true;
    ancestor[v] = v;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
            union_sets(v, u);
            ancestor[find_set(v)] = v;
        }
    }
    for (int other_node : queries[v]) {
        if (visited[other_node]) {
            int mn = v < other_node ? v : other_node, mx = v > other_node ? v : other_node;
            if(p1 > p3) swap(mn, mx);
            lca[{mn, mx}] = ancestor[find_set(other_node)];
        }
    }
}

void compute_LCAs() {
    for(int i = 0; i <= n; i++)
        parent[i] = i;
    ancestor.resize(n+1);
    visited.assign(n+1, false);
    dfs(1);
}

void dfs1(int u, int p, int h=0) {
    lvl[u] = h;
    up[u][0] = p;
    for(int i = 1; i <= LG; i++)
        up[u][i] = up[up[u][i-1]][i-1];
    for(int v : adj[u]) {
        if(v != p)
            dfs1(v, u, h+1);
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) {
            adj[i].clear();
            queries[i].clear();
            degree[i] = vis[i] = 0;
        }
        long long res = 0;
        cin >> p1 >> p2 >> p3;
        int star = -1;
        bool path = true;
        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v), adj[v].push_back(u);
            ++degree[u], ++degree[v];
            if(degree[u] == n-1) star = u;
            if(degree[v] == n-1) star = v;
            path &= (degree[u] <= 2 && degree[v] <= 2);
        }
        if(star != -1) {
            long long less = star-1, more = n-star;
            if(p2 == 1)
                res = (more*(more-1))>>1;
            else if(p2 == 2)
                res = less*more;
            else
                res = (less*(less-1))>>1;
            printf("%ld\n", res);
            continue;
        }
        if(path) {
            int node, ind = 0;
            for(int i = 1; i <= n; i++) {
                if(degree[i] == 1) {
                    node = i;
                    break;
                }
            }
            do {
                arr[ind++] = node;
                vis[node] = 1;
                node = vis[adj[node][0]] ? adj[node][1] : adj[node][0];
            } while(degree[node] != 1);
            arr[ind] = node;
            //Fenwick tree/Narkel tree
            
            /*
            set<int> st, stt;
            for(int i = 0; i < n; i++) {
                st.insert(arr[i]);
                auto it = st.lower_bound(arr[i]);
                leftsmall[i] = distance(st.begin(), it);
                leftlarge[i] = i - leftsmall[i];
                stt.insert(arr[n-i-1]);
                it = stt.lower_bound(arr[n-i-1]);
                rightsmall[n-i-1] = distance(stt.begin(), it);
                rightlarge[n-i-1] = i - rightsmall[n-i-1];
            }
            if(p2 == 1) {
                for(int i = 0; i < n; i++) {
                    res += leftlarge[i]*rightlarge[i];
                }
            } else if(p2 == 2) {
                for(int i = 0; i < n; i++) {
                    res += leftsmall[i]*rightlarge[i] + leftlarge[i]*rightsmall[i];
                }
            } else {
                for(int i = 0; i < n; i++) {
                    res += leftsmall[i]*rightsmall[i];
                }
            }
            */
            printf("%ld\n", res);
            continue;
        }
        if(p1 < p3) {
            for(int i = 1; i < n; i++) {
                for(int j = i+1; j <= n; j++) {
                    queries[i].push_back(j);
                    queries[j].push_back(i);
                }
            }
        } else {
            for(int i = 2; i <= n; i++) {
                for(int j = 1; j < i; j++) {
                    queries[i].push_back(j);
                    queries[j].push_back(i);
                }
            }
        }
        compute_LCAs();
        dfs1(1, 1);
        for(auto x : lca) {
            lcas.push_back({x.ff, x.ss});
        }
        bool p = p1 < p2, q = p2 < p3;
        unordered_set<int> nodes;
        for(auto xx : lcas) {
            int node, node1 = xx.ff.ff, node2 = xx.ff.ss, l = xx.ss;
            //cout << node1 << ' ' << node2 << " -> ";
            bool x = node1 < l, y = l < node2;
            if(node1 != l && node2 != l && p == x && q == y) nodes.insert(l);
            if(node1 != l) {
                node = up[node1][0];
                while(node != l) {
                    x = node1 < node, y = node < node2;
                    if(p == x && q == y) nodes.insert(node);
                    node = up[node][0];
                }
            }
            if(node2 != l) {
                node = up[node2][0];
                while(node != l) {
                    x = node1 < node, y = node < node2;
                    if(p == x && q == y) nodes.insert(node);
                    node = up[node][0];
                }
            }
            res += nodes.size();
            //for(auto yy : nodes) cout << yy << ' '; cout << endl;
            nodes.clear();
        }
        printf("%ld\n", res);
        for(int i = 0; i <= n; i++) {
            adj[i].clear();
            queries[i].clear();
            degree[i] = 0;
        }
        lca.clear();
        lcas.clear();
    }
    return 0;
}