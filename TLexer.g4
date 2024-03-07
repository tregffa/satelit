lexer grammar TLexer;

PLUS : '+' ;
MULT : '*' ;
AND : 'and' ;
OR : 'or' ;
NOT : 'not' ;
EQ : '=' ;
COMMA : ',' ;
SEMI : ';' ;
COLON : ':' ;
LPAREN : '(' ;
RPAREN : ')' ;
LCURLY : '{' ;
RCURLY : '}' ;

FUNC : 'FUNCTION';
END_FUNC : 'END_FUNCTION';
BEGIN : 'BEGIN' ;
VOID : 'VOID';
INT : 'INT';

VAR_INPUT : 'VAR_INPUT';
END_VAR : 'END_VAR';

NUM : [0-9]+ ;
ID: [a-zA-Z_][a-zA-Z_0-9]* ;
WS: [ \t\n\r\f]+ -> skip ;

