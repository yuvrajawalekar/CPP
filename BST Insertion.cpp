
#include<iostream>
using namespace std;

template <class T>
class  TreeNode
{
   T  data;
   TreeNode<T> *left;
   TreeNode<T> *right;

    public:
    void SetData(T temp)
    {
     data = temp;
    }


    T GetData()
    {
     return data;
    }


    void SetLeft(TreeNode<T>* temp)
    {
     left = temp;
    }



    TreeNode<T>* GetLeft()
    {
     return left;
    }


    void SetRight(TreeNode<T>* temp)
    {
     right = temp;
    }



    TreeNode<T>* GetRight()
    {
     return right;
    }

};
template<class T>
class BST{
   private:
   TreeNode<T> *root;
   public:
   BST()
    {
        root = NULL;
    }
   ~BST()
    {
        Delete(root);
    }
public:
    void Delete(TreeNode<T>* temp)
{
  if (temp != NULL)
  {
	   Delete(temp->GetLeft());
	   Delete(temp->GetRight());
  }
  delete temp;
}


static void InOrder(TreeNode<T>* temp)
{
  if (temp != NULL)
  {
	   InOrder(temp->GetLeft());
	   cout<<temp->GetData()<<"\t";
	   InOrder(temp->GetRight());
  }
}


static void PreOrder(TreeNode<T>* temp)
{
  if (temp != NULL)
  {
	   cout<<temp->GetData()<<"\t";
	   PreOrder(temp->GetLeft());
	   PreOrder(temp->GetRight());
  }
}

static void PostOrder(TreeNode<T>* temp)
{
  if (temp != NULL)
  {
	   PostOrder(temp->GetLeft());
	   PostOrder(temp->GetRight());
	   cout<<temp->GetData()<<"\t";
  }
}
TreeNode<T>* GetRootNode()
{
	return root;

}

 void Insert(T iData)
 {
    TreeNode<T> *t  = new TreeNode<T>;
	t->SetLeft(NULL);
	t->SetData(iData);
	t->SetRight(NULL);

	if (root == NULL)
	{
		root = t;
	}
	else
	{
		TreeNode<T>* current = root;
		while (current != NULL)
		{
			if(iData == current->GetData())
			{
				throw runtime_error("Duplicate values");
			}
			if (iData < current->GetData())
			{
				// insert left
				if (current->GetLeft() == NULL)
				{
					current->SetLeft(t);
					return;
				}
				else
				{
					current = current->GetLeft();
				}

			}
			else
			{
				// insert right
				if (current->GetRight() == NULL)
				{
					current->SetRight(t);
					return;
				}
				else
				{
					current = current->GetRight();
				}
			}
		}
	}
}

bool Search(T val)
{
   TreeNode<T> *temp = root;

    while (temp != NULL)
    {
        if (val == temp->GetData())
	{
            return true;
        }
	else if (val < temp->GetData())
	{
            temp = temp->GetLeft();
        }
	else
	{
            temp = temp->GetRight();
        }
    }

    return false;
}



static TreeNode<T>* FindMin(TreeNode<T>* t)
{
	if(t == NULL || t->GetLeft() == NULL)
	{
		return t;
	}
	else
	{
		return FindMin(t->GetLeft());
	}
}



TreeNode<T>* FindMax(TreeNode<T>* t)
{
	if(t==NULL || t->GetRight()==NULL)
	{
		return t;
	}
	else
	{
		return FindMax(t->GetRight());
	}
}


int HeightOfTree(TreeNode<T>*  temp)
{
	int l = 0;
	int r = 0;

	if(temp == NULL)
	{
		return 0;
	}

	l = HeightOfTree(temp->GetLeft());
	r = HeightOfTree(temp->GetRight());
	if( l > r || l == r)
	{
		return (l + 1);
	}
	else
	{
		return (r + 1);
	}

}

};





int  main()
{
	int ch;
	int a;
	//char a;

	BST<int> objBST;
	//BST<char> objBST;


	do
	{
		cout<<"\n1. Insert"
		<<"\n2. InOrder"
		<<"\n3. PreOrder"
		<<"\n4. PostOrder"
		<<"\n5. Height"
		<<"\n6. Exit"
		<<"\n\nEnter Your Choice : ";
		cin>>ch;
		switch(ch)
		{

			case 1:
			cout<<"Enter an element : ";
			cin>>a;
                objBST.Insert(a);
			break;
			case 2:
                objBST.InOrder(objBST.GetRootNode());
			break;
			case 3:
                objBST.PreOrder(objBST.GetRootNode());
			break;
			case 4:
                objBST.PostOrder(objBST.GetRootNode());
			break;
			case 5:	{
			int height = objBST.HeightOfTree(objBST.GetRootNode());
			cout<<"Height of tree:"<<height<<endl;
				}
			break;
			default:cout<<"Invalid Choice";
		}
	}while(ch != 6);
}
