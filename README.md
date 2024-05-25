# merge_sort_cpp

Custom implementation of the merge sort algorithm in C++ using standard library only.

Made for educational purposes.

## Description

The data being processed in this implementation has a format of *`(k,v)`* pair, where *`k`* is an integer and *`v`* is a string of any length. The sorting is done by these pairs in the ascending order.

So for instance, while having an input of:

```txt
4
3 log
2 log log
1 loglog
0 logloglog
```

..the resulting data would be the following:

```txt
4
0 logloglog
1 loglog
2 log log
3 log
```

The return code of the implementation is:

- `0` if all works as expected;
- `1` if user-specified arguments do not match the pattern;
- `2` if input file is unreadable or writing output is not possible;
- `3` if the input data format is incorrect.

## Compiling

This implementation can be compiled with `g++`:

```sh
g++ src/main.cpp -o merge_sort
```

This will produce an executable file named `merge_sort`.

## Usage

Below is a sample command of using this implementation:

```sh
./merge_sort input.txt output.txt
```

Here, `input.txt` is an existing file with initial data, while `output.txt` is the name of the file that will be created to contain the sort result.

## References

- [Wikipedia](https://en.wikipedia.org/wiki/Merge_sort): Description of the merge sort algorithm.
