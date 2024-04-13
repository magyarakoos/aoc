pos = 0; depth = 0
f = (t, x) -> (t == 'f' ? global pos += x : t == 'd' ? global depth += x : global depth -= x)
map(l -> f(split(l)[1][1], parse(Int, split(l)[2])), readlines("input"))
