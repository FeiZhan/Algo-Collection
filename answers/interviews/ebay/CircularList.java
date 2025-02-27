import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        List<Integer> input = new ArrayList<>();
        input.add(0);
        sort(input);
        System.out.println(input);

        input = new ArrayList<>();
        input.add(1);
        input.add(0);
        input.add(2);
        sort(input);
        System.out.println(input);

        input = new ArrayList<>();
        input.add(6);
        input.add(8);
        input.add(2);
        input.add(5);
        input.add(1);
        input.add(4);
        input.add(0);
        input.add(7);
        input.add(3);
        sort(input);
        System.out.println(input);
    }

    public static void sort(List<Integer> input) {
        sort(input, 0, input.size() - 1);
    }

    private static void sort(List<Integer> input, int begin, int end) {
        if (begin >= end) {
            return;
        }

        int pivot = input.get(begin);
        int biggerIndex = end + 1;
        for (int i = begin + 1; i < biggerIndex; i++) {
            int number = input.get(i);
            if (number > pivot) {
                biggerIndex--;
                input.set(i, input.get(biggerIndex));
                input.set(biggerIndex, number);
                i--;
            }
        }
        input.set(begin, input.get(biggerIndex - 1));
        input.set(biggerIndex - 1, pivot);
        sort(input, begin, biggerIndex - 2);
        sort(input, biggerIndex, end);
    }

    public static Node getMiddle(Node root) {
        Node fast = root;
        Node slow = root;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}

public class CircularList {
    private boolean empty = true;
    private int head = 0;
    private int tail = 0;
    private int maxSize = 100;
    private List<Integer> list = new ArrayList<>();

    public void addHead(int value) {
        if (isFull()) {
            throw new Exception();
        }

        list.set(head, value);
        head = (head - 1) % maxSize;
        empty = false;
    }

    public void removeHead() {
        if (empty) {
            throw new Exception();
        }

        head = (head + 1) % maxSize;
        empty = head == tail;
    }

    public boolean isFull() {
        return !empty && (head - 1) % maxSize == tail;
    }

    public int get(int index) {
        if ((tail - head) % maxSize < index) {
            throw new Exception();
        }

        return list.get((head + index) % maxSize);
    }
}
