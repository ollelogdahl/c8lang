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
    //char *top, *cur, *mrk, *ctx, *pos;
    const char *top, *cur, *ptr, *pos;
    unsigned linepos;
    unsigned charpos;
} lexer_t;

// Initializes a new lexer, to lex the string source.
lexer_t *init_lexer(const char *source);
// returns the first token found by the lexer and increments it.
token_t *lexer_scan(lexer_t *lexer);

#endif