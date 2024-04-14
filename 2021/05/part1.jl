m = zeros(Int, 1000, 1000)
filter(p -> x1 == x2 || y1 == y2, 
map(x -> [x[1], x[2], x[3], x[4]],
map(l -> 
map(x -> parse(Int, x), 
match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
readlines("input")
))
)
# λ = (x1, y1, x2, y2) -> for x in x1:x2, y in y1:y2 m[x, y] += 1 end
# map((x1, y1, x2, y2) -> λ(x1, y1, x2, y2), 