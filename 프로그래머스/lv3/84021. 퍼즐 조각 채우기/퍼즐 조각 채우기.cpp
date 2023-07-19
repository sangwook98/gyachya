#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int,int>>> puzzle[7];//크기별로 퍼즐 저장
bool table_visited[51][51];
int board_visited[51][51];

int dx[4] ={-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n;

int check(int nx,int ny){
    return 0<= nx && nx <=n-1 && 0<= ny && ny <=n-1;
}

void rotate(vector<vector<int>> &game_board){
    vector<vector<int>> tmp(game_board);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            tmp[j][n-i-1] = game_board[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            game_board[i][j] = tmp[i][j];
        }
    }

}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    n = game_board.size();
    //1. 모형 좌표 리스트 저장
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j] && !table_visited[i][j]){
                table_visited[i][j]=true;
                vector<pair<int,int>> v;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first, y =q.front().second;
                    v.push_back({x-i,y-j}); //3.상대좌표화 해서 퍼즐배열에 넣기
                    q.pop();
                    for(int k =0;k<4;k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (check(nx,ny) && table[nx][ny] && !table_visited[nx][ny]){
                            table_visited[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                }
                sort(v.begin(),v.end());
                puzzle[v.size()].push_back(v);
            }
        }
    }

    
    //2. 90도씩 돌리면서 퍼즐 맞는지 확인
    for(int p = 0;p<4;p++){
        
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(game_board[i][j] == 0 && !board_visited[i][j]){
                    board_visited[i][j]=true;
                    vector<pair<int,int>> v;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first, y =q.front().second;
                        v.push_back({x-i,y-j}); //3.상대좌표화 해서 퍼즐배열에 넣기
                        q.pop();
                        for(int k =0;k<4;k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (check(nx,ny) && game_board[nx][ny] == 0 && !board_visited[nx][ny]){
                                board_visited[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                    sort(v.begin(),v.end());
                    //4. 보드위 퍼즐 4방향으로 돌리며 맞는 거 있는지 확인
                    int siz = v.size();
                    for(int p = 0; p<puzzle[siz].size();p++){
                        if(v == puzzle[siz][p]){
                            answer+=siz;
                            puzzle[siz].erase(puzzle[siz].begin()+p);
                            for(auto a: v){
                                game_board[a.first+i][a.second+j] = 1;
                            }
                            break;
                        }

                    }
                }
            }
        }

        rotate(game_board);
        //visit배열 초기화
        for(int i =0;i<n;i++)
            fill_n(board_visited[i],n,false);
        
    }
   
    
    return answer;
}