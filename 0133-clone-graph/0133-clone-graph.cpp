/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> cloned;  

    Node* cloneGraph(Node* node) {
        
       if (!node) return nullptr; 

        unordered_map<int, Node*> cloned;  
        queue<Node*> q;
        q.push(node);

        // 첫 번째 노드 생성
        Node* newNode = new Node(node->val);
        cloned[node->val] = newNode;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (cloned.find(neighbor->val) == cloned.end()) {
                    // 새로운 노드 생성
                    cloned[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // 현재 노드의 이웃 리스트에 추가
                cloned[curr->val]->neighbors.push_back(cloned[neighbor->val]);
            }
        }

        return newNode;
    }
};