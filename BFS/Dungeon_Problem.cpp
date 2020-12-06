#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_set>

using namespace std;

typedef pair<int, int> coord;

namespace std
{
    template <>
    struct hash<coord>
    {
        inline size_t operator()(const coord &v) const
        {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };

} // namespace std

class Dungeon
{
public:
    Dungeon()
    {
        board = new string[5];
        board[0] = "...#...";
        board[1] = ".#...#.";
        board[2] = ".#.#...";
        board[3] = "..##...";
        board[4] = "..#E.#.";
    }

    ~Dungeon()
    {
        delete[] board;
    }

    void printBoard()
    {
        cout << '\n';
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void solve(int startRow, int startCol)
    {
        // Check to see if starting position is legal
        if (!isLegal(startRow, startCol))
        {
            printf("\nSpace is occupied\n");
            return;
        }

        // Initialize variables
        int rowVec[] = {1, -1, 0, 0};
        int colVec[] = {0, 0, 1, -1};

        board[startRow][startCol] = 'S';

        coord start = make_pair(startRow, startCol);
        coord node;

        queue<coord> q;
        q.push(start);

        unordered_set<coord> visited = {start};
        coord prev[5][7];

        // BFS algorithm
        while (!q.empty())
        {
            node = q.front();
            q.pop();

            if (board[node.first][node.second] == 'E')
            {
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                if (isLegal(node.first + rowVec[i], node.second + colVec[i]))
                {
                    coord next = make_pair(node.first + rowVec[i], node.second + colVec[i]);
                    if (visited.find(next) == visited.end())
                    {
                        q.push(next);
                        visited.insert(next);
                        prev[next.first][next.second] = node;
                    }
                }
            }
        }

        // Reconstruct path
        stack<coord> path;
        for (coord at = node;
             at.first != startRow || at.second != startCol;
             at = prev[at.first][at.second])
        {
            path.push(at);
        }

        // Print path
        if (prev[path.top().first][path.top().second] == start)
        {
            printf("\nReconstructed Path: (%d, %d)-> ", startRow, startCol);
            while (!path.empty())
            {
                coord out = path.top();
                path.pop();
                printf("(%d, %d)-> ", out.first, out.second);
                if (board[out.first][out.second] != 'E')
                {
                    board[out.first][out.second] = '*';
                }
            }
            cout << '\n';
        }
        else
        {
            printf("\nPath Not Found");
            cout << '\n';
        }
    }

private:
    string *board;

    bool isLegal(int row, int col)
    {
        return (row >= 5 ||
                col >= 7 ||
                row < 0 ||
                col < 0 ||
                board[row][col] == '#')
                   ? false
                   : true;
    }
};

int main()
{
    Dungeon d;
    d.printBoard();
    d.solve(0, 0);
    d.printBoard();
}