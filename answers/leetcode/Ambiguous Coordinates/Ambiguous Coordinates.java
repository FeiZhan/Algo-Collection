class Solution {
    public List<String> ambiguousCoordinates(String S) {
        List<String> results = new LinkedList<>();
        for (int i = 2; i + 1 < S.length(); i++) {
            List<String> left = this.build(S.substring(1, i));
            List<String> right = this.build(S.substring(i, S.length() - 1));
            for (String l : left) {
                for (String r : right) {
                    StringBuilder sb = new StringBuilder();
                    sb.append('(').append(l).append(", ").append(r).append(')');
                    results.add(sb.toString());
                }
            }
        }
        return results;
    }

    private List<String> build(String str) {
        List<String> results = new LinkedList<>();
        if (str.length() > 0) {
            if (str.charAt(0) == '0') {
                if (str.length() == 1) {
                    results.add(str);
                } else if (str.charAt(str.length() - 1) != '0') {
                    StringBuilder sb = new StringBuilder(str);
                    sb.insert(1, '.');
                    results.add(sb.toString());
                }
            } else if (str.charAt(str.length() - 1) == '0') {
                results.add(str);
            } else {
                results.add(str);
                for (int i = 1; i < str.length(); i++) {
                    StringBuilder sb = new StringBuilder(str);
                    sb.insert(i, '.');
                    results.add(sb.toString());
                }
            }
        }
        //System.out.println(str + " " + results.size());
        return results;
    }
}