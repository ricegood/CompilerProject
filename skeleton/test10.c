/* while, for loop test */

void main() {
	int a;
	a = 10;
	while (a-- > 0) {
		/* 9 6 5 4 3 */
		if (a > 6 && a <= 8) {
			continue;
		}
		write_string("a : ");
		write_int(a);
		write_string("\n");
		if (a == 3) {
			break;
		}
	}
	write_string("====================\n");
	/* print 3 */
		write_string("a : ");
		write_int(a);
		write_string("\n");
	write_string("====================\n");
	/* print 0 to 7 except 4 */
	for (a = 0; a < 10; a++) {
		if (a == 4) {
			continue;
		}
		write_string("a : ");
		write_int(a);
		write_string("\n");

		if (a >= 7) {
			break;
		}
	}
	write_string("====================\n");
	/* print 7 */
	write_string("a : ");
	write_int(a);
	write_string("\n");
}