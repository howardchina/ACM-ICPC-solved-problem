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
char s[100000];
void insert()
{
	int i; int len=strlen(s);
	
	node* p=root;
	for(i=0;i<len;i++)
	{
		if(!p->next[s[i]-'a']) p->next[s[i]-'a']=newnode();
		p=p->next[s[i]-'a'];
		p->cnt++;
	}
}

void search(node* root)
{
	int i; int len=strlen(s);
	
	node* p=root,*t;
	for(i=0;i<26;i++)
	{
t=p->next[i];
		if(!t) continue;
		ans+=t->cnt;
		if(t->cnt!=1) search(t);
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