#@result Submitted a few seconds ago • Score: 40.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0.01s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0.01s Test Case #9: 0s Test Case #10: 0s Test Case #11: 0s Test Case #12: 0.24s Test Case #13: 0.24s Test Case #14: 0.24s

# Enter your code here. Read input from STDIN. Print output to STDOUT

text = raw_input().strip()
Kevin = 0
Stuart = 0
for i, c in enumerate(text):
    if c in "aeiouAEIOU":
        Kevin += len(text) - i
    else:
        Stuart += len(text) - i
if Kevin == Stuart:
    print "Draw"
elif Kevin > Stuart:
    print "Kevin", Kevin
else:
    print "Stuart", Stuart
