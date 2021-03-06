#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "display_ss.h"
#include "input_ss.h"
#include "encoding_ss.h"
#include "picfmt_ss.h"
#include "compile_time.h"

int main(int argc, char *argv[])
{
	printf("DPF version 1.0 %s\n", COMPILE_DATE);
	if (argc != 2)
	{
		printf("Usage:\n");
		printf("%s <freetype_file>\n", argv[0]);
		return 0;
	}

	/* 注册显示设备 */
	DisplayInit();

	/* 可能支持多个显示设备: 选择和初始化指定的显示设备 */
	SelectAndInitDefaultDispDev("fb");
	DisplayModuleInit();
	ShowDispModules();

	/*
	 * VideoMem: 为加快显示速度,我们事先在内存中构造好显示的页面的数据,
	             (这个内存称为VideoMem)
	 *           显示时再把VideoMem中的数据复制到设备的显存上
	 * 参数的含义就是分配的多少个VideoMem
	 * 参数可取为0, 这意味着所有的显示数据都是在显示时再现场生成,然后写入显存
	 */
	AllocVideoMem(5);

    /* 注册输入设备 */
	InputInit();
	ShowInputModules();

    /* 调用所有输入设备的初始化函数 */
	AllInputDevicesInit();

    /* 注册字库模块 */
	FontsInit();
	ShowFontModules();

    /* 注册编码模块 */
    EncodingInit();
	ShowEncodingModules();

    /* 设置freetype字库所用的文件和字体尺寸 */
	SetFontsDetail("freetype", argv[1], 24);

    /* 注册图片文件解析模块 */
    PicFmtsInit();
	ShowPicFmts();

    /* 注册页面 */
	PagesInit();
	ShowPageModules();

    /* 运行主页面 */
	RunPage("main", NULL);

	return 0;
}
