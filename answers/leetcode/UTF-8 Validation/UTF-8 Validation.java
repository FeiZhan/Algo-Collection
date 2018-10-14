class Solution {
    public boolean validUtf8(int[] data) {
        if (data == null || data.length == 0) {
            return false;
        }
        boolean valid = true;
        int count = 0;
        for (int c : data) {
            c = c & ((1 << 8) - 1);
            if (count == 0) {
                if ((c & (1 << 7)) != 0) {
                    for (int i = 6; i >= 4; i--) {
                        if ((c & (1 << i)) != 0) {
                            count++;
                        } else {
                            break;
                        }
                    }
                    if (count == 0 || (c & (1 << (6 - count))) != 0) {
                        valid = false;
                        break;
                    }
                }
            } else {
                if ((c & ((1 << 7) + (1 << 6))) == (1 << 7)) {
                    count--;
                } else {
                    valid = false;
                    break;
                }
            }
            //System.out.println(count);
        }
        return valid && count == 0;
    }
}