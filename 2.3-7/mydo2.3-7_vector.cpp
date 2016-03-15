#include <iostream>
#include <istream>
#include <climits>
#include <vector>

using namespace std;

static void merge(vector<char>& S,int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int endless = INT_MAX;
	int L[n1 + 1];
	int R[n2 + 1];
	int i,j;
	int k = left;

	for(i = 0 ; i < n1 ; i++){
		L[i] = S[k++];
	}

	for(j = 0 ; j < n2 ; j++){
		R[j] = S[k++];
	}

	L[i] = endless;
	R[j] = endless;

	i = j = 0;

	for(k = left; k <= right; k++){
		if (L[i] <= R[j])
		{
			S[k] = L[i++];
		}else{
			S[k] = R[j++];
		}
	}
}

static void merge_sort(vector<char>& S, int left, int right)
{
	int mid;
	if ((left >= 0) && (left < right)){
		mid = (left + right) / 2;

		merge_sort(S, left, mid);
		merge_sort(S, mid + 1, right);
		merge(S, left, mid, right);
	}
}

static int binary_search(vector<char>& S, int len, int expect, int target)
{
	int left = 0, right = len - 1, mid;
	do {
		if (left == expect) {
			++left;
		}

		if (right == expect) {
			++right;
		}

		mid = (left + right) / 2;

		if ((mid != expect) && (S[mid] == target)) {
			return 0 ;
		}else if (S[mid] > target) {
			right = --mid;
		}else{
			left = ++mid;
		}
	}while (left <= right);

	return 1;
}

static int check_exist_x(vector<char> & S,int len, int x)
{
	int i;

	if(len < 2) {
		cout << "Too few elements.\n";
		return 1;
	}

	merge_sort(S, 0, len - 1);

	for (i = 0; i < len; i++){
		if(!binary_search(S, len, i, x - S[i])) {
			return 0;
		}
	}

	return 1;
}

int main()
{
	vector<char> source;
    char zi;
	
	cout << "Please input your number:";

	for(int z = 0;z < INT_MAX; z++){
        
		source.push_back(cin >> zi);
        if(zi == 'q'){
            source.pop_back();
            break;
        } 
	}

	int n = source.size();

	int x;
	cout << "Which number do you want to search? please enter:";
	cin >> x;

	int ret;

	ret = check_exist_x(source, n, x);
	cout << "If there are two elements whose sum equals to "<< x <<"?"<< endl;
	if(ret == 1){
		cout << "Yes.\n";
	}else {
		cout << "No.\n";
	}

	return 0;
}















