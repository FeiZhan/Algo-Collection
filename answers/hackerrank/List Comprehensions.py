#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0.01s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

x = int(raw_input())
y = int(raw_input())
z = int(raw_input())
target = int(raw_input())
print [[i, j, k] \
    for i in range(x + 1) \
    for j in range(y + 1) \
    for k in range(z + 1) \
    if i + j + k != target]
