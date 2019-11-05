#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x2c122b9f, "module_layout" },
	{ 0x658d6c04, "single_release" },
	{ 0x45a0eada, "seq_read" },
	{ 0x6d526f5e, "seq_lseek" },
	{ 0xf2c62f80, "remove_proc_entry" },
	{ 0x2d548080, "proc_create_data" },
	{ 0xf24403d5, "proc_mkdir" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xdcb764ad, "memset" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x84bc974b, "__arch_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x93fca811, "__get_free_pages" },
	{ 0xb4a41ed, "seq_printf" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x5498dcad, "single_open" },
	{ 0x72ed3810, "PDE_DATA" },
	{ 0x1fdc7df2, "_mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "BF493F5777FE052FD2F4AD1");
MODULE_INFO(rhelversion, "8.0");
