/*
 * Описана структура данных для хранения информации об использованной памяти:
 * typedef struct list
 * {
 *     void *address;
 *     char comment[64];
 *     size_t size;
 *     struct list *next;
 * } list;
 * Требуется реализовать только одну функцию, которая анализирует данный список и возвращает
 * сколько всего памяти используется. Адрес хранится в поле address, поле size - соответствующий размер
 * данного блока. Если список пустой, то функция должна возвращать NULL. Прототип функции:
 * size_t totalMemoryUsage(list *head)
 * Загрузите только текст данной функции
 */

size_t totalMemoryUsage(list *head)
{
    if (head == NULL)
    {
        printf("NULL");
        exit(1);
    }
    size_t totalMemory = 0;
    for (; head; head = head->next)
    {
        totalMemory += head->size;
    };
    return totalMemory;
}