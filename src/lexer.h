#ifndef C8LANG_LEXER_H
#define C8LANG_LEXER_H

#include "token.h"

typedef struct {
    const char *src;    // the string to parse.
    char *start;        // start of line.
    char *marker;       // start of the token.
    char *c;            // current char.
    char *lim;          // limit.
    char *ctx;          // internal use (RE2C).
} lexer_t;

lexer_t *lexer_init(const char *source);
token_t *scan(lexer_t *lexer);

#endif