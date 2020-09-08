class Solution {

    private class Point {
        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return this.x * 100000 + this.y;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null || obj.getClass() != this.getClass()) {
                return false;
            }

            Point point = (Point) obj;
            return point.x == this.x && point.y == this.y;
        }

    }

    public boolean isPathCrossing(String path) {
        Set<Point> points = new HashSet<>();
        Point current = new Point(0, 0);
        points.add(current);
        for (char c : path.toCharArray()) {
            int x = 0;
            int y = 0;
            switch (c) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'W':
                    x--;
                    break;
                case 'E':
                    x++;
                    break;
            }
            Point next = new Point(current.x + x, current.y + y);
            if (points.contains(next)) {
                return true;
            }
            points.add(next);
            current = next;
        }
        return false;
    }
}