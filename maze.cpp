#include <iostream>

#include <string>
using namespace std; 




bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    if (sr == er && sc == ec) {
        return true; 
    }
    else {
        maze[sr][sc] = '!';

        if (maze[sr + 1][sc] == '.') {
            if (pathExists(maze, nRows, nCols, sr + 1, sc, er, ec)) {
                return true; 
           }
        }

        if (maze[sr -1][sc] == '.') {
            if (pathExists(maze, nRows, nCols, sr -1, sc, er, ec)) {
                return true;
            }
        }
        if (maze[sr][sc +1] == '.') {
            if (pathExists(maze, nRows, nCols, sr, sc +1, er, ec)) {
                return true;
            }
        }
        if (maze[sr][sc-1] == '.') {
            if (pathExists(maze, nRows, nCols, sr, sc-1, er, ec)) {
                return true;
            }
        }
        return false;

    }
}


int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X..X...X.X",
        "X.XXXX.X.X",
        "X.X.X..X.X",
        "X...X.XX.X",
        "XXX......X",
        "X.X.XXXX.X",
        "X.XXX....X",
        "X...X..X.X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10, 10, 5, 3, 8, 8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}