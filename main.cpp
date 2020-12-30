#include "main.h"
#include <fstream>
#include <iostream>
#include <string>

int main() 
{	
	int			*	dimension;
	maze_cell	**	maze = NULL;

	// Initialize global variable
	valid_sol_num = 0;

	// File input
	std::ifstream file;
	file.open(MAZEMY);

	// Check if we can open the file
	if (file.is_open()) 
	{
		std::cout << "File is opened" << "\n";
		dimension = get_maze_dimension(file);
		maze = store_maze(file, dimension);
		find_possible_paths(maze, dimension, 0, 0, "");
		std::cout << "Total number of solutions: " << valid_sol_num << "\n";
		find_cheap_short_path(valid_sol);
	}
	else 
	{
		std::cout << "Cannot open sample maze file" << "\n";
		return 0; 
	}

	return 0;
}

int* get_maze_dimension(std::ifstream& file)
{
	static int dimension[2] = { 0, 0 }; // Number of rows, columns
	std::string line;

	// When a line is available/read
	while (getline(file, line))
	{
		// Count the rows
		dimension[0] += 1;
	}
	// Count the columns
	dimension[1] = line.length(); 
	// Set pointer back to the start of the file
	file.clear();
	file.seekg(0);

	return dimension;
}

maze_cell** store_maze(std::ifstream& file, int* dimension)
{
	int				row = 0,
					column = 0;
	maze_cell	**	maze = NULL;
	std::string line;

	// Dynamic allocate the space for the maze's columns
	maze = new maze_cell*[dimension[0]];
	for (int i = 0; i < dimension[0]; i++)
		// Dynamic allocate based on the number of rows
		maze[i] = new maze_cell[dimension[1]];

	// When a line is available/read
	while (getline(file, line))
	{	
		for (column = 0; column < dimension[1]; ++column) {
			maze[row][column].character = line[column];
			maze[row][column].visited = UNVISITED;
		}
		row += 1;
	}
	// Set pointer back to the start of the file
	file.seekg(0);
	file.close();

	return maze;
}

void find_possible_paths(maze_cell** maze, int* dimension, int row, int column, std::string path)
{
	int				path_length = 0;
	char			new_point;
	std::string		new_path;

	// If this is not a valid point, e.g., a wall or an already visited point, return
	if ((row < 0) || (column < 0) || (row > (dimension[0] - 1)) || (column > (dimension[1] - 1)) ||
		(maze[row][column].visited == VISITED) || (maze[row][column].character == '*')) {
		return;
	}

	// If this is a valid point, add it to the current path
	else {
		new_point = maze[row][column].character;
		path_length = path.length();
		// Add the current recursive path to local path
		if (path_length != 0)
			new_path = new_path.append(path);
		// Add new point to the path
		new_path += new_point;

		// If we have found the path out of the maze (last column of text file)
		if (column == (dimension[1] - 1)) {
			// Add the valid solution to the list of solutions
			valid_sol.push_back(new_path);
			// Count number of solutions
			valid_sol_num++;

			return;
		}
		else {
			// Mark the current point if it is visited
			maze[row][column].visited = VISITED;
			// Recursively check next points for possible paths
			find_possible_paths(maze, dimension, row + 1, column, new_path);	// up
			find_possible_paths(maze, dimension, row - 1, column, new_path);	// down
			find_possible_paths(maze, dimension, row, column + 1, new_path);	// right
			find_possible_paths(maze, dimension, row, column - 1, new_path);	// left
			// Unmark the current point in case we want to visit it again in other possible paths
			maze[row][column].visited = UNVISITED;

			return;
		}
	}
}

void find_cheap_short_path(std::vector<std::string> valid_sol)
{	
	std::string		string; 
	std::string		string_min;
	std::string		string_price_min;
	int				price = 0;
	int				price_min = 0;

	// Getting value from the first solution 
	string				= valid_sol[0];
	string_min			= valid_sol[0];
	string_price_min	= valid_sol[0];
	for (int a = 0; a < string.length(); a++)
		price_min += valid_sol[0][a] - '0';

	// Looping through the solutions to get 1 string at a time
	for (int i = 1; i < valid_sol.size(); i++)
	{
		price = 0;
		string = valid_sol[i];

		// Looping through the string to get 1 number at a time
		for (int a = 0; a < string.length(); a++)
			price += valid_sol[i][a] - '0';

		// Looking for shortest and cheapest solution
		if (price < price_min) {
			string_price_min = string;
			price_min = price;
		}
		if (string.length() < string_min.length())
			string_min = string;
	}

	std::cout << "Shortest path: " << string_min << "\n";
	std::cout << "Cheapest path: " << string_price_min << "\n";
	std::cout << "Cheapest path cost: " << price_min << "\n";

	return; 
}