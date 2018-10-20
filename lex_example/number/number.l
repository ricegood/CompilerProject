letter			[A-Za-z_]
alnum			[A-Za-z0-9_]
digit			[0-9]

%%

[\n\t ] { ; }

1(0|1)*0|0 {printf("2's multiple\n");}
(a|b)*aa(a|b)* {printf("aa\n");}
(ab|b)*a?(ba|b)* {printf("not aa\n");}

. { printf("nonononono\n"); }

%%
main()
{
	yylex();
	// -?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) { printf("number\n"); }
}
