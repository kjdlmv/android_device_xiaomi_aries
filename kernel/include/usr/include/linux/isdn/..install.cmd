cmd_/source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/usr/include/linux/isdn/.install := perl /source/aries-cm/kernel/xiaomi/aries/scripts/headers_install.pl /source/aries-cm/kernel/xiaomi/aries/include/linux/isdn /source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/usr/include/linux/isdn arm capicmd.h; perl /source/aries-cm/kernel/xiaomi/aries/scripts/headers_install.pl /source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/include/linux/isdn /source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/usr/include/linux/isdn arm ; perl /source/aries-cm/kernel/xiaomi/aries/scripts/headers_install.pl /source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/include/generated/linux/isdn /source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/usr/include/linux/isdn arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/usr/include/linux/isdn/$$F; done; touch /source/aries-cm/out/target/product/aries/obj/KERNEL_OBJ/usr/include/linux/isdn/.install
