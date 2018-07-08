class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> domains = new HashMap<>();
        for (String cpdomain : cpdomains) {
            String[] splits = cpdomain.split(" ");
            int count = Integer.parseInt(splits[0]);
            domains.put(splits[1], domains.getOrDefault(splits[1], 0) + count);
            for (int i = 0; i < splits[1].length(); i++) {
                if ('.' == splits[1].charAt(i)) {
                    String subdomain = splits[1].substring(i + 1);
                    domains.put(subdomain, domains.getOrDefault(subdomain, 0) + count);
                }
            }
        }
        List<String> visits = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : domains.entrySet()) {
            visits.add(entry.getValue() + " " + entry.getKey());
        }
        return visits;
    }
}