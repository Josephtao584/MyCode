//floyd求多源路径
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int g[N][N];
int n, k, m;

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b], w);
    }
    floyd();
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        if(g[a][b] > INF / 2) puts("impossible");
        else cout << g[a][b] << endl;
    }

}