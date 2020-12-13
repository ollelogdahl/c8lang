#ifndef C8LANG_TOKEN_H
#define C8LANG_TOKEN_H

typedef enum {
    END,
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

// Initializes a token given a nullterminated string.
token_t *init_token(tokentype type, char *str);
// Initializes a token given a long string. Starts at str, and ends after 
// 'len' characters.
token_t *init_token_sub(tokentype type, char *str, int len);

static char *tokentype_to_str(tokentype type);
char *token_to_str(token_t *token);

#endif