Variables I need to free
- data->ids[] 



# Pseudocode
- check for valid user input
- store user input
- create as many threads as there are philosophers
- give them the same routine/instructions to execute
    1. pick two forks (2 mutex)
    2. eat (ms)
    3. sleep (ms)
    4. think 
    5. repeat until:
        - a philo dies
        - or, they've eaten their maximum number of meals

# To-do
## Bugs
- philo eats more than set meals


# Why learn about Assembly?
- to better understand the need for mutexes
- how threads fight for ressources
- understand the steps involved in change the value of a variable

|Tests| Description|
|---|---|
|<b>alone</b>||
|1 800 200 200||
|<b>many philo, no meals limit</b>|df|
|4 310 200 100|
|4 200 205 200|

|<b>set meals limit</b>| no one should die, simulation should stop after 7 eats|
|5 800 200 200 7||
|4 410 200 200 10||
|5 800 200 200 7|

|should error and not run (no crashing)|
|-5 600 200 200| 
|4 -5 200 200|
|4 600 -5 200|
|4 600 200 -5|
|4 600 200 200 -5|