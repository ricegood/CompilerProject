int main(){
	int a;
	int b;
	char c;

	int x;

	a = 2;
	b = -1;
	c = 'a';

	if (a > b) {
		x = 1;
	} else {
		x = 2;
	}
	
	write_int(x);
	write_string("\n");
	write_int(x+1);
	write_string("\n");
	write_int(x++);
	write_string("\n");
	write_int(x+1);
	write_string("\n");
	write_int(x);
	write_string("\n");
	write_char(c++);
	write_string("\n");
	write_char(c);
	write_string("\n");
	
}