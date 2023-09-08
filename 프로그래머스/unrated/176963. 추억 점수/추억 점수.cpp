#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> mp;
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0;i<name.size();i++){
        mp[name[i]] = yearning[i];
    }
    
    int n = photo.size();
    for(int i=0; i<n;i++){
        int m = photo[i].size();
        int total = 0;
        for(int j = 0;j<m;j++){
            if(mp.count(photo[i][j]) == 1){
                total+=mp[photo[i][j]];
            }
        }
        answer.push_back(total);
    }
    return answer;
}