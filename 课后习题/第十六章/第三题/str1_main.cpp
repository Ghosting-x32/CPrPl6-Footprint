#include<iostream>
#include<string>
#include<random>
#include<cctype>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

//const int NUM = 26;
//const string wordlist[NUM] =
//{
//	"apiary", "beetle", "cereal", "danger", "ensign", "florid","garage", "health", "insult", "jackal",
//	"keeper", "loaner", "manage", "nonce", "onset", "plaid", "quilt", "remote", "stolid", "train", 
//	"useful", "valid", "whence", "xenon", "yearn", "zippy"
//};

void show(const string& st);

int main()
{
	vector<string> wordlist;
	string temp11;
	ifstream ifs1;
	ifs1.open("wordlist.txt", ios::in);
	if (!ifs1.is_open())//文件不存在
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		return 0;
	}

	char ch11;//文件数据为空
	ifs1 >> ch11;
	if (ifs1.eof())
	{
		cout << "文件数据为空！" << endl;
		system("pause");
		return 0;
	}

	ifs1.putback(ch11);//文件有数据，把之前读走的一个字符读回来

	while (ifs1 >> temp11)//&&!ifs1.eof()
	{
		//cout << temp11 << endl;
		wordlist.push_back(temp11);
	}
	//cout << wordlist.size() << endl;
	for_each(wordlist.begin(), wordlist.end(), show);
	cout << endl;

	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);//大写转小写函数位于cctype头文件里面
	while (play == 'y')
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis1(0, 25);

		string target = wordlist[dis1(gen)];//单词列表中随机取一个单词
		int length = target.length();
		string attempt(length, '-');//更新猜对的字符替换占位符
		string badchars;//储存猜错的字符
		int guesses = 6;//只有6次机会猜错

		cout << "Guess my secret word. It has " << length << " letters, and you guess\n";
		cout << "one letter at a time. You get " << guesses << " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;

		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;

			//检测保证猜过的字符不重复猜
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that.Try again.\n";
				continue;
			}

			int loc = target.find(letter);//猜错
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter;

			}
			else//猜对
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);

				while (loc != string::npos)//继续寻找该字符在这个单词中是否还继续出现
				{
					attempt[loc] = letter;

					loc = target.find(letter, loc + 1);

				}

			}

			cout << "Your word: " << attempt << endl;

			if (attempt != target)
			{
				if (badchars.length() > 0)
				{
					cout << "Bad choices: " << badchars << endl;
				}
				cout << guesses << " bad guesses left\n";

			}



		}

		if (guesses > 0)
		{
			cout << "That's right!\n";
		}
		else
		{
			cout << "Sorry, the word is " << target << ".\n";

		}

		system("pause");
		system("cls");

		cout << "Will you play a word game? <y/n> ";
		cin >> play;
		play = tolower(play);

	}



	ifs1.close();

	system("pause");
	return 0;
}


void show(const string& st)
{
	cout << st << " ";

}