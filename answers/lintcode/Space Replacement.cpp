class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
		int true_len(length);
		for (int i = 0; i < length; ++ i) {
			if (' ' == string[i]) {
				true_len += 2;
			}
		}
		int true_pos = true_len - 1;
		for (int i = length - 1; i >= 0; -- i) {
			if (' ' == string[i]) {
				string[true_pos] = '0';
				string[true_pos - 1] = '2';
				string[true_pos - 2] = '%';
				true_pos -= 3;
			}
			else {
				string[true_pos] = string[i];
				-- true_pos;
			}
		}
		return true_len;
    }
};  
