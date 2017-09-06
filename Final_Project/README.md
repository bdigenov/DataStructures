Reddit Joke Data Structures Project
==========
*Friday December 9, 2016*

### Project Members  
Brittany DiGenova (bdigenov), Collin Klenke (cklenke), and Margaret Thomann (mthomann)

### Installation
To compile the code, simply type ```make``` to compile the relevant C++ in the project repository.  To run the code, type the executable ```./custom``` if you would like to use the custom map implementation with separate chaining or ```./standard``` if you'd like to use the standard implementation.  A greeting message will show and then you can type the word or phrase you would like to find a joke for.  Press Enter and wait for the result!

### Overall Description
In order to interact with the Reddit API, we used Python and to store the joke inside the data structure, the C++ interacts with this Python.  After running the program, the user is asked what they would like their joke to be about.  This input is then parsed by the C++ so that any words that don't apply to the joke (such as "tell me a joke about") can be ignored according to the ```ignore.txt``` file.  The C++ then checks the map to determine if this is a new word that the map can simply supply a joke for since a joke has already been stored in a text file or if the C++ program (```jokebot.cpp```) needs to communicate with the python to determine a new joke.  If the joke is already in the text file ```joke.txt```, it prints out the jokes associated with that word in the file.  Otherwise, the Python script (```run_python.sh```) is called so that the joke can be looked for in the Reddit thread r/jokes. ```run_python.sh``` runs the ```waybetterbot.py``` file with an argument of the word we're searching for in the Reddit thread.  ```waybetterbot.py``` then retrieves a joke and writes it to a temporary file ```temp.txt```.  From there, the C++ then ends up printing out the joke and adding it to the joke storage file ```joke.txt```.  Separate chaining was implemented in the C++ implementation of the joke map in ```jokebot.cpp``` by declaring an instantiantion of the custom class JokeMap in the ```joke_map.h``` file as the **novel use of a data structure** for this project.

*tl;dr:* We wanted to make something fun with Reddit and maps.

### Purpose of Each File
Below is a table that describes the purpose of each file in the repository.

| FileName                  |           Purpose             |
|---------------------------|-------------------------------|
| ```ignore.txt```          | Contains words to ignore when searching for jokes and parsing input |
| ```joke_map.h```          | Implementation of custom map class ```JokeMap``` with separate chaining |
| ```joke.txt```            | "Joke book" or cache of where recently searched jokes are stored |
| ```jokebot.cpp```         | Main C++ driver file for the project that parses user input, calls unix script to run the Python, and adds to the map using the custom ```JokeMap``` class |
| ```Makefile```            | Used to compile the files: ```make``` to compile everything, ```make custom``` to compile the custom map implementation with separate chaining, ```make standard``` to use the standard c++ map implementation, ```make test``` to run all of the tests |
| ```mybot.py```            | File used to learn Reddit interactions |
| ```redditbot.cpp```       | Main C++ driver file for the project that parses user input, calls unix script to run the Python, and adds to the map using the standard map C++ container |
| ```run_python.sh```       | Script that runs the Python to interact with the Reddit API |
| ```temp.txt```            | Temporary file the joke retrieved from Reddit is written to; deleted after it is no longer needed by the C++ driver program |
| ```waybetterbot.py```     | Python script that given a keyword, retrieves the joke associated with that word in Reddit using the Reddit API |

