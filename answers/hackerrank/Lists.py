#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

cmd_num = int(raw_input())
num_list = list()
for i in range(cmd_num):
    input_list = raw_input().split()
    if "append" == input_list[0]:
        num_list.append(int(input_list[1]))
    elif "insert" == input_list[0]:
        num_list.insert(int(input_list[1]), int(input_list[2]))
    elif "remove" == input_list[0]:
        num_list.remove(int(input_list[1]))
    elif "pop" == input_list[0]:
        num_list.pop()
    elif "index" == input_list[0]:
        num_list.index(int(input_list[1]))
    elif "count" == input_list[0]:
        num_list.count(int(input_list[1]))
    elif "sort" == input_list[0]:
        num_list.sort()
    elif "reverse" == input_list[0]:
        num_list.reverse()
    elif "print" == input_list[0]:
        print num_list
