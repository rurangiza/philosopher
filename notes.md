Variables I need to free
- data->ids[] 



# Thought process
I created as many threads as philosophers

The challenge of this project is to organize threads in sequence

since all want to do their tasks at the same time, we need to give access to one thread at a time


1. pick a thread
2. unlock the fork of his neighbour (next)
3. pick both forks
3. start the routine
4. lock both forks
5. go to next thread