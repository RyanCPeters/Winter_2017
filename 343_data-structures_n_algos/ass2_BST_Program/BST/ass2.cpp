// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// some interactive and non-interactive testes to test BinarySearchTree

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
#include <cctype>
#include "binarysearchtree.h"
#include "binarynode.h"

using namespace std;
//union StrInt {
//	int8_t smalInt;
//	int16_t medInt;
//	int32_t bigInt;
//	char c;
//	string s;
//
//};

//so if you ever need to try and meet up on campus you can
template<class ItemType>
void itemDisplay(const ItemType& anItem) {
	cout << anItem << " ";
}

string getString() {
	string str;
	cout << "Enter a string: ";
	cin >> str;
	return str;
}

int getInt() {
	int num;
	cout << "Enter an int: ";
	cin >> num;
	return num;
}

vector<int> getInts(const string& inFileName ) {
	/*cout << "Enter multiple ints: ";
	cin.clear();*/
	
	vector<int> v;
	int num;
	ifstream iFile(inFileName);
	if( iFile.is_open() ) {
		while( iFile >> num ) {
			v.push_back(num);
		}
	}
	return v;
}

vector<string> getStrings() {

	string longString;
	cout << "Enter multiple strings: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, longString);
	vector<string> v;
	
	for( unsigned int subStrt = 0, subStp = 0; subStrt < longString.size(); ) {
		if( longString.at(subStrt) != ' ' ) {
			for( subStp = subStrt; subStp < longString.size() && longString.at(subStp) != ' '; ++subStp );
			v.push_back(longString.substr(subStrt, subStp-subStrt));
			subStrt = subStp;
		} else {
			++subStrt;
		}
	}
	return v;
}

void treeMenuString() {
	BinarySearchTree<string> bst;
	const string menu = "treeMenuString\n"
		"1. Add\n2. Search\n"
		"3. Inorder traverse\n"
		"4. Height & Number of nodes\n"
		"5. Rebalance\n"
		"6. Add Multiple\n"
		"7. Clear tree\n"
		"8. Create tree from sorted array\n"
		"10. Exit\n>> ";
	int choice;
	string str;
	cout << menu;
	while (true) {
		cin >> choice;
		switch (choice) {
			case 1:
				str = getString();
				cout << (bst.add(str) ? "" : "Not ") << "Added " << str << endl;
				break;
			case 2:
				str = getString();
				cout << (bst.contains(str) ? "" : "Not ") << "Found " << str << endl;
				break;
			case 3:
				bst.inorderTraverse(itemDisplay);
				cout << endl;
				break;
			case 4:
				cout << "Height: " << bst.getHeight() << endl;
				cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
				break;
			case 5:
				bst.rebalance();
				break;
			case 6:
				for (string str : getStrings())
					cout << (bst.add(str) ? "" : "Not ") << "Added " << str << endl;
				break;
			case 7:
				bst.clear();
				break;
			case 8:
				{
					bst.clear();
					vector<string> v{ getStrings() };
					bst.readTree(&v[0], v.size());
					cout << "Height: " << bst.getHeight() << endl;
					cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
					break;
				}
			case 10:
				{
					bst.clear();
					return;
				}
			default:
				cout << "Bad input" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
		}
		bst.displaySideways();
		cout << menu;
	}
}


void treeMenuInt() {
	BinarySearchTree<int> bst;
	const string menu = "treeMenuInt\n"
		"1. Add\n"
		"2. Search\n"
		"3. Inorder traverse\n"
		"4. Height & Number of nodes\n"
		"5. Rebalance\n"
		"6. Add Multiple\n"
		"7. Clear tree\n"
		"6. Add many\n"
		"10. Exit\n>> ";
	int choice;
	int number;
	string fileName;
	cout << menu;
	while (true) {
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter a number: ";
				cin >> number;
				cout << (bst.add(number) ? "" : "Not ") << "Added " << number << endl;
				break;
			case 2:
				number = getInt();
				cout << (bst.contains(number) ? "" : "Not ") << "Found " << number << endl;
				break;
			case 3:
				bst.inorderTraverse(itemDisplay);
				cout << endl;
				break;
			case 4:
				cout << "Height: " << bst.getHeight() << endl;
				cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
				break;
			case 5:
				bst.rebalance();
				break;
			case 6:
				cout << "Please enter the name of the input file to use.\n"
					"The name should have no spaces and the file type should be .txt \n"
					"\neg., \"many-int-test\"\n>> ";
				cin.clear();
				cin >> fileName;
				for( const int& val : getInts(fileName) ) {
					cout << (bst.add(val) ? "" : "Not ") << "Added " << val << endl;
				}
				break;
			case 10:
				bst.clear();
				return;
			default:
				cout << "Bad input" << endl;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
		}
		bst.displaySideways();
		cout << menu;
	}
}

int main() {
	BinarySearchTree<string> bst1;
	BinarySearchTree<string> bst2;
	bst1.add("g");
	bst1.add("d");
	bst1.add("k");
	cout << ((bst1 != bst2) ? "OK" : "ERR") << ": bst1 != bst2" << endl;
	bst2.add("g");
	bst2.add("d");
	bst2.add("k");
	cout << ((bst1 == bst2) ? "OK" : "ERR") << ": bst1 == bst2" << endl;
	cout << (bst1.contains("d") ? "OK" : "ERR") << ": bst1 contains d" << endl;
	cout << (bst1.contains("x") ? "ERR" : "OK") << ": bst1 does not contain x" << endl;
	cout << (bst1.add("g") ? "ERR" : "OK") << ": adding g second time returns false" << endl;
	//treeMenuString();
	treeMenuInt();
	cin.get();
	return 0;
}


