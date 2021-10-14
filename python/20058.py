import sys
sys.stdin = open("input.txt",'r')

N, Q = map(int, (input().split()))

board = [[int(x) for x in input().split()] for _ in range(2**N)]

l = [int(x) for x in input().split()]

print(board)

print(l)