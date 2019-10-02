#include<iostream>
#include"Node.cpp"
using namespace std;
template<class T>
class Clist
{
	private: Node<T>* head;
		 Node<T>* tail;
		 int count;
	public:
		 Clist():head(NULL),tail(NULL),count(0){}
		 bool IsEmpty()
		 {
			 return (head==NULL&&tail==NULL);
		 }
		 void AddAtEnd(T ele)
		 {
			 Node<T>* temp=new Node<T>;
			 temp->SetData(ele);
			 if(IsEmpty())
			 {
				 temp->SetNext(temp);
				 head=temp;
				 tail=temp;
				 count++;

			 }
			 else
			 {
			 tail->SetNext(temp);
			 temp->SetNext(head);
			 tail=temp;
			 count++;	
			 }
		 }
		 void  AddAtBegin(T ele)
		{
			Node<T>* temp=new Node<T>;
			temp->SetData(ele);
			if(IsEmpty())
			{
				temp->SetNext(temp);
				head=tail=temp;
			}

			else
			{
			temp->SetNext(head);
			tail->SetNext(temp);
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

			temp->SetNext(head);
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
			tail->SetNext(head);
			delete temp;
			return ele;
			count--;

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
			Node<T>* p=head, *q=p->GetNext();
			int i=0,ele;
			if(count>=pos)
			{
				while(i!=pos-2)
				{
					p=p->GetNext();
					q=q->GetNext();
					i++;
				}
				ele=q->GetData();
				p->SetNext(q->GetNext());
				delete q;
				return ele;

			}

		}



		void Display()
		{
			Node<T> *temp=head;
			cout<<"\n";
			while(temp!=tail)
			{
				cout<<temp->GetData()<<"-->";
				temp=temp->GetNext();
			}
			cout<<temp->GetData()<<"-->";
		        cout<<"END OF CIRCULAR LIST"<<endl;
		}
};
		int main()
		{
			Clist <int> ll;
			int n;
			do
			{
				cout<<"\n ENTER the choice."<<endl;
				cout<<"\n1.Add at END";
				cout<<"\n2.Add at Begin";
				cout<<"\n3.Delete from END";
				cout<<"\n4.Delete from Begining";
				cout<<"\n5.Identify Loop in the list";
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
							ll.Floyd();
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
					       break;
					case 9:
						break;
					default: cout<<"\nInvalid Choice."<<endl;
				}

			}while(n!=9);

}
