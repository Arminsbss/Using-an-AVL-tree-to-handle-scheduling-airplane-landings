#include<iostream>
#include<cmath>

using namespace std;


struct node// moshakhasate har khane derakht
{
	int value;
	node* left;
	node* right;
	node* parent;
	
	int height; // har ras ertefae khod ra negah midarad
};

class Tree
{  private:
	node* root;
	int size;
	
	
	public:
		Tree();
		int get_size();
		int get_height(node*);
		node* get_root();
		node* get_parent(node*);
        node* create_node(int);
        void BST_insert(node*,node*,int );// root,parent,x
	 	void print_inorder(node*);
	 	void print_preorder(node*);
	 	void print(node*);
	 	//void update_heights(node*); //(arash)
	 	int update_heights(node*); //(arman)
	 	void  left_rotate(node*);
	 	void right_rotate(node*);
	 	void AVL_insert(int,node*);
	 	int  make_AVL(node*);
	 	int check_heavy(node*); //-1:left-heavy, 0=balanced, 1:right_heavy	 	
 	 	int BST_min(node*);
 	 	int BST_max(node*);
		int BST_Next_Larger(node*,int);
		int BST_Pre_Smaller(node*,int);
		void delete_smaller(int,node*);
		
 	 	
};

Tree::Tree() // maghadire pishfarz ra taeen mikonad
{
	size=0;
	root=NULL;
}

node* Tree::get_parent(node* child) // pedare bache ra barmigardanad
{
  return child->parent;	
}

node* Tree::get_root()  // baes dastresi be ghesmate root mishavad
{
	return root;
}

 node* Tree::create_node(int data) // yek node adi misazad
 {
 	node* temp=new node;
 	temp->left=NULL;
 	temp->right=NULL;
 	temp->parent=NULL;
 	temp->value=data;
 	return temp;
 }

void Tree::BST_insert(node* r,node*p,int x)
{   
	if(r==NULL)
	{
		r=create_node(x);
		r->parent=p;
	    if(p!=NULL)
	    {
	    		if(p->value< r->value)
		  {
			p->right=r;
			
		  }
			if(p->value> r->value)
		  {
			p->left=r;
			
		  }
		}
	
		if(size==0)
		{
			root=r;
		}
		size++;
		
	}
	else if(r->value>x)
	{
		BST_insert(r->left,r,x);
	}
	else
	{
		BST_insert(r->right,r,x);
	}
	
}

int Tree::get_size()
{
	return size;
}

void Tree::print_inorder(node* v){
	if(v==NULL) return;
 	print_inorder(v->left);
 	cout<<v->value<<" ";
 	print_inorder(v->right);
	 
	}
	
void Tree::print_preorder(node* v){
	if (v==NULL) return;
	cout<<v->value<<" ";
	print_preorder(v->left);
	print_preorder(v->right);
	
}	

void Tree::print(node *v){
	cout<<" Inorder : ";
	print_inorder(v);
	cout<<endl;
	cout<<" Preorder : ";
	print_preorder(v);
	cout<<endl;
}
	
int Tree::get_height(node* v){
	if (v==NULL) return -1;
	return 1+ max(get_height(v->left),get_height(v->right));
}

//void Tree::update_heights(node* v){
// 		
//	if(v==NULL) 	
//	return;
//	
// 	update_heights(v->left); //*
// 	v->height=get_height(v); //*
// 	update_heights(v->right);	//*
//	
//}

int Tree::update_heights(node* v) 	
{
	if (v!=NULL){
		v->height= 1 + max (update_heights(v->left),update_heights(v->right));
		return v->height;
	}
	if (v==NULL)  return -1;
}

void Tree::right_rotate(node* x)
{	 	node* k=x->parent;

 	 	if(k==NULL){
 	 		if(x->left->right==NULL)
 	 		{
 	 			x->parent=x->left;
 	 			x->left=NULL;
 	 			x->parent->parent=NULL;
 	 			x->parent->right=x;
 	 			root=x->parent;
			  }
 	 		else{
 	 			x->parent=x->left;
 	 			x->left=x->parent->right;
 	 			x->parent->parent=NULL;
 	 			x->parent->right=x;
 	 			x->left->parent=x;
 	 			root=x->parent;
			  }
 	 		
 	 		
 	 		
 	 		return;
		  }
 	 	if(x==k->right)
 	 	{ 	
 	 	 	if(k->right->left->right==NULL)
 	 	 	{  
		   	k->right=k->right->left;
	 	 	k->right->parent=k;
	 	 	x->left=NULL; // 	 	//temp bacheye raste babashe
 	 	  	x->parent=k->right; 	//va null darim
 	 	 	k->right->right=x;	}
 	 	 	else
 	 	 	{
			   	k->right=x->left; //1
 	 	 	 	x->left->parent=k; //2	
 	 	 		x->left=k->right->right; //3	 	 //temp raste babashe
	 	 		x->parent=k->right; //4 	 	 	//null darim
 	 		 	k->right->right->parent=x; //5	
 	 	 		k->right->right=x; //6 	   
			   }

		  
	}
 	 	

if (x==k->left)
{
 	if(k->left->left->right==NULL)
 	{
	 k->left=k->left->left;
 	k->left->parent=k;      
 	x->left=NULL; 	 	 	//temp bacheye chape babashe
 	x->parent=k->left; 	 	//va null darim
 	k->left->right=x;
  	}
 	else{
	k->left=x->left; //1
	x->left->parent=k; //2	
	x->left=k->left->right; //3	  	//temp chape babashe
	x->parent=k->left; //4 	 	 	//null nadarim
	k->left->right->parent=x; //5	
	k->left->right=x; //6
  	 	}
}
	}	
	
