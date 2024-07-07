#ifndef __DLIST__H__
#define __DLIST__H__

    #include<stdint.h>
    #include<stdbool.h>

    #define MEMORY_ALLOCATION_ERROR "Memory allocation failed"
    #define OVER_RANGE_ERROR "Over range error"

    typedef struct DlistNode
    {
        int value;
        struct DlistNode *back;
        struct DlistNode *next;
    } *DlistNode;

    typedef struct Dlist
    {
        uint32_t length;
        DlistNode begin;
        DlistNode end;
    } *Dlist;

    Dlist dlist_new(void);
    bool dlist_is_empty(Dlist li);
    int dlist_first(Dlist li);
    int dlist_last(Dlist li);
    Dlist dlist_push_back(Dlist li, int value);
    Dlist dlist_push_front(Dlist li, int value);
    Dlist dlist_pop_back(Dlist li);
    Dlist dlist_pop_front(Dlist li);
    Dlist dlist_insert(Dlist li, uint32_t index, int value);
    Dlist dlist_remove(Dlist li, uint32_t index);
    Dlist dlist_clear(Dlist li);

#endif // __DLIST__H__