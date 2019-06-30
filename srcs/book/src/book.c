#include<linux/init.h>
#include<linux/module.h>

static char *book_name = "Dissecting Linux Device Driver";
module_param(book_name, charp, S_IRUGO);

static int book_num = 4000;
module_param(book_num, int, S_IRUGO);

static int __init book_init(void)
{

	printk(KERN_INFO "Book name is %s\n",book_name);
	printk(KERN_INFO "Book number is %d\n",book_num);
	return 0;
}

static void __exit book_exit(void)
{

	printk(KERN_INFO "Book Module exit\n");
}	

module_init(book_init);
module_exit(book_exit);

MODULE_AUTHOR("Jack Ma <majian699@163.com>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple parameter Test Module");
MODULE_ALIAS("A Book module");
MODULE_VERSION("V1.0");
