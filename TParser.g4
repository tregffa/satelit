parser grammar TParser;
options { tokenVocab=TLexer; }

program
    : stat* EOF
    | func_def EOF
    ;

stat: ID EQ expr SEMI
    | expr SEMI
    ;

expr: ID
    | NUM
    | func
    | NOT expr
    | lEx=expr AND rEx=expr
    | lEx=expr OR rEx=expr
    | lEx=expr MULT rEx=expr
    | lEx=expr PLUS rEx=expr
    ;
 type: VOID
    | INT
    ;

func_var_in: VAR_INPUT (name=ID COLON type SEMI)* END_VAR;
func_def: FUNC name=ID COLON type func_var_in BEGIN body=stat* END_FUNC;
func : name=ID LPAREN expr (COMMA expr)* RPAREN;
