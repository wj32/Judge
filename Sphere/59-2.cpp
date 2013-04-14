// NOT WORKING

#include <iostream>
#include <set>
#include <stack>
#include <assert.h>
#include <string.h>
#include <stdio.h>

std::set<int> graph[5001];
int depth[5001];
int depthrev[5001];
int low[5001];
int n, m;

void dfs()
{
    std::stack<int> unseen;
    std::stack<int> parent;
    int nextdepth = 1;
    
    memset(depth, 0, sizeof(depth));
    memset(low, 0, sizeof(low));
    
    unseen.push(1);
    parent.push(1);
    
    while (!unseen.empty())
    {
        int v = unseen.top();
        int vp = parent.top();
        std::set<int> &vertices = graph[v];
        
        unseen.pop();
        parent.pop();
        
        if (!depth[v])
        {
            depth[v] = nextdepth++;
            depthrev[depth[v]] = v;
            assert(!low[v]);
            low[v] = depth[vp];
            
            for (std::set<int>::iterator it = vertices.begin(); it != vertices.end(); ++it)
            {
                int w = *it;
                
                unseen.push(w);
                parent.push(v);
            }
        }
        else if (depth[v] > depth[vp])
        {
            // forward edge
            assert(low[v]);
            
            if (low[v] > depth[vp])
                low[v] = depth[vp];
        }
        else
        {
            // back/cross edge
            assert(low[v]);
            low[v] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        printf("%d: depth %d, low %d\n", i, depth[i], low[i]);
    }
}

void testcase()
{
    std::cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        graph[i].clear();
    
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        
        std::cin >> a >> b;
        graph[a].insert(b);
    }
    
    dfs();
    
    std::set<int> critical;
    
    critical.insert(1);
    
    for (int i = 2; i <= n; i++)
    {
        if (low[i] > 1)
            critical.insert(depthrev[low[i]]);
    }
    
    std::cout << critical.size() << "\n1";
    
    for (std::set<int>::iterator it = ++critical.begin(); it != critical.end(); ++it)
        std::cout << " " << *it;
    
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 10; i++)
        testcase();
}
