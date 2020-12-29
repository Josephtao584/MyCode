#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
/*
给定一颗树，树中包含n个结点（编号1~n）和n-1条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块
中点数的最大值最小，那么这个节点被称为树的重心。
 */
using namespace std;
const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;
bool st[N];

int n, m;
int ans = N;

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    st[u] = true;
    int sum = 1, res = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main()
{
    cin >> n;
    memset(h, - 1, sizeof h);
    while (n--){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return n - 1;
}

