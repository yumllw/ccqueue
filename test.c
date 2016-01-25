/*************************************************************************
 *    		>       File Name: sample.c
 *    		>          Author: wpz
 *    		>      E-mail: yumllw@qq.com 
 *    		> Created Time: 2016年01月25日 星期一 10时33分45秒
 ************************************************************************/
#include <stdio.h>

#include "ccqueue.h"

struct student
{
    char *name;
    int age;
    char *sex;

    struct gen_list ghook;
};

struct cc_queue mqueue;

int main(void)
{
    cc_queue_init(&mqueue);

    struct student a, b, c, d;
    a.name = "张三";
    a.age  = 19;
    a.sex  = "男";

    init_gen_list(&a.ghook);

    b.name = "李四";
    b.age  = 20;
    b.sex  = "男";
    init_gen_list(&b.ghook);

    c.name = "王五";
    c.age  = 21;
    c.sex  = "男";
    init_gen_list(&c.ghook);

    d.name = "赵六";
    d.age  = 22;
    d.sex  = "男";
    init_gen_list(&d.ghook);

    cc_queue_enqueue(&mqueue, &a.ghook);
    cc_queue_enqueue(&mqueue, &b.ghook);
    cc_queue_enqueue(&mqueue, &c.ghook);
    cc_queue_enqueue(&mqueue, &d.ghook);

    return 0;
}
