# c-querty-analyser

## Idea
A "good" word is a word that can be typed only by pressing adjacent buttons on a qwerty keyboard.\
The program takes a filename as a console argument and counts, how many lines of the file are "good words".

## Implementation points
The adjacency of buttons is defined with a map of adjacency - an array of strings of adjacent character to a character.

## Build
**Important!**
The solution uses the posix getline(), so please compile and run on unix.

To build, use makefile from src/\
The program compiles into "checker" to the build/ folder.
