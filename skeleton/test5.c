int main(){
	int *a;
	int b; 
	char *c;
	char d;
	struct a{} e;
	struct a *f;

	/* not comparable */
	a == b; 
	a == c;
	a == d;
	b >= d;
	d <= *a;
	a == f;

	
	/* not int or char or pointer type */
	a == e;
	e == *f;
	e == f;

	/* not int or char type */
	a >= b;
	a >= c;
	a >= d;
	a >= e;
	a >= f;
	e < *f;

	/* OK */
	b == *a;
	d >= *c;
}