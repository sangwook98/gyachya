#include <string>
#include <vector>

using namespace std;
string target="", aeiou="AEIOU";
int cnt = -1,answer;

void dfs(string word){
    
    if(word.size()>5)
        return;
    
    cnt++;
    if(word == target){
        answer = cnt;
        return;
    }
    
    for(int i =0;i<5;i++){
        dfs(word+aeiou[i]);
    }
        
    
}

int solution(string word) {
    target = word;
    dfs("");
    
    return answer;
}