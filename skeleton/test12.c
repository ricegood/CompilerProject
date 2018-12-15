/* pointer operation ++ -- + - test */
void main(){
	int i;
	int *a;
	int b[5];

	for (i = 0; i < 5; i++) {
		b[i] = i+10;
	}

	a = &(b[0]);

	i = 0;
	while(i < 5) {
		write_int(*(a+i)); /* 10 11 12 13 14 */
		write_string("\n");
		i++;
	}

	write_string("==================\n");

	a = &(b[4]);
	i = 0;
	while(i < 5) {
		write_int(*(a-i)); /* 14 13 12 11 10 */
		write_string("\n");
		i++;
	}
}