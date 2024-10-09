class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> domainMap = new HashMap<>();
        for (String cpDomain : cpdomains) {
            String[] split = cpDomain.split(" ");
            int count = Integer.parseInt(split[0]);
            domainMap.put(split[1], domainMap.getOrDefault(split[1], 0) + count);
            int index = 0;
            while (true) {
                index = split[1].indexOf('.', index + 1);
                if (index < 0 || index >= split[1].length()) {
                    break;
                }
                String subDomain = split[1].substring(index + 1);
                domainMap.put(subDomain, domainMap.getOrDefault(subDomain, 0) + count);
            }
        }

        List<String> result = new LinkedList<>();
        for (String domain : domainMap.keySet()) {
            int count = domainMap.get(domain);
            StringBuilder sb = new StringBuilder();
            sb.append(count).append(" ").append(domain);
            result.add(sb.toString());
        }

        return result;
    }
}