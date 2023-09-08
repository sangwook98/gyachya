#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    vector<int> answer ={0,n};
    
    int right = 0;
    int total = 0;
    
    for(int i = 0;i<n;i++){
        while(total < k && right < n){
            total += sequence[right++];
        }
        if(total == k){
            if(answer[1] - answer[0] > right-1 - i ){
                answer = {i,right-1};
            }
        }
        total -= sequence[i];
    }
    

  
    
    return answer;
}