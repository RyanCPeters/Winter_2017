#pragma once
#include <vector>
#include <iostream>
#include "quicksort.cpp"

using namespace std;

class Solution {
	//struct Poisitions { int l, tote; }n1, n2;
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totalSize = nums1.size() + nums2.size();
		int modVal = (totalSize << 31) >> 31;
		int mid = totalSize / 2;
		
		if (nums1.back() <= nums2.front()) {

		} else if (nums2.back() <= nums1.front()) {
			if (nums2.size() == mid) {
				if (modVal) {
					return nums1.front()*1.0;
				}
				return (nums2.back() + nums1.front()) / 2.0;

			}
		} 
	}

};

/*
 set 1:
 67
 26
 11
 87
 84
 30
 14
 63
 59
 14
 71
 59
 28
 6
 18

 set 2:
 14	36	89
 69	50	15
 31	38	92
 
 
 */