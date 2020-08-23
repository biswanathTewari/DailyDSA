#include <bits/stdc++.h>
using namespace std;

void topo(int index,vector<int> adj[],int vis[],stack<int> s){

    vis[index] = 1;


    vector<int> :: iterator i;

    for(i = adj[index].begin();i!=adj[index].end();i++){
        if(vis[*i] == 0){
            topo(*i,adj,vis,s);
            s.push(*i);
        }
    }

}


int* topoSort(int V, vector<int> adj[]) {

    int vis[V];
    fill(vis,vis+V,0);

    stack<int> s;

    for(int i=0;i<V;i++){
        if(vis[i] == 0){
            topo(i,adj,vis,s);
            s.push(i);
        }
    }

    int *a = new int[V];
    int i=0;

    while(!s.empty()){
        a[i++] = s.top();
        s.pop();
    }

    return a;
}


bool check(int V, int* res, vector<int> adj[]) {
    bool flag = true;
    for (int i = 0; i < V && flag; i++) {
        int n = adj[res[i]].size();
        for (auto j : adj[res[i]]) {
            for (int k = i + 1; k < V; k++) {
                if (res[k] == j) n--;
            }
        }
        if (n != 0) flag = false;
    }
    if (flag == false) return 0;
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int* res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}
