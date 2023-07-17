#include <string>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;


int graph[102][102];
int dis[102][102];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX*=2,  characterY*=2,  itemX*=2,  itemY*=2;
    
    for(auto i: rectangle){
        int x = i[0]*2, y = i[1]*2, ux = i[2]*2, uy = i[3]*2;
        
        for(int i = x;i<=ux;i++){
            for(int j = y;j<=uy;j++){
                if(x < i && i < ux && y < j && j < uy)
                    graph[i][j] = -1;
                else if(graph[i][j] != -1)
                    graph[i][j] = 1;
            }
        }
    }
        
    for(int i = 0;i<101;i++)
        fill_n(dis[i],101,INF);
    queue<pair<int,int>> q;
    q.push({characterX,characterY});
    dis[characterX][characterY] = 0;

    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == itemX && y == itemY){
            answer = dis[x][y]/2;
            break;
        }
        
        for(int i = 0;i<4;i++){
            int nx = x +dx[i];
            int ny = y +dy[i];
            if( graph[nx][ny] == 1 && dis[nx][ny] > dis[x][y] +1){
                dis[nx][ny] = dis[x][y] +1;
                q.push({nx,ny});
            }
                
            }
        }
    
    
    
    return answer;
}