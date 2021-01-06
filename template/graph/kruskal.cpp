//
// kruskal求最小生成树
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, M = 200010;

struct Edge{
    int a, b, w;
    bool operator < (const Edge &u) const {
        return w < u.w;
    }
}edge[M];

int n, m;
int p[N];

int find(int x){
    if(p[x] != x) return p[x] = find(p[x]);
    return x;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w};
    }

    sort(edge, edge + m);

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    int res = 0, cnt = 0;

    for(int i = 0; i < m; i++){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            cnt++;
            p[pa] = pb;
            res += w;
        }
    }
    if(cnt >= n - 1)
        cout << res << endl;
    else puts("impossible");
    return 0;
}

