import sys
input = sys.stdin.readline

n = int(input())
numbers = list(map(int,input().split()))
numbers.sort()

if n %2 == 0:
    center = n//2 -1
else:
    center = n//2

print(numbers[center])
