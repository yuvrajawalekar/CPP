#include<iostream>
#include<string>
using namespace std;
template<class T>
class Node
{
	private:
		T data;
		Node *Next;
	public:
		T GetData()
		{
			return data;
		}
		void SetData(T ele)
		{
			data=ele;
		}
		void SetNext(Node* temp)
		{
		Next=temp;
		}
		Node* GetNext()
		{
			return Next;
		}
};
