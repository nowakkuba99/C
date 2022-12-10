## External Sort project 
This repo contains the source files along with basic tests for External Sorter project. It is implemented entirely in C++ with Google Tests module used for Unit testing.

External sorting is used when the file size is much bigger than avaiable RAM memory - so the whole file cannot be read into memory and sorted there.
The main steps for the algorithm are presented below:
1. Divide input file into K blocks of size N or smaller. Where N is the maximum avaiable RAM memory. All the blocks will be of size N with possible smaller size for the last block if the block size N will not be a divider for the input file size.
2. Load each block of size N into memory and perform quick sort on it.
3. Save sorted block into file. If the input file is to stay in memory that is cannot be overwritten the memory complexcity will be 3Q where Q is the input size (since Q is the input file, second Q are the current generation of sorted files and third Q is the new generation that is going to replace current generation).
4. Perform merging of K sorted lists (blocks) until there will be only 1 file left
5. Finish
