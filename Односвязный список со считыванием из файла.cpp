#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node_t {
    struct node_t* next;
    int data;
};

struct node_t* read_list(FILE* inp) {
    int num, evc = 0, oddc = 0;
    struct node_t* odd = (struct node_t*)malloc(sizeof(struct node_t));
    struct node_t* even = (struct node_t*)malloc(sizeof(struct node_t));
    struct node_t* odd_begin = odd;
    struct node_t* even_begin = even;
    while (fscanf(inp, "%d", &num) == 1) {
        if (num % 2 == 0) {
            if (evc != 0)
                even = even->next;
            even->data = num;
            even->next = (struct node_t*)malloc(sizeof(struct node_t));
            evc++;
        }
        else {
            if (oddc != 0)
                odd = odd->next;
            odd->data = num;
            odd->next = (struct node_t*)malloc(sizeof(struct node_t));
            oddc++;
        }
    }
    if (evc == 0) {
        free(odd->next);
        odd->next = NULL;
        return odd_begin;
    }
    else if (oddc == 0) {
        free(even->next);
        even->next = NULL;
        return even_begin;
    }
    else {
        even->next = odd_begin;
        free(odd->next);
        odd->next = NULL;
        return even_begin;
    }
}

void delete_list(struct node_t* top) {
    if (top->next == NULL) {
        free(top);
        return;
    }
    delete_list(top->next);
    free(top);
}

int main() {
    FILE* f = fopen("q.txt", "r");
    struct node_t* s = (struct node_t*)malloc(sizeof(struct node_t));
    s = read_list(f);
    while (1) {
        printf("%d ", s->data);
        if (s->next == NULL)
            break;
        s = s->next;
    }
    return 0;
}