/*
 * Задача 5-3-Польская запись
 * Необходимо вычислить выражение написанное в обратной польской записи. 
 * На вход подается строка состоящая из целых, не отрицательных чисел и арифметических символов. 
 * В ответ единственное целое число - результат. 
 * Формат ввода:
 * Строка состоящая из целых чисел и символов '+', '-', '*', '/', ' '. В конце строки символ '.'. Строка корректная. 
 * Длина строки не превосходит 1000 символов. Все числа и операции разделены ровно одним пробелом.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 1000

// Функция для выполнения арифметической операции
int perform_operation(char operator, int a, int b) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Главная функция
int main() {
    char input[MAX_STACK_SIZE];
    int stack[MAX_STACK_SIZE];
    int top = -1;

    // Чтение строки
    fgets(input, sizeof(input), stdin);
    
    // Разделение строки на токены по пробелам
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Если токен является числом
        if (isdigit(token[0])) {
            int num = atoi(token);
            stack[++top] = num;  // Помещаем число в стек
        } else if (token[0] == '.') {
            break;  // Конец строки, завершение обработки
        } else {
            // Это оператор, поэтому извлекаем два числа из стека
            int b = stack[top--];
            int a = stack[top--];
            // Выполняем операцию и результат возвращаем в стек
            int result = perform_operation(token[0], a, b);
            stack[++top] = result;
        }
        token = strtok(NULL, " ");  // Переходим к следующему токену
    }

    // Выводим результат, который должен быть единственным элементом в стеке
    printf("%d\n", stack[top]);

    return 0;
}
