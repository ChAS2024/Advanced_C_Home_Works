#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char word[20];
    struct list *next;
};

void add_to_list(struct list **head, const char *word) {
    struct list *new_node = (struct list *)malloc(sizeof(struct list));
    strcpy(new_node->word, word);
    new_node->next = *head;
    *head = new_node;
}

void swap_elements(struct list *a, struct list *b) {
    char temp[20];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

void sort_list(struct list *head) {
    struct list *current, *next_node;
    int swapped;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;

        while (current->next != NULL) {
            next_node = current->next;
            if (strcmp(current->word, next_node->word) > 0) {
                swap_elements(current, next_node);
                swapped = 1;
            }
            current = next_node;
        }
    } while (swapped);
}

void print_list(struct list *head) {
    struct list *current = head;
    int first = 1;
    while (current != NULL) {
        if (!first) {
            printf(" ");
        }
        printf("%s", current->word);
        first = 0;
        current = current->next;
    }
    printf("\n");
}

void delete_list(struct list *head) {
    struct list *current = head;
    struct list *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main() {
    struct list *head = NULL;
    char input[1001];
    char *word;

    // Чтение строки из входа
    fgets(input, sizeof(input), stdin);

    // Удаляем точку из конца строки, если она есть
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }
    if (input[len - 1] == '.') {
        input[len - 1] = '\0';
    }

    // Разбиение строки на слова
    word = strtok(input, " ");
    while (word != NULL) {
        add_to_list(&head, word);
        word = strtok(NULL, " ");
    }

    // Сортировка списка
    sort_list(head);

    // Вывод списка в одну строку
    print_list(head);

    // Удаление списка
    delete_list(head);

    return 0;
}
