/* while, for loop test */

void main() {
	int a;
	a = 10;
	while (a-- > 0) {
		/* print 9 to 0 */
		write_string("a : ");
		write_int(a);
		write_string("\n");
	}
	write_string("====================\n");
	/* print 0 to 9 */
	for (a = 0; a < 10; a++) {
		write_string("a : ");
		write_int(a);
		write_string("\n");
	}
}