# Write your MySQL query statement below
SELECT machine_id, ROUND(AVG(processing_time), 3) AS processing_time
    FROM (
        SELECT machine_id, process_id, MAX(timestamp) - MIN(timestamp) AS processing_time
            FROM Activity
            GROUP BY machine_id, process_id
    ) AS processing_times
    GROUP BY machine_id;