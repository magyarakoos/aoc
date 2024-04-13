pos = 0, depth = 0
f = (t, x) -> (t == ')

map(l -> (split(l)[1][1], parse(Int, split(l)[2])), readlines("input"))
