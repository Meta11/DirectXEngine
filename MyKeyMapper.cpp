#include <Windows.h>
#include "MyKeyMapper.h"
#include "MyMenuChoice.h"
#include "TypeDefs.h"

int MyKeyMapper::getKeyFor(int action) const
{
	switch (action)
	{
	case Up:
		return VK_UP;
	case Down:
		return VK_DOWN;
	case Left:
		return VK_LEFT;
	case Right:
		return VK_RIGHT;
	case Shoot:
		return VK_Z;
	case Bomb:
		return VK_X;
	case Focus:
		return VK_SHIFT;
	case Pause:
		return VK_RETURN;
	}

	return -1;
}