class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> results = new HashSet<>();
        for (String email : emails) {
            String[] split = email.split("@");
            int plusIndex = split[0].indexOf("+");
            if (plusIndex >= 0) {
                split[0] = split[0].substring(0, plusIndex);
            }
            split[0] = split[0].replace(".", "");
            email = String.join("@", split);
            results.add(email);
        }
        return results.size();
    }
}