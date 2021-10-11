#include<iostream>
#include<deque>

using namespace std;

void printmax(int *ar,int k, int n)
{
	deque<int> q;
	int i;
	for(i=0;i<k;i++)
	{
		while((!q.empty())	and		ar[i]>=ar[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	for(;i<n;i++)
	{
		cout<<ar[q.front()]<<" ";

		while((!q.empty())	and		q.front() <= i-k)
		{
			q.pop_front();
		}
		while((!q.empty())	and		ar[i]>=ar[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	cout<<ar[q.front()];
}




int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
#endif 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	cin>>n;
	int *ar = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cin>>k;

	printmax(ar,k,n);



}