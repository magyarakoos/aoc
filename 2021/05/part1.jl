m = zeros(Int, 1000, 1000)
λ = (p) -> for x in p[1]:p[3], y in p[2]:p[4] m[x, y] += 1 end
map(p -> λ(p), filter(p -> p[1] == p[3] || p[2] == p[4],
    map(l -> map(x -> parse(Int, x), 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
        readlines("input")
    ))
)