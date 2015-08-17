int main() {
	int n = 5;
	Tower towers[n];
	for (int i = n - 1; i >= 0; -- i) {
		towers[0].add(i);
	}
	towers[0].moveDisks(n, towers[2], towers[1]);
}
class Tower {
public:
	Tower(int i) {
		index = i;
	}
	int index() {
		return index;
	}
	void add(int d) {
		if (! disks.empty() && disks.peek() <= d) {
			return;
		}
		else {
			disks.push(d);
		}
	}
	void moveTopTo(Tower t) {
		int top = disks.pop();
		t.add(top);
	}
private:
	stack<int> disks;
	int index;
};