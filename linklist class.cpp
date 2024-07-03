#include <iostream>
using namespace std;
class node {
	private:
		int num;
		node *next;
	public:
		friend class linklist;
		node() {
			next=nullptr;
		}
};
class linklist {
	private:
		node *first;
		node *last;
	public:
		linklist() {
			first=nullptr;
		}
		void insert(int n) {
			node *newnode=new node;
			if(first==nullptr) {
				first=newnode;
				first->num=n;
				last=newnode;
			} else {
				last->next=newnode;
				last=newnode;
				last->num=n;
			}
		}
		void print() {
			node *temp=first;
			while(temp!=nullptr) {
				cout<<temp->num<<"  ";
				temp=temp->next;
			}
			cout<<"\n";
		}
		void deletefirst() {
			first=first->next;
		}
		void deletelast() {
			node *p=first;
			node *p2=first;
			while(p2!=nullptr) {
				if(p2->next==nullptr) {
					p->next=nullptr;
				}
				p=p2;
				p2=p2->next;
			}
		}
		void deletenum(int n) {
			node *temp=first;
			node *before=first;
			while(temp!=nullptr) {
				if(temp->num==n) {
					before->next=temp->next;
				}
				before=temp;
				temp=temp->next;
			}
		}
		void insertfirst(int n) {
			node *newnode=new node;
			newnode->next=first;
			newnode->num=n;
			first=newnode;
		}
		void insertnum(int n) {
			node *newnode=new node;
			node *temp=first;
			node *before=first;
			while(temp!=nullptr) {
				if(temp->num>=n && before->num<=n) {
					newnode->next=before->next;
					before->next=newnode;
					newnode->num=n;
					break;
				}
				before=temp;
				temp=temp->next;
			}
		}
};
int main() {
	int n;
	linklist a;
	for(int i=2; i<=10; i+=2) {
		a.insert(i);
	}
	a.print();
	cout<<"nnnn";
	cin>>n;
	a.deletenum(n);
	a.print();
	return 0;
}


