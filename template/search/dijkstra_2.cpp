#include<iostream>
#include<cstring>
#include<queue>
#include<functional>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010, M = 150010;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];

void add(int a, int b, int c){
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue <PII, vector<PII>, greater<>> heap;
    heap.push({0, 1});
    while (heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f)
        return -1;
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
    cout << dijkstra() << endl;
    return 0;
}