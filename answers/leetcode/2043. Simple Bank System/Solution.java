class Bank {

    private long[] balance = null;

    public Bank(long[] balance) {
        this.balance = balance;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (account1 <= 0 || account1 > this.balance.length || account2 <= 0 || account2 > this.balance.length || money < 0 || this.balance[account1 - 1] < money) {
            return false;
        }

        this.balance[account1 - 1] -= money;
        this.balance[account2 - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if (account <= 0 || account > this.balance.length || money < 0) {
            return false;
        }

        this.balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (account <= 0 || account > this.balance.length || money < 0 || this.balance[account - 1] < money) {
            return false;
        }

        this.balance[account - 1] -= money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */