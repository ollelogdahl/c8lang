#include "cheat.h"
#include "cheats.h"
#include "token.h"
#include "lexer.h"

CHEAT_TEST(token_init_kw,
    token_t *tok = init_token(KEYWORD, "if");
    cheat_assert(tok->type == KEYWORD);
    cheat_assert_string(tok->value, "if");
)
CHEAT_TEST(token_init_id,
    token_t *tok = init_token(IDENTIFIER, "lorem");
    cheat_assert(tok->type == IDENTIFIER);
    cheat_assert_string(tok->value, "lorem");
)
CHEAT_TEST(token_init_empty,
    token_t *tok = init_token(END, "");
    cheat_assert(tok->type == END);
    cheat_assert_string(tok->value, "");
)

CHEAT_TEST(token_init_sub_all,
    token_t *tok = init_token_sub(KEYWORD, "function", 8);
    cheat_assert(tok->type == KEYWORD);
    cheat_assert_string(tok->value, "function");
)
CHEAT_TEST(token_init_sub,
    token_t *tok = init_token_sub(KEYWORD, "function", 4);
    cheat_assert(tok->type == KEYWORD);
    cheat_assert_string(tok->value, "func");
)
CHEAT_TEST(token_init_sub_empty,
    token_t *tok = init_token_sub(KEYWORD, "function", 0);
    cheat_assert(tok->type == KEYWORD);
    cheat_assert_string(tok->value, "");
)

CHEAT_TEST(token_to_str,
    token_t *tok = init_token(KEYWORD, "if");
    cheat_assert_string(token_to_str(tok), 
        "<token type='KEYWORD' value='if'>");
)
CHEAT_TEST(token_to_str_empty,
    token_t *tok = init_token(END, "");
    cheat_assert_string(token_to_str(tok), 
        "<token type='END' value=''>");
)

CHEAT_TEST(token_to_str_inv,
    token_t *tok = init_token((tokentype)999, "");
    cheat_assert_string(token_to_str(tok), 
        "<token type='INVALID' value=''>");
)

// TODO: Improve this test!
CHEAT_TEST(lexer_init,
    lexer_t *lex = init_lexer("test");
)

CHEAT_TEST(lexer_scan_test,
    lexer_t *lex = init_lexer("test ( == 0x32");
    token_t *tok = NULL;
    tok = lexer_scan(lex);
    cheat_assert(tok->type == IDENTIFIER);
    cheat_assert_string(tok->value, "test");
    tok = lexer_scan(lex);
    cheat_assert(tok->type == LPAREN);
    tok = lexer_scan(lex);
    cheat_assert(tok->type == ASSIGN);
    tok = lexer_scan(lex);
    cheat_assert(tok->type == LITERAL);
    cheat_assert_string(tok->value, "0x32");
)

CHEAT_TEST(lexer_scan_multiline,
    lexer_t *lex = init_lexer("[\n]alfa\n");
    token_t *tok = NULL;
    tok = lexer_scan(lex);
    cheat_assert(tok->type == LBRACKET);
    tok = lexer_scan(lex);
    cheat_assert(tok->type == RBRACKET);
    tok = lexer_scan(lex);
    cheat_assert(tok->type == IDENTIFIER);
    cheat_assert_string(tok->value, "alfa");
)