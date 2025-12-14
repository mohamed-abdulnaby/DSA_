#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int V = 11;
vector<vector<int>> matrix(V, vector<int>(V, 0));
vector<bool> visited(V,false);



vector<int> bfs();
vector<int> dfs();


void createGraph(const vector<vector<int>>& edges)
{
    for (auto e : edges)
    {
        int u = e[0];
        int w = e[1];
        matrix[u][w] = 1;
        matrix[w][u] = 1;
    }

    for (int i = 1; i < V; i++)
    {
        for (int j = 1; j < V; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edges =
    {
        {1,2},{1,4},{2,3},{3,4},{3,9},{3,10},
        {2,5},{2,7},{2,8},{5,7},{5,8},{5,6},{7,8}
    };

    createGraph(edges);

    vector<int> BFS = bfs();

    for(int i : BFS)
        cout<< i << " ";
    cout <<endl;
    vector<int> DFS = dfs();
    for(int i : DFS)
        cout<< i << " ";
    return 0;

}

vector<int> bfs()
{
    int start = 1;

    vector<int> res;
    queue<int> q;


    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int v1 = q.front();
        q.pop();
        res.push_back(v1);


        for(int i = 1; i < V; i++)
        {
            if(matrix[v1][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }

    }
    return res;
}


vector<int> dfs()
{

    fill(visited.begin(), visited.end(), false);

    vector<int> res;
    stack<int> s;
    int start = 1;
    visited[start] = true;
    s.push(start);

    while(!s.empty())
    {
        int v1 = s.top();
        s.pop();

        res.push_back(v1);


        for(int i = V-1; i >=1; i--)
        {
            if(matrix[v1][i] && !visited[i])
            {
                s.push(i);
                visited[i] = true;
            }
        }
    }

    return res;
}
