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
- stop simulation right after a thread died
    - check return values of pthread_join()
    - print some text in the main to check when a thread died
- prevent deadlocks
    - read pdf and understand


# Why learn about Assembly?
- to better understand the need for mutexes
- how threads fight for ressources
- understand the steps involved in change the value of a variable