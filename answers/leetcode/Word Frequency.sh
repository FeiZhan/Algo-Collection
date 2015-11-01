#@result 14 / 14 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 30.53% of bash submissions.

# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2" "$1}'