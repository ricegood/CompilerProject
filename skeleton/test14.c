/* test from ppt page 6 */

int a;
int b[20];
struct temp {int x; int y;};
struct temp c;

int foo(int *d) {
	int f;
	f = a + b[1] + c.x + c.y + *d;
	return f;
}

void main() {
	int g;
	a = 4;
	b[1] = 6;
	c.x = 3;
	c.y = 127;
	g = 6;
	write_int(foo(&g)); /* 146 */
	write_string("\n");
}