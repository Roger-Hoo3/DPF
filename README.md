# digital photo frame(DPF)

环境变量设置

	/dev/event0    对应的是触摸屏
	/dev/fb0	   对应的是LCD
	export TSLIB_TSDEVICE=/dev/event0
	export TSLIB_CALIBFILE=/etc/pointercal
	export TSLIB_CONFFILE=/etc/ts.conf
	export TSLIB_PLUGINDIR=/lib/ts
	export TSLIB_CONSOLEDEVICE=none
	export TSLIB_FBDEVICE=/dev/fb0
