#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<string.h>

struct node
{
	node* next[26];
	int cnt;
};

node* root;
node* newnode()
{
	node* root=new node;
	root->cnt=0;
	int i;

	for(i=0;i<26;i++)
		root->next[i]=NULL;
	return root;
}

int ans;
char s[1000000];
void insert()
{
	int i; int len=strlen(s);
	
	node* p=root;
	for(i=0;i<len;i++)
	{
		if(p->next[s[i]-'a']==NULL) p->next[s[i]-'a']=newnode();
		p=p->next[s[i]-'a'];
		p->cnt++;
		//if(p->cnt!=1) ans+=p->cnt;

	}
}

void search(node* root)
{
	int i; int len=strlen(s);
	
	node* p=root;
	for(i=0;i<26;i++)
	{
		if(!p->next[i]) continue;
		ans+=p->next[i]->cnt;
		if(p->next[i]->cnt!=1) search(p->next[i]);
	}
}

int main()
{
	int n,i;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		root=newnode();
		for(i=1;i<=n;i++) 
		{
			scanf("%s",s);
			insert();
		}

		search(root);
		printf("%d\n",ans);
	}

	return 0;
}
