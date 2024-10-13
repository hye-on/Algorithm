#include <set>
#include <iterator>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'O');

    Node* cursor = new Node(0, NULL, NULL);
    Node* it = cursor;
    for(int i=1;i<n;i++) {
        cursor->next = new Node(i, cursor, NULL);
        cursor = cursor->next;
    }

    
   for(int i=0;i<k;i++) 
       it = it->next;

   
    stack<Node*>st;
    for(string s:cmd){
        if(s[0]=='U' || s[0]=='D'){
            int x = stoi(s.substr(2));
            if(s[0]=='U') while(x--) it = it->prev;
            else while(x--) it = it->next;
        }
        else if(s[0]=='C'){
            st.push(it);
            if(it->prev != NULL) 
                it->prev->next = it->next;
            if(it->next != NULL) 
                it->next->prev = it->prev;
            if(it->next == NULL) 
                it = it->prev;
            else
                it = it->next;
        }
        else if(s[0]=='Z'){
            Node* r = st.top(); 
            st.pop();
            if(r->prev != NULL) 
                r->prev->next = r;
            if(r->next != NULL) 
                r->next->prev = r;
        }
        
    }

     while (!st.empty()) {
        answer[st.top()->n] = 'X';
        st.pop();
    }

    return answer;
}