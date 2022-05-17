#include <stdio.h>
#include <stdbool.h>
#define N 6
/// For printing the final solution Matrix
void printSolution(int solution[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", solution[i][j]);
        printf("\n");
    }
}
/// For checking if solution coordinate is in matrix or not
bool isSafe(int maze[N][N], int x, int y){
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}
/// For looking to the neighbour cells
bool lookRight(int maze[N][N], int x, int y){
    if(maze[x][y+1]==0)
        return false;
    if(maze[x][y+1]==1)
        return true;
}
bool lookDown(int maze[N][N], int x, int y){
    if(maze[x+1][y]==0)
        return false;
    if(maze[x+1][y]==1)
        return true;
}
bool lookLeft(int maze[N][N], int x, int y){
    if(maze[x][y-1]==0)
        return false;
    if(maze[x][y-1]==1)
        return true;
}
bool lookUp(int maze[N][N], int x, int y){
    if(maze[x-1][y]==0)
        return false;
    if(maze[x-1][y]==1)
        return true;
}
/// For moving in available direction
bool moveRight(int maze[N][N], int x,int y){
    if (lookRight(maze, x, y)==true && isSafe(maze, x, y)==true)
        return true;
    else
        return false;
}
bool moveDown(int maze[N][N], int x,int y){
    if (lookDown(maze, x, y)==true && isSafe(maze, x, y)==true)
        return true;
    else
        return false;
}
bool moveLeft(int maze[N][N], int x,int y){
    if (lookLeft(maze, x, y)==true && isSafe(maze, x, y)==true)
        return true;
    else
        return false;
}
bool moveUp(int maze[N][N], int x,int y){
    if (lookUp(maze, x, y)==true && isSafe(maze, x, y)==true)
        return true;
    else
        return false;
}
/// For solving the main maze
bool solveMaze(int maze[N][N], int x, int y, int xFinal, int yFinal){
    int solution[N][N]={{0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0}};
    if (moveRight(maze, x, y)==true){
        solution[x][y+1]=1;
    }
    if (moveDown(maze, x, y)==true){
        solution[x+1][y]=1;
    }
    if (moveLeft(maze, x, y)==true){
        solution[x][y-1]=1;
    }
    if (moveUp(maze, x, y)==true){
        solution[x-1][y]=1;
    }
    printSolution(solution);
}
/// Main maze
int main() {         //S
    int maze[N][N] = {{1, 0, 1, 1, 1, 1},
                      {1, 0, 1, 0, 0, 1},
                      {1, 0, 1, 0, 0, 1},
                      {1, 0, 1, 0, 0, 1},
                      {1, 1, 1, 0, 0, 1},
                      {0, 0, 0, 0, 0, 1}};
    solveMaze(maze, 0, 0, N, N);    //E
    return 0;}