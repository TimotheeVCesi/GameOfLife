#include "cell.h"

bool CellClassic::isAlive() const{
    return state;
}

void CellClassic::setAlive(bool alive){
    state = alive;
}

void CellClassic::updateState(int aliveNeighbors){
    state = isAlive() ? (aliveNeighbors == 2 || aliveNeighbors == 3) : (aliveNeighbors == 3);
}

bool CellObstacle::isAlive() const { 
    return state; 
}

void CellObstacle::setAlive(bool alive){ 
    state = alive; 
}