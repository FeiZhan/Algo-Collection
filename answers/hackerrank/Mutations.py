#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0.01s Test Case #1: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

text = list(raw_input())
index, character = raw_input().split()

text[int(index)] = character

print "".join(text)
