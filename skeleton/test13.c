struct s {
	int x;
	char y[2];
	int z;
};

struct s foo(int x, struct s *y, int *z) {
	y->x = x;
	*z = x;
	return *y; /* return structure pointer */
}

void main() {
	struct s a;
	struct s aa;
	int b;
	int c;
	int *d;

	a.x = 777;
	a.y[0] = 'z';
	a.y[1] = 'm';
	a.z = 123;

	b = 1227;
	c = 273;
	d = &b;

	write_int(a.x); // 777
	write_string("\n");
	write_char(a.y[0]); // 'z'
	write_string("\n");
	write_char(a.y[1]); // 'm'
	write_string("\n");
	write_int(a.z); // 123
	write_string("\n");
	write_int(c); // 273
	write_string("\n");

	write_string("=====================\n")

	aa = foo(*d, &a, &c);

	write_int(a.x); // 1227
	write_string("\n");
	write_char(a.y[0]); // 'z'
	write_string("\n");
	write_char(a.y[1]); // 'm'
	write_string("\n");
	write_int(a.z); // 123
	write_string("\n");
	write_int(c); // 1227
	write_string("\n");

	write_string("=====================\n")
	write_int(aa.x); // 1227
	write_string("\n");
	write_char(aa.y[0]); // 'z'
	write_string("\n");
	write_char(aa.y[1]); // 'm'
	write_string("\n");
	write_int(aa.z); // 123
	write_string("\n");
}