//spfa求最短路（可以有负边）
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], w[N], ne[N], idx;
int n, m;
queue<int> q;
int st[N], dist[N], cnt[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                // 如果超过了n-1 
                // 根据抽屉原理，说明经过某个节点两次，则说明有环
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if (spfa()) puts("Yes");
    else puts("No");
}
