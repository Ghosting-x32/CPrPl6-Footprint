#pragma once

#include<string>
#include<cstddef>


using std::string;


class Screen
{

public:

	using pos = string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c);

	char get() const
	{
		return contents[cursor];
	}

	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);

	void some_member()const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	mutable size_t access_ctr = 0;





};




char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];

}


inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;

}