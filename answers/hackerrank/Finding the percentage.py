#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

name_num = int(raw_input())
name_map = dict()
for i in range(name_num):
    input_list = raw_input().split()
    score_list = list()
    for j in range(1, len(input_list)):
        score_list.append(float(input_list[j]))
    name_map[input_list[0]] = score_list
name = raw_input()
average = 0
if name in name_map:
    for i in range(len(name_map[name])):
        average += name_map[name][i]
    average /= len(name_map[name])
print "%.2f" % average
