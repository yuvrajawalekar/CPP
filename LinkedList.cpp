#include"Node.cpp"
#include<iostream>
#include<string>
using namespace std;
template <class T>
class LinkedList
{
	private:int count; 
		Node<T>* head;
		Node<T>* tail;
	public:
		LinkedList():count(0), head(nullptr),tail(nullptr){}
		bool IsFull()
		{
			return false;

		}
		bool IsEmpty()
		{
			return (nullptr==head&&nullptr==tail);
		}
		void AddAtEnd(T ele)
		{
			Node<T>* temp=new Node<T>;
			temp->SetData(ele);
			if(IsEmpty())
			{
				temp->SetNext(nullptr);
				head=tail=temp;
			}
			else
			{
				temp->SetNext(nullptr);
				tail->SetNext(temp);
				tail=temp;
			}
			count ++;


		}
		void  AddAtBegin(T ele)
		{
			Node<T>* temp=new Node<T>;
			temp->SetData(ele);
			if(IsEmpty())
			{
				temp->SetNext(nullptr);
				head=tail=temp;
			}
		
			else
			{
			temp->SetNext(head);
			head=temp;
			}
			count++;
		}
		T DelFromEND()
		{
			Node<T>* temp=head;
			T ele=tail->GetData();
			while(temp->GetNext()!=tail)
			{	temp=temp->GetNext();
			}

			tail->SetNext(nullptr);
			delete tail;
			tail=temp;
			return ele;
			count--;
		}
		T DelFromBegin()
		{
			T ele=head->GetData();
			Node<T>* temp=head;
			head=head->GetNext();
			delete temp;
			return ele;
			count--;

		}
		void Reverse()
		{
			Node<T> *nhead = head,*t=NULL;
                        head = head->GetNext();
                        nhead->SetNext(NULL);
                        tail = nhead;

                        while(head != NULL)
                        {
                          t= head;
                          head = head->GetNext();
                          t->SetNext(nhead);
                          nhead =t;
                        }
                         head = nhead;

		}
		bool Insertion(int pos, T ele)
		{
			bool bsuccess=false;
			Node<T>* p=head,*q= head->GetNext();
			if(count>=pos-1)
			{
				for(int i=0;i!=(pos-2);i++)
				{
					p=p->GetNext();
					q=q->GetNext();

				}
				Node<T>* temp=new Node<T>;
				temp->SetData(ele);
				temp->SetNext(q);
				p->SetNext(temp);
				bsuccess=true;
			}
			count++;
			return bsuccess;


		}
		T Deletion(int pos)
		{
			Node<T>* p=head, *q=head->GetNext();
			int i=0,ele;
			if(count>=pos)
			{
				while(i!=pos-1)
				{
					p=p->GetNext();
					q=q->GetNext();
					i++;
				}
				head->SetNext(q);
				ele=p->GetData();
				p->SetNext(nullptr);
				delete p;
				return ele;

			}

		}
		void Floyd()
		{
			Node<T>* slow=head;
			Node<T>* fast=head;
			while(slow!=NULL&&fast!=NULL&&fast->GetNext()!=NULL)
			{
				slow=slow->GetNext();
				fast=fast->GetNext()->GetNext();
				
				if(slow==fast)
				{
					cout<<"\nLoop Exists."<<endl;
					return;
				}
			}
                        cout<<"\nLoop doesn't exists."<<endl;

		}



		void Display()
		{
			Node<T> *temp=head;
			cout<<"\n";
			while(nullptr !=temp)
			{
				cout<<temp->GetData()<<"-->";
				temp=temp->GetNext();
			}
		        cout<<"NULL POINTER"<<endl;
		}
};
		int main()
		{
			LinkedList <int> ll;
			int n;
			do
			{
				cout<<"\n ENTER the choice."<<endl;
				cout<<"\n1.Add at END";
				cout<<"\n2.Add at Begin";
				cout<<"\n3.Delete from END";
				cout<<"\n4.Delete from Begining";
				cout<<"\n5.Reverse the LinkedList";
				cout<<"\n6.Insert node at position";
				cout<<"\n7.Delete node at position";
				cout<<"\n8.Display the LinkedList";
				cout<<"\n9.EXIT"<<endl;
				cin>>n;
				switch(n)
				{
					case 1:{
						  int i;
						  cout<<"\nEnter element to add at the end: ";
						  cin>>i;
						  ll.AddAtEnd(i); 
						break;
					       }
					case 2:{ 
						  int i;
						  cout<<"\nEnter element to add at the Begin: ";
						  cin>>i;
						  ll.AddAtBegin(i); 
						break;
					       }
					case 3:{ 
						  cout<<"\nDeleted element from end: "<<ll.DelFromEND()<<endl;
						break;
					       }
					case 4: {
						  cout<<"\nDeleted element from Begining: "<<ll.DelFromBegin()<<endl;
						break;}
					case 5: {
							ll.Reverse();
						break;}
					case 6: {
							int pos; int ele;
							cout<<"\nEnter position: "<<endl;
							cin>>pos;
							cout<<"\nEnter element: "<<endl;
							cin>>ele;
							ll.Insertion(pos,ele);
						break;}
					case 7:{
							int pos;
							cout<<"\nEnter position: "<<endl;
							cin>>pos;
							cout<<"\nElement deleted is "<<ll.Deletion(pos);
						break;}
					case 8:ll.Display();
						ll.Floyd();
					       break;
					case 9: 
						break;
					default: cout<<"\nInvalid Choice."<<endl;
				}

			}while(n!=9);

			return 0;
		}
