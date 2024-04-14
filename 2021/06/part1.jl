pop = zeros(Int, 9)
map(x -> pop[parse(Int, x) + 1] += 1, split(readline("input"), ","))
λ = (cyc) -> begin
    for i in 1:cyc
        cur = zeros(Int, 9)
        for j in 2:9 cur[j - 1] = pop[j] end
        cur[9] += pop[1]
        cur[7] += pop[1]
        global pop = copy(cur)
    end
end
println(sum(pop))