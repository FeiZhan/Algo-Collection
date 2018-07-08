class Solution {
    public List<Integer> lexicalOrder(int n) {
        return IntStream.rangeClosed(1, n).boxed()
            .sorted((n1, n2) -> n1.toString().compareTo(n2.toString()))
            .collect(Collectors.toList());
    }
}