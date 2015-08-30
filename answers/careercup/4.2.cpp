enum State
{
	Unvisited,
	Visited,
	Visiting;
};
bool search(const Graph &g, const Node &start, const Node &end)
{
	std::list<Node> q;
	for (Node::iterator it = g.begin(); it != g.end(); ++ it)
	{
		it->state = Unvisited;
	}
	start.state = Visiting;
	q.push_back(start);
	while (! q.empty())
	{
		Node u = q.pop_front();
		if (NULL != u)
		{
			for (Node::iterator v = u.getAdjacent(); v != end(); ++ v)
			{
				if (Unvisited == v.state)
				{
					if (end == v)
					{
						return true;
					} else
					{
						v.state = Visiting;
						q.add(v);
					}
				}
			}
			u.state = Visited;
		}
	}
	return false;
}
