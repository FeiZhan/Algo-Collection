#include <cstdio>

// select avg(c1*c1) from tab where c2='sunday'

int c1[16] = {-3,2,0,7,4,3,2,1,100,16,1,0,-13,6,2,3};
char* c2[16] = {"a","b","sunday","sunday","sunday","sunday","sunday","sunday","b","sunday",
                "ahgijfdo","","sunday","","abc","monday"};

int main( int argn, char** argv )
{
  // compute result of SQL query
  // select avg(c1*c1) from tab where c2='sunday'

	double sum = 0;
	int count = 0;
	for (int i = 0; i < 16; ++ i) {
		if (0 == strcmp(c2[i], “sunday”)) {
			sum += c1[i] * c1[i];
			++ count;
}
}
printf(“%d.%d”,sum / count, sum%count);

return 0;
}





















//***********************************************************************

#include <cstdio>

class Stack
{
public:

  // TODO: complete class Stack, so it works
  // with main() function below
  // without including extra headers.

	Stack() : tail(0) {
		for (int i = 0; i < 128; ++ i) {
		       data_[i] = 0;
}
}

int size() {
	return tail;
}
bool empty() {
	return 0 == tail;
}
void push(int data) {
	if (tail < 128) {
		data_[tail ++] = data;
}
else {
	throw(“stack overflow!!”);
}
}
int pop() {
	if (tail > 0) {
                        --tail;
		return data_[tail];
}
else {
		throw(“stack is empty!!”);
}
}
protected:
  int data_[128];
	int tail;
};


int main( int argn, char** argv )
{
  Stack s;

  s.push(23);
  s.push(24);
  printf("first pop: %d\n",s.pop());
  printf("second pop: %d\n",s.pop());

  s.push(17);
  s.push(-2);
  s.pop();
  s.push(12);
  printf("size: %d\n",s.size());
  printf("another pop: %d\n",s.pop());

  // printf("maximum element: %d",s.maximum_element());

  printf("Now, stack is%s empty.\n", s.empty() ? "" : " not" );

  return 0;
}



