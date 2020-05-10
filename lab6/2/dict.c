#include "dict.h"
#include <assert.h>
#include <stdlib.h>
#include "../1/map.h"

struct _dict_t {
    map_t map;
    unsigned int length;
};

dict_t dict_empty() {
    dict_t dict = NULL;

    dict = malloc(sizeof(struct _dict_t));
    dict->length = 0;
    dict->map = map_empty();

    return dict;
}

dict_t dict_add(dict_t dict, string_t word, string_t def) {
    assert(dict != NULL && word != NULL && def != NULL);

    dict->map = map_put(dict->map, word, def);
    dict->length++;

    assert(string_eq(def, dict_search(dict, word)));
    return dict;
}

string_t dict_search(dict_t dict, string_t word) {
    assert(dict != NULL && word != NULL);

    string_t def = NULL;
    def = map_get(dict->map, word);

    assert((def == NULL && !dict_exists(dict, word)) || def != NULL);
    return def;
}

bool dict_exists(dict_t dict, string_t word) {
    assert(dict != NULL && word != NULL);

    bool res = map_contains(dict->map, word);

    return res;
}

unsigned int dict_length(dict_t dict) {
    assert(dict != NULL);

    unsigned int res = dict->length;

    return res;
}

dict_t dict_remove(dict_t dict, string_t word) {
    assert(dict != NULL && word != NULL);

    dict->map = map_remove(dict->map, word);
    dict->length--;

    assert(dict != NULL && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    assert(dict != NULL);

    dict->map = map_destroy(dict->map);
    dict->length = 0u;

    assert(dict != NULL && dict_length(dict) == 0);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(dict != NULL && file != NULL);

    map_dump(dict->map, stdout);

    assert(dict != NULL);
}

dict_t dict_destroy(dict_t dict) {
    assert(dict != NULL);

    dict->map = map_destroy(dict->map);

    free(dict);
    dict = NULL;

    assert(dict == NULL);
    return dict;
}
