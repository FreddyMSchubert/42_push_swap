# push_swap by @fschuber Changelog

### todo
- Fix sorting problem for input of exactly 6 elements.
- function that merges a and b operations into single sa, sb -> ss e.g. and also removes redundant operations, e.g. pa pb, ra rra
ra - rra right after one another can also be merged
- remove printf statements before submitting

---

### v0.0.12 - work in progress branch - 19.11.23
- fixed the ascending bubble sort, but its now way too long, will need to optimize
- heard of a custom "k sort" algorithm, implemented it functionally. it is not yet the greatest.
	i do know however from others it can be great so i need to revise it still.
	i made a script to rapidly execute the program 500 times and get the average of the operations. using it, i finetuned the range value in the k sort. the results for the multiplier were:
	```
	1.0 - 1580
	1.4 - 1559
	1.5 - 1573
	1.6 - 1439
	1.7 - 1567
	1.8 - 1561
	2.0 - 1562
	```
	therefore, ill be moving forward with 1.6 as multiplier

### v0.0.11 - work in progress branch - 19.11.23
- Made asc and desc bubble sorts also call corresponding correct order check
	function, that wasn't going to work. Quick now runs through
- Made fix to those check functions to not check for whether elements outside
	of size are sorted, previously did not consider rotations
- created a good debugging setup & tried debugging, but didnt really get anywhere.
	its clear the problem is the bubble sort which doesnt always sort correctly.
- various improvements

---

### v0.0.10 - work in progress branch - 18.11.23
- made bubble sort return to same rotation as before. obviously it cant work like this.
- Various improvements to quick sort logic & implementation

### v0.0.9 - work in progress branch - 18.11.23
- Continued work on quick. Base case works (bubble sort). problem is that if you
	input anything that doesnt just directly get thrown into the base case,
	function returns untrue result. whoops. I can feel maaany print statements
	coming. The pivoting does seem to work though, just the recursive repivoting
	or sorting after pivoting needs work.
- there was an address issue. saved in in error.md for later


### v0.0.8 - work in progress branch - 18.11.23
- added check_argument_validity util function to ensure that an error gets thrown if some of the args arent numbers
- added exit_error function that prints error message, frees stacks, then exits
- enhanced readme readability
- Added a bunch of files related to quick sort algo

---

### v0.0.7 - 17.11.23
- added fsanitize & fixed some issues it pointed to. now issue free!
	- freed stacks at end of program
	- removed ft_tile_arraylen to instead keep track of array lengths within struct. changed everything that reference that function & made sure to keep heights updated
- fixed previously unnoticed problem in bubblesort. the random numbers sh file is great at finding bugs! lead to way less code & slight performance improvement, for 9 8 7 6 5 4 3 2 1 0, it went from 117 to 107

### v0.0.6 - 17.11.23
- Added build/run_push_swap.sh. It executes push_swap bin with random numbers in signed int range, amount of numbers is specified by first parameter.
- Added check to main whether output was correctly sorted, will probably be helpful for long inputs. (Also, I basically just did the bonus.)
- fixed insertion sort issues. Its not very efficient, but thats just because its insertion sort. will merge branches!

---

### v0.0.5 - work in progress branch - 16.11.23
- started figuring out problems in insertion, marked by comments. not fixed yet but on the way there.

### v0.0.4 - 16.11.23
- made check_correctly_sorted accept any array of type t_stack_item, so it doesnt just run through a
- made the program save the correctly sorted array as one of the struct parameters.
- Started creating insertion.c, logic has potential but does not fully work yet.
	- todo: rotation to highest number in b before returning
	- todo: find source of occasional mistakes in ordering

### v0.0.3 - 16.11.23
- Added turn_on_gravity function to remove all empty spaces in stacks and move everything to the front of the array
- pa + pb were invalid - stacks should have 'gravity', there shouldn't be empty spaces inside. Fixed.
- a VERBOSE macro now defines whether the output expected in the subject is printed (0) or a bunch of messages and logging helpful to understand the workings are printed (1)
- reworked bubble sort. its better now!

---

### v0.0.2 - 15.11.23
- Added Bubble sort to start working with subject operations
- Added operations int in t_stacks to keep track of operations count

### v0.0.1 - 15.11.23
- Added README.md with subject
- Added ft_printf + libft submodules & header file
- Added Makefile
- Added stacks & stack_item structs for easy data handling
- Added init_stacks() for initialization, print_stacks() for data checking and free_stacks() for save deletion
- Added a function for every operation specified by the subject.

### v0.0.0 - 15.11.23
- Project intialization & repo setup