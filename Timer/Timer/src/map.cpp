#include "map.h"
#include <Windows.h>

//绘制初始地图
void Map::PrintInitmap()
{
	for (auto& point : initmap)
	{
		point.Print();
		//调用Sleep函数可营造动画效果
		Sleep(10);
	}
}