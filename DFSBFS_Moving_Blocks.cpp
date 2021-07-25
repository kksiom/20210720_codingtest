/*
[입력]
5
0 0 0 1 1
0 0 0 1 0
0 1 0 1 1
1 1 0 0 1
0 0 0 0 0
[출력]
7
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 위치 정보가 (x1,y1):(x2,y2) 로 표현되므로 클래스로 만듬.
class RobotPos {
public:
    int r1;
    int c1;
    int r2;
    int c2;
    RobotPos(int r1, int c1, int r2, int c2) {
        this->r1 = r1;
        this->c1 = c1;
        this->r2 = r2;
        this->c2 = c2;
    }
    bool operator==(const RobotPos& data) {
        if (r1 == data.r1 && c1 == data.c1
            && r2 == data.r2 && c2 == data.c2)
            return true;
        if (r1 == data.r2 && c1 == data.c2
            && r2 == data.r1 && c2 == data.c1)
            return true;
        return false;
    }
};
int n;

vector<RobotPos> getNextPos(RobotPos pos, vector<int>* board) {
    vector<RobotPos> nextPos; // 반환 결과 (이동 가능한 위치들)
    // (상, 하, 좌, 우)로 이동하는 경우에 대해서 처리
    int dy[] = { -1, 1, 0, 0 };
    int dx[] = { 0, 0, -1, 1 };
    for (int i = 0; i < 4; i++) {
        int nr1 = pos.r1 + dy[i];
        int nc1 = pos.c1 + dx[i];
        int nr2 = pos.r2 + dy[i];
        int nc2 = pos.c2 + dx[i];
        // 이동하고자 하는 두 칸이 모두 비어 있다면
        if (board[nr1][nc1] == 0 && board[nr2][nc2] == 0) {
            nextPos.push_back(RobotPos(nr1, nc1, nr2, nc2));
        }
    }

    int delta[] = { -1, 1 };
    // 현재 로봇이 가로로 놓여 있는 경우
    if (pos.r1 == pos.r2) {
        for (int i = 0; i < 2; i++) { // 위쪽으로 회전하거나, 아래쪽으로 회전
            // 위쪽 혹은 아래쪽 두 칸이 모두 비어 있다면
            if (board[pos.r1 + delta[i]][pos.c1] == 0 && board[pos.r2 + delta[i]][pos.c2] == 0) {
                nextPos.push_back(RobotPos(pos.r1, pos.c1, pos.r1 + delta[i], pos.c1));
                nextPos.push_back(RobotPos(pos.r2, pos.c2, pos.r2 + delta[i], pos.c2));
            }
        }
    }
    // 현재 로봇이 세로로 놓여 있는 경우
    if (pos.c1 == pos.c2) {
        for (int i = 0; i < 2; i++) { // 왼쪽으로 회전하거나, 오른쪽으로 회전
            // 왼쪽 혹은 오른쪽 두 칸이 모두 비어 있다면
            if (board[pos.r1][pos.c1 + delta[i]] == 0 && board[pos.r2][pos.c2 + delta[i]] == 0) {
                nextPos.push_back(RobotPos(pos.r1, pos.c1, pos.r1, pos.c1 + delta[i]));
                nextPos.push_back(RobotPos(pos.r2, pos.c2, pos.r2, pos.c2 + delta[i]));
            }
        }
    }
    // 현재 위치에서 이동할 수 있는 위치들을 반환.
    return nextPos;
}

int solution(vector<int>* board) {
    // BFS를 위한 큐 준비. (위치 정보 + 스텝 수)
    queue<pair<RobotPos, int> > q;
    // 전에 방문했던 자리인지 기억.
    vector<RobotPos> visited;
    // 시작 위치 설정
    RobotPos pos = RobotPos(1, 1, 1, 2);
    // 큐에 삽입 + 방문 처리.
    q.push({ pos, 0 });
    visited.push_back(pos);
    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 1개 꺼내어..
        RobotPos pos = q.front().first;
        int cost = q.front().second;
        q.pop();
        // (n, n) 위치에 로봇이 도달했다면, 최단 거리이므로 반환
        if ((pos.r1 == n && pos.c1 == n) || (pos.r2 == n && pos.c2 == n)) {
            return cost;
        }
        // nextPos = 현재 위치에서 이동할 수 있는 위치들 모두 가져오기.
        vector<RobotPos> nextPos = getNextPos(pos, board);
        for (int i = 0; i < nextPos.size(); i++) {
            // 아직 방문하지 않은 위치라면 큐에 삽입하고 방문 처리
            bool already_visited = false;
            RobotPos pos = nextPos[i];
            for (int j = 0; j < visited.size(); j++) {
                if (pos == visited[j]) {
                    already_visited = true;
                    break;
                }
            }
            if (!already_visited) {
                q.push({ pos, cost + 1 });
                visited.push_back(pos);
            }
        }
    }
    return 0;
}

int main() {
    cin >> n;
    // 맵의 외곽에 벽을 두는 형태로 입력 받기. (1로써 둘러 싸기)
    vector<int>* board = new vector<int>[n + 2];
    for (int x = 0; x < n + 2; x++)
        board[0].push_back(1);
    for (int y = 1; y < n + 1; y++) {
        board[y].push_back(1);
        for (int x = 0; x < n; x++) {
            int value;
            cin >> value;
            board[y].push_back(value);
        }
        board[y].push_back(1);
    }
    for (int x = 0; x < n + 2; x++)
        board[n + 1].push_back(1);

    int result = solution(board);
    cout << result << endl;

    return 0;
}

