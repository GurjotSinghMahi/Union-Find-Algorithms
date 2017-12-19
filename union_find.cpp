#include <iostream>

using namespace std;

// implementation of Union find Data structure

int array[10]; // for Graph array
int size[10]; // For Weighted graph size

// Inititalize both Graph and size Array
void initialize()
{
	for (int i=0;i<10;i++)
	{
		array[i]=i;
	}
	
	for (int i=0;i<10;i++)
	{
		size[i]=0;
	}
}

// Print Array
void print_array()
{
	for (int i=0;i<10;i++)
	{
		cout << array[i] <<" ";
	}
cout << endl;
}

// Union Find Implementation
int find(int i)
{
	return array[i];
}

int union_graph(int p, int q)
{
	for(int i=0;i<10;i++)
	{
		if(array[i]==p)
		{
			array[i]=q;	
		}
	}
}



//Quick Union
int find_Quick_Union(int i)
{
	while(array[i]!=i)
	{
		i = array[i];		
	}
return i;
}

void Quick_Union(int p, int q)
{
	if(p==q)
	{
		cout << "SAME ROOT" << endl;
	}
	else
	{
		array[p]=q;
	}
}

//Weighted Quick Union
void Weighted_Quick_Union(int p, int q)
{
	if(p==q)
	{
		cout << "SAME ROOT" << endl;
	}
	else
	{
		if(size[p]<size[q])
		{
			array[p]=q;
			size[q]++;
		}
		else
		{
			array[q]=p;
			size[p]++;
		}
	}
}

//Path Compression --  keeps graph flat
int Path_Compression_Find(int i)
{
	while(array[i]!=i)
	{
		array[i] = array[array[i]];
		i = array[i];		
	}
return i;
}

int main()
{
cout << "Union Find" << endl;
initialize();
union_graph(find(3), find(4));
cout << "3-4:  ";print_array();
union_graph(find(4), find(9));
cout << "4-9:  ";print_array();
union_graph(find(8), find(0));
cout << "8-0:  ";print_array();
union_graph(find(2), find(3));
cout << "2-3:  ";print_array();
union_graph(find(5), find(6));
cout << "5-6:  ";print_array();
union_graph(find(5), find(9));
cout << "5-9:  ";print_array();
union_graph(find(7), find(3));
cout << "7-3:  ";print_array();
union_graph(find(4), find(8));
cout << "4-8:  ";print_array();
union_graph(find(6), find(1));
cout << "6-1:  ";print_array();
cout << endl;

cout << "Quick Union" << endl;
initialize();
Quick_Union(find_Quick_Union(3), find_Quick_Union(4));
cout << "3-4:  ";print_array();
Quick_Union(find_Quick_Union(4), find_Quick_Union(9));
cout << "4-9:  ";print_array();
Quick_Union(find_Quick_Union(8), find_Quick_Union(0));
cout << "8-0:  ";print_array();
Quick_Union(find_Quick_Union(2), find_Quick_Union(3));
cout << "2-3:  ";print_array();
Quick_Union(find_Quick_Union(5), find_Quick_Union(6));
cout << "5-6:  ";print_array();
Quick_Union(find_Quick_Union(5), find_Quick_Union(9));
cout << "5-9:  ";print_array();
Quick_Union(find_Quick_Union(7), find_Quick_Union(3));
cout << "7-3:  ";print_array();
Quick_Union(find_Quick_Union(4), find_Quick_Union(8));
cout << "4-8:  ";print_array();
Quick_Union(find_Quick_Union(6), find_Quick_Union(1));
cout << "6-1:  ";print_array();
cout << endl;

cout << "Weighted Quick Union" << endl;
initialize();
Weighted_Quick_Union(find_Quick_Union(3), find_Quick_Union(4));
cout << "3-4:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(4), find_Quick_Union(9));
cout << "4-9:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(8), find_Quick_Union(0));
cout << "8-0:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(2), find_Quick_Union(3));
cout << "2-3:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(5), find_Quick_Union(6));
cout << "5-6:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(5), find_Quick_Union(9));
cout << "5-9:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(7), find_Quick_Union(3));
cout << "7-3:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(4), find_Quick_Union(8));
cout << "4-8:  ";print_array();
Weighted_Quick_Union(find_Quick_Union(6), find_Quick_Union(1));
cout << "6-1:  ";print_array();
cout << endl;

cout << "Weighted Quick Union with Path Compression" << endl;
initialize();
Weighted_Quick_Union(Path_Compression_Find(3), Path_Compression_Find(4));
cout << "3-4:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(4), Path_Compression_Find(9));
cout << "4-9:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(8), Path_Compression_Find(0));
cout << "8-0:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(2), Path_Compression_Find(3));
cout << "2-3:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(5), Path_Compression_Find(6));
cout << "5-6:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(5), Path_Compression_Find(9));
cout << "5-9:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(7), Path_Compression_Find(3));
cout << "7-3:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(4), Path_Compression_Find(8));
cout << "4-8:  ";print_array();
Weighted_Quick_Union(Path_Compression_Find(6), Path_Compression_Find(1));
cout << "6-1:  ";print_array();
cout << endl;

return 0;
}
