#pragma once
#include "IKeyMapper.h"

class MyKeyMapper : public IKeyMapper {
public:
	int getKeyFor(int action) const;
};
