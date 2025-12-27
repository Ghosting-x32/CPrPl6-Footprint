#pragma once

#include<string>
#include<iostream>
#include<cstddef>


using std::string;


class Screen
{

public:

	using pos = string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c);
	Screen(pos ht, pos wd);


	char get() const
	{
		return contents[cursor];
	}

	inline char get(pos ht, pos wd) const;
	//Screen& move(pos r, pos c);
	Screen move(pos r, pos c);

	void some_member()const;


	//Screen& set(char c);
	Screen set(char c);
	Screen& set(pos r, pos col, char ch);

	//Screen& display(std::ostream& os)
	//{
	//	do_display(os);

	//	return *this;
	//}

	Screen display(std::ostream& os)
	{
		do_display(os);

		return *this;
	}

	const Screen& display(std::ostream& os) const
	{
		do_display(os);

		return *this;
	}





private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	mutable size_t access_ctr = 0;

	void do_display(std::ostream& os) const
	{
		os << contents;
	}



};




char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];

}


//inline
//Screen& Screen::move(pos r, pos c)
//{
//	pos row = r * width;
//	cursor = row + c;
//	return *this;
//
//}

inline
Screen Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;

}



//inline Screen& Screen::set(char c)
//{
//	contents[cursor] = c;
//
//	return *this;
//}

inline Screen Screen::set(char c)
{
	contents[cursor] = c;

	return *this;
}


inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;

	return *this;
}