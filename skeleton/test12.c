/* pointer operation ++ -- + - test */
struct s {int x; char y[3]; int z;};

void main(){
	int i;

	int *a;
	int b[5];

	struct s *aa;
	struct s bb[5];

	for (i = 0; i < 5; i++) {
		b[i] = i+10;
	}

	a = &(b[0]);

	i = 0;
	while(i < 5) {
		write_int(*(a+i)); /* 10 11 12 13 14 */
		write_string("\n");
		write_int(b[i]); /* 10 11 12 13 14 */
		write_string("\n");
		i++;
	}

	write_string("==================\n");

	a = &(b[4]);
	i = 0;
	while(i < 5) {
		write_int(*(a-i)); /* 14 13 12 11 10 */
		write_string("\n");
		write_int(b[4-i]); /* 10 11 12 13 14 */
		write_string("\n");
		i++;
	}

	write_string("==================\n");

	for (i = 0; i < 5; i++) {
		bb[i].x = i;
		bb[i].y[1] = 'k';
		bb[i].z = 10+i;
	}

	aa = &(bb[0]);

	i = 0;
	while(i < 5) {
		write_int((*aa).x);
		write_string("\n");
		write_char(aa->y[1]);
		write_string("\n");
		write_int(bb[i].z);
		write_string("\n");
		i++;
		aa++;
		write_string("-----\n");
	}

	write_string("==================\n");

	aa = &(bb[4]);
	i = 0;

	while(i < 5) {
		write_int((*aa).x);
		write_string("\n");
		write_char(aa->y[1]);
		write_string("\n");
		write_int(bb[4-i].z);
		write_string("\n");

		i++;
		aa--;

		write_string("-----\n");
	}

}