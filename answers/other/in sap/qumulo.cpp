// Today, we’re going to be helping Joe. Joe works in a maze.
// Unfortunately, portions of the maze have caught on fire, and
// Joe doesn’t have the maze escape manual in his back pocket.
//
// Poor Joe! But you can help Joe escape the maze.
// 
// Given a maze with both Joe and the squares that are on fire, you
// must determine whether Joe can exit the maze before the fire
// reaches him, and how long it takes him to do it (in minutes).
//
// Joe and the fire each move one square per minute, vertically or 
// horizontally (not diagonally). The fire spreads in four directions
// from each square that is on fire. Joe may exit the maze from any
// square that borders the edge of the maze. Neither Joe nor the fire
// may enter a square that is occupied by a wall.
//
// As an example, consider the maze below:
//
// #############   Legend: J = Joe, F = fire, # = wall, |_ = exit
// # J         #   It will take Joe 14 minutes to exit this maze.
// ####  ##### #   The fire will be right behind him.
// |  #  #   # #
// |  #F #   # #
// |__#______#_| 
// 
// The maze is represented by the data structure below. I’ve written
// it in Java, but you can use whatever language you’re most
// proficient in to solve the problem. 

public enum Square { Open, Wall, Fire, Joe };
public class Maze {
//Square[][] cells;
vector<vector<Square> > cells;
};

public static int escapeTheMaze(Maze maze) {
    queue<Maze> maze_queue;
    maze_queue.push(maze);
    int time = 0;
    while (! maze_queue.empty()) {
        size_t size = maze_queue.size();
        for (size_t i = 0; i < size; ++ i) {
            Maze current = maze_queue.top();
            maze_queue.pop();
            size_t joe[2];
            for (size_t j = 0; j < current.cells.size(); ++ j) {
                for (size_t k = 0; k < current.cells[j].size(); ++ k) {
                    if (Joe  == current.cells[j][k]) {
                        if (0 == j || j + 1 == current.cells.size() || 0 == k || k + 1 == current.cells[j].size()) {
                            return time;
                        }
                        joe[0] = j;
                        joe[1] = k;
                        current.cells[j][k] = Open;
                        break;
                    }
                }
            }
            Maze new_maze(current);
            for (size_t j = 0; j < current.cells.size(); ++ j) {
                for (size_t k = 0; k < current.cells[j].size(); ++ k) {
                    if (Fire == current.cells[j][k]) {
                        if (j > 0 && Wall != current.cells[j - 1][k]) {
                            new_maze[j - 1][k] = Fire;
                        }
                        if (j + 1 < current.cells.size() && Wall != current.cells[j + 1][k]) {
                            new_maze[j + 1][k] = Fire;
                        }
                        if (k > 0 && Wall != current.cells[j][k - 1]) {
                            new_maze[j][k - 1] = Fire;
                        }
                        if (k + 1 < current.cells[j].size() && Wall != current.cells[j][k + 1]) {
                            new_maze[j][k + 1] = Fire;
                        }
                    }
                }
            }
            current = new_maze;
            if (joe[0] > 0 && Open == current.cells[joe[0] - 1][joe[1]]) {
                Maze temp(current);
                temp.cells[joe[0] - 1][joe[1]] = Joe;
                maze_queue.push(temp);
            }
            if (joe[0] + 1 < current.cells.size() && Open == current.cells[joe[0] + 1][joe[1]]) {
                Maze temp(current);
                temp.cells[joe[0] + 1][joe[1]] = Joe;
                maze_queue.push(temp);
            }
            if (joe[1] > 0 && Open == current.cells[joe[0]][joe[1] - 1]) {
                Maze temp(current);
                temp.cells[joe[0]][joe[1] - 1] = Joe;
                maze_queue.push(temp);
            }
            if (joe[1] + 1 < current.cells[joe[0]].size() && Open == current.cells[joe[0]][joe[1] + 1]) {
                Maze temp(current);
                temp.cells[joe[0]][joe[1] + 1] = Joe;
                maze_queue.push(temp);
            }
        }
        ++ time;
    }
    return -1;
}