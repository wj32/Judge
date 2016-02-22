#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int id;
    unsigned int distance;
    vector<pair<Node *, int>> adjacent;
    
    Node(int id)
        : id(id), distance(-1)
    { }
};

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        map<int, Node *> nodes;
        
        for (int j = 1; j <= n; j++) {
            nodes.insert(make_pair(j, new Node(j)));
        }
        
        for (int j = 0; j < m; j++) {
            int x, y, r;
            cin >> x >> y >> r;
            Node *u = nodes.find(x)->second;
            Node *v = nodes.find(y)->second;
            u->adjacent.push_back(make_pair(v, r));
            v->adjacent.push_back(make_pair(u, r));
        }
        
        int s;
        cin >> s;
        priority_queue<pair<int, Node *>> pq;
        
        nodes.find(s)->second->distance = 0;
        pq.push(make_pair(0, nodes.find(s)->second));
        
        while (!pq.empty()) {
            const auto d = pq.top().first;
            const auto u = pq.top().second;
            pq.pop();
            
            if (d > u->distance) {
                continue;
            }
            
            for (const auto &pair : u->adjacent) {
                const auto v = pair.first;
                const auto e = pair.second;
                if (v->distance > d + e) {
                    v->distance = d + e;
                    pq.push(make_pair(d + e, v));
                }
            }
        }

        bool first = true;
        
        for (int j = 1; j <= n; j++) {
            if (j == s) {
                continue;
            }
            
            cout << (first ? "" : " ") << (int)nodes.find(j)->second->distance;
            first = false;
        }
        
        cout << endl;
    }
    
    return 0;
}
