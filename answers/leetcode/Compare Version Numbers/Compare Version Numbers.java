class Solution {
    public int compareVersion(String version1, String version2) {
        String[] split1 = version1.split("\\.");
        String[] split2 = version2.split("\\.");
        for (int i = 0; i < split1.length || i < split2.length; i++) {
            int num1 = i < split1.length ? Integer.parseInt(split1[i]) : 0;
            int num2 = i < split2.length ? Integer.parseInt(split2[i]) : 0;
            if (num1 != num2) {
                return num1 > num2 ? 1 : -1;
            }
        }
        return 0;
    }
}