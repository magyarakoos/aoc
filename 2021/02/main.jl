pos = 0; depth = 0
f = (t, x) -> (t == 'f' ? pos += x : t == 'd' ? depth += x : depth -= x)
map(l -> f(split(l)[1][1], parse(Int, split(l)[2])), readlines("input"))
