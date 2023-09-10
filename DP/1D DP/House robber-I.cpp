int maxMoneyLooted(vector<int> &h, int n) {

	int prev2=0,prev=h[0],curri;

	for(int i=1;i<=n-1;i++)
	{
		int looted=h[i];
		if(i>1)looted+=prev2;
		int notLooted=0+prev;

		curri=max(looted,notLooted);

		prev2=prev;
		prev=curri;
	}
	return prev;
}