class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> justified = new LinkedList<>();
        int left = 0;
        int count = 0;
        for (int i = 0; i < words.length; i++) {
            if (count + words[i].length() + i - left > maxWidth) {
                StringBuilder sb = new StringBuilder();
                if (left + 1 == i) {
                    sb.append(words[left]);
                    for (int j = count; j < maxWidth; j++) {
                        sb.append(" ");
                    }
                } else {
                    int space = (maxWidth - count) / (i - left - 1);
                    int mod = (maxWidth - count) % (i - left - 1);
                    for (int j = left; j + 1 < i; j++) {
                        sb.append(words[j]);
                        for (int k = 0; k < space; k++) {
                            sb.append(" ");
                        }
                        if (j - left < mod) {
                            sb.append(" ");
                        }
                    }
                    sb.append(words[i - 1]);
                }
                justified.add(sb.toString());
                count = 0;
                left = i;
            }
            count += words[i].length();
        }
        if (left < words.length) {
            StringBuilder sb = new StringBuilder();
            for (int i = left; i < words.length; i++) {
                sb.append(words[i]);
                if (sb.length() < maxWidth) {
                    sb.append(" ");
                }
            }
            for (int i = sb.length(); i < maxWidth; i++) {
                sb.append(" ");
            }
            justified.add(sb.toString());
        }
        return justified;
    }
}