#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int i = 0;
    int n = arr.size();
    answer.push_back(arr[i++]);
    
    for(;i<n;i++){
        if(answer.back() != arr[i]){
            answer.push_back(arr[i]);
        }
            
    }

    return answer;
}