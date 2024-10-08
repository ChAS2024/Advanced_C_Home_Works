/*
 * Задача 5-1-Вычеркивание
 * Сколько различных трехзначных чисел можно получить из заданного натурального N, вычеркивая цифры из его десятичной записи?
 * Формат данных на входе: Единственное натуральное число N.
 * Формат данных на выходе: Единственное целое число – найденное количество.
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DIGITS 10

int main() {
    char N[105];  // Для хранения числа N как строки
    bool seen[1000] = {false};  // Массив флагов для всех возможных трехзначных чисел
    int count = 0;
    
    // Ввод числа N
    scanf("%s", N);
    
    int len = strlen(N);

    // Перебираем все возможные комбинации трех цифр
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                // Сформируем число из цифр N[i], N[j], N[k]
                int num = (N[i] - '0') * 100 + (N[j] - '0') * 10 + (N[k] - '0');
                
                // Если это число еще не было встречено, увеличиваем счетчик и помечаем его как встреченное
                if (!seen[num]) {
                    seen[num] = true;
                    count++;
                }
            }
        }
    }

    // Выводим результат
    printf("%d\n", count);

    return 0;
}
