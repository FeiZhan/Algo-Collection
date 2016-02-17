#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0.01s Test Case #4: 0s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

from itertools import permutations
text, length = raw_input().split()
text = sorted(text)
length = int(length)
for v in permutations(text, length):
    print "".join(v)