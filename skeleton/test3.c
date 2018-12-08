int main(){
	/* test pointer */
	int *a;
	int b;
	int bb;
	char *c;
	char d;
	char dd;


	b = 10;

	write_int(*a);	/* 0 */
	write_string("\n");

	write_int(b);	/* 10 */
	write_string("\n");

	write_int(bb);	/* 0 */
	write_string("\n====================\n");

	a = &b;

	write_int(*a);	/* 10 */
	write_string("\n");

	write_int(b);	/* 10 */
	write_string("\n");

	write_int(bb);	/* 0 */
	write_string("\n====================\n");

	bb = *a;
	write_int(*a);	/* 10 */
	write_string("\n");

	write_int(b);	/* 10 */
	write_string("\n");

	write_int(bb);	/* 10 */
	write_string("\n====================\n");

	b = 5;

	write_int(*a);	/* 5 */
	write_string("\n");

	write_int(b);	/* 5 */
	write_string("\n");

	write_int(bb);	/* 10 */
	write_string("\n====================\n");


	d = 'a';

	write_char(*c);	/* 0 */
	write_string("\n");
	write_char(d);	/* a */
	write_string("\n");
	write_char(dd);	/* 0 */
	write_string("\n====================\n");

	c = &d;
	
	write_char(*c);	/* a */
	write_string("\n");
	write_char(d);	/* a */
	write_string("\n");
	write_char(dd);	/* 0 */
	write_string("\n====================\n");

	dd = *c;
	
	write_char(*c);	/* a */
	write_string("\n");
	write_char(d);	/* a */
	write_string("\n");
	write_char(dd);	/* a */
	write_string("\n====================\n");

	d = 'b';
	
	write_char(*c);	/* b */
	write_string("\n");
	write_char(d);	/* b */
	write_string("\n");
	write_char(dd);	/* a */
	write_string("\n");




}