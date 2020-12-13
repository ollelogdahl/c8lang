#ifndef C8LANG_LEXER_H
#define C8LANG_LEXER_H

#include "token.h"

typedef struct {
/*
    const char *src;    // the string to parse.
    char *start;        // start of line.
    char *marker;       // start of the token.
    char *c;            // current char.
    char *lim;          // limit.
    char *ctx;          // internal use (RE2C).
*/
    char *top, *cur, *ptr, *pos;
} lexer_t;

// Initializes a new lexer, to lex the string source.
lexer_t *lexer_init(char *source);
// returns the first token found by the lexer and increments it.
token_t *scan(lexer_t *lexer);

#endif