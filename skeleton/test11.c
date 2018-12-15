/* a=b=1 */
void main(){
	int a;
	int b;
	int c;
	int d;

	a=b=111;

	c=777;
	d=777;


	write_int(a); /* 111 */
	write_string("\n");
	write_int(b); /* 111 */
	write_string("\n");

	write_int(c); /* 777 */
	write_string("\n");
	write_int(d); /* 777 */
	write_string("\n");
}