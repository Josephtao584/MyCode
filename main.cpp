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
int dist[N], cnt[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(){
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
        st[i] = true;
    }
    while (q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n)
                    return -1;
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }

    }
    return 1;
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
    if(t == -1) puts("Yes");
    else cout << "No" << endl;
}


