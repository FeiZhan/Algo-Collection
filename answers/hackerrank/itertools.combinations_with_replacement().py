#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0.01s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

import itertools

text, num = raw_input().split()
text = sorted(text)
num = int(num)

combi = map("".join, list(itertools.combinations_with_replacement(text, num)))

for v in combi:
    print(v)