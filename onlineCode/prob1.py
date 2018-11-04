import os, sys

T = int(input())
N,O,D = 0,0,0
x1,x2,A,B,C,M,L = 0,0,0,0,0,0,0
for i in range(T):
    list = input().split(" ")
    N=int( list[0])
    O=int (list[1])
    D=int (list[2])
    #print(N,O,D)
    list = input().split(" ")
    x1=int( list[0])
    x2=int (list[1])
    A=int (list[2])
    B=int( list[3])
    C=int( list[4])
    M=int( list[5])
    L=int(list[6])
    #print(x1,x2,A,B,C,M,L)

x=[]
s=[]
x.append(x1)
x.append(x2)
s.append( x1 + L)
s.append( x2 + L )
for i in range(N):
    if i in range(2):
        continue
    x.append(A*x[i-1] + B*x[i-2] + C)
    s.append( x[i] + L )


max_so_far = 0
max_ending_here = 0
    
for i in range(N):
    print(s[i])
    
