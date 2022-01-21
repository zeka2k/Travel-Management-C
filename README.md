Problem description:

A Porto-based travel company, Porto-Pontos, offers travel planning services to its clients.
The aim is to develop a system to dynamically register and manage all the information
necessary for the operation of the Porto-Pontos company. In addition to recording all the
information, the company also intends to provide customers with information on the best
travel routes according to their destinations, so that they can select the best route to take.
As part of the trip planning service, Porto-Pontos maintains, for each registered user, a log of
past trips. User identification, cities visited and start/end dates are some of the information
that are present in this history. In addition to the travel history, each user record also has the
date of birth, registration date, address, contacts and billing information. For each city, the
system maintains geographic information and a set of points of interest.
Imagine, for example, that you wanted to travel to Australia, but given the large number of
places you would like to visit, there are countless possible routes to go through these points
in the most optimal way.

Let's assume that a customer intends to visit Australia, indicating to the company which
points they would like to visit in that country. The company starts by building a map with the
spatial distribution (x,y) of each location to be visited by the customer, as shown in Figure 1.
Based on the coordinates of each location, it is possible to calculate the Euclidean distance
(Pythagoras’ theorem) between every two points/places. Based on these distances, the
company intends to calculate the shortest route to go through all the places, starting in a
certain city, passing through all places once and returning to the starting point.
This problem is known as the Traveling Salesman Problem (TSP). It is a computationally
complex optimization problem because it requires exhaustively combining and comparing a
large number of possible paths. This is an NP-complete class problem, meaning that, in the
worst-case scenario, the execution time to find the best solution increases exponentially with
the number of points to visit.
Genetic Algorithm (GA)
There are several algorithms that can be used to find solutions for these types of problems.
In this project we will use a Genetic Algorithm (GA) that uses a research heuristic inspired by
Charles Darwin's theory of natural evolution of species. This algorithm reflects the natural
selection process where the fittest individuals in each generation (best paths found in that
generation) are selected for reproduction, most likely to generate new paths to form the next
generation of offspring, opening up more possibilities to improve the solution (shortening the
path between all the places to visit).
The approach of this algorithm allows us to find viable solutions in a non-exhaustive way and
therefore without going through the entire space of possible solutions. It does not guarantee
that the optimal solution will be found, but it usually allows you to evolve towards discovering
a better solution as you progress in the next generations. The total number of generations
considered, is usually a parameter of the AG.
In this algorithm, each path can be represented by an array containing sequentially the IDs
of the cities in the order they are going to be visited. For each route it will be possible to
calculate the total distance covered based on the Euclidean distance between each pair of
neighboring locations. The initial population of routes can be generated randomly, that is,
choosing possible visit sequences among the various places to visit using random
permutations.
In this algorithm, we would then have to represent the following information:
● Gene: city represented by an ID and its coordinates (x, y);
● Individual (aka Chromosome): path between cities, which satisfies the conditions of
the problem:
○ i) visit all cities;
○ ii) pass each city only once;
○ iii) return to the starting city;
● Population: set of possible paths, ie, a collection of Individuals;
● Parents: two possible pathways (parent individuals) whose genes are combined to
create two new pathways (two descendant individuals);
● Selection: operation of choosing, among individuals in the population of one
generation, pairs of parents to cross and originate pairs of offspring individuals for the
population of the next generation.
● Crossover: operation of combining genes from pairs of parents to generate the next
Population, ie, next generation of paths to be evaluated;
● Mutation: way of introducing variation in the population of paths, randomly swapping
two cities of a possible path;
● Fitness : function that allows you to measure the quality of an individual, ie, how
much better or worse a path is (in our case it may be the inverse of the path
distance);
● Elitism: criteria for transporting the best individuals to the next generation. It allows
the direct passage of some individuals to the next generation, thus preventing the
population from “worsening”.
The genetic algorithm (GA) repeatedly follows a set of steps, which can be summarized in
the following sequence:
1. Create the initial population with P individuals;
2. Determine the Fitness of each Individual in the Population;
3. Select pairs of individuals, the Parents, to be used to cross-breed the next
generation;
4. Generate, for each pair of parents, a pair of children for the next
Population/Generation by applying the operator Crossover to the selected
parents;
5. Apply mutations to the new generation individuals in order to increase
population variability;
6. Repeat the process from step (2).
For example, let's say we have N=6 cities to visit. Each city will be identified by an ID (0...5)
and characterized by two coordinates (x,y):
C0 = {id=0, coordinates={1.0, 0.0}}
C1 = {id=1, coordinates={ 1.0, 1.0}}
C2 = {id=2, coordinates={2.0, 1.0}}
C3 = {id=3, coordinates={2.0, 0.0}}
C4 = {id=4, coordinates={3.0, 0.0}}
C5 = {id=5, coordinates={3.0, 1.0}}
Create the Initial Population: we could generate an initial population with, for example, two
possible Individuals (paths). The size P of the initial population must be passed as a
parameter to the AG.
T1 = {0,1,2,3,4,5}
T2 = {0,2,3,1,5,4}
Determine the fitness of each Individual in the Population: we can calculate the fitness
of each Individual (cf. trajectory ), as being the inverse of the sum of the distances between
all pairs of nodes of this trajectory, ie
fitness(T1) = 1 / (dist(C0,C1) + dist(C1, C2) + ... + dist(C4, C5) + dist(C5, C0))
fitness(T2) = 1 / (dist(C0,C2) + dist(C2, C3) + ... + dist(C5, C4) + dist(C4, C0))
In this way we can obtain a list of Individuals, which can be sorted from highest to lowest
fitness value..
Select the set of Crossovers: select the set of Parents that will be used to generate the
next generation, combining the following approaches:
● Fitness Proportional Selection (aka Roulette Wheel): defines a weighted probability
(P) depending on the fitness of each Individual, that measures the suitability to be
selected. For example, in a set of N individuals, where Ai is the fitness of Individual i,
its probability could be calculated by Pi = Ai / (thus normalizing all Pi in an𝑗=1
𝑁
∑𝐴𝑗
interval/scale [ 0.1]). Having the Pi for all individuals, then random numbers between
0..1 can be generated allowing to choose the individuals according to the range of
their probabilities;
● Selection by elitism: Individuals with the greatest fitness value can also be included in
the new generation, ensuring that the fittest persist throughout the generations.
Generate the next Population: carry out the crossovers between the genes of the pairs of
parents in order to create two new Individuals for the new generation (NB: keeping the 3
problem conditions defined above). We need to define a crossover function between
Individuals, such as choosing a random subset of genes from the first parent and then filling
in the remaining genes from the second parent in the order they appear (and vice versa),
without duplicating any genes from the selected subset of the first parent. For example, if we
were to generate the children T3 and T4 by crossing the parents T1 and T2, we could
randomly select from T1 and T2 the subsequences of 3 cities {1,2,3} and {2,3,1}, which
would be then crossed / exchanged for T3 and T4 (keeping the remaining elements of the
parent individuals):
T1 = {0,1,2,3,4,5}
T2 = {0,2,3,1,5.4 }
T3 = {0,2,3.1,4,5}
T4 = {0,1,2,3,5,4}
In this case, if we had more Individuals (paths) in the set of Crosses, then we could select
directly the E best Individuals (with higher Fitness scores) for the new generation (elitism).
The number E of individuals who would pass to the next generation through elitism is one of
the parameters passed to the GA.
To introduce more diversity into the solutions found, mutations in the genes of individuals
from the new generations must also be used. This way, new individuals (trajectories) are
introduced eventually allowing for the exploration of other solutions. Each gene, from each
individual in the population of each generation, can, with independent probability Q, be
mutated/altered. In the example we have been following, if for a given gene the value drawn
between 0 and 1 was less than Q (probability of mutation), then that gene would be changed
from its original ID, ID1, to a new ID, ID2, which would be chosen from the range of possible
IDs. We could then proceed to an exchange between pairs of cities (genes) of the same
individual, exchanging ID1 and ID2.
Finally, we can repeat the previous loop, during G generations, with G being another of the
parameters passed to GA.
It will be important, however, to be able to follow the evolution of the Individuals (trajectories)
of different generations and their respective distances, throughout the execution of the
algorithm. For that, we must store data from the GA execution in a linked list (e.g. fittest
individual (shortest trajectory) and respective distance in each generation). By completing
this procedure, we will be able to print or save on a file, at the end of the execution, an
evolution graph from the solution (distance from the best Individual (trajectory/path) of each
generation versus the number of generations executed).
In summary, the following parameters are required for this algorithm:
● P: initial population size (even number) for each generation (example P=20)
● Q: mutation probability for a given gene (example Q=0.01)
● E: number of individuals that directly pass through elitism to the next generation
(even number E, with E < P; example E=2)
● G: number of generations to be performed by GA (example AG=50)
● N: number of cities which represent the number of genes in each individual or
chromosome (example N=6)
To support the GA generation process, implementation of structures which allow the storage
of data inherent to this process will be required. As such, each task is expected to contain
the following structures:
- Population consisting of an array of array(s) of Integers (with each array of Integers
representing an Individual which stores a possible path);
- Linked list where each element represents the information collected by each
generation/iteration of the GA;
- Square matrix with pre-calculated Euclidean distances between city pairs (may
contain only the lower or upper half of the matrix);
Below you can find a summary of the requirements to consider for this project.
