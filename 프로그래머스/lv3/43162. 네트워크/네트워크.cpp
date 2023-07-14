#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0;i<n;i++){
        if(!visited[i]){
            answer++;
            visited[i]= true;
            queue<int> q({i});
            
            while(!q.empty()){
                int x = q.front();
                q.pop();
                
                for(int j = 0;j<n;j++){
                    if(computers[x][j] && !visited[j]){
                        visited[j]= true;
                        q.push(j);
                    }
                }    
            }
            
            
        }
    }
    return answer;
}