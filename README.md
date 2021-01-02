# Maze Solver

This is a program written in C++ which made use of Recursion algorithm to implement the Systematic Backtracking concept and determine all possible paths to any random mazes. 

## Concepts and Ideas

Systematic backtracking is a recursive mechanism which can be used to build a complete search algorithm on top of a constructive search method. When walking through a maze, we will try to follow a path as far as we can, which will either lead us to an exit or a deadend. If it is a deadend, we want to retrace our step to reach the most recent fork, where we can continue searching if there is a path we have not taken. This approach guarantees that you will be able to find all possible solutions of the maze. 

## Setting up

1. The maze is stored in a text file, which we need to read as an input. We have to store the maze in an array of string, aka vectors. 
2. In the maze file, the numbers will represent the spot that you can move to and also its price. The '*' represents the wall.
3. We always start at coordinate (0, 0), or top left, of the maze file, and can move horizontally and vertically, as long as it is a valid path. 
4. We get out of the maze when we are on the right hand size of the maze, aka the right column of the text file. 
5. Valid paths do not contain loops, meaning we cannot go through a spot twice.
6. We want the number of possible solutions to the maze, the shortest and also the cheapest solution. 

## Solver sample

If the following maze is presented,

![](https://github.com/Anthon1e/Maze-Solver/blob/main/Sample1.png)

we will get the following output as solution:

![](https://github.com/Anthon1e/Maze-Solver/blob/main/Sample2.png)

## Known bugs

There might be warnings when you run the program but they are insignificant