void Tree::left_rotate(node* x)
{	 	node* k=x->parent;

 	 	if(k==NULL){
 	 		if(x->right->left==NULL)
 	 		{
 	 			x->parent=x->right;
 	 			x->right=NULL;
 	 			x->parent->parent=NULL;
 	 			x->parent->left=x;
 	 			root=x->parent;
			  }
 	 		else{
 	 			x->parent=x->right;
 	 			x->right=x->parent->left;
 	 			x->parent->parent=NULL;
 	 			x->parent->left=x;
 	 			x->right->parent=x;
 	 			root=x->parent;
			  }
 	 		
 	 		
 	 		
 	 		return;
		  }
 	 	if(x==k->right)
 	 	{ 	
 	 	 	if(k->right->right->left==NULL)
 	 	 	{  
		   	k->right=k->right->right;
	 	 	k->right->parent=k;
	 	 	x->right=NULL; // 	 	//temp bacheye raste babashe
 	 	  	x->parent=k->right; 	//va null darim //done
 	 	 	k->right->left=x;	}
 	 	 	else
 	 	 	{
			   	k->right=x->right; //1
 	 	 	 	x->right->parent=k; //2	
 	 	 		x->right=k->right->left; //3	 	 //temp raste babashe
	 	 		x->parent=k->right; //4 	 	 	//null nadarim //done
 	 		 	k->right->left->parent=x; //5	
 	 	 		k->right->left=x; //6 	   
			   }

		  
	}
 	 	

 	if (x==k->left)
 	{
	 	if(k->left->right->left==NULL)
 	 	 	{  
		   	k->left=k->left->right;
	 	 	k->left->parent=k;
	 	 	x->right=NULL; // 	 	//temp bacheye raste babashe
 	 	  	x->parent=k->left; 	//va null darim //done
 	 	 	k->left->left=x;	}
 	 	 	else
 	 	 	{
			   	k->left=x->right; //1
 	 	 	 	x->right->parent=k; //2	
 	 	 		x->right=k->left->left; //3	 	 //temp raste babashe
	 	 		x->parent=k->left; //4 	 	 	//null nadarim //done
 	 		 	k->left->left->parent=x; //5	
 	 	 		k->left->left=x; //6 	   
			   }
	
 	
  	}
  }
  	
int Tree::check_heavy(node*a){
	int R; 
 	int L;
	if(a->right==NULL) {R=-1;}
	else {R=a->right->height;}
	
	if(a->left==NULL) {L=-1;}
	else {L=a->left->height;}
	
 	if(L-R>0) return -1; //left_heavy
	if(R-L>0) return 1; //right_heavy
	if(R-L==0) return 0; //balanced	
}

			
int Tree::make_AVL(node* r){
	if(r==NULL) {return -1;}
	int a=make_AVL(r->left);
	int b=make_AVL(r->right);
 	if(a-b>=2) 
	  	{ if (check_heavy(r->left)==0 || check_heavy(r->left)==-1)
	  	 	{
			   right_rotate(r);}
		  else
		  { left_rotate(r->left);
		    right_rotate(r);
					 }				 
			update_heights(root);
			return r->parent->height;   	
		  }
	else if(b-a>=2){
		  if (check_heavy(r->right)==1 ||check_heavy(r->right)==0)
	 	 	{left_rotate(r);}
		 	else {right_rotate(r->right);
			  	 left_rotate(r);}
			update_heights(root);
			return r->parent->height;	  	  
			  }	 
	else	{
		
			update_heights(root);
  	 	 	return r->height;   
  	 	 }
}

void Tree::AVL_insert(int x,node* r){
	
	BST_insert(r,NULL,x);
	update_heights(r);
	make_AVL(r);
	
}

int Tree::BST_min(node* r){
	if (r->left==NULL) return r->value;
	else {
		 	return BST_min(r->left);
	}
}

int Tree::BST_max(node* r){
	if (r->right==NULL) return r->value;
	else {
		 	return BST_max(r->right);
	}
}



int Tree::BST_Next_Larger(node* r,int x){
 	if(r==NULL) return -1000000;
 	if(r->value<x) return BST_Next_Larger(r->right,x);
 	if(r->value>x){
 		 	 	if(r->left==NULL) return r->value;
 		 	 	if(r->left->value>x) return BST_Next_Larger(r->left,x);
 		 	 	if(r->left->value<x) {
 		 	 		if(BST_Next_Larger(r->left,x)!=-1000000)
 		 	 		return min(r->value,BST_Next_Larger(r->left,x));
 		 	 		else return r->value;	
				   }
				   if(r->left->value==x) return x;
				   }
	if(r->value==x) return x;			   
}

