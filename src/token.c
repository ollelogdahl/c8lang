#include "token.h"
#include <string.h>

char *token_type_to_str(tokentype type) {
    switch (type) {
    case EOF: return "EOF";
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

    return "invalid token.";
}

char *token_to_str(token_t *token) {
    char *typestr = token_type_to_str(token->type);
    char *templ = "<token type='%s' value='%s'>";

    char *str = calloc(strlen(typestr) + strlen(templ), sizeof(char));
    sprintf(str, templ, typestr, token->value);
    return str;
}