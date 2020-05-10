#include <list>
#include <string>
#include "test_runner.h"
using namespace std;

class Editor {
 public:
  // Реализуйте конструктор по умолчанию и объявленные методы
  Editor(){}
  void Left();
  void Right();
  void Insert(char token);
  void Cut(size_t tokens = 1);
  void Copy(size_t tokens = 1);
  void Paste();
  string GetText() const;

private:
	list<char> str;
	list<char> buffer;
	list<char>::iterator cursor = str.end();

	list<char>::iterator Previous(list<char>::iterator cursor)
	{
		if (cursor == str.begin())
			return str.begin();
		return --cursor;
	}
};

void Editor::Left() {
	if (cursor != str.begin()) {
		--cursor;
	}
}

void Editor::Right() {
	if (cursor != str.end()) {
		++cursor;
	}
}

void Editor::Insert(char token)
{
	str.emplace(cursor, token);
}

void Editor::Cut(size_t tokens)
{
	Copy(tokens);
	if (cursor != str.end()) {
		auto last = cursor;
		for (size_t i = 0; i < tokens; ++i) {
			if (last == str.end())
				break;
			++last;
		}		
		str.erase(cursor, last);
		cursor = last;
	}
}
void Editor::Copy(size_t tokens)
{
	if (cursor != str.end()) {
		buffer.clear();
		auto last = cursor;
		for (size_t i = 0; i < tokens; ++i) {
			if (last == str.end())
				break;
			++last;
		}
		copy(cursor, last, back_inserter(buffer));
	}
}
void Editor::Paste()
{
	for (auto& item : buffer)
		Insert(item);
}
string Editor::GetText() const
{
	string data;
	copy(str.begin(), str.end(), back_inserter(data));
	return data;
}

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}