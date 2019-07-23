#include "pathfinding.hpp"


/** solve_maze(int** maze, int n)
 * Decides whether the maze is solvable from position (0, 0) by making a call
 * to the recursive function by the same name.
 */
bool solve_maze(int** maze, int n){
    int pos[2] = {0,0};
    return solve_maze(maze , n , pos );
}

/** solve_maze(int** maze, int n)
 * Recursively decides whether the maze is solvable from the given position
 * using backtracking.
 * A maze is solvable if position (n - 1, n - 1)  may be reached from the
 * given position by only moving downward and to the right, but not both at
 * once (i.e. not diagonally). A position in the maze is valid to move to
 * only if it contains a 1.
 */
bool solve_maze(int** maze, int n, int position[2]){
    int x,y = 0;
    if(x >= 0 || y <= 0 || x >= n || y >= n || !maze[x][y] == 1){return false;}//are you in maze and
    if(position[0] == n-1 && position[1] == n-1){return true;} //are you on a done
    int down[2] = {x,y+1};
    int right[2] = {x+1,y};
    return solve_maze(maze,n, down) || solve_maze(maze,n, right);//do recurrance
    

}