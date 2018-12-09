struct s {int x; int y[2]; int z;} s0;

struct s *foo2(int a) {
	s0.x = a+13;
	s0.y[0] = 7;
	s0.y[1] = a;
	s0.z = a-2;
	return &s0;
}


void main() {
	
	struct s s1;
	struct s *s2;

/*	s1 = *foo2(5); */
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

	write_int(foo2(5)->x); /* 18 */
	write_string("\n");
	write_int(foo2(5)->y[0]); /* 7 */
	write_string("\n");
	write_int(foo2(5)->y[1]); /* 5 */
	write_string("\n");
	write_int(foo2(5)->z); /* 3 */
	write_string("\n=====================\n");

	write_int((*foo2(5)).x); /* 18 */
	write_string("\n");
	write_int((*foo2(5)).y[0]); /* 7 */
	write_string("\n");
	write_int((*foo2(5)).y[1]); /* 5 */
	write_string("\n");
	write_int((*foo2(5)).z); /* 3 */
	write_string("\n=====================\n");

	write_int(s0.x); /* 18 */
	write_string("\n");
	write_int(s0.y[0]); /* 7 */
	write_string("\n");
	write_int(s0.y[1]); /* 5 */
	write_string("\n");
	write_int(s0.z); /* 3 */
	write_string("\n=====================\n");

}