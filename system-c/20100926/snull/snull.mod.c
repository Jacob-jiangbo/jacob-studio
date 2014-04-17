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
};

static const struct modversion_info ____versions[]
__attribute_used__
__attribute__((section("__versions"))) = {
	{ 0x30c5d25f, "struct_module" },
	{ 0x89b301d4, "param_get_int" },
	{ 0x98bd6f46, "param_set_int" },
	{ 0xc3fe6db4, "__spin_lock_init" },
	{ 0x80462479, "ether_setup" },
	{ 0x521445b, "list_del" },
	{ 0xf479665c, "netif_receive_skb" },
	{ 0x7d11c268, "jiffies" },
	{ 0xac4dca9f, "__netif_rx_schedule" },
	{ 0x69900829, "_spin_unlock" },
	{ 0x7ea2c004, "kfree_skb" },
	{ 0xc88c7ada, "_spin_lock" },
	{ 0x158e436c, "skb_under_panic" },
	{ 0xb6dcbd1c, "kmem_cache_alloc" },
	{ 0x947430b8, "malloc_sizes" },
	{ 0x602a308b, "register_netdev" },
	{ 0xba154599, "alloc_netdev" },
	{ 0x4a814c5f, "free_netdev" },
	{ 0x2cb6e470, "unregister_netdev" },
	{ 0x37a0cba, "kfree" },
	{ 0x4edaae97, "netif_rx" },
	{ 0xa353b8a, "eth_type_trans" },
	{ 0xf4d17791, "skb_over_panic" },
	{ 0xa13798f8, "printk_ratelimit" },
	{ 0x9d1bc11c, "__alloc_skb" },
	{ 0xfcb902e, "__netif_schedule" },
	{ 0xe49e22e1, "_spin_unlock_irqrestore" },
	{ 0x9d75ed43, "_spin_lock_irqsave" },
	{ 0x1902adf, "netpoll_trap" },
	{ 0x1b7d4074, "printk" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "87EA34D2054898CD73680A1");
