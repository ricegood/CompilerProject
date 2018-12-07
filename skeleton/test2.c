int main(){
	int a;
	int b;

	int x;

	a = 2;
	b = -1;

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
	
}