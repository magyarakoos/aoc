m = zeros(Int, 1000, 1000)
λ = (p) -> for x in p[1]:p[3], y in p[2]:p[4] m[x, y] += 1 end
map(p -> λ(p), filter(p -> p[1] == p[3] || p[2] == p[4],
    map(l -> map(x -> parse(Int, x) + 1, 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
        readlines("input")
    ))
)
for i in 1:20
    for j in 1:20
        print(m[])
end
println(count(x -> x >= 2, m))