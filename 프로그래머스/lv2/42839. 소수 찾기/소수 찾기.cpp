#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool not_prime[10000000];
string numbers;
int answer;
int n;

bool visited[8];
bool num_visited[10000000];

bool is_prime(int x){
    if(x == 0 || x == 1)
        return false;
    
    for(int i =2;i<=sqrt(x);i++){
        if(x%i == 0)
            return false;
    }
    
    return true;
}

void dfs(string num){

    
    if(num.size() > 0){
        int a = stoi(num);
        if(is_prime(a) &&!num_visited[a]){
            num_visited[a]=true;
            // printf("%s\n",num.c_str());
            answer++;
        }

    }
       
    if(num.size() == n)
        return;

    for(int i =0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(num+numbers[i]);
            visited[i]=false;
        }

    }
        
    
}

int solution(string numbers_) {
    numbers = numbers_;
    n = numbers.size();
    int maxi = pow(10,n);
    
    // not_prime[0] = true, not_prime[1]=true;
    // for(int i = 2;i<maxi;i++){
    //     if(!not_prime[i]){
    //         for(int j =i*2;j<maxi;j+=i)
    //             not_prime[j]=true;
    //     }
    // }
    
    dfs("");
    
    return answer;
}