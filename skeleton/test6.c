int c;
int *foo(int a) {
	c = a+10;
	return &c;
}

int foo2() {
	return 1227;
}

void main() {
	int a;
	int *b;
	a = *foo(5);
	b = foo(5);

	write_int(foo2()); /* 1227 */
	write_string("\n");

	write_int(*foo(5)); /* 15 */
	write_string("\n");

	write_int(a); /* 15 */
	write_string("\n");

	write_int(*b); /* 15 */
	write_string("\n");
	
	write_int(*b + 5); /* 20 */
	write_string("\n");

	write_int(*b); /* 15 */
	write_string("\n");

	write_int(c); /* 15 */
	write_string("\n");
}