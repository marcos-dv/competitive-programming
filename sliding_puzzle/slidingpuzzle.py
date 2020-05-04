#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import heapq as pq
import copy

" Programa para resolver el Puzzle Deslizante mediante heuristica usando "
" el metodo A* con heuristica la distancia Manhattan "
" No alcanza la solucion pero bueno "

# El vacio se marca con un 0
VACIO = 0
# Lado del puzzle NxN
N = 3

# Devuelve lista de coordenadas
# coord[k] = (i,j) tal que state[i,j] == k
# Se usa para tener las coordenadas del estado final
def coords(state):
    points = []
    for k in range(0,N*N):
        for i in range(0,N):
            for j in range(0,N):
                if state.numbers[i][j] == k:
                    points.append((i,j))
    return points

# Distancia de cada pieza a su posicion buena
def h(state):
    dif = 0
    for i in range(0,N):
        for j in range(0,N):
            k = state.numbers[i][j]
            ii, jj = goal_coors[k]
            dif += abs(ii-i)+abs(jj-j)
    return dif

# Heuristica mala (cuantas piezas caen mal)
def hMala(state):
    dif = 0
    for i in range(0,N):
        for j in range(0,N):
            if state.numbers[i][j] != goal_state.numbers[i][j]:
                dif += 1
    return dif

# Estado del juego
class State:
    def __init__(self, numbers):
        # copia las listas dentro de la lista
        self.numbers = copy.deepcopy(numbers)
    # eq compara el tablero
    def __eq__(self, other): 
        for i in range(0,N):
            for j in range(0,N):
                if self.numbers[i][j] != other.numbers[i][j]:
                    return False
        return True
    # hash para usar set
    def __hash__(self):
        hashval = 15;
        prime = 31
        for i in range(0,N):
            for j in range(0,N):
                hashval = (self.numbers[i][j]^prime+hashval) % 4884279
        return hashval
    # <= 
    def __lt__(self, other): 
        for i in range(0,N):
            for j in range(0,N):
                if self.numbers[i][j] < other.numbers[i][j]:
                    return True
                elif self.numbers[i][j] > other.numbers[i][j]:
                    return False
        return False

    def print(self):
        string = ''
        for i in range(0,N):
            for j in range(0,N):
                string += str(self.numbers[i][j])+' '
            string += '\n'
        print(string)
        
    # expandir movimientos
    def expand(self):
        for i in range(0,N):
            for j in range(0,N):
                if self.numbers[i][j] == VACIO:
                    x = i
                    y = j
        neighbours = []
        
        if (y-1 >= 0):
            newStateE = self.copy()
            newStateE.numbers[x][y] = self.numbers[x][y-1]
            newStateE.numbers[x][y-1] = self.numbers[x][y]
            neighbours.append(newStateE)
        if (y+1 < N):
            newStateW = self.copy()
            newStateW.numbers[x][y] = self.numbers[x][y+1]
            newStateW.numbers[x][y+1] = self.numbers[x][y]
            neighbours.append(newStateW)
        if (x-1 >= 0):
            newStateS = self.copy()
            newStateS.numbers[x][y] = self.numbers[x-1][y]
            newStateS.numbers[x-1][y] = self.numbers[x][y]
            neighbours.append(newStateS)
        if (x+1 < N):
            newStateN = self.copy()
            newStateN.numbers[x][y] = self.numbers[x+1][y]
            newStateN.numbers[x+1][y] = self.numbers[x][y]
            neighbours.append(newStateN)
        
        return neighbours
    
    def copy(self):
        return State(self.numbers)

# Clase nodo para la heuristica
# Representa un estado, su valor g
class Node:
    def __init__(self, state, gValue):
        self.state = State(state.numbers)
        self.g = gValue
    # Compara 2 nodos por su f-valor
    def __le__(self, other): 
        return h(self.state)+self.g <= h(other.state)+other.g
    def __lt__(self, other): 
        return h(self.state)+self.g < h(other.state)+other.g

        
###########################################
###########################################
##################### MAIN ################
###########################################
###########################################

#########################
##### Datos iniciales
        
# estado inicial
init_state = State([[1,2,3],[6,VACIO,4],[7,5,8]])
# estado final
goal_state = State([[1,2,3],[4,5,6],[7,8,VACIO]])
# preprocesa coordenadas
goal_coors = coords(goal_state)


print('Meta')
goal_state.print()
print('--------')

#########################
##### Algoritmo A*

# Nodo inicial
initial_node = Node(init_state, 0)
# Nodos por procesar
open_nodes = [initial_node]
#closed_nodes = []
# Nodos procesados
close = set()
max_iter = 1
while max_iter <= 500000 and len(open_nodes) > 0:  
    # Candidato con menor f-valor
    curNode = pq.heappop(open_nodes)
    if max_iter % 1 == 0:
        print('Estado ', max_iter, ' | f = ', (h(curNode.state)+curNode.g), '| h = ', h(curNode.state), ', g = ', curNode.g)
        curNode.state.print()

    # Estado final alcanzado
    if h(curNode.state) == 0:
        break
    # Nodo ya visitado, no expandimos
    if curNode.state in close:
        continue
    
    # Expansion
    for state in curNode.state.expand():
        open_nodes.append(Node(state, curNode.g+1))
    # Insertar en procesados
    close.add(curNode.state)
    max_iter += 1
    
#################### Fin del algoritmo
print('Estado final alcanzado tras ', max_iter, ' pasos, h = ', h(curNode.state))
curNode.state.print()

###########################################
########## Fin del programa ###############
###########################################

