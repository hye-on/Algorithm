#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3001

using namespace std;

int n;
bool isCycleNode[MAX];
vector<int> graph[MAX];
bool visited[MAX];
int parent[MAX];
bool cycleFound;
int distToLoop[MAX];

void calculateDistance() {
   queue<pair<int, int>> q;
   memset(visited, false, sizeof(visited));

   for (int node = 1; node <= n; node++) {
       if (isCycleNode[node]) {
           visited[node] = true;
           q.push({node, 0});
       }
   }

   while (!q.empty()) {
       int currentNode = q.front().first;
       int currentDist = q.front().second;
       q.pop();
       
       for (int nextNode : graph[currentNode]) {
           if (visited[nextNode]) continue;
           
           visited[nextNode] = true;
           distToLoop[nextNode] = currentDist + 1;
           q.push({nextNode, currentDist + 1});
       }
   }
}

void findCycle(int currentNode) {
   visited[currentNode] = true;

   for (int nextNode : graph[currentNode]) {
       if (cycleFound) return;

       if (visited[nextNode]) {
           if (nextNode != parent[currentNode]) {
               isCycleNode[currentNode] = true;
               cycleFound = true;

               int temp = currentNode;
               while (temp != nextNode) {
                   isCycleNode[parent[temp]] = true;
                   temp = parent[temp];
               }
               return;
           }
       }
       else {
           parent[nextNode] = currentNode;
           findCycle(nextNode);
       }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   cin >> n;
   
   for (int i = 0; i < n; i++) {
       int from, to;
       cin >> from >> to;
       graph[from].push_back(to);
       graph[to].push_back(from);
   }

   findCycle(1);
   calculateDistance();

   for (int i = 1; i <= n; i++) {
       cout << distToLoop[i] << ' ';
   }

   return 0;
}