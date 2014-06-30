
SUBDIRS =  scull 

#KERNELDIR = /buildarea1/jwang6/qumu_x86_prj/bitbake_build/tmp/work/qemux86_64-wrs-linux/linux-windriver-3.4-r0/linux/

#SUBDIRS =  misc-progs misc-modules \
           skull scull scullc sculld scullp scullv sbull snull\
	   short shortprint pci simple usb tty lddbus
all: subdirs

subdirs:
	@echo  "Main $(KERNELDIR)"
	for n in $(SUBDIRS); do $(MAKE) -C $$n || exit 1; done

clean:
	for n in $(SUBDIRS); do $(MAKE) -C $$n clean; done
