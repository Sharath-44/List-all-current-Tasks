#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/task.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static void print_task(struct task_struct *task, int depth)
{
    struct task_struct *child_task;

    if (depth == 0) {
        printk(KERN_INFO "%s [%d] %ld\n", task->comm, task->pid, task->__state);
    } else {
        printk(KERN_INFO "|");
        for (int i = 1; i < depth; i++)
            printk(KERN_CONT "    |");
        printk(KERN_CONT "----");
        printk(KERN_CONT "> %s [%d] %ld\n", task->comm, task->pid, task->__state);
    }

    depth++;
    list_for_each_entry(child_task, &task->children, sibling)
        print_task(child_task, depth);
}

static int __init list_tasks_init(void)
{
    printk(KERN_INFO "List all current tasks:\n");
    print_task(&init_task, 0);
    return 0;
}

static void __exit list_tasks_exit(void)
{
    printk(KERN_INFO "Exiting list_tasks module.\n");
}

module_init(list_tasks_init);
module_exit(list_tasks_exit);

