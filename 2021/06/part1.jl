pop = zeros(Int, 9)
map(x -> pop[parse(Int, x) + 1] += 1, split(readline("input"), ","))
for i in 1:80
    cur = zeros(Int, 9)
    for j in 2:9 cur[j - 1] = pop[j] end
    
end