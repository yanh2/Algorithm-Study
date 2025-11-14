#include<iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int tc = 0;
    int n;
    while(cin >>n){
        tc++;
 
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
 
        int cnt =0; 
        for(int i=2; i<n-2; i++){
            if(v[i]<v[i-1] || v[i]<v[i+1] || v[i]<v[i-2] || v[i]<v[i+2]) continue;
            int ans = 0;
            int tmp =0;
            for(int j=1; j<=2; j++){
                tmp = v[i-j]+1;
                ans = max(ans, tmp);
                tmp = v[i+j]+1;
                ans = max(ans, tmp);
            }
            cnt += (v[i]-ans+1);
        }
        cout << "#"<<tc<< ' ' << cnt<<endl; 
    } 
    return 0;
}
