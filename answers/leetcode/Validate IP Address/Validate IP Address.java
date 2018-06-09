class Solution {
    public String validIPAddress(String IP) {
        String[] ipv4 = IP.split("\\.", -1);
        if (ipv4.length == 4) {
            boolean isIpv4 = true;
            for (String s : ipv4) {
                try {
                    int num = Integer.parseInt(s);
                    if (num < 0 || num > 255 || s.length() == 0 || (s.length() > 1 && s.charAt(0) == '0') || s.charAt(0) == '-') {
                        isIpv4 = false;
                        break;
                    }
                } catch (Exception e) {
                    isIpv4 = false;
                    break;
                }
            }
            if (isIpv4) {
                return "IPv4";
            }
        }
        String[] ipv6 = IP.split(":", -1);
        if (ipv6.length == 8) {
            boolean isIpv6 = true;
            for (String s : ipv6) {
                if (s.length() > 4 || s.length() == 0 || s.charAt(0) == '-') {
                    isIpv6 = false;
                    break;
                }
                try {
                    int num = Integer.parseInt(s, 16);
                    /*if (s.length() > 1 && num == 0) {
                        isIpv6 = false;
                        break;
                    }*/
                } catch (Exception e) {
                    isIpv6 = false;
                    break;
                }
            }
            if (isIpv6) {
                return "IPv6";
            }
        }
        return "Neither";
    }
}