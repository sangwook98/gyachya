#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

int compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int find_parent(int a){
    if(parent[a] != a){
        parent[a] = find_parent(parent[a]);
    }
    return parent[a];
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0;i<n;i++)
        parent[i] = i;
    
    sort(costs.begin(),costs.end(),compare);
    
    for(int i = 0;i<costs.size();i++){
        int a = costs[i][0],b=costs[i][1], c= costs[i][2];
        if(find_parent(a) != find_parent(b)){
            union_parent(a,b);
            answer +=c;
        }
    }
    
    return answer;
}