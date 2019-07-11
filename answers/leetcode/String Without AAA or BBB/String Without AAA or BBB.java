class Solution {
    public String strWithout3a3b(int A, int B) {
        int greater = Math.max(A, B);
        int smaller = Math.min(A, B);
        char a = A > B ? 'a' : 'b';
        char b = A <= B ? 'a' : 'b';
        StringBuilder sb = new StringBuilder();
        while (greater > 0) {
            sb.append(a);
            greater--;
            if (greater > 0) {
                sb.append(a);
                greater--;
            }
            if (smaller > 0) {
                sb.append(b);
                smaller--;
            }
        }
        for (int i = 3; i < A + B && smaller > 0; i += 3, smaller--) {
            sb.insert(i, b);
        }
        return sb.toString();
    }
}