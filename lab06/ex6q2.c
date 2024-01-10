#include "ex6q2.h"

// Please don't change anything in this main function!
int main(void) {
    if (!test_bubble(bubble_sort))
        fprintf(stderr, "Bubble sorting failed\n");
    if (!test_gnome(gnome_sort))
        fprintf(stderr, "Gnome sorting failed\n");
    if (!test_insertion(insertion_sort))
        fprintf(stderr, "Insertion sorting failed\n");
    if (!test_custom(custom_sort)) {
        fprintf(stderr, "Custom sorting failed\n");
	}
	return 0;
}

void bubble_sort(int n, int arr[n]) {

}

// Not very well known, but very easy!
// Check out the description on here https://en.wikipedia.org/wiki/Gnome_sort
void gnome_sort(int n, int arr[n]) {

}

void insertion_sort(int n, int arr[n]) {

}


// The sort you found! (See lab description for details)
void custom_sort(int n, int arr[n]) {

}
