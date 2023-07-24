#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    
    // answer.push_back(arr[0]);
    // for(int i: arr){
    //     if(answer.back() != i)
    //         answer.push_back(i);
    // }
    

    return arr;
}