'''
Created on 26.03.2011

@author: Sergei Zalivako
'''

import sys

startVertex = 0
finishVertex = 0
color = []
vertexes = []
previous = []

def input():
    file = open('input.txt', 'r')
    vertexesCount = int(file.readline())
    for currentVertex in range(vertexesCount):
        vertexes.append(file.readline().split())        
        color.append('white')
        previous.append(-1)
        vertexes[currentVertex].remove(vertexes[currentVertex][0])                
        vertexIndex = 0
        for vertex in vertexes[currentVertex]:
            vertexes[currentVertex][vertexIndex] = int(vertex) - 1
            vertexIndex = vertexIndex + 1
    
    pathEnds = file.readline().split()
    file.close()
    global startVertex
    startVertex = int(pathEnds[0]) - 1
    global finishVertex
    finishVertex = int(pathEnds[1]) - 1
    

def DFS_Visit(currentVertex):
    color[currentVertex] = 'gray'
    for viewedVertex in vertexes[currentVertex]:
        if (color[viewedVertex] == 'white'):
            DFS_Visit(viewedVertex)
            previous[viewedVertex] = currentVertex
    color[currentVertex] = 'black'

def output():
    file = open('output.txt', 'w')
    if previous[finishVertex] == -1:
        file.write('-1')
    else:
        currentVertex = finishVertex
        path = []
        while (previous[currentVertex] != -1):
            path.append(currentVertex)
            currentVertex = previous[currentVertex]
        path.append(currentVertex)
        path.reverse()
        for vertexNumber in path:
            file.write(str(vertexNumber + 1) + ' ')
        file.close()    

sys.setrecursionlimit(10**9)
input()
DFS_Visit(startVertex)
output()
