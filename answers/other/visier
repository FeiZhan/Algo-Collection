import java.io.IOException;
import java.io.Reader;
import java.lang.RuntimeException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

class SolutionIter implements Iterable<Integer> {

    private List<Integer> numbers;

    public SolutionIter(Reader inp) {
        if (inp == null) {
            throw new RuntimeException("Invalid input.");
        }
        this.numbers = new LinkedList<>();

        try {
            boolean ended = false;
            boolean haveError = false;
            boolean started = false;
            boolean startWithZero = false;
            int number = 0;
            int sign = 0;
            int digit;

            while ((digit = inp.read()) >= 0) {
                char c = (char) digit;
                if (haveError) {
                    // Do nothing
                } else if (c == ' ') {
                    if (started) {
                        ended = true;
                    }
                } else if (c == '\n') {
                    if (started) {
                        sign = sign >= 0 ? 1 : -1;
                        this.numbers.add(sign * number);
                    }
                } else if (c == '+' || c == '-') {
                    if (started || sign != 0) {
                        haveError = true;
                    } else {
                        sign = c == '+' ? 1 : -1;
                    }
                } else if (c >= '0' && c <= '9') {
                    if (ended) {
                        haveError = true;
                    }
                    if (c == '0' && number == 0) {
                        if (startWithZero) {
                            haveError = true;
                        } else {
                            startWithZero = true;
                        }
                    }
                    if (!haveError) {
                        started = true;
                        number = number * 10 + Character.getNumericValue(c);
                        if (number > 1000000000) {
                            haveError = true;
                        }
                    }
                } else {
                    haveError = true;
                }

                if (c == '\n') {
                    ended = false;
                    haveError = false;
                    started = false;
                    startWithZero = false;
                    number = 0;
                    sign = 0;
                }
            }
        } catch (IOException e) {
            throw new RuntimeException("Invalid input.", e);
        }
    }

    public Iterator<Integer> iterator() {
        return this.numbers.iterator();
    }
}

/**
 * Example usage:
 *
 * for (Integer x : new SolutionIter(reader)) {
 *     System.out.println(x);
 * }
 */

// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        if (A == null || A.length == 0) {
            throw new RuntimeException("Invalid input.");
        }

        Stack<Integer> right = new Stack<>();
        for (int i = A.length - 1; i >= 0; i--) {
            if (right.isEmpty() || A[i] >= right.peek()) {
                right.push(A[i]);
            }
        }
        int left = Integer.MIN_VALUE;
        int maxDiff = 0;
        for (int i = 0; i + 1 < A.length; i++) {
            left = Math.max(left, A[i]);
            if (A[i] == right.peek()) {
                right.pop();
            }
            int diff = Math.abs(left - right.peek());
            maxDiff = Math.max(maxDiff, diff);
        }
        return maxDiff;
    }
}