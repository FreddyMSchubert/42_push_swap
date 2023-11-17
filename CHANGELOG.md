# push_swap by @fschuber Changelog

### todo
- check whether number input is valid in init

### v0.0.6 - 17.11.23
- Added build/run_push_swap.sh. It executes push_swap bin with random numbers in unsigned int range, amount of numbers is specified by first parameter.
- Added check to main whether output was correctly sorted, will probably be helpful for long inputs. (Also, I basically just did the bonus.)
- fixed insertion sort issues. Its not very efficient, but thats just because its insertion sort. will merge branches!

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