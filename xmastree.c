#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "strrep.h"

enum color {Red, Green, Blue, Yellow};

char * tree =
"             ^^\n"
"            <  >\n"
"             vv\n"
"             /\\\n"
"            /  \\\n"
"           /++++\\\n"
"          /  ()  \\\n"
"          /      \\\n"
"         /~`~`~`~`\\\n"
"        /  []  ()  \\\n"
"        /          \\\n"
"       /*&*&*&*&*&*&\\\n"
"      /  ()  {}  []  \\\n"
"      /              \\\n"
"     /++++++++++++++++\\\n"
"    /  {}  ()  []  {}  \\\n"
"    /                  \\\n"
"   /~`~`~`~`~`~`~`~`~`~`\\\n"
"  /  ()  []  {}  ()  []  \\\n"
"  /*&*&*&*&*&*&*&*&*&*&*&\\\n"
" /                        \\\n"
"/,.,.,.,.,.,.,.,.,.,.,.,.,.\\\n"
"           |   |\n"
"          |`````|\n"
"          \\_____/\n";

char *color_str(char *input, int color) {

    char *color_off = "\x1B[0m";
    char *color_on;
    switch (color)
    {
        case Red:
            color_on = "\x1B[31m";
            break;
        case Green:
            color_on = "\x1B[32m";
            break;
        case Blue:
            color_on = "\x1B[34m";
            break;
        case Yellow:
            color_on = "\x1B[33m";
            break;

        default:
            color_on = "\x1B[0m";

    }
    char *result = malloc(strlen(color_on) + strlen(input) + strlen(color_off) + 1);
    strcat(result, color_on);
    strcat(result, input);
    strcat(result, color_off);

    return result;
}

char *color_tree(int seed) {
    seed = seed % 8;
    char *colored_tree;

    // create and color christmas tree star 
    colored_tree = strrep(tree, "^^", color_str("/\\", Yellow));
    colored_tree = strrep(colored_tree, "vv", color_str("\\/", Yellow));
    colored_tree = strrep(colored_tree, "<", color_str("<", Yellow));
    colored_tree = strrep(colored_tree, ">", color_str(">", Yellow));
    
    // color christmas lights according to the seed value
    if (seed & (1 << Red)) {
        colored_tree = strrep(colored_tree, "()", color_str("()", Red));
    }
    if (seed & (1 << Green)) {
        colored_tree = strrep(colored_tree, "[]", color_str("[]", Green));
    }
    if (seed & (1 << Blue)) {
        colored_tree = strrep(colored_tree, "{}", color_str("{}", Blue));
    }
   
    return colored_tree;
}

int main() {
    while (1) {
        char *tree_cpy = tree;
        int seed = rand();

        printf("\033c"); // clear console
        printf("%s\n", color_tree(seed));
        sleep(1);
    }
    return 0;
}
