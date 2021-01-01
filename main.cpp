//
// Created by 陶文鹏 on 2020/12/31.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100050, M = 100050;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
bool st[N];
int q[N];
int dist[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(){
    memset(dist, 0x3f, sizeof dist);
    int hh = 0, tt = -1;
    dist[1] = 0;
    q[++tt] = 1;
    st[1] = true;
    while (hh <= tt){
        int t = q[hh++];
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    st[j] = true;
                    q[++tt] = j;
                }
            }
        }

    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();
    if(t == -1) puts("impossible");
    else cout << t << endl;
}


