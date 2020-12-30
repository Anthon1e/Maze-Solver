#include <fstream>
#include <iostream>
#include <vector>
#include <string>

/* Global variable for finding solutions */
std::vector<std::string>    valid_sol;
int                         valid_sol_num;

/* Define constant */
#define MAZE1     "maze1.txt"
#define MAZE2     "maze2.txt"
#define MAZE3     "maze3.txt"
#define MAZE119   "maze119.txt"
#define MAZE3877  "maze3877.txt"
#define MAZEMY    "mazemy.txt"
#define VISITED   'Y'
#define UNVISITED 'N'

/* For maze storing */
typedef struct maze_cell {
    char character;
    char visited;
} maze_cell;

/* Function */
int         *   get_maze_dimension(std::ifstream& file);
maze_cell   **  store_maze(std::ifstream& file, int* dimension);
void            find_possible_paths(maze_cell** maze, int* dimension, int row, int column, std::string path);
void            find_cheap_short_path(std::vector<std::string> valid_sol);