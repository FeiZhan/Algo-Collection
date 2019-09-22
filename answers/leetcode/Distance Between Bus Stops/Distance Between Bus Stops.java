/*
 * @lc app=leetcode id=1184 lang=java
 *
 * [1184] Distance Between Bus Stops
 */
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int left = Math.min(start, destination);
        int right = Math.max(start, destination);
        int dist = 0;
        int sum = 0;
        for (int i = 0; i < distance.length; i++) {
            sum += distance[i];
            if (i >= left && i < right) {
                dist += distance[i];
            }
        }
        return Math.min(dist, sum - dist);
    }
}

