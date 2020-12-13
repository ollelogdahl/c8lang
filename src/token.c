#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

token_t *init_token(tokentype type, char *str) {
    token_t *tok = (token_t*)malloc(sizeof(token_t));
    tok->type = type;

    // Allocates the new string 
    char* mem = (char*)malloc(strlen(str));
    strcpy(mem,str);
    tok->value = mem;

    return tok;
}

token_t *init_token_sub(tokentype type, char *str) {
    token_t *tok = (token_t*)malloc(sizeof(token_t));


}

static char *tokentype_to_str(tokentype type) {
    switch (type) {
    case END: return "END";
    case KEYWORD: return "KEYWORD";
    case IDENTIFIER: return "IDENT";
    case LITERAL: return "LITERAL";
    case LPAREN: return "(";
    case RPAREN: return ")";
    case LBRACKET: return "[";
    case RBRACKET: return "]";
    case LBRACE: return "{";
    case RBRACE: return "}";
    case COMMA: return ",";
    case SCOLON: return ";";
    case PLUS: return "+";
    case MINUS: return "-";
    case MUL: return "*";
    case DIV: return "/";
    case ASSIGN: return "=";
    case INC: return "++";
    case DEC: return "--";
    case NOT: return "!";
    case AND: return "&";
    case OR: return "|";
    case EQ: return "==";
    case NEQ: return "!=";
    }

    return "INVALID";
}

char *token_to_str(token_t *token) {
    char *typestr = tokentype_to_str(token->type);
    char *templ = "<token type='%s' value='%s'>";

    char *str = calloc(strlen(typestr) + strlen(templ), sizeof(char));
    sprintf(str, templ, typestr, token->value);
    return str;
}