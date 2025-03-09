#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calDay(int month, int day) {
   int totalDays = 0;
   for (int i = 0; i < month - 1; ++i) {
       totalDays += days[i];
   }
   return totalDays + day - 1;
}

int main() {
   int n;
   cin >> n;
   
   vector<pair<int, int>> v(n);
   int a, b, c, d;
   
   for (int i = 0; i < n; i++) {
       cin >> a >> b >> c >> d;
       v[i].first = calDay(a, b);
       v[i].second = calDay(c, d);
   }

   sort(v.begin(), v.end());

   int sd = calDay(3, 1);
   int ed = calDay(11, 30)+1;

   int idx = sd;
   int ans = 0;
   
   while (idx < ed) {
       int max_end = idx;
       
       for (int i = 0; i < n; i++) {
           if (v[i].first <= idx && v[i].second > max_end) {
               max_end = v[i].second;
           }
       }
       
       if (max_end == idx) {
           ans = 0;
           break;
       }
       
       ans++;
       //확정된 날짜 갱신
       idx = max_end;
   }

   cout << ans;
   return 0;
}