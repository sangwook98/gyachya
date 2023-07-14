#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[51];

int is_near(string a, string b){
    int n = a.size();
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i] != b[i])
            cnt++;
    }
    return cnt;
}

int bfs(string begin, string target, vector<string> words){
    queue<pair<string, int>> q;
    q.push({begin,0});
        
    while (!q.empty()){
        string now = q.front().first;
        int move = q.front().second;
        q.pop();
        
        for(int i = 0;i<words.size();i++){
            if(!visited[i]){
                int cnt = is_near(now, words[i]);
                
                 if (cnt == 1){
                    visited[i]= true;
                    q.push({words[i],move+1});
                    if(words[i] == target)
                        return move + 1;
                }
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = bfs(begin,target,words);
    
    return answer;
}