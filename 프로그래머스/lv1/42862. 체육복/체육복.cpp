#include <string>
#include <vector>

using namespace std;

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {

    fill_n(arr,31,1);
    
    for(auto i: lost){
        arr[i]--;
    }
    for(auto i: reserve){
        arr[i]++;
    }
    for(int i = 1;i<=n;i++){
        if(i == 1){
            if(arr[i] == 2 && arr[i+1] == 0)
                arr[i]--, arr[i+1]++;
        }
        else if (i == n){
            if(arr[i] == 2 && arr[i-1] == 0)
                arr[i]--, arr[i-1]++;
        }
        else{
            if(arr[i] == 2){
                if(arr[i-1] == 0){
                    arr[i]--, arr[i-1]++;
                }else if(arr[i+1] == 0){
                    arr[i]--, arr[i+1]++;
                }
            }
        }
    }
    
    
    int answer = 0;
    for(int i = 1;i<=n;i++){
        if(arr[i] >= 1)
            answer++;
    }
    return answer;
}