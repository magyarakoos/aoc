s = Set()
f = (m) -> push!(s, (parse(Int, m[1]), parse(Int,)))
map(l -> match(r"(\d+),(\d+),(\d+)", l), readlines("input"))
