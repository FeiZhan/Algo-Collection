#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0.01s Test Case #3: 0.01s Test Case #4: 0.01s Test Case #5: 0.01s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

name_num = int(raw_input())
score_map = dict()
for i in range(name_num):
    name = raw_input()
    score = float(raw_input())
    if score not in score_map:
        score_map[score] = list()
    score_map[score].append(name)
for v in sorted(score_map[sorted(score_map)[1]]):
    print v
