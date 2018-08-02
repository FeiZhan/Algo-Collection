class Solution {
    public String largestNumber(int[] nums) {
        String number = Arrays.stream(nums)
            .mapToObj(Integer::toString)
            .sorted((s1, s2) -> (s2 + s1).compareTo(s1 + s2))
            .collect(Collectors.joining(""));
        int i = 0;
        for (; i + 1 < number.length() && number.charAt(i) == '0'; i++) {}
        return number.substring(i);
    }
}