#include "lexer.h"

#include <stdlib.h>
#include <stdio.h>

#define YYCTYPE char
#define YYCURSOR lexer->cur
#define YYMARKER lexer->ptr
#define TOK(type) init_token_sub(type, lexer->top, lexer->cur-lexer->top)
#define TOKO(type, off) init_token_sub(type, lexer->top+off, lexer->cur - (lexer->top + off))
#define LXINC lexer->charpos += lexer->cur-lexer->top

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

    'if'            {LXINC; return TOK(IF); }
    'else'          {LXINC; return TOK(ELSE); }
    'while'         {LXINC; return TOK(WHILE); }
    'for'           {LXINC; return TOK(FOR); }
    'return'        {LXINC; return TOK(RETURN); }

    let (let|dig)*  {LXINC; return TOK(IDENTIFIER); }

    [1-9][0-9]*     {LXINC; return TOK(DECLITERAL); }
    '0x'hex+        {LXINC; return TOKO(HEXLITERAL, 2); }
    '0'[0-7]+       {LXINC; return TOKO(OCTLITERAL, 1); }
    '0b'[0-1]+      {LXINC; return TOKO(BINLITERAL, 2); }

    "("             {LXINC; return TOK(LPAREN); }
    ")"             {LXINC; return TOK(RPAREN); }
    "["             {LXINC; return TOK(LBRACKET); }
    "]"             {LXINC; return TOK(RBRACKET); }
    "{"             {LXINC; return TOK(LBRACE); }
    "}"             {LXINC; return TOK(RBRACE); }
    ","             {LXINC; return TOK(COMMA); }
    ";"             {LXINC; return TOK(SCOLON); }
    
    "+"             {LXINC; return TOK(PLUS); }
    "-"             {LXINC; return TOK(MINUS); }
    "*"             {LXINC; return TOK(MUL); }
    "/"             {LXINC; return TOK(DIV); }
    "="            {LXINC; return TOK(ASSIGN); }
    "++"            {LXINC; return TOK(INC); }
    "--"            {LXINC; return TOK(DEC); }

    "!"            {LXINC; return TOK(NOT); }
    "|"            {LXINC; return TOK(OR); }
    "&"            {LXINC; return TOK(AND); }
    "=="            {LXINC; return TOK(EQ); }
    "!="            {LXINC; return TOK(NEQ); }

    whitespace      {LXINC; goto regular; }

    "\r\n"|"\n" {
        lexer->linepos++;
        lexer->charpos = 0;
        goto regular; 
    }

    [\000-\377] {
        printf("Unrecognized symbol '%c' at %d:%d\n", yych, lexer->linepos, lexer->charpos);
        exit(EXIT_FAILURE);
    }
    */
}