%{
/**************************************************************
* File Name   : subc.l
*
* Description
*	This is a skeleton input file to lex.
*
* Which tool to use
*	The GNU lex-clone, flex/flex++ is recommended to use.
*	It supports a C++ mode.
*	For any information about flex, refer to flex.man.
*
*	Good Luck!
*
***************************************************************/

/**************************************************************/
/* This section will appear at the head of lex.yy.c/lex.yy.cc */
/**************************************************************/

#include "subc.h"
/***************************************************************
{Other useful code segments can be here.}
***************************************************************/
int commentdepth=0;
%}

letter			[A-Za-z_]
alnum			[A-Za-z0-9_]
digit			[0-9]
white-space		[ \t\n]+
integer-constant(([1-9]+{digit}*)|0)
float-constant	{digit}+("."){digit}*([eE][("+")|("-")]?{digit}+)?
operator		("\("|"\)"|"\["|"\]"|"\{"|"\}"|"\->"|"\."|"\,"|"\.."|"\!"|"\~"|"\++"|"\--"|"\*"|"\/"|"\%"|"\+"|"\-"|"\<<"|"\>>"|"\<"|"\<="|"\>"\"\>="|"\=="|"\!="|"\&"|"\^"|"\|"|"\&&"|"\||"|"\?"|"\:"|"\;"|"\="|"\+="|"\-="|"\*="|"\/="|"\%="|"\&="|"\^="|"\|="\"\<<="|"\>>=")
open-comment 	("/*")
close-comment 	("*/")
keyword 		("auto"|"break"|"case"|"char"|"continue"|"default"|"do"|"double"|"else"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"while")

%start AA BB

%%
<AA>{integer-constant}			{ printf("INT\t%s\n",yytext); }
<AA>{integer-constant}/("..")	{ printf("INT\t%s\n",yytext); }
<AA>{float-constant}			{ printf("F\t%s\n",yytext); }
<AA>{white-space}				{ }
<AA>{operator}					{ printf("OP\t%s\n",yytext); }
<AA>{keyword}					{ printf("KEY\t%s\n",yytext); }
<AA>(_|{letter})+({alnum}*)		{ printf("ID\t%s\n",yytext); }

<AA>{open-comment}				{ printf("# INITIALLY OPEN COMMENT DEPTH = %d\n",++commentdepth); BEGIN BB;}
<BB>{open-comment}				{ printf("OPEN COMMENT DEPTH = %d\n",++commentdepth); }
<BB>{close-comment}				{ if (commentdepth > 1) {
									printf("CLOSE COMMENT DEPTH = %d\n",--commentdepth);
						 		  }
						 		  else if (commentdepth == 1) {
						  			printf("# FINALLY CLOSE COMMENT DEPTH = %d\n",--commentdepth);
						  			BEGIN AA;
						  		  }
								}

. 								{ }

%%

void initHash() 
{
	int i;

	char* keyWord[]={
		"int","return", "\0"
	};

	/* Initilize Hash Tabel with Keywords */
	for (i = 0; strcmp(keyWord[i], "\0") !=0; i++) {
		//enter(KEYWORD, keyWord[i],strlen(keyWord[i]));
	}
}

int main(int argc, char** argv)
{
	id* temp;

	++argv;
	--argc;

	if (argc > 0) {
		yyin = fopen(argv[0], "r");
	} else {
		yyin = stdin;
	}

	initHash();

	BEGIN AA;
	yylex ();

	return 0;
}
