# push_swap by @fschuber Changelog

### v1.0.4 - 30.11.23
- Valgrind memory leak grand fixage!
	- main freeing logic fix
	- stacks.operations not being initialized if input is in string format fix
- makefile changes

---

### v1.0.3 - 28.11.23
- some minor changes to input parsing, int error checking & main return value

### v1.0.2 - 27.11.23
- back from holidays, final changes before hand in. restructuring of checker ex_line and makefile changes

---

### v1.0.1 - 23.11.23
- since i cant retry handing it in yet and i wanna be done with the project i made a beautiful and colorful readme with graphs.
- also updated the scripts a little

---

### v1.0.0 - 22.11.23
- First grading attempt failed. Will have to wait a couple days to retry. There was a problem with one error condition, the INT limits one. Really stupid mistake, but that's exactly what code reviews are good for. But at least now I know that the rest of my project is flawless and hand in ready.
- created stacks_number_input file which does an atoi while checking for valid int range. if outside of range, it exits program. made input management functions call this file.
- made sure number larger than long range that wrap around to be within int range also get picked up as an error
- removed fsanitize from makefile, last time i accidentally handed in the project with that flag still on

---

### v0.2.1 - 21.11.23
- started work on checker.
- imported get_next_line as submodule
- Made all operations take a bool int as a parameter to indicate whether to print out the operation so we can reuse the same functions from the checker program and from teh main program.
- finished up work on checker. was really easy since i could reuse pretty much all functions.
- thats it actually. will start first grading attempt now.

### v0.2.0 - 21.11.23
- did some error handling for when there is the same number multiple times & for when an input is outside of int range
- made a function that detects when everythings already sorted and exits the program
- fixed case where there is only 1 input by handling it explicitly
- i am now completely prepared for all the tests in the non-bonus tier. bonus time! (sounds like an occasion worthy of version number incrementation.)

### v0.1.5 - 21.11.23
- made input possible via "5" "6" "2" format or "5 6 2" format. Thanks to this, the checker program now runs through successfully.
- correct displayed errors in stderr as stated in subject

### v0.1.4 - 21.11.23
- added cheap_quick algorithm, which just splits the numbers in a and b and then applies bubble sort. still more efficient than any other algorithm for values 5 - 9 though!
- did a lot of testing. the steps now never go over the subject boundaries. that means im done! time to finish up.

### v0.1.3 - 21.11.23
- removed whole results logic. it was unnecessary, it didnt actually improve the program much but increased complexity a lot
- added a finetuning.sh script that iterates through different input amounts which can then be compared between different scripts. turns out, theres no need for insertion sort at all. the small area where it would be a little better than k sort is also where bubble sort is even better. so no insertion sort!
- i went on a big commenting spree and made sure every function was at least a little documented
- using a modification of the get_average script that also prints out the largest ever occurring number of operations. every case works but the case with 5 inputs, my program goes over 12 steps there.

---

### v0.1.2 - 20.11.23
- Added proper norm link
- Made results save 0 for removed results during optimization, previously used NULL which was a problem with printing them out. Printing still doesnt work but were getting there (hopefully). Bubble and K work as expected, but peculiarly, insert doesnt, and i dont understand why.

### v0.1.1 - 20.11.23
- Added results_optimizer than picks out any redundancies in result and removes them.
- made insertion sort and k sort work with new result format so they can also be optimized before being outputted. to do this, i added a do_operation function that increments the operations counter, does the operation, and adds it to the result tracker
- removed print statements from operation functions to fully switch to new system
- removed system print statements to get ready for submission
- removed quick sort as it will not be submitted. if i ever want to fix the issues there, i get can get it out of the git history.
- printing of results with new system is still flawed. I get memory leaks.
- large variety of code refactoring & improvements, norminette is now without errors

### v0.1.0 - 20.11.23
- fixed sorted index assignment
- removed bin folder, changed executable location
- made k sort work and made my life a lot easier by introducing a swap_item_properties function and using it in all the operation functions
- functional pretty efficient sorting from 0 to 500 inputs. incrementing version number!
- started adding results tracker to replace directly printing, for now only in bubble sort

### v0.0.14 - 20.11.23
- various code readability & norminette improvements
- simplified get_median and push_numbers_after_median functions with some performance improvements
- Added a list of known tricky cases. when theres a check, its been fixed. Should go through and test them all before handing in.
- quick sort doesnt work at all its really quite painful

### v0.0.13 - work in progress branch - 20.11.23
- further k sort finetuning
- fixed problem in quick where input of 6 elements would crash by not thinking about it and changing stuff about the code for so long i fixed whatever the problem was on accident
- massively reduced length of bubble sorts for quick. also put them into their own file
- added 42 norm pdf to readme so people can read through rules & removed .vscode folder from gitignore for use on other pcs
- added a visualizer as new submodule because its cool and potentially helpful (https://github.com/o-reo/push_swap_visualizer). to use, execute using '../submodules/push_swap_visualizer/build/bin/visualizer' and put '../bin/push_swap' as executable.
updated v0.0.15: '../push_swap'
- merged back to master

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
