m = zeros(Int, 1000, 1000)
λ = (p) -> for x in p[1]:p[3], y in p[2]:p[4] m[y, x] += 1 end
map(p -> λ(p), filter(p -> true,# p[1] == p[3] || p[2] == p[4],
    map(l -> map(x -> parse(Int, x) + 1, 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
        readlines("input")
    ))
)
for i in 1:10
    for j in 1:10
        print(m[i, j])
    end
    println()
end
println(count(x -> x >= 2, m))