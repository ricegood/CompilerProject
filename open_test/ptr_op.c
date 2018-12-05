/* pointer operation */

int main(void) {
	int a[10];
	int *b;
	char c[20];
	char *d;

	a = b;		/* error => error:LHS is not a variable */
	a[0] = 0;
	c[5] = 'a';

	b = &a;		/* error => not variable */
	b = &a[10];
	b = &b;		/* error */
	b = &*(a+5);/* error */
	b = &(b++);	/* error */
	b = &*(b++); /* error [original comment is wrong] */

	d = b;		/* error */
	d = c;		/* recognized it error => ERROR is right. ppt 23page. (int*) != (int array)  */

	c[1] = a[2]; /* error */
	d = &(++d); /* error */
	d = &*(++d); /* error [original comment is wrong] */

	if (b < d) { /* [Q] error => not int or char type */
		return -1;
	}

	return 0;
}

