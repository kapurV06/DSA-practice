#include <iostream>
using namespace std;

void bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    vector<int> vis(adj.size(), 0);

    vis[start] = 1;
    q.push(start);

    cout << "BFS: ";
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u])
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
    }
    cout << endl;
}


void dfsUtil(int u, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    cout << u << " ";
    for(int v : adj[u])
        if(!vis[v]) dfsUtil(v, adj, vis);
}

void dfs(int start, vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    cout << "DFS: ";
    dfsUtil(start, adj, vis);
    cout << endl;
}


struct Edge { int u, v, w; };

int findP(int x, vector<int>& parent) {
    if(parent[x] == x) return x;
    return parent[x] = findP(parent[x], parent);
}

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(),
        [](Edge a, Edge b){ return a.w < b.w; });

    vector<int> parent(n);
    for(int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "Kruskal MST:\n";

    for(auto e : edges) {
        int pu = findP(e.u, parent);
        int pv = findP(e.v, parent);
        if(pu != pv) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            cost += e.w;
            parent[pu] = pv;
        }
    }
    cout << "Total cost = " << cost << endl;
}


void prim(int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(n, INT_MAX), used(n, 0);
    key[0] = 0;
    int cost = 0;

    cout << "Prim MST:\n";

    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++)
            if(!used[j] && (u == -1 || key[j] < key[u]))
                u = j;

        used[u] = 1;
        cost += key[u];

        for(auto p : adj[u]) {
            int v = p.first, w = p.second;
            if(!used[v] && w < key[v]) key[v] = w;
        }
    }

    cout << "Total cost = " << cost << endl;
}


void dijkstra(int start, vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX), used(n, 0);
    dist[start] = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++)
            if(!used[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        used[u] = 1;

        for(auto p : adj[u]) {
            int v = p.first, w = p.second;
            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    cout << "Dijkstra distances:\n";
    for(int i = 0; i < n; i++)
        cout << i << " : " << dist[i] << endl;
}


int main() {
    int n = 5;

    vector<vector<int>> adj(n);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,3};
    adj[3] = {1,2,4};
    adj[4] = {3};

    bfs(0, adj);
    dfs(0, adj);

    vector<Edge> edges = {
        {0,1,2}, {0,3,6}, {1,2,3},
        {1,3,8}, {1,4,5}, {2,4,7}, {3,4,9}
    };

    cout << endl;
    kruskal(n, edges);

    vector<vector<pair<int,int>>> adjW(n);
    for(auto e : edges) {
        adjW[e.u].push_back({e.v, e.w});
        adjW[e.v].push_back({e.u, e.w});
    }

    cout << endl;
    prim(n, adjW);

    cout << endl;
    dijkstra(0, adjW);

    return 0;
}