int Tree::BST_Pre_Smaller(node* r,int x){
	if(r==NULL) return 1000000;
 	if(r->value>x) return BST_Pre_Smaller(r->left,x);
 	if(r->value<x){
 		 	 	if(r->right==NULL) return r->value;
 		 	 	if(r->right->value<x) return BST_Pre_Smaller(r->right,x);
 		 	 	if(r->right->value>x) {
 		 	 		if(BST_Pre_Smaller(r->right,x)!=1000000)
 		 	 		return max(r->value,BST_Pre_Smaller(r->right,x));
 		 	 		else return r->value;	
				   }
				   if(r->right->value==x) return x;
				   }
	if(r->value==x) return x;	
}

void Tree::delete_smaller(int x,node* r){
	if(r==NULL) return;
	node* k=r->parent;
	node* q=r->right;
	if(k==NULL&&q==NULL){
		if(r->value>x) {
			delete_smaller(x,r->left);	
		}
		if(r->value<=x){
			r->left=NULL;
			r=NULL;
			root=NULL; 
			return;
		}
	}
	if(k==NULL&&q!=NULL){
		if(r->value>x){
			delete_smaller(x,r->left);
		}
		if(r->value<=x){		
			root=r->right;
			r->right->parent=NULL;
			delete_smaller(x,root);
		}
	}
	if(k!=NULL&&q==NULL){
		if(r->value>x){
			delete_smaller(x,r->left);
		}
	 	if(r->value<=x){
	 		if(r==k->right){
	 			k->right==NULL; 
			 }
			if(r==k->left){
				k->left=NULL; 
			} 
		 }
		 }
	if(k!=NULL&&q!=NULL){
		if(r->value>x) {
			delete_smaller(x,r->left);
		}
		if(r->value<=x){
		 	if(k->right==r){
		 		k->right=r->right;
		 		r->right->parent=k;
		 		//delete r; 
		 		delete_smaller(x,k->right);
			 }
			else {
				k->left=r->right;
		 		r->right->parent=k;
		 		delete_smaller(x,k->left); 
			}
		 	
		}
	}
	
}

int main(){ 
    int time=-1000000;	
 	Tree A;
	while(1){
	
	cout<<"Press 0 to add a reservation. \n";
	cout<<"Press 1 to set time \n";
	cout<<"Press 2 to cancel a reservation \n";
	cout<<"Press 3 to display inorder and preorder traversal. \n";
	int choice;
	
	cin>>choice;
	switch(choice){
		
	case 0:	{ 
	cout<<"__________________________________________"<<endl;
	int p;
 	cout<<"Enter the number of reservations:"<<endl;
 	cin>>p;
 	cout<<"K(Time needed to complete each action) is set 5 by default"<<endl; 
 	int d;
 	for(int i=0;i<p;i++)
    { 
     	if(A.get_root()!=NULL){
      	 		cin>>d;
      	 		int L=A.BST_Next_Larger(A.get_root(),d);
      	 		int S=A.BST_Pre_Smaller(A.get_root(),d);
      	 		if((abs(L-d)>=5 && abs(S-d)>=5) && d>time) {
	 	 		 A.AVL_insert(d,A.get_root());
	 	 		 cout<<" Reservation is succussfully made."<<endl;
	 	 		 }	 
      	 		else {
      	 		if(d<=time) {cout<<"You can't make reservation in the past."<<endl;}
	 			else if (!(abs(L-d)>=5 && abs(S-d)>=5)) {
	 	 		cout<<"This time is clashing with a prior reservation."<<endl;
     	 		cout<<"Choose another time, please."<<endl;
     	 	 	}
	 		  	}
	  	 	}
    	 else{
    	 	if(d<=time) cout<<"You can't make reservation in the past."<<endl;
 	 		else{
			  cin>>d;
     	 	A.AVL_insert(d,A.get_root());
    	   cout<<" Reservation is succussfully made."<<endl;
    	     	}
   	 		}
 	 		}
 		cout<<"__________________________________________"<<endl;	
		break;
	    }
	case 1:	{
		cout<<"__________________________________________"<<endl;
		cout<<"Please, eneter the time."<<endl;
		cin>>time;
		if(A.get_root()!=NULL) {
		A.delete_smaller(time,A.get_root());
		A.update_heights(A.get_root());
		A.make_AVL(A.get_root());
	 	}
	
		cout<<"__________________________________________"<<endl;
		break;
		
	}
	case 2 : {
		cout<<"__________________________________________"<<endl;
	 	cout<<"Time:"<<time<<endl;
		cout<<"__________________________________________"<<endl;
		break;	
	}
	case 3 : {
	 	cout<<"__________________________________________"<<endl;
	 	A.print(A.get_root());
	
		cout<<"__________________________________________"<<endl;

 	}
    
  
}
}
	return 0;
}

