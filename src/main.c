
#include "token.h"
#include "lexer.h"
#include <stdio.h>

int main(int argc, char **argv) {
    char *str = "int { 0x31 31 ==";
    printf("%s\n", str);
    lexer_t *lex = init_lexer(str);

    token_t *token = NULL;
    while((token = lexer_scan(lex))->type != END) {
        printf("parsed token %s\n", token_to_str(token));
    }

    return 0;
}