from pprint import pprint
import sys
from collections import deque
sys.stdin = open("input.txt", "r")

n, k = map(int, input().split())
arr = deque(list(map(int, input().split())))

ans = 1

robot = deque(list([0]*n))

while True:
    arr.rotate(1)
    robot.rotate(1)
    robot[-1] = 0
    for i in range(-2, -n-1, -1):
        if robot[i] == 1 and robot[i+1] == 0 and arr[i+1-n] > 0:
            robot[i] = 0
            robot[i+1] = 1
            arr[i+1-n] -= 1
    robot[-1] = 0
    if robot[0] == 0 and arr[0] > 0:
        robot[0] = 1
        arr[0] -= 1
    if arr.count(0) >= k:
        break
    ans += 1

print(ans)