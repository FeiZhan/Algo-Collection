#@result 26 / 26 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 97.92% of bash submissions.

# Read from the file file.txt and output all valid phone numbers to stdout.
cat file.txt | grep -Eo '^(\([0-9]{3}\) ){1}[0-9]{3}-[0-9]{4}$|^([0-9]{3}-){2}[0-9]{4}$'