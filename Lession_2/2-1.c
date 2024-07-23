/*
 * Описана структура данных
 * typedef struct list
 * {
 *    void *address;
 *    char comment[64];
 *    size_t size;
 *    struct list *next;
 * } list;
 * Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти
 * занимающий больше всего места. Адрес хранится в поле address, поле size - соответствующий размер
 * данного блока. Если список пустой, то функция должна возвращать NULL. Если есть несколько таких
 * блоков, то вернуть адрес любого из них. Прототип функции:
 * void * findMaxBlock(list *head)
 */

void *findMaxBlock(list *head)
{
    if (head == NULL)
    {
        printf("NULL");
        exit(1);
    }
    size_t max = head->size;
    void *addr;
    addr = head->address;
    while (head)
    {
        if (head->size > max)
        {
            max = head->size;
            addr = head->address;
        }
        head = head->next;
    };
    return addr;
}