obj-m += syscall-replace-module.o

all:
	make -C /lib/modules/4.19.13/build M=$(PWD) modules
clean:
	make -C /lib/modules/4.19.13/build M=$(PWD) clean
