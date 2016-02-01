#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0.01s Test Case #1: 0.01s Test Case #2: 0.01s Test Case #3: 0.01s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0.01s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0.01s

# Enter your code here. Read input from STDIN. Print output to STDOUT

raw_input()
set0 = set(map(int, raw_input().strip().split()))
raw_input()
set1 = set(map(int, raw_input().strip().split()))
sym_diff = sorted(set0.union(set1).difference(set0.intersection(set1)))
for v in sym_diff:
    print v
