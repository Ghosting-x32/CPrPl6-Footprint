#pragma once
#include<vector>
#include<string>

#include"Screen.h"

class Screen;

using std::vector;
using std::string;


class Window_mgr
{
public:

	using ScreenIndex = vector<Screen> ::size_type;


	void clear(ScreenIndex i);

	ScreenIndex addScreen(const Screen& s);


private:

	vector<Screen> screens{ Screen(24, 80, ' ') };
	







};
