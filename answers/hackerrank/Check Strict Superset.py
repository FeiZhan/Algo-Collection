#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0.01s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s

num_set = set(map(int, raw_input().split()))
N = int(raw_input())
flag = True
for i in range(N):
    new_set = set(map(int, raw_input().split()))
    if not (new_set.issubset(num_set) and len(num_set) > len(new_set)):
        flag = False
print flag
