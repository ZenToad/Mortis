#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

#include <stdio.h>

typedef struct strmap_t {
    char *key; 
    char *value; 
} strmap_t;
strmap_t *strmap = NULL;

char *intern(char *str) {
    if (shgeti(strmap, str) < 0) {
        shput(strmap, str, str);
    }
    return shget(strmap, str);
}

void test_array(void) {
    // dynamic array
    int *arr = NULL;
    arrput(arr, 1);
    arrput(arr, 2);
    arrput(arr, 3);
    arrput(arr, 4);
    arrput(arr, 5);

    for (int i = 0; i < arrlen(arr); i++) {
        printf("%d\n", arr[i]);
    }
}

void test_hashmap(void) {
    // hash map
    float f;
    struct { float key; char value; } *hash = NULL;
    f=10.5; hmput(hash, f, 'h');
    f=20.4; hmput(hash, f, 'e');
    f=50.3; hmput(hash, f, 'l');
    f=40.6; hmput(hash, f, 'X');
    f=30.9; hmput(hash, f, 'o');
    f=40.6; printf("%c - ", hmget(hash, f));
    f=40.6; hmput(hash, f, 'l');
    for (int i=0; i < hmlen(hash); ++i)
        printf("%c ", hash[i].value);
}

void test_interning(void) {
    // curious what the string hash stuff does...
    sh_new_arena(strmap);

    // but how does this work for interning a string?
    // do we just see if it's there?
    char *a = strdup("hello");
    assert(intern("hello") == intern(a));
}

void test_string_formatting(void) {
    // the other thing we often need is string formatting.
    // 
}

int main(int argc, char **argv) {
    test_interning();
    return 0;
}
