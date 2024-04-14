m = zeros(Int, 1000, 1000)
λ = (p) -> for x in p[1]:p[3], y in y1:y2 m[x, y] += 1 end
filter(p -> p[1] == p[3] || p[2] == p[4],
map(l -> map(x -> parse(Int, x), 
    match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
    readlines("input")
))
# map((x1, y1, x2, y2) -> λ(x1, y1, x2, y2), 