#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct List* list_create();

void list_add_first(struct List* list, Data x);

Data list_remove_first(struct List* list);

Data list_get_first(struct List* list);

void list_print(struct List* list);

int list_size(struct List* list);

void list_clear(struct List* list);

void list_destroy(struct List* list);

//--------------------------------------------------------------------------------

struct List* list_create() {
    struct List* list = (struct List*) malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}


void list_add_first(struct List* list, Data x) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = x;
    if (list->head) {
        node->next = list->head;
    }
    else {
        node->next = NULL;
    }

    list->head = node;
}


void list_add_last(struct List* list, Data x) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;

    struct Node* tmp = list->head;

    if (list->head) {
        while (tmp->next) {
            tmp = tmp->next;
        }
    }
    else {
        list->head = node;
        return;
    }

    tmp->next = node;
}



Data list_remove_first(struct List* list) {
    Data value = (list->head)->val;

    struct Node* tmp = (list->head)->next;

    free(list->head);

    list->head = tmp;

    return value;
}



Data list_remove_last(struct List* list) {
    struct Node* tmp = list->head;
    Data value = 0;
    if ((tmp->next)) {
        while ((tmp->next)->next) {
            tmp = tmp->next;
        }

        value = (tmp->next)->val;

        free(tmp->next);

        tmp->next = NULL;
    }
    else {
        value = (list->head)->val;

        free(list->head);

        list->head = NULL;
    }

    return value;
}



Data list_get_first(struct List* list) {
    return (list->head)->val;
}



Data list_get_last(struct List* list) {
    struct Node* tmp = list->head;

    if (list->head) {
        while (tmp->next) {
            tmp = tmp->next;
        }
    }

    return tmp->val;
}



void list_print(struct List* list)
{
    struct Node* tmp = list->head;

    if (list->head) {
        if (list->head) {
            printf("%d ", tmp->val);
            while (tmp->next) {
                tmp = tmp->next;
                printf("%d ", tmp->val);
            }
        }
        printf("\n");
    }
    else {
        printf("Empty list\n");
    }
}


int list_size(struct List* list)
{
    int n = 0;
    struct Node* tmp = list->head;

    if (list->head) {
        n++;
        while (tmp->next) {
            n++;
            tmp = tmp->next;
        }
    }
    return n;
}


void list_clear(struct List* list)
{
    struct Node* tmp = list->head;
    struct Node* tmp1 = NULL;

    if (list->head) {
        while (tmp) {
            tmp1 = tmp;
            tmp = tmp->next;
            free(tmp1);
        }
    }
    list->head = NULL;
}



void list_destroy(struct List* list) {
    struct Node* tmp = list->head;
    struct Node* tmp1 = NULL;

    if (list->head) {
        while (tmp) {
            tmp1 = tmp;
            tmp = tmp->next;
            free(tmp1);
        }
    }
    free(list);
}

void add_list(struct List* list, Data x) {
    if (list->head->val >= x) {
        struct Node* tmp = list->head;
        list->head = (struct Node*)malloc(sizeof(struct Node));
        list->head->next = tmp;
        list->head->val = x;
        return;
    }
    struct Node* tmp = list->head;
    while (tmp->next != NULL) {
        if (tmp->next->val >= x) {
            struct Node* tmp2 = tmp->next;
            struct Node* mid = (struct Node*)malloc(sizeof(struct Node));
            tmp->next = mid;
            mid->next = tmp2;
            mid->val = x;
            return;
        }
        tmp=tmp->next;
    }
    tmp->next = (struct Node*)malloc(sizeof(struct Node));
    tmp->next->next = NULL;
    tmp->next->val = x;
    return;
}

int main() {
    struct List* list = list_create();
    list_add_first(list, 5);
    list_add_first(list, 4);
    list_add_first(list, 2);
    list_add_first(list, 1);
    list_add_first(list, 0);
    add_list(list, 3);
    list_print(list);
    list_destroy(list);
    return 0;
}
