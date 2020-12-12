#ifndef C8LANG_TOKEN_H
#define C8LANG_TOKEN_H

typedef enum {
    EOF,
    KEYWORD,
    IDENTIFIER,
    LITERAL,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    LBRACE,
    RBRACE,
    COMMA,
    SCOLON,

    PLUS,
    MINUS,
    MUL,
    DIV,
    ASSIGN,
    INC,
    DEC,

    NOT,
    OR,
    AND,
    EQ,
    NEQ 
} tokentype;

typedef struct {
    const char *value;
    tokentype type;
} token_t;

token_t *init_token(tokentype type, char *str);
static char *tokentype_to_str(tokentype type);
char *token_to_str(token_t *token);

#endif