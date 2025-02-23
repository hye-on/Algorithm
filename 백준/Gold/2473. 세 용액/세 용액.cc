#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int>num;

long long search_water(int l ,int r,int two_water){
   int left = l, right = r,mid=0;
   long long three_water = 3000000001;
   
   long long ret =3000000001;
   while(left<=right){
       mid = (left+right)/2;
       long long sum = (long long)two_water + num[mid];
       
       if(abs(sum)<three_water){
           three_water = abs(sum);
           ret = num[mid];
       }
       if(sum<0){
           left = mid + 1;
       }else{
           right = mid - 1;
       }
   }
   
   return ret;
}

int main() {
   cin>>n;
   num.resize(n);
   vector<int>ans(3);
   for(int i=0;i<n;i++)
       cin>>num[i];

   sort(num.begin(),num.end());
   
   long long three_water = 3000000001;
   

   for(int i=0; i<n-2; i++){
       for(int j=n-1; j>i+1; j--){
           long long two_water = (long long)num[i] + num[j];
           int w = search_water(i+1,j-1,two_water);
           long long sum = two_water + w;

           if(abs(sum)<three_water){
               ans[0] = num[i];
               ans[1] = w;
               ans[2] = num[j];
               three_water = abs(sum);
           }
       }
   }

   sort(ans.begin(), ans.end());
   for(auto a : ans)
       cout<<a<<' ';
   
   return 0;
}