#include "token.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

token_t *init_token(tokentype type, const char *str) {
    token_t *tok = (token_t*)malloc(sizeof(token_t));
    tok->type = type;
    // Allocates the new string 
    char *mem = (char*)malloc(strlen(str));
    strcpy(mem, str);
    tok->value = mem;

    return tok;
}

token_t *init_token_sub(tokentype type, const char *str, int len) {
    token_t *tok = (token_t*)malloc(sizeof(token_t));
    tok->type = type;

    char *mem = (char*)calloc(len, sizeof(char));
    strncpy(mem, str, len);
    tok->value = mem;

    return tok;
}

static char *tokentype_to_str(tokentype type) {
    switch (type) {
    case END: return "END";

    case IF: return "IF KW";
    case ELSE: return "ELSE KW";
    case WHILE: return "WHILE KW";
    case FOR: return "FOR KW";
    case RETURN: return "RETURN KW";

    case IDENTIFIER: return "IDENTIFIER";
    case DECLITERAL: return "DECIMAL LITERAL";
    case HEXLITERAL: return "HEXIMAL LITERAL";
    case OCTLITERAL: return "OCTAL LITERAL";
    case BINLITERAL: return "BINARY LITERAL";

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