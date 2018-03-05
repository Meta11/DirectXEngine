#pragma once

enum MyMenuChoice {
	Up    = 0x00000001,
	Down  = 0x00000002,
	Left  = 0x00000004,
	Right = 0x00000008,
	Shoot = 0x00000016,
	Bomb  = 0x00000032,
	Focus = 0x00000064,
	Pause = 0x00000128,
	MAX   = 0x00000256
};
