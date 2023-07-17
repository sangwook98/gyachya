#include <string>
#include <vector>

using namespace std;

int graph[101][101];


int dx[2] = {0,1};//오,아래
int dy[2] = {1,0};



int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto i:puddles)
        graph[i[1]][i[0]] = -1;
    
    graph[1][1] = 1;
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(graph[i][j] == -1)
                graph[i][j] = 0;
            else{
                graph[i][j] += (graph[i-1][j]+graph[i][j-1])%1000000007;
            }
        }
    }
    
   
    answer = graph[n][m];
    return answer;
}