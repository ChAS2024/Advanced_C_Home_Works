#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Определение структуры дерева
typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;

// Структура для хранения узлов вместе с их горизонтальным расстоянием
typedef struct QueueNode {
    tree *node;
    int hd;
    struct QueueNode *next;
} QueueNode;

// Очередь для обхода в ширину
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, tree *node, int hd) {
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

QueueNode* dequeue(Queue *q) {
    if (q->front == NULL)
        return NULL;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

// Основная функция для печати вида дерева сверху
void btUpView(tree *root) {
    if (root == NULL)
        return;

    // Создаем очередь для обхода в ширину
    Queue *q = createQueue();
    enqueue(q, root, 0);

    // Хэш таблица для хранения первого встреченного узла на каждой горизонтальной линии
    // (горизонтальное расстояние, значение узла)
    int hd_min = INT_MAX, hd_max = INT_MIN;
    int topView[1000]; // Заранее выделяем место, индекс соответствует горизонтальному расстоянию

    while (!isEmpty(q)) {
        QueueNode *temp = dequeue(q);
        int hd = temp->hd;
        tree *node = temp->node;
        
        // Проверяем, виден ли этот узел сверху
        if (hd < hd_min) {
            hd_min = hd;
            topView[hd + 500] = node->key; // Смещение на 500, чтобы избежать отрицательных индексов
        } else if (hd > hd_max) {
            hd_max = hd;
            topView[hd + 500] = node->key;
        }

        // Добавляем левого и правого потомков в очередь
        if (node->left)
            enqueue(q, node->left, hd - 1);
        if (node->right)
            enqueue(q, node->right, hd + 1);

        free(temp);
    }

    // Печать значений, видимых сверху
    for (int i = hd_min; i <= hd_max; i++) {
        printf("%d ", topView[i + 500]);
    }
    printf("\n");
}
