#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i+1;j++){
            if(j == 0){
                triangle[i][j] += triangle[i-1][j];
            }else if (j == i){
                triangle[i][j] += triangle[i-1][j-1];
            }else{
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }
    for(int i = 0;i<n;i++){
        answer = max(answer,triangle[n-1][i]);
    }
    return answer;
}