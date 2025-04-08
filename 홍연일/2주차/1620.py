import sys

n, m = map(int, sys.stdin.readline().split())
name_to_number = {}
number_to_name = {}

for i in range(1, n + 1):
    pokemon_name = sys.stdin.readline().strip()
    name_to_number[pokemon_name] = i
    number_to_name[i] = pokemon_name

for _ in range(m):
    query = sys.stdin.readline().strip()
    
    if query.isdigit():
        print(number_to_name[int(query)])
    else:
        print(name_to_number[query])
