#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0.02s Test Case #1: 0.98s Test Case #2: 1.44s Test Case #3: 0.29s Test Case #4: 0.82s Test Case #5: 1.48s Test Case #6: 0.25s Test Case #7: 0.47s Test Case #8: 0.27s Test Case #9: 0.01s

# Enter your code here. Read input from STDIN. Print output to STDOUT

num_num = int(raw_input())
nums = map(int, raw_input().split())
num_set = set(nums)
print (sum(num_set) * num_num - sum(nums)) / (num_num - 1)
