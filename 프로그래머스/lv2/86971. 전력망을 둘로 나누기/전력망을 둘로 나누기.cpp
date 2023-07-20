#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
bool visited[101];

int bfs(int x){
    queue<int> q;
    q.push(x);
    int ans = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans++;
        for(int a: v[now]){
            if(!visited[a]){
                visited[a] = true;
                q.push(a);
            }
        }
    }
    return ans;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    for(auto i: wires){
        int a = i[0], b = i[1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(auto i:wires){
        int a = i[0], b = i[1];
        fill_n(visited,n+1,false);
        visited[a]= true;
        visited[b]= true;
        int c = bfs(a);
        int d = bfs(b);
        answer = min(abs(d-c),answer);
    }
    
    return answer;
}