#include <assert.h>
#include <stdlib.h>
#include "map.h"
#include "stack/stack.h"

struct _node_t {
    map_t left;
    map_t right;
    key_t key;
    value_t value;
};

map_t map_empty() {
    return NULL;
}

static map_t
create_node(key_t key, value_t value, map_t left, map_t right) {
    map_t node = NULL;
    node = malloc(sizeof(struct _node_t));
    node->key = key;
    node->value = value;
    node->left = left;
    node->right = right;
    return (node);
}

static map_t
free_node(map_t node) {
    free(node);
    return map_empty();
}

static bool
is_empty(map_t node) {
    return (node == NULL);
}

static bool
is_BST(map_t map) {
    map_t node = map;

    if (is_empty(node))
        return true;
    else {
        bool bigger_than_left_BST = is_empty(node->left) || (string_less(node->left->key, node->key) && is_BST(node->left));

        bool smaller_than_right_BST = is_empty(node->right) || (string_less(node->key, node->right->key) && is_BST(node->right));

        return (bigger_than_left_BST && smaller_than_right_BST);
    }
}

map_t map_put(map_t map, key_t key, value_t value) {
    assert(key != NULL);
    assert(value != NULL);
    assert(is_BST(map));

    map_t node = map;

    map_t aux = node;
    map_t parent_of_aux;

    if (is_empty(node))
        return (create_node(key, value, map_empty(), map_empty()));

    while (!is_empty(aux)) {
        if (key_eq(key, aux->key)) {
            aux->value = value;
            break;
        } else if (key_less(key, aux->key)) {
            parent_of_aux = aux;
            aux = aux->left;
        } else {
            parent_of_aux = aux;
            aux = aux->right;
        }
    }

    if (is_empty(aux)) {
        if (string_less(key, parent_of_aux->key))
            parent_of_aux->left = create_node(key, value, map_empty(), map_empty());
        else
            parent_of_aux->right = create_node(key, value, map_empty(), map_empty());
    }

    return (node);
}

value_t
map_get(map_t map, key_t key) {
    assert(key != NULL);
    assert(is_BST(map));

    value_t value = NULL;

    map_t node = map;
    map_t aux = node;

    while (!is_empty(aux)) {
        if (key_eq(key, aux->key)) {
            value = aux->value;
            break;
        } else if (key_less(key, aux->key))
            aux = aux->left;
        else
            aux = aux->right;
    }

    return (value);
}

bool map_contains(map_t map, key_t key) {
    assert(key != NULL);
    assert(is_BST(map));

    bool result = false;

    map_t node = map;
    map_t aux = node;

    while (!is_empty(aux)) {
        if (key_eq(key, aux->key)) {
            result = true;
            break;
        } else if (key_less(key, aux->key))
            aux = aux->left;
        else
            aux = aux->right;
    }

    return (result);
}

static map_t
map_remove_this(map_t map) {
    map_t node = map;
    map_t successor;

    if (is_empty(node))
        return (map_empty());
    else if (is_empty(node->right))
        successor = node->left;
    else if (is_empty(node->left))
        successor = node->right;
    else if (is_empty(node->right->left)) {
        successor = node->right;
        successor->left = node->left;
    } else {
        successor = node->right;
        map_t parent_of_successor;
        while (!is_empty(successor->left))  // the successor will be the
                                            // smallest key larger than map
        {
            parent_of_successor = successor;
            successor = successor->left;
        }
        parent_of_successor->left =
            successor->right;  // successor->left will always be empty, but it
                               // could have a right tree
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

    map_t node = map;

    if (map_contains(node, key)) {
        map_t aux = node;
        map_t parent_of_aux;

        if (key_eq(key, node->key))  // case of removing the root
            node = map_remove_this(node);
        else {
            while (!is_empty(aux)) {
                if (key_eq(key, aux->key)) {
                    aux = map_remove_this(aux);
                    break;
                } else if (key_less(key, aux->key)) {
                    parent_of_aux = aux;
                    aux = aux->left;
                } else {
                    parent_of_aux = aux;
                    aux = aux->right;
                }
            }

            if (string_less(key, parent_of_aux->key))
                parent_of_aux->left = aux;
            else
                parent_of_aux->right = aux;
        }
    }

    return (node);
}

void destroy_this(map_t map) {
    map_t node = map;

    string_destroy(node->key);
    string_destroy(node->value);
    free_node(node);
    node = map_empty();
}

map_t min_node(map_t map) {
    map_t node = map;

    if (is_empty(node))
        return (map_empty());

    while (!is_empty(node->left))
        node = node->left;

    return (node);
}

map_t map_destroy_stack(map_t map) {
    assert(is_BST(map));

    map_t node = map;
    map_t aux = node;

    stack_t call_stack = stack_empty();

    if (is_empty(node))
        return (map_empty());

    while (!is_empty(node)) {
        if (is_empty(node->right)) {
            aux = node->left;
            destroy_this(node);
            node = aux;
        } else {
            aux = min_node(node);
            aux->left = node->right;
            node->right = map_empty();
        }
    }
}

map_t map_destroy(map_t map) {
    assert(is_BST(map));

    map_t node = map;

    map_t aux = node;

    if (is_empty(node))
        return (map_empty());

    while (!is_empty(node)) {
        if (is_empty(node->right)) {
            aux = node->left;
            destroy_this(node);
            node = aux;
        } else {
            aux = min_node(node);
            aux->left = node->right;
            node->right = map_empty();
        }
    }
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
