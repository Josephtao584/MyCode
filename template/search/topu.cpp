#include <iostream>
#include <cstring>
#include <unordered_set>
#include <queue>

using namespace std;

const int N = 100010, M = 100010;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N], q[N];

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}
bool topSort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++){
        if(d[i] == 0){
            q[++tt] = i;
        }
    }
    while (hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0){
                q[++tt] = j;
            }
        }
    }
    return tt == n - 1;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof d);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if(topSort()){
        for(int i = 0; i < n; i ++)
            cout <<q[i]<<' ';
    }else puts("-1");

    return 0;
}