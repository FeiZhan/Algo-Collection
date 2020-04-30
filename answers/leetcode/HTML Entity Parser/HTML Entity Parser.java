class Solution {

    private static final Map<String, Character> ENTITIES = new HashMap<>();

    static {
        ENTITIES.put("quot", '"');
        ENTITIES.put("apos", '\'');
        ENTITIES.put("amp", '&');
        ENTITIES.put("gt", '>');
        ENTITIES.put("lt", '<');
        ENTITIES.put("frasl", '/');
    }

    public String entityParser(String text) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c == '&') {
                int end = text.indexOf(';', i);
                if (end >= 0) {
                    String sub = text.substring(i + 1, end);
                    if (ENTITIES.containsKey(sub)) {
                        sb.append(ENTITIES.get(sub));
                        i = end;
                        continue;
                    }
                }
            }
            sb.append(c);
        }
        return sb.toString();
    }
}