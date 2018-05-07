# Overview

Filler is a game where two algorithms are fighting on a map. 

A virtual machine organizes the game :
- calls each player alternatively
- give each a random piece

On each turn, the current player have to put his piece on the map, and try to bother the ennemy.

The goal is to put more pieces on the map than the ennemy. 

## Algorithm

## Exemple

## Requirements

You will need brew for this project.

`brew install $(<requirements.txt)`

## Installation

`make`

## Run

`./filler_vm -f maps/[map] -p1 players/[player1] -p2 players/[player2]`

Or with the vizualiser :

`./filler_vm -f maps/[map] -p1 players/[player1] -p2 players/[player2] | ./visu`
