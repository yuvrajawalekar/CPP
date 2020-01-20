
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

template <class T>
class LinkedList
{
	private:int count = 0;
		Node<T>* head;
		Node<T>* tail;
	public:
		LinkedList():head(nullptr),tail(nullptr){}
		bool IsFull()
		{
			return false;

		}
		bool IsEmpty()
		{
			return (head == nullptr && tail==nullptr);
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
		void DelFromEND()
		{
		    if(IsEmpty())
            {
                cout<<"\nLinked List is Empty!";
            }
		    else
            {
                Node<T>* temp=head;
                T ele=tail->GetData();
                if(head->GetNext()==nullptr && tail->GetNext()==nullptr)
                {
                    delete tail;
                    head=nullptr;
                    tail=nullptr;
                    cout<<"\nElement deleted at last position is: "<<ele<<endl;
                }
                else
                {
                    while(temp->GetNext()!=tail)
                    {
                        temp=temp->GetNext();
                    }

                    tail->SetNext(nullptr);
                    delete tail;
                    temp->SetNext(nullptr);
                    tail=temp;
                    count--;
                    cout<<"\nElement deleted at last position is: "<<ele<<endl;
                }


            }

		}
		void DelFromBegin()
		{

		    if(IsEmpty())
            {
                cout<<"\nLinked List is Empty!";
            }
            else if(head->GetNext()==nullptr && tail->GetNext()==nullptr)
                {
                    T ele=head->GetData();
                    delete head;
                    head=nullptr;
                    tail=nullptr;
                    cout<<"\nElement deleted at first position is: "<<ele<<endl;
                }
            else
            {
                T ele=head->GetData();
                Node<T>* temp=head;
                head=head->GetNext();
                delete temp;
                count--;
                 cout<<"\nElement at deleted first position is: "<<ele<<endl;
            }


		}
		void Reverse()
		{
		    if(IsEmpty())
            {
                cout<<"\nLinked List is Empty!";
            }
            else
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

                         cout<<"\nLinked List is Reversed";

            }

		}
		bool Insertion(int pos, T ele)
		{
			bool bsuccess=false;
			Node<T>* p=head,*q= head->GetNext();

			if(pos == 1)
            {
                Node<T>* temp=new Node<T>;
				temp->SetData(ele);
				temp->SetNext(head);
                head = temp;
                bsuccess=true;
            }

			else if((pos-2)>=0)
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
		void Deletion(int pos)
		{
		    if(IsEmpty())
            {
                cout<<"\nLinked List is Empty!";
            }
            else
            {
                Node<T>* p=head, *q=head->GetNext();
                int i=0;
                T ele;

               if(pos == 1)
                {
                    ele=p->GetData();
                    head = head->GetNext();
                    p->SetNext(nullptr);
                    delete p;
                    cout<<"Element deleted at position "<<pos<<" is: "<<ele<<endl;
                }
                else
                    {
                    while(i!=(pos-2))
                    {
                        p=p->GetNext();
                        q=q->GetNext();
                        i++;
                    }
                    p->SetNext(q->GetNext());
                    ele=q->GetData();
                    q->SetNext(nullptr);
                    delete q;
                    cout<<"Element deleted at position "<<pos<<" is: "<<ele<<endl;

                }


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
		     if(IsEmpty())
            {
                cout<<"\nLinked List is Empty!";
            }
		    else
            {
                Node<T> *temp=head;
                cout<<"\n";
                while(temp!=nullptr)
                {
                    cout<<temp->GetData()<<"-->";
                    temp=temp->GetNext();
                }
		        cout<<"NULL POINTER"<<endl;
		    }

		}
};
		int main()
		{
			LinkedList <int> ll;
			LinkedList <float> l2;
			int n;
			do
			{
				cout<<"\n ENTER the choice."<<endl;
				cout<<"\n1.Add at END";
				cout<<"\n2.Add at Begin";
				cout<<"\n3.Delete from END";
				cout<<"\n4.Delete from Beginning";
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
						  ll.DelFromEND();
						break;
					       }
					case 4: {
						  ll.DelFromBegin();
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
							ll.Deletion(pos);
						break;}
					case 8:ll.Display();
						//ll.Floyd();
					       break;
					case 9:
						break;
					default: cout<<"\nInvalid Choice."<<endl;
				}

			}while(n!=9);

			return 0;
		}
