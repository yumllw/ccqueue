/*************************************************************************
 *    		>       File Name: ccqueue.h
 *    		>          Author: wpz
 *    		>      E-mail: yumllw@qq.com 
 *    		> Created Time: 2016年01月25日 星期一 10时02分39秒
 ************************************************************************/
#ifndef __CC_QUEUE_H
#define __CC_QUEUE_H

#include "glist.h"

#define CCQ_TRUE  1
#define CCQ_FALSE 0

struct cc_queue
{
    struct gen_list *ccq_head;
    struct gen_list *ccq_tail;

    pthread_mutex_t hlock;
    pthread_mutex_t tlock;
};

void cc_queue_init(struct cc_queue *ccq)
{
    struct gen_list *dummy;

    dummy = new_gen_list_entry();
    if (!dummy)
    {
	printf("");
	return (-1);
    }

    ccq->ccq_head = ccq->ccq_tail = dummy;

    pthread_mutex_init(&ccq->hlock, NULL);
    pthread_mutex_init(&ccq->tlock, NULL);
}

int cc_queue_empty(struct cc_queue *ccq)
{
    return (ccq->ccq_head == ccq->ccq_tail) \
			   ? CCQ_TRUE:CCQ_FALSE;
}

void cc_queue_enqueue(struct cc_queue *ccq, struct gen_list *qnode)
{
    
    pthread_mutex_lock(&ccq->tlock);

    if (ccq->ccq_head != ccq->ccq_tail)
    {
	qnode->prev   = ccq->ccq_tail;
	ccq->ccq_tail = qnode;
    }
    else
    {
	ccq->ccq_head->next = qnode;
	qnode->prev   = ccq->ccq_head;
	ccq->ccq_tail = qnode;
    }

    pthread_mutex_unlock(&ccq->tlock);
}

void cc_queue_dequeue(struct cc_queue *ccq, struct gen_list *qnode)
{
    if (cc_queue_empty(ccq))
    {
	printf("队列为空\n");
	return CCQ_FALSE;
    }

    pthread_mutex_lock(&ccq->hlock);

    qnode = ccq->ccq_head->next;

    if (ccq->ccq_head->next->next != ccq->ccq_head->next)
    {
	ccq->ccq_head->next = qnode->next;
        qnode->next->prev = ccq->ccq_head;

	qnode->prev = qnode->next = qnode;
    }
    else
    {
	ccq->ccq_head->next = qnode->prev;
	qnode->prev = qnode;
    }

    pthread_mutex_unlock(&ccq->hlock);
}

#endif /* __CC_QUEUE_H */
