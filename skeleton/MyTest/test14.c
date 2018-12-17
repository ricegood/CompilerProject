/* test from ppt page 6 + question */

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
	int i;

	a = 4;
	b[1] = 6;
	c.x = 3;
	c.y = 127;
	g = 6;
	write_int(foo(&g)); /* 146 */
	write_string("\n");

	for (i=270;i<272;) {
		write_int(i++); /* 270 271 */
		write_string("\n");
	}
	write_string("===============\n");
	for (;i<=275;) {
		write_int(i++); /* 272 273 274 275 */
		write_string("\n");
	}

	for (;;) {
		write_string("this is ?\n");
		break;
	}
}