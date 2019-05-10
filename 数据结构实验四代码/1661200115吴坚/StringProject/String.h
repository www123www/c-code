#pragma once
class String
{
public:
	String() {};
	~String() {};
	String SubString(int pos, int num);
	void Insert(String t, int pos);
	void Delete(int pos, int num);
	void Creat();
	void Display();
private:
	char *str;
	int size;
};