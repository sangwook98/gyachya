#include <string>
#include <vector>


using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i = 0;i<number.size();i++){
        char a = number[i];
        
        while(!answer.empty() && k){
            char b = answer.back();
            
            if(b < a){
                answer.pop_back();
                k--;
            }else{
                break;
            }
            
        }
        answer.push_back(a);
      
    }
    while(k)
        answer.pop_back(),k--;
    

    return answer;
}