class Solution {
    public String simplifyPath(String path) {
        String simplified = null;
        if (path != null) {
            String[] splitted = path.split("/");
            for (int i = 0; i < splitted.length; i++) {
                if (splitted[i].equals(".")) {
                    splitted[i] = "";
                } else if (splitted[i].equals("..")) {
                    splitted[i] = "";
                    int j = i - 1;
                    while (j >= 0) {
                        if (!splitted[j].equals("")) {
                            splitted[j] = "";
                            break;
                        }
                        j--;
                    }
                }
            }
            StringBuilder sb = new StringBuilder();
            for (String s : splitted) {
                if (!s.equals("")) {
                    sb.append("/").append(s);
                }
            }
            simplified = sb.toString();
            if (simplified.length() == 0) {
                simplified = "/";
            }
        }
        return simplified;
    }
}