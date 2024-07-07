#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

Dlist dlist_new(void)
{
    return NULL;
}

bool dlist_is_empty(Dlist li)
{
    if (li == NULL)
        return true;
    return false;
    
}

int dlist_first(Dlist li)
{
    if(dlist_is_empty(li))
        return NULL;
    return li->begin->value;
}

int dlist_last(Dlist li)
{
    if(dlist_is_empty(li))
        return NULL;
    return li->end->value;
}

Dlist dlist_push_back(Dlist li, int value)
{
    DlistNode node = NULL;
    node = malloc(sizeof(DlistNode));
    if (node == NULL)
    {
        fprintf(stderr, MEMORY_ALLOCATION_ERROR);
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->next = NULL;
    node->back = NULL;

    if(dlist_is_empty(li))
    {
        li = malloc(sizeof(Dlist));
        if (li == NULL)
        {
            fprintf(stderr, MEMORY_ALLOCATION_ERROR);
            exit(EXIT_FAILURE);
        }
        li->begin = node;
        li->end = node;
    }
    else
    {
        node->back = li->end;
        li->end = node;
    }
    li->length++;
    return li;
}

Dlist dlist_push_front(Dlist li, int value)
{
    DlistNode node = NULL;
    node = malloc(sizeof(DlistNode));
    if (node == NULL)
    {
        fprintf(stderr, MEMORY_ALLOCATION_ERROR);
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->next = NULL;
    node->back = NULL;

    if (dlist_is_empty(li))
    {
        li = malloc(sizeof(Dlist));
        if (li == NULL)
        {
            fprintf(stderr, MEMORY_ALLOCATION_ERROR);
            exit(EXIT_FAILURE);
        }
        li->begin = node;
        li->end = node;
    }
    else
    {
        node->next = li->begin;
        li->begin = node;
    }
    li->length++;
    return li;
}

Dlist dlist_pop_back(Dlist li)
{
    if (dlist_is_empty(li))
        return dlist_new();
    
    DlistNode temp = li->end;
    li->end = li->end->back;
    free(temp);
    li->length--;
    if (li->length == 0)
    {
        free(li);
        li = NULL;
        return dlist_new();
    }
    return li;
}

Dlist dlist_pop_front(Dlist li)
{
    if (dlist_is_empty(li))
        return dlist_new();
    
    DlistNode temp = li->begin;
    li->begin = li->begin->next;
    free(temp);
    li->length--;
    if (li->length == 0)
    {
        free(li);
        li = NULL;
        return dlist_new();
    }
    return li;
}

Dlist dlist_insert(Dlist li, uint32_t index, int value)
{
    if(index < 0 || index > li->length -1)
    {
        fprintf(stderr, OVER_RANGE_ERROR);
        exit(EXIT_FAILURE);
    }
    DlistNode node = NULL;
    node = malloc(sizeof(DlistNode));
    if (node == NULL)
    {
        fprintf(stderr, MEMORY_ALLOCATION_ERROR);
        exit(EXIT_FAILURE);
    }
    DlistNode begin = li->begin;
    if(dlist_is_empty(li))
        return dlist_push_front(li, value);
    for (int i = 0; i < index; i++)
    {
        begin = begin->next;
    }
    node->next = begin->next;
    if (node->next != NULL)
        node->next->back = node;
    node->back = begin;
    begin->next = node;
    li->length++;
    return li;
}

Dlist dlist_remove(Dlist li, uint32_t index)
{
    if(index < 0 || index > li->length -1)
    {
        fprintf(stderr, OVER_RANGE_ERROR);
        exit(EXIT_FAILURE);
    }
    if(dlist_is_empty(li))
        return dlist_new();
    if (li->length == 1)
    {
        return dlist_pop_back(li);
    }
    
    DlistNode node = li->begin;
    for (int i = 0; i < index; i++)
    {
        node->next;
    }
    DlistNode temp = node;
    if (node->back != NULL)
        node->back->next = node->next;
    if (node->next != NULL)
        node->next->back = node->back;
    free(temp);
    li->length--;
    return li;
}

Dlist dlist_clear(Dlist li)
{
    if (dlist_is_empty(li))
        return dlist_new();
    DlistNode node = li->begin;
    while (node != NULL)
    {
        DlistNode temp = node;
        node = node->next;
        free(temp);
    }
    li->begin = NULL;
    li->end = NULL;
    li->length = 0;
    free(li);
    return dlist_new();
}