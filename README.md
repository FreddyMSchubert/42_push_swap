# push_swap
(because swap_push just isn't as natural.)

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/push_swape.png" alt="Push_swap 42 project badge"/><br>
</p>

> This project was created in compliance with the 42 norm, which means no ternary operators, no switches, no for loops, no in function comments, ... -> https://github.com/FreddyMSchubert/42_cursus/blob/main/en.norm.pdf

![Kextreme gif](https://github.com/FreddyMSchubert/42_push_swap/blob/master/assets/readme_assets/kextreme.gif?raw=true)

## Subject

```
[2] [ ]
[1] [ ]
[3] [ ]
[6] [ ]
[5] [ ]
[8] [ ]
 a -- b
```

Given 2 stacks a and b where b is emtpy and a is filled with a random amount of non-duplicated signed integers, sort numbers in ascending order into stack a with the following operations:

| Command | Description                                                        |
|---------|--------------------------------------------------------------------|
| sa      | Swap the first two elements at the top of stack a                  |
| sb      | Swap the first two elements at the top of stack b                  |
| ss      | Swap the first two elements at the top of both stacks              |
| pa      | Take the first element at the top of b and put it at the top of a  |
| pb      | Take the first element at the top of a and put it at the top of b  |
| ra      | Shift up all elements of stack a by 1. The first becomes the last  |
| rb      | Shift up all elements of stack b by 1. The first becomes the last  |
| rr      | Shift up all elements of both stacks by 1. The first becomes the last |
| rra     | Shift down all elements of stack a by 1. The last becomes the first |
| rrb     | Shift down all elements of stack b by 1. The last becomes the first |
| rrr     | Shift down all elements of both stacks by 1. The last becomes the first |


Allowed external functions:
- read, write, malloc, free, exit

## Usage
1. Clone the repo
2. To run it, you can do the following:
```C
./push_swap 3 1 5 8 2 7		// runs the executable
./run_push_swap.sh 25		// runs the executable with 25 random inputs
./get_average.sh 100 30		// runs the executable with 30 random inputs
							// 100 times and prints average, lowest and highest values
./finetuning.sh 1 50 100	// gets the average from 100 executions with random inputs
							// for all values between 1 and 50.
```
3. In the header file, the VERBOSE macro can have the following values:
	- 0  -> normal, subject specified program output
	- 1  -> detailed logging
	- -1 -> outputs 0 output + the amount of operations. useful for e.g. get_average script

## Approach

1. The operation efficiency matters, and while the program should be relatively performant, there's absolutely no problem e.g. creating a sorted stack as the very first thing to simplify things like finding a median.
2. One algorithm alone is not going to cut it.

I started out implementing a bunch of algorithms and seeing how efficient they would turn out to be. Here's what I made:

> To be clear, these are all pretty different to their usual implementations. I just called the algorithms what they most closely resembled.

### Unused Algorithms

<strong>Insertion Sort:</strong> First, push all elements into stack b. Then, continue rotating b to the highest element possible and pushing it back to stack a until the stack is sorted.<br>
	<em>Why is it not included:</em> We lose a lot of moves where we do no sorting at all by pushing things to b. If we can find a way to sort the elements a little while pushing to b and then ensure correct order when pushing back, we'd be much better off. (-> K Sort)

<strong>Quick Sort:</strong> Recursively, pick a pivot, push everything above the pivot to the other stack, and call yourself on both halves. When you get called and your selected area is below a threshhold, apply bubble sort instead of setting another pivot.<br>
	<em>Why is it not included:</em> This would have been the most complicated algorithm, and I didn't get it done before coming into contact with K sort, which blew it out of the water in terms of efficiency.<br>

### Used Algorithms

<strong>Bubble Sort (< 5 stack-len):</strong> If the current value is larger than the next, swap them, otherwise rotate the stack.<br>
	<em>Problem:</em> Since the stacks wrap around, you will go in an infinite loop.<br>
<em>Solution:</em> Just don't swap the elements if the element at index 0 is the one that will end up being at the very end of the sorted stack.

![Bubble GIF](https://github.com/FreddyMSchubert/42_push_swap/blob/master/assets/readme_assets/bubble.gif?raw=true)

<strong>Cheap Quick Sort (< 10 stack-len):</strong> Quick sort, but it's not recursive. You just set a pivot once and apply bubble on both halves.<br>
<em>Why have it at all:</em> Because surprisingly, it actually surpasses both bubble and k sort in operation efficiency for some low-range values.

![Cheapquick GIF](https://github.com/FreddyMSchubert/42_push_swap/blob/master/assets/readme_assets/cheapquick.gif?raw=true)

<strong>K Sort (> 9 stack-len):</strong> Insertion sort, but with some sorting while pushing values over to b. This pre-sorting only occurs within a certain stack-len relative range though. This creates a K-like shape in b and can be pushed back to a while finishing the sorting very efficiently.<br>

![K GIF](https://github.com/FreddyMSchubert/42_push_swap/blob/master/assets/readme_assets/k.gif?raw=true)

## Performance
> These values are averages over many program calls with random numbers. Test the performance yourself with the /build/get_average.sh script.

<div>
    <a href="https://plotly.com/~ottoottootto/1/?share_key=zNIWNRe4Pu1EGi9qCprv4x" target="_blank" title="Plot 1" style="display: block; text-align: center;"><img src="https://plotly.com/~ottoottootto/1.png?share_key=zNIWNRe4Pu1EGi9qCprv4x" alt="Plot 1" style="max-width: 100%;width: 600px;"  width="600" onerror="this.onerror=null;this.src='https://plotly.com/404.png';" /></a>
</div>

_click on the image to get an interactive graph_

| Inputs | Operations |
|--------|------------|
| 3      | 1.49       |
| 5      | 8.91       |
| 10     | 34.27      |
| 25     | 100.79     |
| 50     | 238.85     |
| 100    | 578.47     |
| 200    | 1463.09    |
| 300    | 2521.83    |
| 400    | 3742.26    |
| 500    | 5096.81    |
| 1000   | 13500.86   |

---

Made by Frederick Schubert: fschuber@student.42heilbronn.de | http://frederickschubert.de
