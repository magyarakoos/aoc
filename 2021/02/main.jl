f = map(l -> (split(l)[1][1], parse(Int, split(l)[2])), readlines("input"))
map(x -> x, filter(t -> t[1] == 'f', f))