//
// Prim求最小生成数
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 200010;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int prim(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    for(int i = 1; i <= n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        if(dist[t] == 0x3f3f3f3f) return -1;
        res += dist[t];
        st[t] = true;
        for(int j = h[t]; j != -1; j = ne[j]){
            int k = e[j];
            if(!st[k])
                dist[k] = min(dist[k], w[j]);
        }
    }
    return res;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int t = prim();
    if(t == -1) puts("impossible");
    else cout << t << endl;
    return 0;
}

