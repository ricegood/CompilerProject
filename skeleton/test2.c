int main() {
	a -= 10;
}

// before ASSIGNOP
a -= 1;
unary->ID
binary->unary
unary->INTEGER_CONST
binary->unary
binary->binary '-' binary
and_list->binary
and_expr->and_list
or_list->and_expr
or_expr->or_list
expr->or_expr
stmt->expr ';'
stmt_list->stmt_list stmt

// after ASSIGNOP
a -= 1;
unary->ID
binary->unary
and_list->binary
and_expr->and_list
or_list->and_expr
or_expr->or_list
expr->or_expr

unary->INTEGER_CONST
binary->unary
and_list->binary
and_expr->and_list
or_list->and_expr
or_expr->or_list
expr->or_expr

expr->expr ASSIGNOP expr
stmt->expr ';'
stmt_list->stmt_list stmt
