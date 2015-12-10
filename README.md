# Pathfinder

## Introduction 
The purpose of this project is to find a path between two locations on a map.
It takes two input arguments:
- The map file
- The interference value (R) 
 - (Specifies the minimum allowed distance between each robot.)
 
When run, the program will attempt to find a path through the map, and print out a new map with the paths each robot traveled displayed.

If the initial positions of the robots conflict with the interference value (R), it will print an error message and return -1.

All program errors return code -1

### Key
- '$' Path traveled by robot S
- '@' Path traveled by robot F
- '!' Path traveled by robots S and F
- 'S' Initial position of robot S
- 'F' Initial position of robot F
- 'E' Final position of robot S
- 'L' Final position of robot robot F
- '#' Wall (newlines are also walls) 
- ' ' Traversable path 
 
## Requirements 
- GCC 4.9 or Clang
- Doesn't work with GCC 4.4

## Usage 
Run the following commands to install & use: 
```
git clone git@github.com:nihilanth41/pathfinder.git -b final-draft
cd pathfinder/src
make 
./pathfinder.bin <map file> <interference (R)>  
```
Example usage:
```
./pathfinder.bin room.txt 0
```

## Known issues
1. Memory issues 
	* Definitely has some issues with memory allocation
	* Map file is loaded into a static sized 2D array instead of allocated dynamically 
	* Memory leaks
2. Segfaults sometimes
	* I think this is due to a logic error, dereferencing a NULL pointer, array bounds checking, etc.
	* If it segfaults run it a couple times it usually works.
3. Builds but doesn't run (always segfaults) with gcc 4.4 (the version on babbage)
	* It usually runs (but segfaults occasionally) when built with gcc 4.9, or Clang on OSX.
4. The algorithm adds walls ('#') when back-tracking, so the output map may look slightly different


## Authors 
- Jakob Daugherty
- John Jolley
- Zachary Rump 
