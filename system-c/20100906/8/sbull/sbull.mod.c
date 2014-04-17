#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__attribute_used__
__attribute__((section("__versions"))) = {
	{ 0xe189b8a7, "struct_module" },
	{ 0x89b301d4, "param_get_int" },
	{ 0x98bd6f46, "param_set_int" },
	{ 0x83e84bbe, "__mod_timer" },
	{ 0x7d11c268, "jiffies" },
	{ 0xee13fdc6, "check_disk_change" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0xc01b39cf, "bio_endio" },
	{ 0xada0da4b, "end_that_request_last" },
	{ 0xd6d8a159, "elv_dequeue_request" },
	{ 0x6b6cabd, "end_that_request_first" },
	{ 0x43b40de7, "kunmap_atomic" },
	{ 0x15fb4609, "kmap_atomic" },
	{ 0x5c7edc16, "end_request" },
	{ 0xebfb717d, "elv_next_request" },
	{ 0xc8be7b15, "_spin_lock" },
	{ 0xba7888df, "blk_queue_make_request" },
	{ 0xa8b5cd96, "blk_alloc_queue" },
	{ 0x679a54f2, "init_timer" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xe017dd92, "add_disk" },
	{ 0x25da070, "snprintf" },
	{ 0x4c6fdd55, "alloc_disk" },
	{ 0x368983c1, "blk_queue_hardsect_size" },
	{ 0xce56a2de, "blk_init_queue" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x71a50dbc, "register_blkdev" },
	{ 0x1b7d4074, "printk" },
	{ 0x37a0cba, "kfree" },
	{ 0xeac1c4af, "unregister_blkdev" },
	{ 0xa7299224, "blk_put_queue" },
	{ 0x20b98cab, "put_disk" },
	{ 0xbf0dc9ac, "del_gendisk" },
	{ 0xcda10c1, "del_timer_sync" },
	{ 0x2fd1d81c, "vfree" },
	{ 0x87a055d6, "blk_cleanup_queue" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E9A170A39FEF1A27BBD7607");
