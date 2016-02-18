#@result Submitted a few seconds ago • Score: 20.00 Status: Accepted Test Case #0: 0.01s Test Case #1: 0s Test Case #2: 0.01s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

input = raw_input().split(' ')
output = []
for word in input:
    if word:
        output.append(word[0].upper() + word[1 :].lower())
    else:
        output.append('')

print ' '.join(output)
