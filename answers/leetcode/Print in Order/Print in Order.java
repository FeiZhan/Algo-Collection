class Foo {

    private AtomicInteger count = new AtomicInteger(0);

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        this.count.incrementAndGet();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (this.count.get() < 1) {
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        this.count.incrementAndGet();
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (this.count.get() < 2) {
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}