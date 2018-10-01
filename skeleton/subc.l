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
operator		("("|")"|"["|"]"|"{"|"}"|"->"|"."|","|".."|"!"|"~"|"++"|"--"|"*"|"/"|"%"|"+"|"-"|"<<"|">>"|"<"|"<="|">"|">="|"=="|"!="|"&"|"^"|"|"|"&&"|"||"|"?"|":"|";"|"="|"+="|"-="|"*="|"/="|"%="|"&="|"^="|"|="|"<<="|">>=")
open-comment 	("/*")
close-comment 	("*/")
keyword 		("auto"|"break"|"case"|"char"|"continue"|"default"|"do"|"double"|"else"|"extern"|"float"|"for"|"goto"|"if"|"long"|"register"|"return"|"short"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"while")

%start AA BB

%%
<AA>{integer-constant}			{ printf("INT\t%s\n",yytext); }
<AA>{integer-constant}/("..")	{ printf("INT\t%s\n",yytext); }
<AA>{float-constant}			{ printf("F\t%s\n",yytext); }
<AA>{white-space}				{ }
<AA>{operator}					{ printf("OP\t%s\n",yytext); }
<AA>(_|{letter})+({alnum}*)		{ 
									char* trimmed_yytext = trim(yytext);
								  id* data = enter(UNDEFINED, trimmed_yytext, strlen(trimmed_yytext));
								  if (data->tokenType == KEYWORD)
								  	printf("KEY\t%s\t%d\n",data->name,data->count);
								  else if(data->tokenType == ID)
								  	printf("ID\t%s\t%d\n",data->name,data->count);
								}

<AA>{open-comment}				{ commentdepth++; BEGIN BB;}
<BB>{open-comment}				{ commentdepth++; }
<BB>{close-comment}				{ if (commentdepth > 1) {
									commentdepth--;
						 		  }
						 		  else if (commentdepth == 1) {
						  			commentdepth--;
						  			BEGIN AA;
						  		  }
								}

. 								{ }

%%

void initHash() 
{
	int i;

	char* keyWord[]={
		"auto","break","case","char","continue","default","do","double","else","extern","float","for","goto","if","int","long","register","return","short","sizeof","static","struct","switch","typedef","union","unsigned","void","while", "\0"
	};

	/* Initilize Hash Tabel with Keywords */
	for (i = 0; strcmp(keyWord[i], "\0") !=0; i++) {
		enter(KEYWORD, keyWord[i],strlen(keyWord[i]));
	}
}

char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }

    len = strlen(str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while( isspace((unsigned char) *frontp) ) { ++frontp; }
    if( endp != frontp )
    {
        while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
    }

    if( str + len - 1 != endp )
            *(endp + 1) = '\0';
    else if( frontp != str &&  endp == frontp )
            *str = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if( frontp != str )
    {
            while( *frontp ) { *endp++ = *frontp++; }
            *endp = '\0';
    }


    return str;
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
