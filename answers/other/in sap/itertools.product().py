#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0.01s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0.01s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

import itertools
list0 = map(int, raw_input().split())
list1 = map(int, raw_input().split())
print " ".join(map(str, itertools.product(list0, list1)))