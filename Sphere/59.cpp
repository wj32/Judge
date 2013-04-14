#include <iostream>
#include <set>
#include <stack>

std::set<int> graph[5001];

int reachable(int remove)
{
    std::set<int> seen;
    std::stack<int> unseen;
    
    unseen.push(1);
    
    while (!unseen.empty())
    {
        int v = unseen.top();
        
        unseen.pop();
        seen.insert(v);
        
        for (std::set<int>::iterator it = graph[v].begin(); it != graph[v].end(); ++it)
        {
            int w = *it;
            
            if (w != remove && seen.find(w) == seen.end())
                unseen.push(w);
        }
    }
    
    return seen.size();
}

void testcase()
{
    int n, m;
    
    std::cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        graph[i].clear();
    
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        
        std::cin >> a >> b;
        graph[a].insert(b);
    }
    
    std::set<int> critical;
    
    critical.insert(1);
    
    for (int i = 2; i <= n; i++)
    {
        if (reachable(i) != n - 1)
            critical.insert(i);
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
