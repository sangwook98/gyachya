#include <string>
#include <vector>

using namespace std;
int arr[21];

int solution(string name) {
    int n = name.size();
    int answer = 0;
    int total = 0;
    for(int i = 0; i< n;i++){
        int a = name[i] - 'A';
        arr[i] = a > 13 ? 26- a: a;
        total += arr[i];
    }
    
    int left_right= n-1;
    for(int i = 0; i< n;i++){
        int next_i = i+1;
        while(next_i < n && name[next_i] == 'A')
            next_i++;
        left_right = min(left_right, i + n - next_i + min(i,n - next_i));
    }
    answer = total + left_right;
    return answer;
}