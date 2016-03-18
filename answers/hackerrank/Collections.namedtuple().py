#@result Submitted a few seconds ago • Score: 20.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0.01s Test Case #5: 0s

# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import namedtuple
stu_num = int(raw_input())
Student = namedtuple('Student', raw_input())
sum = 0.0
for i in range(stu_num):
    stu = Student(*(raw_input().split()))
    sum += int(stu.MARKS)
print sum / stu_num