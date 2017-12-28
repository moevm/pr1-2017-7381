
#include "music.h"
#include "course.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    char opt;
    
    MusicalComposition* list = NULL;

    char* name = (char*)malloc(81 * sizeof(char));
    char* author = (char*)malloc(81 * sizeof(char));
    int year;

    int n;
    
    printf("Введите команду:\n1: Добавить элемент в список.\n2: Удалить элемент из списка.\n3: Вывести количество элементов списка.\n4: Вывести список композиций.\n5: Удалить все композиции с длиной названия меньше n.\n6: Завершить программу.\n");
    do {
        printf("-> ");
        scanf(" %c", &opt);
        switch (opt) {
        case '1':
            printf("Введите название композиции:\t");
            scanf("%s", name);
            printf("Введите автора композиции:\t");
            scanf("%s", author);
            printf("Введите год издания:\t\t");
            scanf("%d", &year);
            push(&list, createMusicalComposition(name, author, year));     
            break;
        case '2':
            printf("Введите название композиции:\t");
            scanf("%s", name);
            removeEl(&list, name);
            break;
        case '3':
            printf("Элементов в списке: %d\n", count(list));
            break;
        case '4':
            print_names(list);
            break;
        case '5':
            printf("Введите любое число:\n");
            scanf("%d", &n);
            deleteEl(&list, n);
            break;
        case '6':
            printf("Освобождение памяти\n");
            break;
        default:
            printf("Неизвестная команда\n");
            break;
        }
    } while (opt != '6');

    free(name);
    free(author);
    freeList(&list);

    return 0;
}