struct temp a; /* ERROR */
int a;

struct a {
	struct b {int a;} b;
	int a;
};

int main() {
	struct a temp;
	struct b temp2;
	int a;

	a = temp.a; /* OK */
	a = temp.a.b; /* error */
	a = temp.c; /* error */
	a = (temp.b).a; /* OK */
	a = temp.b; /* error */

	temp.b = temp2; /* OK */
}