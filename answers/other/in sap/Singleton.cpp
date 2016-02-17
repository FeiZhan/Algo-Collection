class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution *instance = new Solution();
        return instance;
    }
private:
    Solution() {}
    Solution(const Solution&);
    Solution& operator=(const Solution&);
    virtual ~Solution() {}
};
