struct s {int x; int y[2]; int z;};

int foo(int a) {
	return a+1;
}

struct s foo2(int a) {
	struct s s0;
	s0.x = a+13;
	s0.y[0] = 7;
	s0.y[1] = a;
	s0.z = a-2;
	return s0;
}

void main() {
	struct s s1;

	write_int(s1.x); /* 0 */
	write_string("\n");
	write_int(s1.y[0]); /* 0 */
	write_string("\n");
	write_int(s1.y[1]); /* 0 */
	write_string("\n");
	write_int(s1.z); /* 0 */
	write_string("\n=====================\n");


	s1 = foo2(5);

	write_int(s1.x); /* 18 */
	write_string("\n");
	write_int(s1.y[0]); /* 7 */
	write_string("\n");
	write_int(s1.y[1]); /* 5 */
	write_string("\n");
	write_int(s1.z); /* 3 */
	write_string("\n=====================\n");
}