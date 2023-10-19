#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//start 09:14

//조건들
//1. 직사각형 격자 형태, n,m이 따로있음.

int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool visited[101][101];
bool check(int nx,int ny){
    return 0<= nx && nx<=n-1 && 0<= ny && ny<= m-1;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                int total = maps[i][j] - '0';
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(check(nx,ny) && !visited[nx][ny] && maps[nx][ny] != 'X'){
                            visited[nx][ny] = true;
                            total += maps[nx][ny] - '0';
                            q.push({nx,ny});
                        }
                    }
                    
                }
                answer.push_back(total);
            }
        }
    }
    
    if(answer.size() == 0)
        answer.push_back(-1);
    sort(answer.begin(),answer.end());
    
    return answer;
}