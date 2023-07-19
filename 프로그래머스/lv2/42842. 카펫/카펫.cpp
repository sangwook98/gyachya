#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1;i<=yellow;i++){
        if(yellow%i == 0){
            int a = yellow/i;
            if(2*a+2*i+4 == brown){
                answer.push_back(a+2);
                answer.push_back(i+2);
                break;
            }
                
        }
    }
    sort(answer.begin(),answer.end(),greater());
    return answer;
}