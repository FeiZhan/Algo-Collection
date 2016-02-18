#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0.01s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0.01s Test Case #5: 0s

for i in range(int(raw_input())): #More than 4 lines will result in 0 score. Blank lines won't be counted.
    a = int(raw_input()); A = set(raw_input().split())
    b = int(raw_input()); B = set(raw_input().split())
    print B == B.union(A)
