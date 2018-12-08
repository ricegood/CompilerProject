struct s {int x; int y;};

int foo(int a) {
	return a+1;
}

struct s foo2(int a) {
	struct s s1;
	s1.x = a+13;
	s1.y = 7;
	return s1;
}

void main() {
	struct s s1;
	s1 = foo2(5);
	write_int(s1.x);
	write_string("\n");
	write_int(s1.y);
	write_string("\n");
}