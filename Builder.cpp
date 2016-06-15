/*
Name
		Builder Pattern

Definition(Not Formal but easy to understand) -
		This pattern is used to create complex objects.
		When the object is complex the creation of object should be a generic process that can be reused.
		This helps to create different versions of the complex object easily.

Problem
		Want to build a RTF (Rich Text format) reader which can convert text to various document formats
		Ex: XML, ASCII, HTML
		New document formats can be added in future.
		How to create the RTF reader so that it can handle this in a generic manner?
*/
#include <iostream>
#include <string.h>
using namespace std;

//Abstract builder class
class TextBuilder{
public:
	//Taking string for example purpose in real case character wise parsing should be done 
	virtual void ConvertChar(string &c)= 0;
	virtual void ConvertFont(string &c)= 0;
};

//Concrete builder class
class ASCIIBuilder :public TextBuilder {
public:
	void ConvertChar(string &c) {
		cout <<"Inside ConvertChar in ASCIIBuilder: " <<  "ASCII  string - " << c << endl;
	}
	void ConvertFont(string &c) {
		cout <<"Inside ConvertFont in ASCIIBuilder: " <<  "ASCII string  - " << c << endl;
	}

};

//Concrete builder class
class XMLBuilder : public TextBuilder {
public:
	void ConvertChar(string &c) {
		cout <<"Inside ConvertChar in XMLBuilder: " <<  "XML string - " << c << endl;
	}
	void ConvertFont(string &c) {
		cout <<"Inside ConvertFont in XMLBuilder: " <<  "XML string - " << c << endl;
	}

};

// Some people call it Director class
class RTFReader{
	private:
		TextBuilder *__builder;
	public:
		RTFReader(TextBuilder *builder) {
			__builder = builder;
		}
		void ParseRTF(string inpdata) {
			__builder->ConvertChar(inpdata);
			__builder->ConvertFont(inpdata);
		}
		~RTFReader() {
				delete __builder;
		}
};



int main() {
	RTFReader areader(new ASCIIBuilder());
	RTFReader xreader(new XMLBuilder());

	areader.ParseRTF("test");
	xreader.ParseRTF("test");

	return 0;
}
