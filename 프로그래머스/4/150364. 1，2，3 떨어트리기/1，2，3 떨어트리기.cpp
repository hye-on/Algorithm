#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<queue<int>> childQueue; // 각 노드의 자식 노드를 순차적으로 방문하기 위한 큐
vector<vector<int>> adjList; // 각 노드의 자식 노드 목록을 저장하는 인접 리스트
vector<int> visitCount; // 각 노드가 현재까지 몇 번 방문되었는지 저장
vector<int> targetValues; // 각 노드의 목표 값을 저장

// 현재 리프 노드를 찾고 큐를 순환시키는 함수
int getLeafNode() {
    int currentNode = 1; // 시작 노드
    int nextNode;
    // 리프 노드를 찾을 때까지 계속 자식 노드를 탐색
    while (!childQueue[currentNode].empty()) {
        nextNode = childQueue[currentNode].front(); // 현재 노드의 첫 번째 자식 노드를 가져옴
        childQueue[currentNode].pop(); // 해당 자식 노드를 큐에서 제거
        childQueue[currentNode].push(nextNode); // 다시 큐에 넣어 순환 방문 준비
        currentNode = nextNode; // 자식 노드로 이동
    }
    return currentNode; // 최종적으로 리프 노드를 반환
}

// 목표 값을 만족할 수 있는지 확인하는 함수
int checkTarget() {
    int result = 0;
    // 모든 노드에 대해 목표 값과 현재 방문 횟수를 비교
    for (int i = 0; i < visitCount.size(); i++) {
        // 목표 값에 도달하지 않았지만 더 방문할 수 있는 경우
        //1. 다 3으로 채워넣어도 모자라면 더 넣어야 함
        if (visitCount[i] * 3 < targetValues[i]) {
            result = 1; // 계속 진행 가능
        }
        // 목표 값보다 더 많이 방문한 경우 목표 달성 불가능
        //2. 다 1로 채워도 넘치면 목표 달성 불가능 
        if (targetValues[i] < visitCount[i]) {
            return 2; // 목표 달성 불가능
        }
    }
    //3. 만약 다 3으로 채웠을 때 모든 노드가 달성 가능하면 공을 더 넣치 않고 어떤 공을 넣을지 결정
    return result; // 0이면 목표 달성 가능, 1이면 계속 진행
}

// 주어진 트리의 간선과 목표 값을 바탕으로 해답을 찾는 함수
vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    // 노드 간의 연결 정보 및 자식 노드 정보 초기화
    int nodeCount = target.size();
    adjList = vector<vector<int>>(nodeCount + 1); // 인접 리스트 초기화
    childQueue = vector<queue<int>>(nodeCount + 1); // 각 노드의 자식 노드 큐 초기화
    visitCount = vector<int>(nodeCount + 1, 0); // 방문 횟수 초기화
    targetValues = vector<int>(1, 0); // 인덱스 0은 사용하지 않음
    targetValues.insert(targetValues.end(), target.begin(), target.end()); // target 복사

    // 간선 정보를 이용해 인접 리스트 구성
    for (const auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
    }
    
    // 자식 노드들을 사전 순으로 정렬
    //초기길 설정
    for (int i = 0; i < adjList.size(); i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    // 각 노드의 자식 노드를 큐에 넣음
    for (int i = 0; i < adjList.size(); i++) {
        for (int child : adjList[i]) {
            childQueue[i].push(child);
        }
    }

    vector<int> visitedOrder; // 리프 노드 방문 순서
    while (true) {
        int leafNode = getLeafNode(); // 리프 노드 찾기
        visitedOrder.push_back(leafNode); // 방문 순서 저장
        visitCount[leafNode] += 1; // 해당 노드의 방문 횟수 증가
        
        //조건 1 :  모든 경우 중 가장 적은 숫자를 사용
        int status = checkTarget(); // 목표 달성 여부 확인
        if (status == 0) { // 목표 달성 시 종료
            break;
        } else if (status == 2) { // 목표 달성 불가능한 경우
            return vector<int>(1, -1); // 불가능을 표시
        }
    }

    // 조건 2 : 사준순으로 가장 빠른 경우 : 사전 순으로 값을 할당하여 최종 결과 생성
    vector<int> result;
    for (int node : visitedOrder) {
        visitCount[node] -= 1; // 방문 횟수 감소
        
        //사전순이기 때문에 1을 먼저 넣는 것이 좋음 
        //a: 1을 넣었을 때 남은 수 :  targetValues[node] - 1
        //b:  방문횟수에서 1개를 쓰고(위에서 1감소) 나은 개수로 채울수 있는 최대 수 : visitCount[node] * 3
        // b가 더 크다면 가능하다. 
        if (visitCount[node] * 3 >= targetValues[node] - 1) {
            result.push_back(1);
            targetValues[node] -= 1;
        } else if (visitCount[node] * 3 >= targetValues[node] - 2) {
            result.push_back(2);
            targetValues[node] -= 2;
        } else {
            result.push_back(3);
            targetValues[node] -= 3;
        }
    }

    return result; // 최종 결과 반환
}
