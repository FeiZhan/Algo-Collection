class Solution {

    private static Set<String> TWOS = new HashSet<>();

    public Solution() {
        int number = 1;
        while (number >= 0) {
            String str = String.valueOf(number);
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            TWOS.add(new String(chars));
            number *= 2;
        }
    }

    public boolean reorderedPowerOf2(int N) {
        String str = String.valueOf(N);
        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        str = new String(chars);
        return TWOS.contains(str);
    }
}