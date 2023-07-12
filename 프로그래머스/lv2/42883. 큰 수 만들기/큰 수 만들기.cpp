#include <string>
#include <vector>


using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    while(k && !number.empty()){
        char a = number.front();
        
        if(answer.empty()){
             answer +=a;
            number.erase(0,1);
        }
           
        else{
            char b = answer.back();
            if(b < a){
                answer.pop_back();
                k--;
            }else{
                answer.push_back(a);
                number.erase(0,1);
            }
        }
            
    }
    while(k){
        answer.pop_back();
        k--;
    }
    
    answer += number;
    return answer;
}