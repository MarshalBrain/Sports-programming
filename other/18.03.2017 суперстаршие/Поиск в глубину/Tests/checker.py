'''
Created on 27.03.2011

@author: Sergei Zalivako
'''

import sys

vertexes = []

file = open(sys.argv[1] + '.in', 'r')
vertexesCount = int(file.readline())
for currentVertex in range(vertexesCount):
    vertexes.append(file.readline().split())        
    vertexes[currentVertex].remove(vertexes[currentVertex][0])                
    vertexIndex = 0
    for vertex in vertexes[currentVertex]:
        vertexes[currentVertex][vertexIndex] = int(vertex) - 1
        vertexIndex = vertexIndex + 1
    
pathEnds = file.readline().split()
file.close()
startVertex = int(pathEnds[0]) - 1
finishVertex = int(pathEnds[1]) - 1

file = open(sys.argv[1] + '.out', 'r')
rightAnswer = int(file.readline())
file.close()
    
file = open('output.txt', 'r')
if file == 0:
    print 'No output file\n'
else:
    path = file.readline().split()
    if len(path) == 1 and path[0] == '-1':
        if rightAnswer == -1:
            print 'OK\n'
        else:
            print 'Wrong answer\n'
    else:
        previousElement = -1
        currentElement = -1
        for pathElement in path:
            previousElement = currentElement
            currentElement = int(pathElement) - 1
            if previousElement != -1:
                if not currentElement in vertexes[previousElement]:
                    print 'Wrong answer\n'
                    sys.exit()
        if int(path[0]) != startVertex + 1:
            print 'Wrong answer\n'
            sys.exit()
        elif int(path[-1]) != finishVertex + 1:
            print 'Wrong answer\n'
            sys.exit()
        else:
            print 'OK\n'
        
    