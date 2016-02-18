#@result Submitted a few seconds ago • Score: 50.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0.09s Test Case #4: 0.16s Test Case #5: 0.11s Test Case #6: 0.14s Test Case #7: 0.01s

# Enter your code here. Read input from STDIN. Print output to STDOUT

raw_input()
array = [int(v) for v in raw_input().split()]
A = set(int(v) for v in raw_input().split())
B = set(int(v) for v in raw_input().split())
happiness = 0
for v in array:
	happiness += (v in A) - (v in B)
print happiness
