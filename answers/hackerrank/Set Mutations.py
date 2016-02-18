#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0.01s Test Case #1: 0.01s Test Case #2: 0.01s Test Case #3: 0.01s Test Case #4: 0s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

raw_input()
nums = set(map(int, raw_input().split()))
oper_num = int(raw_input())
for i in range(oper_num):
    operation, num_num = raw_input().split()
    new_nums = set(map(int, raw_input().split()))
    getattr(nums, operation)(new_nums)
print sum(nums)
