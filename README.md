# Overview

Filler is a game where two algorithms are fighting on a map. 

A virtual machine organizes the game :
- calls each player alternatively
- give each a random piece

On each turn, the current player have to put his piece on the map, and try to bother the ennemy.

The goal is to put more pieces on the map than the ennemy. 

## Algorithm

This algorithm is based on a DFS with a Manhattan heuristic.

Each turn, the algorithm will divide the board in 3 parts (using the distance between each cell and the nearest player) : his part, the oppenent part and the neutral part.
Next, he will try to maximize his territory by putting the piece where he can win the more cells. This algorithm will have tendency to surround his opponent.

I created a visualizer to have a better understanding of the game.

## Exemple

![Start Menu](https://raw.githubusercontent.com/afoures/Filler/master/images/startMenu.png)
![Help Menu](https://raw.githubusercontent.com/afoures/Filler/master/images/helpMenu.png)
![Winner](https://raw.githubusercontent.com/afoures/Filler/master/images/winner.png)

## Requirements

You will need brew for this project.

`brew install $(<requirements.txt)`

## Installation

`make`

## Run

`./filler_vm -f maps/[map] -p1 players/[player1] -p2 players/[player2]`

Or with the visualizer :

`./filler_vm -f maps/[map] -p1 players/[player1] -p2 players/[player2] | ./visu`
