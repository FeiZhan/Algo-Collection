class BrowserHistory {

    private Stack<String> history = new Stack<>();
    private Stack<String> future = new Stack<>();
    private String current = null;

    public BrowserHistory(String homepage) {
        this.current = homepage;
    }

    public void visit(String url) {
        this.history.push(this.current);
        this.future.clear();
        this.current = url;
    }

    public String back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (this.history.isEmpty()) {
                break;
            }
            this.future.push(this.current);
            this.current = this.history.pop();
        }
        return this.current;
    }

    public String forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (this.future.isEmpty()) {
                break;
            }
            this.history.push(this.current);
            this.current = this.future.pop();
        }
        return this.current;
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */