//
// Created by Joseph on 2020/12/30.
//
#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 510, M = 100010;

int n, m;
int g[N][N];
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

using namespace std;

int dijkastra_1(){         //朴素版
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;

        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

void add(int a, int b, int c){
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}
int dijkastra_2(){         //邻接矩阵版
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;
        for(int j = h[t]; j != -1; j = ne[j]){
            int u = e[j];
            dist[u] = min(dist[u], dist[t] + w[j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a, b, c;
        g[a][b] = min(g[a][b], c);
    }
    int t = dijkastra_1();
    cout << t << endl;
}

