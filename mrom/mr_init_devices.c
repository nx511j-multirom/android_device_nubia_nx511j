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
	"/sys/bus/usb",
	"/sys/class/android_usb/android0/f_adb",
	"/sys/class/misc/android_adb",
	"/dev/usb-ffs/adb",
	"/sys/class/tty/ptmx",
	
	// EMMC stuff
	"/sys/block/mmcblk0",
	"/sys/bus/mmc",
	"/sys/bus/mmc/drivers/mmcblk",

	//"/sys/bus/sdio/drivers/bcmsdh_sdmmc",
	"/sys/devices/platform/msm_hotplug/driver",
	//"/sys/devices/platform/msm_sdcc.1*",
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
	
	// MicroSD card
	//"/sys/block/mmcblk1",
	//"/sys/devices/platform/msm_sdcc.2*",

	// Input stuff
    	"/sys/class/misc/uinput",
	"/sys/devices/virtual/misc/uinput",
	"/sys/class/input*",

	// Input stuff

	"/sys/devices/soc.0/78b6000.i2c/i2c-0/0-006a/input",// Touchscreen
	"/sys/devices/soc.0/78b6000.i2c/i2c-0/0-006a/input/input0*",// Touchscreen
	
	"/sys/devices/soc.0/gpio_keys.66/input/input7",// Volume keys

	//"/sys/devices/i2c-3/3-0020/input/input3*", // Touchscreen
	"/sys/devices/platform/gpio-keys/input*", // Volume keys

	/*
	"/sys/devices/soc.0/gpio_keys.66",

	"/sys/devices/soc.0/gpio_keys.66/input/input7",// Volume keys

	//"/sys/devices/i2c-3/3-0020/input/input3*", // Touchscreen
	"/sys/devices/platform/gpio-keys/input*", // Volume keys
	*/
	//"/sys/devices/platform/msm_ssbi.0/pm8921-core/pm8xxx-pwrkey/input*", // Power key

	//"/sys/bus/platform/drivers/gpio-keys",
	"/sys/bus/platform/drivers/gpio-keys/gpio_keys.66/input*",
	/*
	"/sys/bus/spmi/drivers/qcom,qpnp-vibrator",
	"/sys/bus/spmi/drivers/qcom,qpnp-vadc",
	"/sys/bus/spmi/drivers/qcom,leds-qpnp",
	"/sys/bus/spmi/drivers/qcom,qpnp-power-on",
	"/sys/bus/spmi/drivers/qcom,qpnp-pin",
	"/sys/bus/spmi/devices/qpnp-vadc-ffffffc0743a3400",
	"/sys/bus/spmi/devices/qpnp-pin-ffffffc0743a2800",
	"/sys/bus/spmi/devices/qpnp-pin-ffffffc0743a2c00",
	"/sys/bus/spmi/devices/qpnp-pwm-ffffffc0743a5000",


	"/sys/devices/soc.0/leds-qpnp-ffffffc0743a4800",
	"/sys/devices/soc.0/qpnp-pin-ffffffc0743a2c00",
	"/sys/devices/soc.0/qpnp-pin-ffffffc0743a2800",
	"/sys/devices/soc.0/qpnp-power-on-ffffffc0743a2400",
	"/sys/devices/soc.0/qpnp-vadc-ffffffc0743a3400",
	"/sys/devices/soc.0/leds-qpnp-ffffffc0743a4800",
	"/sys/devices/soc.0/qpnp-vibrator-ffffffc0743a5400",
	"/sys/devices/soc.0/qpnp-linear-charger-ffffffc0743a4000",
	"/sys/bus/spmi/drivers/qcom,qpnp-vadc",
	*/

	//virtual
	//"/sys/devices/virtual/tty*",
	"/sys/devices/virtual/tty/tty",
	"/sys/devices/virtual/tty/ptmx",
	//"/sys/devices/virtual/input*",

 	NULL
};
