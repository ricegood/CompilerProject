/*struct s {int x; int y[2]; int z;};*/
int c;
int *foo(int a) {
	c = a+10;
	return &c;
}
/*
struct s *foo2(int a) {
	struct s s0;
	s0.x = a+13;
	s0.y[0] = 7;
	s0.y[1] = a;
	s0.z = a-2;
	return &s0;
}
*/

void main() {
	/*
	struct s s1;
	struct s *s2;
	*/
	int a;
	int *b;
	a = *foo(5);
	b = foo(5);

	write_int(*foo(5)); /* 15 */
	write_string("\n");

	write_int(a); /* 15 */
	write_string("\n");

	write_int(*b); /* 15 */
	write_string("\n");
	
	write_int(c); /* 15 */
	write_string("\n");
	/*

	write_int(s1.x); /* 0 */
	write_string("\n");
	write_int(s1.y[0]); /* 0 */
	write_string("\n");
	write_int(s1.y[1]); /* 0 */
	write_string("\n");
	write_int(s1.z); /* 0 */
	write_string("\n=====================\n");


	s1 = *foo2(5);
	s2 = foo2(5);

	write_int(s1.x); /* 18 */
	write_string("\n");
	write_int(s1.y[0]); /* 7 */
	write_string("\n");
	write_int(s1.y[1]); /* 5 */
	write_string("\n");
	write_int(s1.z); /* 3 */
	write_string("\n=====================\n");

	write_int(s2->x); /* 18 */
	write_string("\n");
	write_int(s2->y[0]); /* 7 */
	write_string("\n");
	write_int(s2->y[1]); /* 5 */
	write_string("\n");
	write_int(s2->z); /* 3 */
	write_string("\n=====================\n");
	*/
}