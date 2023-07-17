#include <string>
#include <vector>

using namespace std;
int a, b;
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int i = 0;i<sizes.size();i++){
        if(sizes[i][0] < sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        a = max(a,sizes[i][0]);
        b = max(b,sizes[i][1]);
    }
    answer = a*b;
    return answer;
}