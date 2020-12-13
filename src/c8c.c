#include "c8c.h"

#include <stdio.h>
#include <stdlib.h>

#include "token.h"
#include "lexer.h"

void c8c_compile(const char *filename) {

    // Create a stream from a file.
    FILE *stream = fopen(filename, "r");
    if(stream == 0) {
        printf("Cannot open stream for file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Reads file line by line and create tokens.
    char *line = 0;
    size_t len = 0;
    while(getline(&line, &len, stream) != -1) {
        // Construct a lexer for the given line
        lexer_t *lex = init_lexer(line);

        printf("%s", line);

        // Parse all tokens in the given line.
        token_t *token = 0;
        while((token = lexer_scan(lex))->type != END) {
            printf("parsed token %s\n", token_to_str(token));
            free(token);
        }
        free(lex);
    }

    /*
    lexer_t *lex = init_lexer(str);

    token_t *token = 0;
    while((token = lexer_scan(lex))->type != END) {
        printf("parsed token %s\n", token_to_str(token));
        free(token);
    }
    */
}