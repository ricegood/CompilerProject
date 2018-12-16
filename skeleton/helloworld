	shift_sp 1
	push_const EXIT
	push_reg fp
	push_reg sp
	pop_reg fp
	jump main
EXIT:
	exit
main:
	shift_sp 0
main_start:
str_1. string "hello world\n"
	push_const str_1
	write_string
main_final:
	push_reg fp
	pop_reg sp
	pop_reg fp
	pop_reg pc
main_end:
	Lglob. data 0
