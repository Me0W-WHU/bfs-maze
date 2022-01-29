#include <iostream>
#include <queue>
#define INF 0x7fffffff
using namespace std;

//using pair to represent coordinates
typedef pair<int, int> P;

int N, M;
char maze[100][100];
int sr, sc, er, ec;
int nr, nc;

//distance matrix
int d[100][100];

//move vector
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    //maze size
    cin >> N >> M;

    //maze input
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            cin >> maze[i][j];
            d[i][j] = INF;
            if (maze[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            else if (maze[i][j] == 'E') {
                er = i;
                ec = j;
            }
        }
    }

    //initialize queue
    d[sr][sc] = 0;
    queue<P> q;
    q.push(P(sr, sc));

    //bfs
    while(!q.empty()) {
        //get current point (pop queue)
        P cp = q.front();
        q.pop();

        //check endpoint
        if (cp.first == er && cp.second == ec) break;

        //search forward (push queue)
        for (int i = 0 ; i < 4 ; i++) {
            nr = cp.first + dx[i];
            nc = cp.second + dy[i];
            //in range && accessible && haven't been searched
            if (nr >= 0 && nr < N && nc >=0 && nc < M && maze[nr][nc] != '#' && d[nr][nc] == INF) {
                q.push(P(nr, nc));
                //update distance matrix while searching
                d[nr][nc] = d[cp.first][cp.second] + 1;
            }
        }
    }

    //output result
    cout << d[er][ec];
}
