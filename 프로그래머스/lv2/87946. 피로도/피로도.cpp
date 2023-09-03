#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dungeons;
bool visited[9];

int n,answer;

int compare(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
        
    return a[0]>b[0];
}


void dfs(int life,int count){
    if(count > answer)
        answer = count;
        
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            if(life >= dungeons[i][0]){
                dfs(life - dungeons[i][1], count+1);
            }
            visited[i]= false;
        }
    }
  
    
    
}

int solution(int k, vector<vector<int>> dungeons_) {
    dungeons = dungeons_;
    n = dungeons.size();
    
    dfs(k,0);
    
    return answer;
}