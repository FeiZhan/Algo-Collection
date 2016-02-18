#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

text = raw_input()
substr = raw_input()
count = len([i for i in range(0, len(text) - len(substr) + 1) if text[i : i + len(substr)] == substr])
print count
