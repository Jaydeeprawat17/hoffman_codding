#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<alloc.h>
#include<string.h>
#define max 126
//HOFFMAN CODING PROBLEM PROGRAM
struct Data_list{
 char c;
 int frequency;
 char hoffman_bits[8];
};
struct node{
 int frequency;
 char c;
 int left_cost,right_cost;
 struct node *next;
 struct node *left,*right;
};


class File{
public:
int size;
struct Data_list data[max];
char fname[17];
ifstream fp;
public:
File(){
 size=0;
}
 void get_frequency(){
  char c;
  cout<<"Enter File Name: ";
  cin>>fname;
  fp.open(fname);
   if(fp){
     while(!fp.eof()){
	fp.get(c);
	if(c!=EOF)
	get_frequency_list(c);
      }
    }else{
      cerr<<"Unable to find";
    }
    fp.close();
 }

 void get_frequency_list(char c){
    for(int s=0;s<=size;s++){
       if(data[s].c==c){
	   data[s].frequency+=1;
	   return;
       }
    }
    data[size].c=c;
    data[size++].frequency=1;

 }

// show data List
 void show_list(){
    for(int s=0;s<size;s++){
      cout<<data[s].c<<" "<<data[s].frequency<<" "<<data[s].hoffman_bits<<endl;
      }
 }


};


class LinkedList:public File{
protected:
struct node *start;
public:
LinkedList(){
 start=NULL;
}

void insertion(int frequency,char c){
  struct node *newnode,*temp;

      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->frequency=frequency;
      newnode->c=c;
      newnode->next=NULL;
      newnode->left=NULL;
      newnode->right=NULL;

   if(start==NULL){
       start=newnode;
       return;
   }
     temp=start;
       while(temp->next!=NULL)
	  temp=temp->next;

       temp->next=newnode;

}

 void fetch_data(){
    for(int s=0;s<size;s++){
	insertion(data[s].frequency,data[s].c);
    }
 }

  void get_values(){
     struct node *temp=start;
     if(temp==NULL) {
       cerr<<" List is Empty";
       return;
     }
     while(temp!=NULL){
	cout<<temp->c<<" "<<temp->frequency<<endl;
	temp=temp->next;
     }
  }

};

class Hoffman:public LinkedList{
char bits[8];
int find;
public:
Hoffman(){
}

void sort(){
  struct node *next,*temp;
    next=start;
      while(next->next!=NULL){
	 temp=start;
	 while(temp->next!=NULL){
	    if(temp->frequency>temp->next->frequency){
		 struct node *left,*right;
		 int f;
		 char c;

		 c=temp->c;
		 f=temp->frequency;
		 left=temp->left;
		 right=temp->right;

		 temp->c=temp->next->c;
		 temp->frequency=temp->next->frequency;
		 temp->left=temp->next->left;
		 temp->right=temp->next->right;

		 temp->next->c=c;
		 temp->next->frequency=f;
		 temp->next->left=left;
		 temp->next->right=right;

	    }
	    temp=temp->next;
	 }
	  next=next->next;
      }
 }



 void handle(){
   int fre;

   while(start->next!=NULL){
     sort();

       fre=start->frequency+start->next->frequency;
      struct node *tree,*temp=start;

      tree=(struct node*)malloc(sizeof(struct node));

      tree->frequency=fre;
      tree->left=start;
      tree->right=start->next;
      tree->c='\0';
      start=start->next;
       tree->next=start->next;
       start->next=NULL;
       temp->next=NULL;
      start=tree;
   }
   cout<<"Root Fre: "<<start->frequency<<endl;;

 }

// p1 solved
 void recursion(struct node *node){
    if(node->left==NULL||node->right==NULL)
       return;

    node->left_cost=0;
    recursion(node->left);
    node->right_cost=1;
    recursion(node->right);
 }

 void assign(){
    struct node *temp;
    temp=start;
    recursion(temp);
 }
// p2  find bits and save every char's their bits
// find add
void clearBits(){
 bits[0]='\0';
}

void addBits(int b){
int len=strlen(bits);
  bits[len]=(char)(b+'0');
  bits[len+1]='\0';
}
void removeBits(){
   bits[strlen(bits)-1]='\0';
}
 void sp(struct node *temp,char c){
    if(temp->left==NULL||temp->right==NULL||find==1){
       if(find==1) return;
       removeBits();
       return;
     }
     addBits(temp->left_cost);

     if(temp->left->c==c){
       find=1;
       return;
     }


    sp(temp->left,c);
    if(find==1) return;
     addBits(temp->right_cost);

    if(temp->right->c==c){
       find=1;
     }


    sp(temp->right,c);

//   if(find!=1&&(temp->left->c!=c || temp->right->c!=c)&& (temp->left->left==NULL||temp->right->right==NULL )){
  if(!find)
       removeBits();
 //   }
}

 void s(){
 find=0;
 clearBits();

  for(int s=0;s<size;s++){
  clearBits();
  find=0;
     sp(start,data[s].c);
     strcpy(data[s].hoffman_bits,bits);
  }
  show_list();
 }


};

void main(){

clrscr();
 Hoffman fre;
 fre.get_frequency();
 fre.fetch_data();

  fre.handle();

 fre.assign(); //p3

  fre.s(); //p4

 getch();
}