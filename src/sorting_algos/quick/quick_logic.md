We need a recursive function:

// pstack = primary stack
// sstack = secondary stack
static void set_pivot_rec(t_stack_item *Pstack, t_stack_item *Sstack, int length)
	if (len > PIVOT_THRESH)
		set a new pivot at the median between 0 and length on primary
		move all of the numbers larger than median to secondary stack
		execute yourself with switched stacks and the length being the amount of
			elements you just pushed over
		pull elements back to primary, rotate primary back to where you started,
		apply yourself without switched stacks and length set to 0 -> median
	if (len <= PIVOT_THRESH)
		sort elements between 0 and length on primary stack
		theres nothing keeping you from using secondary stack as long as
			you clean up, so could even use insertion sort (though bubble
			sort may actually be more efficient up to a certain number of
			elements. find that out and set the PIVOT_THRESH to that.)

// ESSENTIALLY:
Every odd recursive depth has e.g. a as primary and b as secondary, where
	that is switched for every even depth.
	This should work well as long as we never leave any elements inside of the
	other stack accidentally & never move anything outside of the 0 -> length range