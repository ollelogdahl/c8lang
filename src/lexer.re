#include "lexer.h"

#define YYCTYPE char
#define YYOFFSET cur-start

lexer_t *lexer_init(const char *source) {
    lexer_t *lx = (lexer_t*)malloc(sizeof(lexer_t));
    lx->top = source;
    lx->cur = source;
    lx->ptr = source;
    lx->pos = source;
    return lx;
}

token_t *lexer_scan(lexer_t *lexer) {
    
    /*!re2c

    '0x'?[0-9]+  {return init_token(LITERAL, )}

    * {
        printf("Unregognized symbol '%c'\n", yych);
        exit(EXIT_FAILURE);
    }
    */
}