'''
Created on 13.03.2011

@author: Sergei Zalivako
'''

if __name__ == '__main__':
    INFINITY = 1000000000000
    file = open('input.txt', 'r')
    i = int(file.readline())
    A = range(i)
    for row in range(i):
        A [row] = range(i)
    for row in range(i):
        A[row] = file.readline().split();
        for column in range(i):
            A[row][column] = int(A[row][column])
            if A[row][column] == 0 and row != column:
                A[row][column] = INFINITY
    file.close()
        
    file = open('output.txt', 'w')
    for row in range(i):
        for column in range(i):
            for k in range(i):
                if A[row][k] + A[k][column] < A[row][column]:
                    A[row][column] = A[row][k] + A[k][column]
    for row in range(i):
        for column in range(i):
            if A[row][column] < INFINITY/2:
                file.write(str(A[row][column]) + " ")
            else:
                file.write("0 ")
        file.write("\n")
    file.close()