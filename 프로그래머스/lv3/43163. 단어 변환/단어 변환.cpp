#include <string>
#include <vector>

using namespace std;
int answer= 100001;
bool visited[50];
vector<string> words;
string target;

bool available(string a, string b){
    int m = a.size();
    int count = 0;
    for(int i=0;i<m; i++){
        if(a[i] != b[i]){
            count++;
        }
        if(count > 1)
            return false;
    }
    return true;
}

void dfs(string word,int cnt){
    if(word == target){
        answer = min(answer,cnt);
        return;
    }
    
    for(int i = 0;i<words.size();i++){
        if(!visited[i] && available(word, words[i])){
            visited[i]= true;
            dfs(words[i],cnt+1);
            visited[i]=false;
        }
    }
}

int solution(string begin, string target_, vector<string> words_) {
    words = words_;
    target = target_;
    dfs(begin,0);
    answer = answer == 100001 ? 0 : answer;
    return answer;
}