class Solution {
    public String simplifyPath(String path) {
        String[] folders = path.split("/");
        Stack<String> stack = new Stack();

        for (String folder : folders) {
            switch (folder) {
                case "":
                case ".":
                    break;
                case "..":
                    if (!stack.empty()) {
                        stack.pop();
                    }
                    break;
                default:
                    stack.push(folder);
                    break;
            }
        }

        return "/" + String.join("/", new LinkedList<>(stack));
    }
}
//Runtime: 6 ms, faster than 49.58% of Java online submissions for Simplify Path.
//Memory Usage: 38.9 MB, less than 94.06% of Java online submissions for Simplify Path.
