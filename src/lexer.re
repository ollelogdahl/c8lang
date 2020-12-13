#include "lexer.h"

#include <stdlib.h>
#include <stdio.h>

#define YYCTYPE char
#define YYCURSOR lexer->cur
#define YYMARKER lexer->ptr
#define TOK(type) init_token_sub(type, lexer->top, lexer->cur-lexer->top)
#define INC lexer->charpos += lexer->cur-lexer->top

lexer_t *init_lexer(const char *source) {
    lexer_t *lx = (lexer_t*)malloc(sizeof(lexer_t));
    lx->top = source;
    lx->cur = source;
    lx->ptr = source;
    lx->pos = source;
    lx->linepos = 0;
    lx->charpos = 0;

    return lx;
}

token_t *lexer_scan(lexer_t *lexer) {    
regular:
    if(*(lexer->cur) == '\0')
        return init_token(END, "");
    lexer->top = lexer->cur;

    /*!re2c
    re2c:yyfill:enable = 0;

    let = [a-zA-Z_];
    dig = [0-9];
    hex = [a-fA-F0-9];
    whitespace = [ \t\v\f]+;

    "("             {INC; return TOK(LPAREN); }
    ")"             {INC; return TOK(RPAREN); }
    "["             {INC; return TOK(LBRACKET); }
    "]"             {INC; return TOK(RBRACKET); }
    "{"             {INC; return TOK(LBRACE); }
    "}"             {INC; return TOK(RBRACE); }
    ";"             {INC; return TOK(SCOLON); }
    
    "=="            {INC; return TOK(ASSIGN); }

    [0-9]+          {INC; return TOK(DECLITERAL); }
    '0x'[0-9]+      {INC; return TOK(HEXLITERAL); }
    '0b'[0-9]+      {INC; return TOK(BINLITERAL); }
    '0'[0-9]+       {INC; return TOK(OCTLITERAL); }

    let (let|dig)*  {INC; return TOK(IDENTIFIER); }
    whitespace      {INC; goto regular; }

    "\r\n"|"\n" {
        lexer->linepos++;
        lexer->charpos = 0;
        goto regular; 
    }

    [\000-\377] {
        printf("Unrecognized symbol '%c' at line %d char %d\n", yych, lexer->linepos, lexer->charpos);
        exit(EXIT_FAILURE);
    }
    */
}