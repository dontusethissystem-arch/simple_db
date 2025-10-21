import random
import numpy as np

# ---- Problem setup ----
# Let's define cities as random 2D points
def create_cities(n=10, seed=42):
    random.seed(seed)
    return [(random.randint(0,100), random.randint(0,100)) for _ in range(n)]

def tour_length(tour, cities):
    dist = 0
    for i in range(len(tour)):
        x1, y1 = cities[tour[i]]
        x2, y2 = cities[tour[(i+1) % len(tour)]]
        dist += ((x1-x2)**2 + (y1-y2)**2)**0.5
    return dist

# ---- GA components ----
def init_population(pop_size, n_cities):
    return [random.sample(range(n_cities), n_cities) for _ in range(pop_size)]

def fitness(tour, cities):
    return 1.0 / tour_length(tour, cities)

# Tournament selection
def select(pop, cities, k=3):
    contenders = random.sample(pop, k)
    return min(contenders, key=lambda t: tour_length(t, cities))

# Order crossover (OX)
def crossover(p1, p2):
    n = len(p1)
    a, b = sorted(random.sample(range(n), 2))
    child = [None]*n
    child[a:b] = p1[a:b]
    pos = b
    for c in p2:
        if c not in child:
            if pos == n: pos = 0
            child[pos] = c
            pos += 1
    return child

# Swap mutation
def mutate(tour, prob=0.1):
    t = tour[:]
    if random.random() < prob:
        i, j = random.sample(range(len(t)), 2)
        t[i], t[j] = t[j], t[i]
    return t

# ---- GA main loop ----
def genetic_algorithm(cities, pop_size=100, generations=500):
    pop = init_population(pop_size, len(cities))
    best = min(pop, key=lambda t: tour_length(t, cities))
    best_len = tour_length(best, cities)

    for g in range(generations):
        new_pop = []
        for _ in range(pop_size):
            p1 = select(pop, cities)
            p2 = select(pop, cities)
            child = crossover(p1, p2)
            child = mutate(child)
            new_pop.append(child)
        pop = new_pop
        candidate = min(pop, key=lambda t: tour_length(t, cities))
        cand_len = tour_length(candidate, cities)
        if cand_len < best_len:
            best, best_len = candidate, cand_len
            print(f"Gen {g}: Best length = {best_len:.2f}")
    return best, best_len

# ---- Run ----
cities = create_cities(20)
best_tour, best_len = genetic_algorithm(cities, generations=200)
print("Best tour:", best_tour)
print("Best length:", best_len)
