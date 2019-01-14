class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        for (int asteroid : asteroids) {
            if (stack.isEmpty() || asteroid > 0) {
                stack.push(asteroid);
            } else {
                boolean alive = true;
                while (!stack.isEmpty() && stack.peek() > 0) {
                    int previous = stack.pop();
                    if (previous >= -asteroid) {
                        alive = false;
                        if (previous > -asteroid) {
                            stack.push(previous);
                        }
                        break;
                    }
                }
                if (alive) {
                    stack.push(asteroid);
                }
            }
        }
        int index = 0;
        int[] result = new int[stack.size()];
        Iterator<Integer> iterator = stack.iterator();

        while (iterator.hasNext() && index < stack.size()){
            result[index] = iterator.next();
            index++;
        }
        return result;
    }
}