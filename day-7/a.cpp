#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
const int VEL = 50;

vector<pair<int, double> > adj[N];
vector<int> vis[N];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        double wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
        adj[y].push_back({x, wt});
    }

    return 0;
}
