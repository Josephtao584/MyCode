#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 30;

double g[N][N];

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> map;
        memset(g, 0, sizeof g);
        int index = 0;
        for(int i = 0; i < equations.size(); i++) g[i][i] = 0;
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            if(!map.count(a)) map[a] = index++;
            if(!map.count(b)) map[b] = index++;
            int m_a = map[a], m_b = map[b];
            g[m_a][m_b] = values[i];
            g[m_b][m_a] = 1.0 / values[i];
        }

        for(int k = 0; k < index; k++)
            for(int i = 0; i < index; i++)
                for(int j = 0; j < index; j++)
                    if(g[i][j] == 0)
                        g[i][j] = g[i][k] * g[k][j];

        vector<double> res;
        for(int i = 0; i < queries.size(); i++){
            string a = queries[i][0];
            string b = queries[i][1];
            if(!map.count(a) || !map.count(b)) {
                res.push_back(-1);
            }else{
                int m_a = map[a], m_b = map[b];
                res.push_back(g[m_a][m_b]);
            }
        }
        return res;
    }
};