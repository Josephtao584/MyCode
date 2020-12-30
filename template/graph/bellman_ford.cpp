#include <iostream>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge{
    int a, b, w;
}edge[M];

int bellman_ford(){
    for(int i = 0; i < k; i++){
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; j++){
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2)
        return -1;
    return dist[n];
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    int t = bellman_ford();
    if(t == -1)
        cout << "impossible" << endl;
    else
        cout << t << endl;
}
