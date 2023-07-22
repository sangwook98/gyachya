#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(string a, string b){
    return a + b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for(int i:numbers)
        tmp.push_back(to_string(i));
    
    sort(tmp.begin(),tmp.end(),compare);
    for(auto i:tmp)
        answer+=i;
    
    bool cnt = false;
    for(int i = 0;i<answer.size();i++){
        if(answer[i] != '0'){
            cnt = true;
            break;
        }
    }
    if(!cnt)
        answer = '0';
    
    return answer;
}