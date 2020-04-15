class ProductOfNumbers {

    private long allProduct = 1l;
    private List<Long> products = new ArrayList<>();

    public ProductOfNumbers() {
        this.products.add(1l);
    }

    public void add(int num) {
        if (num == 0) {
            this.allProduct = 1l;
            this.products.clear();
        } else {
            this.allProduct *= num;
        }
        this.products.add(this.allProduct);
    }

    public int getProduct(int k) {
        int beforeIndex = this.products.size() - k - 1;
        if (beforeIndex < 0) {
            return 0;
        }
        long before = this.products.get(beforeIndex);
        //System.out.println(k + ": " + this.allProduct + " " + before);
        if (before == 0) {
            return 0;
        }
        return (int) (this.allProduct / before);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */