s = Set()
f = (m) -> push!(s, (m[1], m[2], m[3]))
map(l -> f(map(x -> parse(Int, x), match(r"(\d+),(\d+),(\d+)", l))), readlines("input"))
