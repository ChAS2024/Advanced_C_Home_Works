/* Задача 7-3-Найти брата
 * В программе описано двоичное дерево:
 * typedef struct tree {
 *    datatype key;
 *    struct tree *left, *right;
 *    struct tree *parent; //ссылка на родителя
 * } tree;
 * Требуется реализовать функцию, которая по ключу возвращает адрес соседнего элемента - брата. 
 * Если такого ключа нет или у узла нет брата, то необходимо вернуть 0. Прототип функции: tree * findBrother(tree *root, int key)
 */

#include <stdio.h>
#include <stdlib.h>

// Определение структуры дерева
typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent; // ссылка на родителя
} tree;

// Вспомогательная функция для поиска узла по ключу
tree* findNode(tree *root, int key) {
    if (root == NULL)
        return NULL;
    if (root->key == key)
        return root;

    tree *leftSearch = findNode(root->left, key);
    if (leftSearch != NULL)
        return leftSearch;

    return findNode(root->right, key);
}

// Основная функция для поиска брата
tree* findBrother(tree *root, int key) {
    // Ищем узел по ключу
    tree *node = findNode(root, key);
    
    if (node == NULL || node->parent == NULL)
        return 0; // Узел не найден или у корневого узла нет родителя

    // Проверяем, есть ли у узла брат
    tree *parent = node->parent;
    if (parent->left == node && parent->right != NULL)
        return parent->right;
    if (parent->right == node && parent->left != NULL)
        return parent->left;

    return 0; // Брата нет
}