### Testing
All of the test code is located in the same folder as the project code (we tried using a separate test directory folder but ran into issues with cd-ing and capturing the output).  All of the tests that are performed are contained in the ```Makefile``` in this folder.  To test the code, simply run ```make test```.  The following is tested:
* **Correctness:**  Ensuring that *standard implementation of the map* output matches the *custom implementation of the map using separate chaining and a custom map class* output
* **Execution time:**  *standard implementation of the map* vs. the *custom implementation of the map using separate chaining and a custom map class*
* **Scaling through Consulting Execution Time:** Determining which map implementation (*standard* or *separate chaining*) scales better when the program is run for N = 5, 10, 20, 50 where N is the number of joke searches performed during the program execution and all of the jokes in N are *new* jokes.
* **Usefulness of the Joke Book Cache by Consulting Execution Time**:  Here, we looked at the execution time for jokes that were already added to the ```joke.txt`` file vs. the execution time for jokes that weren't yet in the file.  This is examining all jokes that are *old* jokes.

### Benchmarking Results
##### Correctness 
The tests ```test-output-standard``` and ```test-output-custom``` just check to make sure that by typing in "Hello", the code outputs the expected Reddit joke that corresponds to hello.  We ensured this was the expected output by going to the Reddit website.  The ```diff``` command is used in the ```Makefile``` to make sure the files match.

| Input   | Expected Output                                                                                                                          | Output with Standard Map                                                                                                               | Output with Custom Map                                                                                                                 |
|---------|------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------|
| "Hello" | YO! LET ME KNOW IF YOU WANT TO HEAR A JOKE. TYPE 'x' TO EXIT. "Hello, is this anonymous NSA hotline?" "Yes, David, how can we help you?" | YO! LET ME KNOW IF YOU WANT TO HEAR A JOKE. TYPE 'x' TO EXIT."Hello, is this anonymous NSA hotline?""Yes, David, how can we help you?" | YO! LET ME KNOW IF YOU WANT TO HEAR A JOKE. TYPE 'x' TO EXIT."Hello, is this anonymous NSA hotline?""Yes, David, how can we help you?" |

##### Scaling through Consulting Execution Time
Here we tested both implementations with a joke size of N = 1, 5, 10, 20 and 50 (files were created manually that include unique words for each size).  Neither map scaled particularly well with the execution time for N = 50 taking as long as at least 15 mins.  Our custom map implementation, however, usually wasn't significantly slower than the execution time for the standard map, which we were happy about!  We also discovered memory issues with our custom implementation at this stage but had already decideded to focus specifically on execution time when testing.  We removed the ```joke.txt``` file each time the program was run for each joke file input so this test purely tests scaling without caching.  In some cases, our custom map implementation was even faster than the standard one (for example in the case where N = 20 and when N = 5).  We are attributing these slight decrepancies potentially to the latency of the Reddit API.

| Number of Joke Searches Performed | Standard Map Execution Time (w/o caching) | Custom Map Execution Time (w/o caching) |
|-----------------------------------|-------------------------------------------|-----------------------------------------|
| N = 1                             | 0m14.021s                                 | 0m14.044s                               |
| N = 5                             | 1m20.644s                                 | 0m51.098s                               |
| N = 10                            | 2m45.147s                                 | 3m33.096s                               |
| N = 20                            | 5m28.727s                                 | 3m29.003s                                        |
| N = 50                            | 15m7.956s                                          | 15m29.229s                                         |
##### Usefulness of the Joke Book Cache by Consulting Execution Time
Here it is very evident that using the ```joke.txt``` file to include jokes that were already searched is significantly faster than searching for them again using the Reddit API.  This is true for N = 1, 5 and 10 which implies that the lookup in the ```joke.txt``` file is faster even for inputs of larger sizes.  

| Number of Joke Searches Performed | Standard Map Execution Time (w/o caching) | Standard Map Execution Time (w/ caching) | Custom Map Execution Time (w/o caching) | Custom Map Execution Time (w/ caching) |
|-----------------------------------|-------------------------------------------|------------------------------------------|-----------------------------------------|----------------------------------------|
| N = 1                             | 0m19.564s                                 | 0m0.006s                                 | 0m15.599s                               | 0m0.006s                               |
| N = 5                             | 3m0.101s                                  | 0m0.006s                                 | 2m56.864s                               | 0m0.006s                               |
| N = 10                            | 4m59.134s                                 | 0m0.006s                                 | 4m37.415s                               | 0m0.006s                               |

