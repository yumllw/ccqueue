/*************************************************************************
 *    		>       File Name: ccqueue.h
 *    		>          Author: wpz
 *    		>      E-mail: yumllw@qq.com 
 *    		> Created Time: 2016年01月25日 星期一 10时44分50秒
 ************************************************************************/
#ifndef __GEN_LIST_H
#define __GEN_LIST_H

#include <malloc.h>

struct gen_list
{
    struct gen_list *prev;
    struct gen_list *next;
};

void init_gen_list(struct gen_list *entry)
{
    entry->prev = entry;
    entry->next = entry;
}

struct gen_list *new_gen_list_entry(void)
{
    struct gen_list *entry;
    entry = (struct gen_list *)malloc(sizeof(struct gen_list));
    if (!entry)
    {
	printf("");
	return NULL;
    }
 
    init_gen_list(entry);
    
    return entry;
}

#define prefetch(x) __builtin_prefetch(x)

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({	    \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})


#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define list_for_each(pos, head) \
    for (pos = (head)->next; prefetch(pos->next), pos != (head); \
	    pos = pos->next)

#endif /* __GEN_LIST_H */
