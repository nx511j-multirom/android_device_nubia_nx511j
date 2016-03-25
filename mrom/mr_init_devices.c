#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
	// Framebuffer
	"/sys/class/graphics/fb0",

	// ADB stuff
	//------------------adb not working ------------//
	"/sys/bus/usb",
	"/sys/class/android_usb/android0/f_adb",
	"/sys/class/misc/android_adb",
	"/dev/usb-ffs/adb",
	//------------------------------------//
	"/sys/class/tty/ptmx",
	"/sys/devices/virtual/tty/tty",
	"/sys/devices/virtual/tty/ptmx",
	
	// EMMC stuff
	"/sys/block/mmcblk0",
	"/sys/bus/mmc",
	"/sys/bus/mmc/drivers/mmcblk",
	"/sys/devices/platform/msm_hotplug/driver",
	"/sys/module/mmcblk",
	"/sys/module/mmc_core",
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0",
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001",
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0",
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p19", // boot
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p24", // cache
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p1",  // modem
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p23", // persist
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p22", // system
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p30", // userdata
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p26", // keystore
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p27", // config 
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p6",  // ssd 
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p4",  // sec
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p15", // hyp
	"/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0//mmc0:0001/block/mmcblk0/mmcblk0p25", // misc 
	

	// Input stuff
    	"/sys/class/misc/uinput",
	"/sys/devices/virtual/misc/uinput",
	//"/sys/class/input*",

	// Input stuff

	"/sys/devices/soc.0/78b6000.i2c/i2c-0/0-006a/input",// Touchscreen
	"/sys/devices/soc.0/78b6000.i2c/i2c-0/0-006a/input/input0",
	"/sys/devices/soc.0/78b6000.i2c/i2c-0/0-006a/input/input0/event0",
	
	"/sys/devices/soc.0/gpio_keys.66/input",
	"/sys/devices/soc.0/gpio_keys.66/input/input7",   // Volume keys
	"/sys/devices/soc.0/gpio_keys.66/input/input7/event7",
/*
evtest /dev/input/event6                                                                                       
Input driver version is 1.0.1
Input device ID: bus 0x0 vendor 0x0 product 0x0 version 0x0
Input device name: "qpnp_pon"
Supported events:
  Event type 0 (Reset)
    Event code 0 (Reset)
    Event code 1 (Key)
  Event type 1 (Key)
    Event code 116 (Power)
*/
	"/sys/devices/virtual/input",
	"/sys/devices/virtual/input/input6", 
	"/sys/devices/virtual/input/input6/event6", 
	

/*
evtest /dev/input/event8

    Event code 63 (F5)
    Event code 64 (F6)
    Event code 65 (F7)
    Event code 66 (F8)
    Event code 67 (F9)
    Event code 116 (Power)
    Event code 139 (Menu)
    Event code 158 (Back)
    Event code 172 (HomePage)
    Event code 330 (Touch)

*/
	"/sys/devices/virtual/input",
	"/sys/devices/virtual/input/input8", // Touch Screen
	"/sys/devices/virtual/input/input8/event8",


 	NULL
};
