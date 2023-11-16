# push_swap by @fschuber Changelog

### todo
- check whether number input is valid in init

### v0.0.3
- Added turn_on_gravity function to remove all empty spaces in stacks and move everything to the front of the array
- pa + pb were invalid - stacks should have 'gravity', there shouldn't be empty spaces inside. Fixed.
- a VERBOSE macro now defines whether the output expected in the subject is printed (0) or a bunch of messages and logging helpful to understand the workings are printed (1)
- redid bubble sort. its better now!

### v0.0.2
- Added Bubble sort to start working with subject operations
- Added operations int in t_stacks to keep track of operations count

### v0.0.1
- Added README.md with subject
- Added ft_printf + libft submodules & header file
- Added Makefile
- Added stacks & stack_item structs for easy data handling
- Added init_stacks() for initialization, print_stacks() for data checking and free_stacks() for save deletion
- Added a function for every operation specified by the subject.

### v0.0.0
- Project intialization & repo setup