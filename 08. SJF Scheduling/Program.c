#include<stdio.h>
int main()
{
	int nop, wt[10], twt, tat[10], ttat, i, j, bt[10], t;
	float awt, atat;
	awt = 0.0;
	atat = 0.0;
	printf("\n\nEnter the number of process: ");
	scanf("%d", &nop);
	for(i=0; i<nop; i++)
	{
		printf("Enter the burst time of process %d : ", i+1);
		scanf("%d",&bt[i]);
	}
	for(i=0; i<nop; i++)
	{
		for(j=i+1; j<nop; j++)
		{
			if(bt[i]>=bt[j])
			{
				t = bt[i];
				bt[i] = bt[j];
				bt[j] = t;
			}
		}
	}
	wt[0] = 0;
	tat[0] = bt[0];
	twt = wt[0];
	ttat = tat[0];
	for(i=1; i<nop; i++)
	{
		wt[i] = wt[i-1]+bt[i-1];
		tat[i] = wt[i]+bt[i];
		twt+=wt[i];
		ttat+=tat[i];
	}
	awt = (float)twt/nop;
	atat = (float)ttat/nop;
	printf("\nProcess ID\tBurst Time\tWAiting Time\tTurn Around Time");
	for(i=0; i<nop; i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d", i+1, bt[i], wt[i], tat[i]);
	}
	printf("\n\n Total Waiting Time : %d", twt);
	printf("\n Total Turn Around Time : %d", ttat);
	printf("\n Average Waiting Time : %f", awt);
	printf("\n Average Turn Around Time : %f", atat);
	return 0;
}
