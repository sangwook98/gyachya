#include <string>
#include <vector>
#include <queue>

using namespace std;
bool visited[101];
vector<int> edge[101];

int bfs(int x){
    int count = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        count++;
        for(auto i:edge[a]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100000;
    for(auto i:wires){
        edge[i[0]].push_back(i[1]);
        edge[i[1]].push_back(i[0]);
    }
    
    for(int i = 0;i<wires.size();i++){
        fill_n(visited,n+1,false);
        visited[wires[i][0]]= true;
        visited[wires[i][1]]= true;
        int a = bfs(wires[i][0]);
        int b = bfs(wires[i][1]);
        answer = min(answer,abs(a-b));
    }
    
    return answer;
}