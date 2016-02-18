#@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

num = int(raw_input())
countries = set()
for i in range(num):
    countries.add(raw_input())
print len(countries)
