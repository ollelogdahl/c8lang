
#include "token.h"
#include <stdio.h>

int main(int argc, char **argv) {
    token_t *token = init_token(KEYWORD, "if");
    printf("%s\n", token_to_str(token));

    return 0;
}