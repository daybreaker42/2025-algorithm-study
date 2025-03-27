# 10_10799.py - Laser Cutting Pipes

def main():
    brackets = input().strip()
    
    # Solving
    pipes_stacked = 0
    total_pieces = 0
    
    i = 0
    while i < len(brackets):
        if brackets[i] == '(' and i + 1 < len(brackets) and brackets[i + 1] == ')':
            # Laser detected
            total_pieces += pipes_stacked
            i += 2  # Skip both parentheses
        elif brackets[i] == '(':
            # New pipe starts
            pipes_stacked += 1
            i += 1
        else:  # brackets[i] == ')'
            # Pipe ends
            pipes_stacked -= 1
            total_pieces += 1
            i += 1
    
    print(total_pieces)

if __name__ == "__main__":
    main()

# comment
# - When a laser appears () -> add the number of current stacked pipes to the result
# - When a pipe ends ) -> add 1 to the result (one additional piece at the end)
# - Keep track of how many pipes are currently stacked
