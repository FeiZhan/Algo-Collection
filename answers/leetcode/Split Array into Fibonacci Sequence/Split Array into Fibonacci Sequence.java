class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        int first = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(0) == '0' && i > 0) {
                break;
            }
            first = first * 10 + Character.getNumericValue(S.charAt(i));
            int second = 0;
            for (int j = i + 1; j < S.length(); j++) {
                if (S.charAt(i + 1) == '0' && j > i + 1) {
                    break;
                }
                second = second * 10 + Character.getNumericValue(S.charAt(j));
                List<Integer> result = new LinkedList<>();
                result.add(first);
                result.add(second);
                boolean flag = true;
                int previous = first;
                int current = second;
                int nextStart = j + 1;
                while (flag) {
                    int next = previous + current;
                    result.add(next);
                    String nextStr = Integer.toString(next);
                    int nextEnd = nextStart + nextStr.length();
                    //System.out.println(previous + " + " + current + " = " + next + ", " + nextEnd);
                    if (nextEnd > S.length()
                        || !nextStr.equals(S.substring(nextStart, nextEnd))) {
                        flag = false;
                    } else if (nextEnd == S.length()) {
                        return result;
                    }
                    previous = current;
                    current = next;
                    nextStart = nextEnd;
                }
            }
        }
        return new LinkedList<>();
    }
}