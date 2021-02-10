#include <iostream>
#include <vector>
using namespace std;


bool inOrder(const vector<int> &nums){
   for (int i = 1; i < nums.size(); ++i) {
      if (nums.at(i - 1) > nums.at(i)) {
         return false;
      }
   }
   return true;
}

int main() {

	vector<int> nums1(5);
	nums1.at(0) = 5;
	nums1.at(1) = 6;
	nums1.at(2) = 7;
	nums1.at(3) = 8;
	nums1.at(4) = 3;


	if (inOrder(nums1)) {
		cout << "In order" << endl;
	}
	else {
		cout << "Not in order" << endl;
	}

	vector<int> nums2(5);
	nums2.at(0) = 5;
	nums2.at(1) = 6;
	nums2.at(2) = 7;
	nums2.at(3) = 8;
	nums2.at(4) = 10;

	if (inOrder(nums2)) {
		cout << "In order" << endl;
	}
	else {
		cout << "Not in order" << endl;
	}

	return 0;
}
