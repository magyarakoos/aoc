pop = zeros(Int, 9)
map(x -> pop[parse(Int, x) + 1] += 1, split(readline("input"), ","))
