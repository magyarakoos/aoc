s = Set()
f = (m) -> push!(s, (parse(Int, m[1]), parse(Int, m[2])))
map(l -> map(x -> parse(Int, x), match(r"(\d+),(\d+),(\d+)", l)), readlines("input"))
