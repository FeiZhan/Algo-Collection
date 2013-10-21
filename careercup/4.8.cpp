void findSum(TreeNode *head, int sum, std::vector<int> buffer, int level)
{
	if (NULL == head)
	{
		return;
	}
	int tmp = sum;
	buffer.push_back(head->data);
	for (int i = level; i >= 0; -- i)
	{
		tmp -= buffer[i];
		if (0 == tmp)
		{
			std::cout << output(buffer) << " " << i << " " << level << std::endl;
		}
	}
	std::vector<int> c1(buffer), c2(buffer);
	findSum(head->left, sum, c1, level + 1);
	findSum(head->right, sum, c2, level + 1);
}
