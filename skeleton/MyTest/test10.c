/* while, for loop test */
int i;
int b[10];

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
		} else {
			for(i = 0; i < a; i++) {
				if (i == 0) {
					continue;
				}
				write_string("\ti : ");
				write_int(i);
				write_string("\n");
				if (i == 5) {
					break;
				}
			}
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

	write_string("====================\n");
	for (i = 0; i < 10; i++) {
		b[i] = i;
	}

	for (i = 0; i < 10; i++) {
		write_string("b[i] : ");
		write_int(b[i]);
		write_string("\n");
		/*
		for (a = i; a < 10; a++) {
			write_string("\tb[a] : ");
			write_int(b[a]);
			write_string("\n");
		}
		*/
	}
}