#@result Submitted a few seconds ago • Score: 20.00 Status: Accepted Test Case #0: 0s Test Case #1: 0.01s Test Case #2: 0.02s Test Case #3: 0.02s Test Case #4: 0.02s Test Case #5: 0.02s Test Case #6: 0s Test Case #7: 0.01s Test Case #8: 0.01s Test Case #9: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import defaultdict
a_num, b_num = map(int, raw_input().split())
str_map = defaultdict(list)
for i in range(a_num):
    str_map[raw_input()].append(i + 1)
for i in range(b_num):
    query = raw_input()
    if query in str_map:
        print " ".join(map(str, str_map[query]))
    else:
        print -1