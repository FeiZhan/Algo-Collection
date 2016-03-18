#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0.01s Test Case #1: 0.01s Test Case #2: 0s Test Case #3: 0.01s Test Case #4: 0s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

import collections

raw_input()
size_list = collections.Counter(map(int, raw_input().split()))
customer_num = int(raw_input())
all_money = 0
for i in range(customer_num):
    size, money = map(int, raw_input().split())
    if size_list[size] > 0:
        size_list[size] -= 1
        all_money += money
print all_money