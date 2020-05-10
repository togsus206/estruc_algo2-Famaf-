#include "map.h"
#include <assert.h>
#include <stdlib.h>

struct _node_t {
    map_t left;
    map_t right;
    key_t key;
    value_t value;
};

map_t map_empty() { return NULL; }

static map_t create_node(key_t key, value_t value, map_t left, map_t right) {
    map_t node = NULL;
    node = malloc(sizeof(struct _node_t));
    node->key = key;
    node->value = value;
    node->left = left;
    node->right = right;
    return (node);
}

static map_t free_node(map_t node) {
    free(node);
    return map_empty();
}

static bool is_empty(map_t node) { return (node == NULL); }

static bool is_BST(map_t map) {
    map_t node = map;

    if (is_empty(node)) {
        return true;
    } else {
        bool bigger_than_left_BST =
            is_empty(node->left) ||
            (string_less(node->left->key, node->key) && is_BST(node->left));

        bool smaller_than_right_BST =
            is_empty(node->right) ||
            (string_less(node->key, node->right->key) && is_BST(node->right));

        return (bigger_than_left_BST && smaller_than_right_BST);
    }
}

map_t map_put(map_t map, key_t key, value_t value) {
    assert(key != NULL);
    assert(value != NULL);
    assert(is_BST(map));

    map_t node = map;

    if (is_empty(node)) {
        node = create_node(key, value, map_empty(), map_empty());
    } else if (key_eq(key, map->key)) {
        node->value = value;
    } else if (key_less(key, map->key)) {
        node->left = map_put(node->left, key, value);
    } else {
        node->right = map_put(node->right, key, value);
    }

    return (node);
}

value_t map_get(map_t map, key_t key) {
    assert(key != NULL);
    assert(is_BST(map));

    value_t value = NULL;

    map_t node = map;

    if (is_empty(map)) {
        return (NULL);
    } else if (key_eq(key, map->key)) {
        value = node->value;
    } else if (key_less(key, map->key)) {
        value = map_get(node->left, key);
    } else {
        value = map_get(node->right, key);
    }

    return (value);
}

bool map_contains(map_t map, key_t key) {
    assert(key != NULL);
    assert(is_BST(map));

    map_t node = map;

    if (is_empty(node)) {
        return false;
    } else if (key_eq(key, node->key)) {
        return true;
    } else if (key_less(key, node->key)) {
        return map_contains(node->left, key);
    } else {
        return map_contains(node->right, key);
    }
}

static map_t map_remove_this(map_t map) {
    map_t node = map;
    map_t successor;

    if (is_empty(node)) {
        return (map_empty());
    } else if (is_empty(node->right)) {
        successor = node->left;
    } else if (is_empty(node->left)) {
        successor = node->right;
    } else if (is_empty(node->right->left)) {
        successor = node->right;
        successor->left = node->left;
    } else {
        successor = node->right;
        map_t parent_of_successor;
        // the successor will be the smallest key larger than map
        while (!is_empty(successor->left)) {
            parent_of_successor = successor;
            successor = successor->left;
        }
        // successor->left will always be empty, but it could have a right tree
        parent_of_successor->left = successor->right;
        successor->left = node->left;
        successor->right = node->right;
    }
    string_destroy(node->key);
    string_destroy(node->value);
    free_node(node);
    return (successor);
}

map_t map_remove(map_t map, key_t key) {
    assert(is_BST(map));

    map_t result = map;

    if (!map_contains(map, key)) {
        result = map;
    } else if (key_eq(key, map->key)) {
        result = map_remove_this(result);
    } else if (key_less(key, map->key)) {
        result->left = map_remove(map->left, key);
    } else {
        result->right = map_remove(map->right, key);
    }

    return (result);
}

map_t map_destroy(map_t map) {
    assert(is_BST(map));

    map_t node = map;

    if (!is_empty(node)) {
        string_destroy(node->key);
        string_destroy(node->value);
        map_destroy(node->left);
        map_destroy(node->right);
        free_node(node);
        node = map_empty();
    }

    return (node);
}

void map_dump(map_t map, FILE* file) {
    assert(is_BST(map));

    if (map != NULL) {
        map_dump(map->left, file);
        key_dump(map->key, file);
        fprintf(file, ": ");
        value_dump(map->value, file);
        fprintf(file, "\n");
        map_dump(map->right, file);
    }
}
