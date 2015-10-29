class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
		if (0 == str.length()) {
			return;
		}
		size_t length(str.length());
		offset %= str.length();
		str += str;
		str = str.substr(length - offset, length);
    }
};