/*
 55 850 707 758 315 506 798 954 493 261 833 696 74 891 606 748 620 540 526 556 303 252 513 41 278 657 466 701 833 934 79 78 486 116 902 943 888 468 531 681 506 751 774 617 652 702 712 149 789 802 116 218 57 871 503 876 750 598 282 877 408 544 1000 629 172 466 449 299 847 927 827 401 731 351 32 399 675 39 223 322 897 462 416 508 951 238 212 130 161 522 108 501 58 204 398 945 567 647 294 877 915 412 821 916 975 577 499 338 921 465 871 539 843 206 281 597 707 609 757 14 273 203 896 348 635 879 93 948 398 866 848 723 919 783 598 477 118 563 623 479 52 544 846 741 74 598 469 275 448 154 792 394 652 5 51 236 437 883 554 900 39 99 964 599 945 741 504 959 717 450 809 189 936 238 917 187 541 771 688 187 472 602 544 884 58 48 588 797 934 609 252 149 51 920 874 289 148 899 524 911 377 490 524 508 710 678 117 316 208 774 11 426 952 61 420 44 23 473 832 919 483 406 132 94 129 221 831 700 316 909 276 66 318 12 581 550 337 278 810 773 473 633 224 300 21 282 615 830 62 438 883 778 713 912 428 953 350 474 79 791 588 522 145 411 876 143 189 228 948 559 547 243 14 784 555 509 645 77 595 739 290 778 437 570 57 729 657 399 904 700 781 498 120 688 338 551 323 703 57 950 505 741 448 152 107 626 826 850 761 569 769 807 103 296 364 486 450 876 88 775 881 713 580 285 311 387 609 7 162 169 992 239 666 5 194 435 919 910 12 549 834 77 364 495 213 531 698 295 759 168 195 974 800 661 809 968 397 742 808 573 452 153 406 100 8 69 490 618 788 634 7 498 319 663 532 553 790 241 129 352 262 407 49 169 62 486 245 559 237 69 903 700 14 374 457 19 608 914 916 292 829 672 234 176 571 189 664 330 108 421 490 103 143 174 138 555 322 518 205 488 262 772 917 267 311 679 592 200 982 62 810 960 612 511 872 784 647 44 753 958 302 16 710 690 499 661 439 113 756 662 568 793 576 508 546 661 759 53 557 691 440 785 577 198 481 154 237 574 403 55 708 475 626 863 812 768 323 528 163 833 640 664 21 869 783 308 497 75 330 905 798 242 965 212 695 281 401 731 308 203 471 655 579 761 306 69 579 837 399 836 292 938 63 999 784 731 691 255 964 551 742 893 287 709 564 76 230 228 925 909 472 952 274 621 583 385 738 316 864 309 821 698 238 845 906 932 597 43 423 193 346 765 10 953 103 256 746 520 810 83 119 203 308 677 602 918 417 235 486 766 721 437 719 104 767 357 726 836 965 664 222 647 499 73 373 568 662 824 672 92 621 604 297 689 657 501 154 750 635 481 596 522 398 212 441 308 325 585 833 244 271 461 107 976 347 874 63 306 485 787 941 325 333 362 616 42 57 445 432 66 486 989 962 207 706 93 979 163 838 843 714 122 615 986 446 653 459 56 587 319 111 901 803 19 411 429 316 735 751 376 807 845 674 1 613 395 717 869 334 272 519 588 997 88 921 286 460 859 2 54 675 934 911 833 437 299 730 121 804 737 14 56 80 836 627 684 926 352 598 552 548 659 109 776 37 35 652 123 44 46 711 354 322 745 32 724 465 647 590 114 70 979 3 453 889 832 553 813 120 578 148 184 849 524 596 859 951 757 790 559 332 365 863 414 435 825 334 235 851 676 972 44 59 762 645 204 583 851 217 339 33 969 79 677 266 841 50 723 151 53 948 893 64 56 352 55 74 668 853 614 305 283 142 835 521 256 97 478 94 707 50 178 156 829 18 301 381 662 132 771 406 228 600 294 28 313 487 129 838 523 164 970 969 987 357 386 973 730 617 222 93 591 280 603 60 651 194 143 77 165 136 378 817 897 598 208 684 977 450 206 860 758 382 305 363 326 602 86 981 496 121 720 839 255 238 484 891 554 893 434 716 259 643 102 956 616 604 755 716 750 580 347 940 384 134 865 300 567 232 201 162 652 765 590 67 719 52 701 104 586 794 889 548 546 803 424 535 618 453 811 952 174 262 542 190 992 644 55 878 132 505 812 874 311 579 867 45 391 694 657 36 26 513 669 831 575 575 315 780 17 829 211 999 305 457 657 964 202 611 626 4 190 699 669 197 467 799 398 262 183 344 211 763 425 737 112 505 925 731 141 629 694 722 520 807 204 816 284 131 510 164 163 61 23 514 80 243 344 812 86 362 730 556 44 762 592 798 693 111 404 390 399 996 272 843 488 626 396 508 723 
 */