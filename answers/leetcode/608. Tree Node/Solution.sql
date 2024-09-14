# Write your MySQL query statement below
SELECT DISTINCT Tree.id,
    IF(Tree.p_id IS NULL, 
        "Root",
        IF(ChildTree.id IS NULL, "Leaf", "Inner")) AS type
    FROM Tree
        LEFT JOIN Tree AS ChildTree
        ON Tree.id = ChildTree.p_id;